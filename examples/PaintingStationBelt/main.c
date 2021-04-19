#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <open62541/plugin/log_stdout.h>
#include <open62541/server.h>
#include <open62541/server_config_default.h>
#include <signal.h>
#include <stdlib.h>
#include "PaintingStationBelt.h"
#include "Callbacks.h"

#include <time.h>
#ifndef WIN32
#include <pthread.h>
#define THREAD_HANDLE pthread_t
#define THREAD_CREATE(handle, callback) pthread_create(&handle, NULL, callback, NULL)
#define THREAD_JOIN(handle) pthread_join(handle, NULL)
#define THREAD_CALLBACK(name) static void * name(void *_)
#else
#include <windows.h>
#define THREAD_HANDLE HANDLE
#define THREAD_CREATE(handle, callback) { handle = CreateThread( NULL, 0, callback, NULL, 0, NULL); }
#define THREAD_JOIN(handle) WaitForSingleObject(handle, INFINITE)
#define THREAD_CALLBACK(name) static DWORD WINAPI name( LPVOID lpParam )
#endif


static UA_Server* server;
static volatile UA_Boolean running = true;
UA_UInt16 nsIdx; //Namespace  "http://helloWorld.com/UA/"

static void stopHandler(int sign) {
    UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "received ctrl-c");
    running = false;
}

THREAD_CALLBACK(ThreadWorker) {
    while(running) {
        UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER,
                    "Try to dequeue an async operation");
        const UA_AsyncOperationRequest* request = NULL;
        void *context = NULL;
        UA_AsyncOperationType type;
        if(UA_Server_getAsyncOperationNonBlocking(server, &type, &request, &context, NULL) == true) {
            UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "AsyncMethod_Testing: Got entry: OKAY");
            UA_CallMethodResult response = UA_Server_call(server, &request->callMethodRequest);
            UA_Server_setAsyncOperationResult(server, (UA_AsyncOperationResponse*)&response,
                                              context);
            UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "AsyncMethod_Testing: Call done: OKAY");
            UA_CallMethodResult_clear(&response);
        } else {
            /* not a good style, but done for simplicity :-) */
            sleep(5);
        }
    }
    return 0;
}

/* This callback will be called when a new entry is added to the Callrequest queue */
static void
TestCallback(UA_Server *server) {
    UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER,
                "Dispatched an async method");
}

int main(int argc, char** argv) {
    signal(SIGINT, stopHandler);
    signal(SIGTERM, stopHandler);

    server = UA_Server_new();
    UA_ServerConfig *config = UA_Server_getConfig(server);
    UA_ServerConfig_setDefault(config);
    UA_StatusCode retval;

     /* Set the NotifyCallback */
    config->asyncOperationNotifyCallback = TestCallback;
    /* create nodes from nodeset */
    if(PaintingStationBelt(server) != UA_STATUSCODE_GOOD) {
        UA_LOG_ERROR(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "Could not add the PaintingStationBelt nodeset. "
        "Check previous output for any error.");
        retval = UA_STATUSCODE_BADUNEXPECTEDERROR;
    } else {
        // Do some additional stuff with the nodes
        // this will just get the namespace index, since it is already added to the server
        nsIdx = UA_Server_addNamespace(server, "http://deteconFischertechnik/UA/");		
    }
	
    UA_NodeId parent = UA_NODEID_NUMERIC(nsIdx, 3001);
	Callbacks_Init(server, &parent, &nsIdx);

    THREAD_HANDLE hThread;
    THREAD_CREATE(hThread, ThreadWorker);

	retval = UA_Server_run(server, &running);

    THREAD_JOIN(hThread);

    UA_Server_delete(server);
    
    return retval == UA_STATUSCODE_GOOD ? EXIT_SUCCESS : EXIT_FAILURE;
}
