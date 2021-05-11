## callbacks for variables

You can associate callback functions with variables. Those functions will be executed either before reading variables or after writing them.
Those callback functions can be used to log user variable modifications.

Definde the callback function

``` {.objectivec language="C"}
void 
	Callbacks_AfterWrite_State(UA_Server *server,
	const UA_NodeId *sessionId, void *sessionContext,
	const UA_NodeId *nodeId, void *nodeContext,
	const UA_NumericRange *range, const UA_DataValue *data)
	{
		UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "State has Changed");
	}        
```

and assign the callback function as follows

``` {.objectivec language="C"}
/*Create and set the appropriate methods in the Callback variable. Important if you don't assign a function you have to set NULL, otherwise unexpected pointer errors can occur.*/
	UA_ValueCallback callback;
	callback.onRead = NULL;
	callback.onWrite = Callbacks_AfterWrite_State;
	//Set the callback variable to the NodeID
	UA_Server_setVariableNode_valueCallback(server, 
	variable_State,
	callback);
```

From now on, changes to the variable will be logged.
