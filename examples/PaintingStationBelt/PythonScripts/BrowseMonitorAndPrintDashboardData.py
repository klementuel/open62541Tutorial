import sys
sys.path.insert(0, "..")
import logging
import time

try:
    from IPython import embed
except ImportError:
    import code

    def embed():
        vars = globals()
        vars.update(locals())
        shell = code.InteractiveConsole(vars)
        shell.interact()
        



from opcua import Client
from opcua import ua
import opcua.common
import json

import threading


nodeList = []

def update():
     newList = nodeList
     for item in newList:
            out = {
                "topic" : str(item.get_browse_name()).split(":",1)[1].split(")",1)[0],
                "payload" : str(item.get_value())
            }
            jsonout = json.dumps(out)
            print(jsonout)




class SubHandler(object):

    """
    Subscription Handler. To receive events from server for a subscription
    data_change and event methods are called directly from receiving thread.
    Do not do expensive, slow or network operation there. Create another 
    thread if you need to do such a thing
    """

    def datachange_notification(self, node, val, data):  
       threading.Thread(target=update).start()
        
    def event_notification(self, event):
        print("Python: New event", event)



if __name__ == "__main__":
    logging.basicConfig(level=logging.WARN)
    #logger = logging.getLogger("KeepAlive")
    #logger.setLevel(logging.DEBUG)

    client = Client("opc.tcp://localhost:4840/")
    # client = Client("opc.tcp://admin@localhost:4840/freeopcua/server/") #connect using a user
    try:
        client.connect()
        client.load_type_definitions()  # load definition of server specific structures/extension objects

        # gettting our namespace idx
        uri = "http://deteconFischertechnik/UA/"
        idx = client.get_namespace_index(uri)
        
        root = client.get_root_node()
        mainObj = root.get_child(["0:Objects", "{}:PaintingStationBelt".format(idx)])
        machineData = mainObj.get_child(["{}:MachineData".format(idx)])
        kpi = mainObj.get_child(["{}:KPI".format(idx)])

        # getting Nodes Variables
        nodeList.append(machineData.get_child(["{}:State".format(idx)]))
        nodeList.append(machineData.get_child(["{}:LastStartTime".format(idx)]))
        nodeList.append(machineData.get_child(["{}:LastStopTime".format(idx)]))
        nodeList.append(machineData.get_child(["{}:ProductIsReady".format(idx)]))
       
        
        # getting Nodes KPI Real Time Infroamtions
        nodeList.append(kpi.get_child(["{}:RealTimeInformation".format(idx), "{}:LastCycleTime".format(idx)]))
        nodeList.append(kpi.get_child(["{}:RealTimeInformation".format(idx), "{}:LastWaitTime".format(idx)]))
        nodeList.append(kpi.get_child(["{}:RealTimeInformation".format(idx), "{}:LastProductionTime".format(idx)]))

        
        #getting Nodes HealtMeter
        nodeList.append(kpi.get_child(["{}:HealtMeter".format(idx), "{}:StoppageCount".format(idx)]))
        nodeList.append(kpi.get_child(["{}:HealtMeter".format(idx), "{}:FailureCount".format(idx)]))
        nodeList.append(kpi.get_child(["{}:HealtMeter".format(idx), "{}:OperationTimeFailureCount".format(idx)]))
        nodeList.append(kpi.get_child(["{}:HealtMeter".format(idx), "{}:ReqTaktTime".format(idx)]))    

        nodeList.append(kpi.get_child(["{}:Quality".format(idx), "{}:MTBF".format(idx)]))
        nodeList.append(kpi.get_child(["{}:Quality".format(idx), "{}:Yield".format(idx)]))
        
        nodeList.append(kpi.get_child(["{}:Responsiveness".format(idx), "{}:AverageCycleTime".format(idx)]))
        nodeList.append(kpi.get_child(["{}:Responsiveness".format(idx), "{}:AverageProductionTime".format(idx)]))
        nodeList.append(kpi.get_child(["{}:Responsiveness".format(idx), "{}:AverageWaitTime".format(idx)]))
        
        nodeList.append(kpi.get_child(["{}:Efficiency".format(idx), "{}:Availability".format(idx)]))
        nodeList.append(kpi.get_child(["{}:Efficiency".format(idx), "{}:OEE".format(idx)]))
        nodeList.append(kpi.get_child(["{}:Efficiency".format(idx), "{}:Performance".format(idx)]))
        nodeList.append(kpi.get_child(["{}:Efficiency".format(idx), "{}:Quality".format(idx)]))
        nodeList.append(kpi.get_child(["{}:Efficiency".format(idx), "{}:Utilization".format(idx)]))
 
        # subscribing to a variable node
        handler = SubHandler()
        sub = client.create_subscription(500, handler)
        handle = sub.subscribe_data_change(nodeList[0])
        
        time.sleep(0.1)



        embed()
    finally:
        client.disconnect()