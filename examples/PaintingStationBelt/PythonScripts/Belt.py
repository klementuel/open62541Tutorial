import sys
sys.path.insert(0, "..")
import logging
import time
import ftrobopy,sys


from opcua import Client
from opcua import ua

from datetime import datetime

if __name__ == "__main__":
    logging.basicConfig(level=logging.WARN)

    client = Client("opc.tcp://localhost:4840/")
    
    
   
    try:
        client.connect()
        client.load_type_definitions()  # load definition of server specific structures/extension objects
        
        # gettting our namespace idx
        uri = "http://deteconFischertechnik/UA/"
        idx = client.get_namespace_index(uri)
     

        # Now getting a variable node using its browse path
        # Client has a few methods to get proxy to UA nodes that should always be in address space such as Root or Objects
        root = client.get_root_node()
        mainObj = root.get_child(["0:Objects", "{}:PaintingStationBelt".format(idx)])
        machineData = mainObj.get_child(["{}:MachineData".format(idx)])
        kpi = mainObj.get_child(["{}:KPI".format(idx)])
        print("Root Node is:", root, " Main Object is: ", mainObj, " MachineData Node is: ", machineData, " Kpi Node is: ", kpi)

        # getting Nodes Variables
        varState = machineData.get_child(["{}:State".format(idx)])
        print("State Node is: ", varState)
        varStartTime =  machineData.get_child(["{}:LastStartTime".format(idx)])
        print("LastStartTime Node is: ", varStartTime)
        varStopTime =  machineData.get_child(["{}:LastStopTime".format(idx)])
        print("varStopTime Node is: ", varStopTime)
        varProductIsReady =  machineData.get_child(["{}:ProductIsReady".format(idx)])
        print("varProductIsReady Node is: ", varProductIsReady)
        
        
        # getting Nodes KPI Real Time Infroamtions
        varCycleTime = kpi.get_child(["{}:RealTimeInformation".format(idx), "{}:LastCycleTime".format(idx)])
        print("varCycleTime Node is: ", varCycleTime)
        varWaitTime = kpi.get_child(["{}:RealTimeInformation".format(idx), "{}:LastWaitTime".format(idx)])
        print("varWaitTime Node is: ", varWaitTime)
        varProductionTime = kpi.get_child(["{}:RealTimeInformation".format(idx), "{}:LastProductionTime".format(idx)])
        print("varProductionTime Node is: ", varProductionTime)
        
        #getting Nodes HealtMeter
        varStopCount = kpi.get_child(["{}:HealtMeter".format(idx), "{}:StoppageCount".format(idx)])
        print("varStopCount Node is: ", varStopCount)
        varFailCount = kpi.get_child(["{}:HealtMeter".format(idx), "{}:FailureCount".format(idx)])
        print("varFailCount Node is: ", varFailCount)
        
        #get Counts
        stopcount = varStopCount.get_value()
        failcount = varFailCount.get_value()
        
        #get Time now for Start Time
        startTime = datetime.now()
        
        #get last Stop Stime or set it to start Time if ist is first start
        if stopcount == 0:
            lastStopTime = datetime.now()
        else:
            lastStopTime = varStopTime.get_value()
        
        #Set Start Time
        varStartTime.set_value(ua.Variant(startTime, ua.VariantType.DateTime))
        
        #set Product State
        varProductIsReady.set_value(False, ua.VariantType.Boolean)
        
        #Connect to TxT Controller
        try:
         # Try to connect to the belt
            belt = ftrobopy.ftrobopy('192.168.7.2', 65000)
            host = belt.getHost()
        except:
            print("{\"result\" : \"error\"}")
            varState.set_value("ErrorConnection", ua.VariantType.String)

        #Start Belt Routine if Host is correct
        if (host !=  '192.168.7.2'):
            #node.send ({"status" : "controller not connected"})
            varState.set_value("ErrorConnection", ua.VariantType.String)
            print("{\"result\" : \"error\"}")
        else:
            # Motor Difintion
            Motor1 = belt.motor(1)
            # Lamp definition
            lamp = belt.output(3)
            # right photorisistor difinition
            R1 = belt.resistor(1)
            # left photorisistor difinition#
            R2 = belt.resistor(2)
            lamp.setLevel(512)
            time.sleep(2)
            R1_value = R1.value()
            #print (R1_value)
            if R1_value > 1000:
                time.sleep(1)
                print("{\"action\" : \"startBelt\"}")
                varState.set_value("StartBelt", ua.VariantType.String)
                check = True
                while check:
                    if varState.get_value() != "StartBelt":
                        check = False
                        varProductIsReady.set_value(False, ua.VariantType.Boolean)
                        varStopCount.set_value((stopcount + 1), ua.VariantType.UInt16)
                        varFailCount.set_value((failcount + 1), ua.VariantType.UInt16)
                
                        stopTime = datetime.now()
                        varStopTime.set_value(ua.Variant(stopTime, ua.VariantType.DateTime))
                        break
                    Motor1.setSpeed(-512)
                    # run the motor
                    R2_value = R2.value()
                    time.sleep(0.08)
                    #print (R2_value)
                    if R2_value > 1000:
                        while check:
                            Motor1.setSpeed(-512)
                            # run the motor
                            R2_value = R2.value()
                            if R2_value < 900:
                                Motor1.stop()
                                lamp.setLevel(0)
                                print("{\"action\" : \"stopBelt\",\"result\" : \"success\"}")
                                
                                ##OPCUA Sucess State and KPI Update
                                varState.set_value("StopBelt", ua.VariantType.String)
                                varProductIsReady.set_value(True, ua.VariantType.Boolean)
                                stopTime = datetime.now()
                                productionTime = round(stopTime.timestamp() - startTime.timestamp(),2)
                                cycleTime = round(stopTime.timestamp() - lastStopTime.timestamp(),2)
                                varStopTime.set_value(stopTime, ua.VariantType.DateTime) 
                                varCycleTime.set_value(cycleTime)  
                                varProductionTime.set_value(productionTime)
                                varStopCount.set_value((stopcount + 1), ua.VariantType.UInt16)
                                varWaitTime.set_value((cycleTime - productionTime))
                                check = False
                                time.sleep(1)
                                varState.set_value("Ready", ua.VariantType.String)
                                      
            else:      
                lamp.setLevel(0)
                print ("{\"result\" : \"error\"}")
                
                #OPC UA Error State and KPI Update
                varState.set_value("ErrorBelt", ua.VariantType.String)
                varProductIsReady.set_value(False, ua.VariantType.Boolean)
                varStopCount.set_value((stopcount + 1), ua.VariantType.UInt16)
                varFailCount.set_value((failcount + 1), ua.VariantType.UInt16)
                stopTime = datetime.now()
                varStopTime.set_value(ua.Variant(stopTime, ua.VariantType.DateTime))           
                
    finally:
        #Stop Services
        belt.stopOnline()
        client.disconnect()
        #sys.exit()