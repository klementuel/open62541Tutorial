#include <open62541/plugin/log_stdout.h>
#include <open62541/server.h>
#include <open62541/server_config_default.h>
#include <signal.h>
#include <stdlib.h>
#include "MotorSteuerung.h"

#include <time.h>

UA_Boolean running = true;
UA_UInt16 nsIdx; //Namespace  "http://helloWorld.com/UA/"

static UA_StatusCode
ControlMethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output) {
	//Handle Input 
	UA_Int16 speed_in = *(UA_Int16*)input[0].data;
	UA_Int16 distance_in = *(UA_Int16*)input[1].data;
	UA_Boolean direction_in = *(UA_Boolean*)input[2].data;
	
	//Handle Direction and set for test the return Value to direction value
	UA_Boolean ret_val = direction_in;
	UA_Variant value;
	UA_Variant_setScalar(&value, &ret_val, &UA_TYPES[UA_TYPES_BOOLEAN]);
	UA_Server_writeValue(server, UA_NODEID_NUMERIC(nsIdx, 2012), value);
	
	//Return the Value to Methode Output
    UA_Variant_setScalarCopy(output, &ret_val, &UA_TYPES[UA_TYPES_BOOLEAN]);
	
	//End Methode
    UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "Control was called");
    return UA_STATUSCODE_GOOD;
}



static void stopHandler(int sign) {
    UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "received ctrl-c");
    running = false;
}

int main(int argc, char** argv) {
    signal(SIGINT, stopHandler);
    signal(SIGTERM, stopHandler);
    
    UA_Server *server = UA_Server_new();
    UA_ServerConfig_setDefault(UA_Server_getConfig(server));
    UA_StatusCode retval;
    /* create nodes from nodeset */
    if(MotorSteuerung(server) != UA_STATUSCODE_GOOD) {
        UA_LOG_ERROR(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "Could not add the MotorSteuerung nodeset. "
        "Check previous output for any error.");
        retval = UA_STATUSCODE_BADUNEXPECTEDERROR;
    } else {
        // Do some additional stuff with the nodes
        // this will just get the namespace index, since it is already added to the server
        nsIdx = UA_Server_addNamespace(server, "http://helloWorld.com/UA/");
    	// UA_MOTOR1_RUNNING_BOOL = 2010 
		UA_NodeId testInstanceId = UA_NODEID_NUMERIC(nsIdx, 2010);
        UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "Motor1 Bool Running is in ns=%d;id=%d",
					testInstanceId.namespaceIndex, testInstanceId.identifier.numeric);
					
    }
	//
	retval = UA_Server_run_startup(server);
	//Set Callback for M1 Control https://open62541.org/doc/1.2/server.html#method-callbacks
	UA_Server_setMethodNode_callback(server,
                            		UA_NODEID_NUMERIC(nsIdx, 2013),
                            	   	&ControlMethodCallback);
	
	//https://open62541.org/doc/current/server.html#server-lifecycle
	if(retval != UA_STATUSCODE_GOOD) {
		 UA_Server_delete(server);
		 return retval;
	}
   
   	int timestampM1Running = time(0) + 2;
	int timestampM1Speed = time(0) + 1;
   	//https://open62541.org/doc/current/types.html
   	UA_Boolean m1running = false;
	UA_Int16 m1speed = 0;
	while(running == true)
	{
		//Server Routine https://open62541.org/doc/current/server.html#server-lifecycle
		UA_Server_run_iterate(server, true);
		
		//Multi Use Variables for Update
		int time_now = time(0);
		UA_Variant value;
		
		//Update Variable Running every 2s
		if(time_now > timestampM1Running) {
			timestampM1Running = time_now + 2;
			m1running = m1running ? false : true;
			//https://open62541.org/doc/current/plugin_log.html
	        UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "New Motor 1 Running Bool: %s",
						m1running ? "True" : "False");
			//https://open62541.org/doc/current/types.html#generated-data-type-definitions
			//https://open62541.org/doc/current/types.html#variant
			UA_Variant_setScalar(&value, &m1running,  &UA_TYPES[UA_TYPES_BOOLEAN]);
			
			//https://open62541.org/doc/current/server.html#reading-and-writing-node-attributes	
			UA_Server_writeValue(server, UA_NODEID_NUMERIC(nsIdx, 2010), value);
		}
		
		//Update Variable Speed every 1s
		if(time_now > timestampM1Speed) {
			timestampM1Speed = time_now + 1;
			m1speed++;
	        UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "New M1 Speed int: %d",
						m1speed); 
			UA_Variant_setScalar(&value, &m1speed,  &UA_TYPES[UA_TYPES_INT16]);
			UA_Server_writeValue(server, UA_NODEID_NUMERIC(nsIdx, 2011), value);
		}
	}
   
    return retval == UA_STATUSCODE_GOOD ? EXIT_SUCCESS : EXIT_FAILURE;
}
