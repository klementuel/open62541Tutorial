#include "Callbacks.h"

/**
 * @brief Pointer to the Orgin Namespace Index for Callbacks
 * 
 */
UA_UInt16 *_callbackNsIdx;

/**
 * @brief Pointer to the Orgin open62541 Server for Callbacks
 * 
 */
UA_Server *_callbackServer;

/**
 * @brief Pointer to the Orgin OPC UA Object that has the know Schemantic desricptes for the callbacks
 * 
 */
UA_NodeId *_callbackParent;


void 
Callbacks_Init(UA_Server *server, UA_NodeId *parent, UA_UInt16 *cbNsIdx)
{
    _callbackNsIdx = cbNsIdx;
    _callbackServer = server;
    _callbackParent = parent;

    Kpi_Init(server, parent, cbNsIdx);

    UA_QualifiedName targetNameArr[3] = {UA_QUALIFIEDNAME(*_callbackNsIdx, "Control"), 
                                        UA_QUALIFIEDNAME(*_callbackNsIdx, "Test"), 
                                        UA_QUALIFIEDNAME(*_callbackNsIdx, "")};

    UA_NodeId methode_Test;
    findChildNode(server, *parent, 2, targetNameArr, &methode_Test);


    UA_NodeId methode_Init;
    targetNameArr[1] = UA_QUALIFIEDNAME(*_callbackNsIdx, "Init");
    findChildNode(server, *parent, 2, targetNameArr, &methode_Init);
    
    UA_NodeId methode_Start;
    targetNameArr[1] = UA_QUALIFIEDNAME(*_callbackNsIdx, "Start");
    findChildNode(server, *parent, 2, targetNameArr, &methode_Start);

    UA_NodeId methode_Stop;
    targetNameArr[1] = UA_QUALIFIEDNAME(*_callbackNsIdx, "Stop");
    findChildNode(server, *parent, 2, targetNameArr, &methode_Stop);

    targetNameArr[0] = UA_QUALIFIEDNAME(*_callbackNsIdx, "MachineData");

    UA_NodeId variable_State;
    targetNameArr[1] = UA_QUALIFIEDNAME(*_callbackNsIdx, "State");
    findChildNode(server, *parent, 2, targetNameArr, &variable_State);

    targetNameArr[0] = UA_QUALIFIEDNAME(*_callbackNsIdx, "KPI");
    targetNameArr[1] = UA_QUALIFIEDNAME(*_callbackNsIdx, "RealTimeInformation");

    UA_NodeId variable_LastCycleTime;
    targetNameArr[2] = UA_QUALIFIEDNAME(*_callbackNsIdx, "LastCycleTime");
    findChildNode(server, *parent, 3, targetNameArr, &variable_LastCycleTime);

    UA_NodeId variable_LastWaitTime;
     targetNameArr[2] = UA_QUALIFIEDNAME(*_callbackNsIdx, "LastWaitTime");
    findChildNode(server, *parent, 3, targetNameArr, &variable_LastWaitTime);

    UA_NodeId variable_LastProdcutionTime;
    targetNameArr[2] = UA_QUALIFIEDNAME(*_callbackNsIdx, "LastProductionTime");
    findChildNode(server, *parent, 3, targetNameArr, &variable_LastProdcutionTime);

    UA_NodeId variable_StoppageCount;
    targetNameArr[1] = UA_QUALIFIEDNAME(*_callbackNsIdx, "HealtMeter");
    targetNameArr[2] = UA_QUALIFIEDNAME(*_callbackNsIdx, "StoppageCount");
    findChildNode(server, *parent, 3, targetNameArr, &variable_StoppageCount);
	
    UA_Server_setMethodNode_callback(server,
                            		methode_Test,
                            	   	&Callbacks_Methode_Test);
    UA_Server_setMethodNodeAsync(server, methode_Test, UA_TRUE);
    UA_Server_setMethodNode_callback(server,
                            		methode_Init,
                            	   	&Callbacks_Methode_Init);
    UA_Server_setMethodNode_callback(server,
                            		methode_Start,
                            	   	&Callbacks_Methode_Start);
    UA_Server_setMethodNodeAsync(server, methode_Start, UA_TRUE);
    UA_Server_setMethodNode_callback(server,
                            		methode_Stop,
                            	   	&Callbacks_Methode_Stop);


    UA_ValueCallback callback;
    callback.onRead = NULL;
    callback.onWrite = Callbacks_AfterWrite_LastCycleTime;
    UA_Server_setVariableNode_valueCallback(server, 
                                            variable_LastCycleTime,
                                            callback);
    callback.onWrite = Callbacks_AfterWrite_LastProductionTime;
    UA_Server_setVariableNode_valueCallback(server, 
                                            variable_LastProdcutionTime,
                                            callback);
    callback.onWrite = Callbacks_AfterWrite_LastWaitTime;
    UA_Server_setVariableNode_valueCallback(server, 
                                            variable_LastWaitTime,
                                            callback);
    callback.onWrite = Callbacks_AfterWrite_State;
    UA_Server_setVariableNode_valueCallback(server, 
                                            variable_State,
                                            callback);
    callback.onWrite = Callbacks_AfterWrite_StoppageCount;
    UA_Server_setVariableNode_valueCallback(server, 
                                            variable_StoppageCount,
                                            callback);
}

void 
Callbacks_AfterWrite_LastCycleTime(UA_Server *server,
               const UA_NodeId *sessionId, void *sessionContext,
               const UA_NodeId *nodeId, void *nodeContext,
               const UA_NumericRange *range, const UA_DataValue *data)
{
    UA_QualifiedName targetNameArr[3] = {UA_QUALIFIEDNAME(*_callbackNsIdx, "KPI"), 
                                        UA_QUALIFIEDNAME(*_callbackNsIdx, "Responsiveness"), 
                                        UA_QUALIFIEDNAME(*_callbackNsIdx, "AverageCycleTime")};
    UA_NodeId node;
    findChildNode(server, *_callbackParent, 3, targetNameArr, &node);

    static UA_UInt16 count = 0;
    UA_Variant test = *(UA_Variant*)data;
    UA_Duration cycleAll = 0;
    UA_Duration lastCycleTime = *(UA_Double*)test.data;
    count++;
     if(count != 1)
    {
        UA_Variant varOldAvg;
        UA_Variant_init(&varOldAvg);
        UA_Server_readValue(server, node, &varOldAvg);
        cycleAll = *(UA_Duration*)varOldAvg.data;
        cycleAll = cycleAll * (count-1);
    }
    UA_Double avg = (cycleAll + lastCycleTime) / count;
    UA_Variant varNewAvg;
    UA_Variant_setScalar(&varNewAvg, &avg, &UA_TYPES[UA_TYPES_DURATION]);
    UA_Server_writeValue(server, node, varNewAvg);

    

    
    targetNameArr[1] = UA_QUALIFIEDNAME(*_callbackNsIdx, "HealtMeter"); 
    targetNameArr[2] = UA_QUALIFIEDNAME(*_callbackNsIdx, "ReqTaktTime");
    UA_Variant varTakt;
    UA_Variant_init(&varTakt);                               
    findChildNode(server, *_callbackParent, 3, targetNameArr, &node);
    UA_Server_readValue(server, node, &varTakt);
    UA_Duration reqTakt = *(UA_Duration*)varTakt.data;

    if(reqTakt < lastCycleTime)
    {
        targetNameArr[2] = UA_QUALIFIEDNAME(*_callbackNsIdx, "OperationTimeFailureCount");
        findChildNode(server, *_callbackParent, 3, targetNameArr, &node);
        UA_Variant varOtfc;
        UA_Variant_init(&varOtfc);
        UA_Server_readValue(server, node, &varOtfc);
        UA_Int16 opCount = *(UA_UInt16*)varOtfc.data;
        opCount++;
        UA_Variant_setScalar(&varOtfc, &opCount, &UA_TYPES[UA_TYPES_UINT16]);
        UA_Server_writeValue(server, node, varOtfc);
    }
}

void 
Callbacks_AfterWrite_LastProductionTime(UA_Server *server,
               const UA_NodeId *sessionId, void *sessionContext,
               const UA_NodeId *nodeId, void *nodeContext,
               const UA_NumericRange *range, const UA_DataValue *data)
{
    UA_QualifiedName targetNameArr[3] = {UA_QUALIFIEDNAME(*_callbackNsIdx, "KPI"), 
                                        UA_QUALIFIEDNAME(*_callbackNsIdx, "Responsiveness"), 
                                        UA_QUALIFIEDNAME(*_callbackNsIdx, "AverageProductionTime")};
    UA_NodeId node;
    findChildNode(server, *_callbackParent, 3, targetNameArr, &node);

    static UA_UInt16 count = 0;
    UA_Variant test = *(UA_Variant*)data;
    UA_Double prodAll = 0;
    UA_Double lastProdTime = *(UA_Double*)test.data;
    count++;
     if(count != 1)
    {
        UA_Variant varOldAvg;
        UA_Variant_init(&varOldAvg);
        UA_Server_readValue(server, node, &varOldAvg);
        prodAll = *(UA_Double*)varOldAvg.data;
        prodAll = prodAll * (count-1);
    }
    UA_Double avg = (prodAll + lastProdTime) / count;
    UA_Variant varNewAvg;
    UA_Variant_setScalar(&varNewAvg, &avg, &UA_TYPES[UA_TYPES_DOUBLE]);
    UA_Server_writeValue(server, node, varNewAvg);
}            

void 
Callbacks_AfterWrite_LastWaitTime(UA_Server *server,
               const UA_NodeId *sessionId, void *sessionContext,
               const UA_NodeId *nodeId, void *nodeContext,
               const UA_NumericRange *range, const UA_DataValue *data)
{
    UA_QualifiedName targetNameArr[3] = {UA_QUALIFIEDNAME(*_callbackNsIdx, "KPI"), 
                                        UA_QUALIFIEDNAME(*_callbackNsIdx, "Responsiveness"), 
                                        UA_QUALIFIEDNAME(*_callbackNsIdx, "AverageWaitTime")};
    UA_NodeId node;
    findChildNode(server, *_callbackParent, 3, targetNameArr, &node);

    static UA_UInt16 count = 0;
    UA_Variant test = *(UA_Variant*)data;
    UA_Double waitAll = 0;
    UA_Double lastWaitTime = *(UA_Double*)test.data;
    count++;
     if(count != 1)
    {
        UA_Variant varOldAvg;
        UA_Variant_init(&varOldAvg);
        UA_Server_readValue(server, node, &varOldAvg);
        waitAll = *(UA_Double*)varOldAvg.data;
        waitAll = waitAll * (count-1);
    }
    UA_Double avg = (waitAll + lastWaitTime) / count;
    UA_Variant varNewAvg;
    UA_Variant_setScalar(&varNewAvg, &avg, &UA_TYPES[UA_TYPES_DOUBLE]);
    UA_Server_writeValue(server, node, varNewAvg);

}               

void 
Callbacks_AfterWrite_State(UA_Server *server,
               const UA_NodeId *sessionId, void *sessionContext,
               const UA_NodeId *nodeId, void *nodeContext,
               const UA_NumericRange *range, const UA_DataValue *data)
{
    UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "State has Changed");
}               

extern void 
Callbacks_AfterWrite_StoppageCount(UA_Server *server,
               const UA_NodeId *sessionId, void *sessionContext,
               const UA_NodeId *nodeId, void *nodeContext,
               const UA_NumericRange *range, const UA_DataValue *data)
{
    Kpi_Update();
}

UA_StatusCode
Callbacks_Methode_Test(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{
    //Handle Input 
	UA_Boolean tL1 = *(UA_Boolean*)input[0].data;
	UA_Boolean tL2 = *(UA_Boolean*)input[1].data;
	UA_Boolean tBelt = *(UA_Boolean*)input[2].data;
    UA_Boolean ret = true;
	
    
    
    if(tL1)
    {
        char command[50];
        strcpy(command, "python3 ../PythonScripts/TestLightSensor1.py");
        system(command);
    }
    if(tL2)
    {
        char command[50];
        strcpy(command, "python3 ../PythonScripts/TestLightSensor2.py");
        system(command);
    }
    if(tBelt)
    {
         char command[50];
        strcpy(command, "python3 ../PythonScripts/TestBelt.py");
        system(command);
    }

   
	
	//Return the Value to Methode Output
    UA_Variant_setScalarCopy(output, &ret, &UA_TYPES[UA_TYPES_BOOLEAN]);
	
	//End Methode
    UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "Test was called");
    return UA_STATUSCODE_GOOD;
}

UA_StatusCode
Callbacks_Methode_Start(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{
    char command[50];
    strcpy(command, "python3 ../PythonScripts/Belt.py");
    system(command);
    UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "Start Belt was called");
    return UA_STATUSCODE_GOOD;
}

UA_StatusCode
Callbacks_Methode_Stop(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{
    UA_Variant value;
    UA_String in = UA_STRING("StopBelt");
    UA_NodeId node;
    
    UA_QualifiedName targetNameArr[3] = {UA_QUALIFIEDNAME(*_callbackNsIdx, "MachineData"), 
                                        UA_QUALIFIEDNAME(*_callbackNsIdx, "State"), 
                                        UA_QUALIFIEDNAME(*_callbackNsIdx, "")};
    findChildNode(server, *_callbackParent, 2, targetNameArr, &node);
	UA_Variant_setScalar(&value, &in, &UA_TYPES[UA_TYPES_STRING]);
	UA_Server_writeValue(server, node, value);

    //End Methode
    UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "Stop Belt was called");
    return UA_STATUSCODE_GOOD;
}                               

UA_StatusCode
Callbacks_Methode_Init(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{
    UA_Variant value;
    UA_String in = UA_STRING("Ready");
    UA_DateTime now = UA_DateTime_now();
    UA_Duration req;
    UA_NodeId node;
    
    UA_QualifiedName targetNameArr[3] = {UA_QUALIFIEDNAME(*_callbackNsIdx, "MachineData"), 
                                        UA_QUALIFIEDNAME(*_callbackNsIdx, "State"), 
                                        UA_QUALIFIEDNAME(*_callbackNsIdx, "")};
    findChildNode(server, *_callbackParent, 2, targetNameArr, &node);
	UA_Variant_setScalar(&value, &in, &UA_TYPES[UA_TYPES_STRING]);
	UA_Server_writeValue(server, node, value);

    targetNameArr[0] = UA_QUALIFIEDNAME(*_callbackNsIdx, "KPI");
    targetNameArr[1] = UA_QUALIFIEDNAME(*_callbackNsIdx, "HealtMeter");
    targetNameArr[2] = UA_QUALIFIEDNAME(*_callbackNsIdx, "ReqTaktTime");
    findChildNode(server, *_callbackParent, 3, targetNameArr, &node);

    UA_Variant var;
    UA_Variant_init(&var);
    UA_Server_readValue(server, node, &var);
    req = *(UA_Duration*)var.data;

    if(req == 0) 
    {
        req = 60;
        UA_Variant_setScalar(&value, &req, &UA_TYPES[UA_TYPES_DURATION]);
        UA_Server_writeValue(server, node, value);
    }

    return UA_STATUSCODE_GOOD;
}                             