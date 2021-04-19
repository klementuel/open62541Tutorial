#ifndef OPCUA_HELPER
#define OPCUA_HELPER
#include <open62541/plugin/log_stdout.h>
#include <open62541/server.h>
#include <open62541/plugin/log_stdout.h>


/**
 * @brief For Schematic Request with Browse Names
 * It Handle Erros until the request and give Feedback to the UA_Log
 * 
 * example:
 * nsIdx = UA_Server_addNamespace(server, "http://namespace/UA/");
 * UA_NodeId parent = UA_NODEID_NUMERIC(nsIdx, 3001);
 * UA_QualifiedName targetNameArr[2] = {UA_QUALIFIEDNAME(*_callbackNsIdx, "firstChildfromParent"), 
 *                                       UA_QUALIFIEDNAME(*_callbackNsIdx, "targetChildfromParent"); //this can be expant
 * 
 * UA_NodeId test;
 * findChildNode(server, *parent, 2, targetNameArr, &test);
 * 
 * @param server the UA_Server were we want to find the Child
 * @param parentNode Were we start to find the child
 * @param relativePathCnt How deep should we look for the Node ID
 * @param targetNameArr The Schemantic Request with Browse names as Array with UA_QualifiedName
 *  
 * @param result The Node ID wich we want to update
 * @return int -1 it'was an error, 0 everthing is ok
 */
extern int findChildNode(UA_Server *server, 
                    UA_NodeId parentNode, 
                    const int relativePathCnt, 
                    UA_QualifiedName targetNameArr[], 
                    UA_NodeId *result);

#endif