/**
 * @file Callbacks.h
 * @author Klemens Körner (klemens.koerner@detecon.com)
 * @brief The Callback Function
 * Just use Callbacks_Init
 * Everthings get Link with the Browse Mode from the Object
 * But you should use the Custom BeltType as NodeSetObject and dont change the BrowseNames
 * It is a Beta Version it has not Execption Handling Handle with Care
 * 
 * @version 0.6
 * @date 19-03-2021
 * 
 * Mozzilla Public License V2.0
 * 
 */

#ifndef CALLBACKS
#define CALLBACKS
#include <Python.h>
#include <open62541/plugin/log_stdout.h>
#include <open62541/server.h>
#include <open62541/server_config_default.h>
#include "OpcUaHelper.h"
#include "KpiCalculator.h"
#include <stdlib.h>
#include <signal.h>


/**
 * @brief Initial the Callbacks
 * 
 * @param server OPC UA Server
 * @param parent  OPC UA Object what need this Callbacks
 * @param cbNsIdx OPC UA Namespace from the Node ID Set
 */
extern void 
Callbacks_Init(UA_Server *server, UA_NodeId *parent, UA_UInt16 *cbNsIdx);

/**
 * @brief Callback After Write KPI/RealTimeData/LastCycleTime
 * It Calculate the AverageCycleTime in KPI/Responsiveness
 * 
 */
extern void 
Callbacks_AfterWrite_LastCycleTime(UA_Server *server,
               const UA_NodeId *sessionId, void *sessionContext,
               const UA_NodeId *nodeId, void *nodeContext,
               const UA_NumericRange *range, const UA_DataValue *data);

/**
 * @brief Callback After Write KPI/RealTimeData/LastProductionTime
 * It Calculate the AverageProductionTime in KPI/Responsiveness
 * 
 */
extern void 
Callbacks_AfterWrite_LastProductionTime(UA_Server *server,
               const UA_NodeId *sessionId, void *sessionContext,
               const UA_NodeId *nodeId, void *nodeContext,
               const UA_NumericRange *range, const UA_DataValue *data);

/**
 * @brief Callback After Write KPI/RealTimeData/LastWaitTime
 * It Calculate the AverageWaitTime in KPI/Responsiveness
 * 
 */
extern void 
Callbacks_AfterWrite_LastWaitTime(UA_Server *server,
               const UA_NodeId *sessionId, void *sessionContext,
               const UA_NodeId *nodeId, void *nodeContext,
               const UA_NumericRange *range, const UA_DataValue *data);

/**
 * @brief Callback After Write Variables/State
 * Itś a placeholder Function that can Handle a State Change
 * 
 */
extern void 
Callbacks_AfterWrite_State(UA_Server *server,
               const UA_NodeId *sessionId, void *sessionContext,
               const UA_NodeId *nodeId, void *nodeContext,
               const UA_NumericRange *range, const UA_DataValue *data);

/**
 * @brief Callback After Write KPI/HealthMeter/StoppageCount
 * If StoppageCount get Update it triggers the KPI Update Routine
 * 
 */
extern void 
Callbacks_AfterWrite_StoppageCount(UA_Server *server,
               const UA_NodeId *sessionId, void *sessionContext,
               const UA_NodeId *nodeId, void *nodeContext,
               const UA_NumericRange *range, const UA_DataValue *data);


/**
 * @brief Callback Method Methods/Test
 * The Callback for the Method
 * 
 */
extern UA_StatusCode
Callbacks_Methode_Test(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output);

/**
 * @brief Callback Method Methods/Start
 * The Callback for the Method
 * 
 */
extern UA_StatusCode
Callbacks_Methode_Start(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output);

/**
 * @brief Callback Method Methods/Stop
 * The Callback for the Method
 * 
 */
extern UA_StatusCode
Callbacks_Methode_Stop(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output);      

/**
 * @brief Callback Method Methods/Init
 * The Callback for the Method
 * 
 */
extern UA_StatusCode
Callbacks_Methode_Init(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output);        


extern void* StartPython(void *arg);           

#endif //CALLBACKS