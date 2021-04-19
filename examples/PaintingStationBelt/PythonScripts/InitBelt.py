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

        # getting Nodes Variables
        varState = machineData.get_child(["{}:State".format(idx)])
        varStartTime =  machineData.get_child(["{}:LastStartTime".format(idx)])
        varStopTime =  machineData.get_child(["{}:LastStopTime".format(idx)])
        varProductIsReady =  machineData.get_child(["{}:ProductIsReady".format(idx)])

        #getting Nodes HealtMeter
        varReqTime = kpi.get_child(["{}:HealtMeter".format(idx), "{}:ReqTaktTime".format(idx)])
        
        #get Time now for Start Time
        startTime = datetime.now()
        
        #get last Stop Stime
        lastStopTime = datetime.now()
        
        #Set Start Time
        varStartTime.set_value(ua.Variant(startTime, ua.VariantType.DateTime))
        
        #Set Stop Time
        varStopTime.set_value(ua.Variant(startTime, ua.VariantType.DateTime))
        
        #set Product State
        varProductIsReady.set_value(False, ua.VariantType.Boolean)
        
        varState.set_value("Ready", ua.VariantType.String)
        
        if varReqTime.get_value() == 0:
            varReqTime.set_value(30, ua.VariantType.Double)
                
    finally:
        #Stop Services

        client.disconnect()
        #sys.exit()