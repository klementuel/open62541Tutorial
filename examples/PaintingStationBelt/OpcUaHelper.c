#include "OpcUaHelper.h"

int findChildNode(UA_Server *server, 
                        UA_NodeId parentNode, 
                        const int relativePathCnt, 
                        UA_QualifiedName targetNameArr[], 
                        UA_NodeId *result) 
{
    int ret = 0;

    UA_BrowsePathResult bpr = UA_Server_browseSimplifiedBrowsePath(server, 
                parentNode, relativePathCnt, targetNameArr);

    if (bpr.statusCode != UA_STATUSCODE_GOOD || bpr.targetsSize < 1)
    {
        char msg[200];
        strcpy(msg, "Find Child Error from: ");
        for(int tragets = 0; tragets < relativePathCnt; tragets++)
        {
            strcat(msg, "/");
            strcat(msg, (char*)targetNameArr[tragets].name.data);
        }
        strcat(msg, " With status Code: "); 
        strcat(msg, UA_StatusCode_name(bpr.statusCode));
        UA_LOG_WARNING(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, msg);
        ret = -1;
    }
    else
    {
        UA_NodeId_copy(&bpr.targets[0].targetId.nodeId, result);
        char msg[200];
        strcpy(msg, "Child found:  ");
        for(int tragets = 0; tragets < relativePathCnt; tragets++)
        {
            strcat(msg, "/");
            strcat(msg, (char*)targetNameArr[tragets].name.data);
        }
        UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, msg);
    }

    
    UA_BrowsePathResult_clear(&bpr);

    return ret;
}

