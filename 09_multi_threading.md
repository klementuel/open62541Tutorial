## Multithreading Method Calls

Please read https://open62541.org/doc/current/server.html#async-operations before following this example.

By default, open62541 is configured single threaded. Consequently, the application will make blocking functions calls, which will prevent any parallel data processing during a method call.
Enable multithreading (Thread-Safe API) by setting `UA\_Multithreading = 100` with ccmake and rebuild. Any value 0 to 99 will result in no multithreading.

Extend code inclusions as follows:

``` {.objectivec language="C"}
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
```

and add two additional functions (before your main section):

``` {.objectivec language="C"}
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
```

Set the method call backs as follows:

``` {.objectivec language="C"}
UA_Server_setMethodNode_callback(server, methode_Start, &Callbacks_Methode_Start);
UA_Server_setMethodNodeAsync(server, methode_Start, UA_TRUE);
```

From now on, you can call asynchronous methods.

