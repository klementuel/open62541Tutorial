/* WARNING: This is a generated file.
 * Any manual changes will be overwritten. */

#include "PaintingStationBelt.h"


/* ItemType - ns=1;i=2002 */

static UA_StatusCode function_PaintingStationBelt_0_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectTypeAttributes attr = UA_ObjectTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "ItemType");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "ItemType");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECTTYPE,
UA_NODEID_NUMERIC(ns[1], 2002LU),
UA_NODEID_NUMERIC(ns[0], 58LU),
UA_NODEID_NUMERIC(ns[0], 45LU),
UA_QUALIFIEDNAME(ns[1], "ItemType"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTTYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_0_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2002LU)
);
}

/* ProductionFinish - ns=1;i=2030 */

static UA_StatusCode function_PaintingStationBelt_1_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 13LU);
UA_DateTime *variablenode_ns_1_i_2030_variant_DataContents =  UA_DateTime_new();
if (!variablenode_ns_1_i_2030_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_DateTime_init(variablenode_ns_1_i_2030_variant_DataContents);
*variablenode_ns_1_i_2030_variant_DataContents = ( (UA_DateTime)(978307200000 * UA_DATETIME_MSEC) + UA_DATETIME_UNIX_EPOCH);
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2030_variant_DataContents, &UA_TYPES[UA_TYPES_DATETIME]);
attr.displayName = UA_LOCALIZEDTEXT("", "ProductionFinish");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "ProductionFinish");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2030LU),
UA_NODEID_NUMERIC(ns[1], 2002LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "ProductionFinish"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_DateTime_delete(variablenode_ns_1_i_2030_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2030LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_1_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2030LU)
);
}

/* ID - ns=1;i=2022 */

static UA_StatusCode function_PaintingStationBelt_2_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12LU);
UA_String *variablenode_ns_1_i_2022_variant_DataContents =  UA_String_new();
if (!variablenode_ns_1_i_2022_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_1_i_2022_variant_DataContents);
*variablenode_ns_1_i_2022_variant_DataContents = UA_STRING_ALLOC("None");
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2022_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "ID");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "ID");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2022LU),
UA_NODEID_NUMERIC(ns[1], 2002LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "ID"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_1_i_2022_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2022LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_2_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2022LU)
);
}

/* CycleTime - ns=1;i=2071 */

static UA_StatusCode function_PaintingStationBelt_3_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 290LU);
UA_Double *variablenode_ns_1_i_2071_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_1_i_2071_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_1_i_2071_variant_DataContents);
*variablenode_ns_1_i_2071_variant_DataContents = (UA_Double) 0.0;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2071_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "CycleTime");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "CycleTime");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2071LU),
UA_NODEID_NUMERIC(ns[1], 2002LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "CycleTime"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_1_i_2071_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2071LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_3_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2071LU)
);
}

/* ProductionStart - ns=1;i=2029 */

static UA_StatusCode function_PaintingStationBelt_4_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 13LU);
UA_DateTime *variablenode_ns_1_i_2029_variant_DataContents =  UA_DateTime_new();
if (!variablenode_ns_1_i_2029_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_DateTime_init(variablenode_ns_1_i_2029_variant_DataContents);
*variablenode_ns_1_i_2029_variant_DataContents = ( (UA_DateTime)(978307200000 * UA_DATETIME_MSEC) + UA_DATETIME_UNIX_EPOCH);
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2029_variant_DataContents, &UA_TYPES[UA_TYPES_DATETIME]);
attr.displayName = UA_LOCALIZEDTEXT("", "ProductionStart");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "ProductionStart");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2029LU),
UA_NODEID_NUMERIC(ns[1], 2002LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "ProductionStart"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_DateTime_delete(variablenode_ns_1_i_2029_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2029LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_4_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2029LU)
);
}

/* Name - ns=1;i=2028 */

static UA_StatusCode function_PaintingStationBelt_5_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12LU);
UA_String *variablenode_ns_1_i_2028_variant_DataContents =  UA_String_new();
if (!variablenode_ns_1_i_2028_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_1_i_2028_variant_DataContents);
*variablenode_ns_1_i_2028_variant_DataContents = UA_STRING_ALLOC("None");
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2028_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "Name");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Name");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2028LU),
UA_NODEID_NUMERIC(ns[1], 2002LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Name"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_1_i_2028_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2028LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_5_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2028LU)
);
}

/* DeteconMachineTyp - ns=1;i=2003 */

static UA_StatusCode function_PaintingStationBelt_6_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectTypeAttributes attr = UA_ObjectTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "DeteconMachineTyp");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "DeteconMachineTyp");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECTTYPE,
UA_NODEID_NUMERIC(ns[1], 2003LU),
UA_NODEID_NUMERIC(ns[0], 58LU),
UA_NODEID_NUMERIC(ns[0], 45LU),
UA_QUALIFIEDNAME(ns[1], "DeteconMachineTyp"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTTYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_6_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2003LU)
);
}

/* PaintingStationBelt - ns=1;i=3001 */

static UA_StatusCode function_PaintingStationBelt_7_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "PaintingStationBelt");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "DeteconMachineTyp");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 3001LU),
UA_NODEID_NUMERIC(ns[0], 85LU),
UA_NODEID_NUMERIC(ns[0], 35LU),
UA_QUALIFIEDNAME(ns[1], "PaintingStationBelt"),
UA_NODEID_NUMERIC(ns[1], 2003LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_7_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 3001LU)
);
}

/* Control - ns=1;i=2090 */

static UA_StatusCode function_PaintingStationBelt_8_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Control");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Control");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2090LU),
UA_NODEID_NUMERIC(ns[1], 3001LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Control"),
UA_NODEID_NUMERIC(ns[0], 61LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_8_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2090LU)
);
}

/* Test - ns=1;i=2093 */

static UA_StatusCode function_PaintingStationBelt_9_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "Test");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Test");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[1], 2093LU),
UA_NODEID_NUMERIC(ns[1], 2090LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Test"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_PaintingStationBelt_9_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2093LU)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* OutputArguments - ns=1;i=2095 */

static UA_StatusCode function_PaintingStationBelt_10_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 0;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 296LU);
UA_Argument variablenode_ns_1_i_2095_variant_DataContents[1];

UA_init(&variablenode_ns_1_i_2095_variant_DataContents[0], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_1_i_2095_variant_DataContents[0].name = UA_STRING("Sucess");
variablenode_ns_1_i_2095_variant_DataContents[0].dataType = UA_NODEID_NUMERIC(ns[0], 1LU);
variablenode_ns_1_i_2095_variant_DataContents[0].valueRank = (UA_Int32) -1;
UA_Variant_setArray(&attr.value, &variablenode_ns_1_i_2095_variant_DataContents, (UA_Int32) 1, &UA_TYPES[UA_TYPES_ARGUMENT]);
attr.displayName = UA_LOCALIZEDTEXT("", "OutputArguments");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "OutputArguments");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2095LU),
UA_NODEID_NUMERIC(ns[1], 2093LU),
UA_NODEID_NUMERIC(ns[0], 46LU),
UA_QUALIFIEDNAME(ns[0], "OutputArguments"),
UA_NODEID_NUMERIC(ns[0], 68LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

return retVal;
}

static UA_StatusCode function_PaintingStationBelt_10_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2095LU)
);
}

/* InputArguments - ns=1;i=2094 */

static UA_StatusCode function_PaintingStationBelt_11_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 0;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 296LU);
UA_Argument variablenode_ns_1_i_2094_variant_DataContents[3];

UA_init(&variablenode_ns_1_i_2094_variant_DataContents[0], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_1_i_2094_variant_DataContents[0].name = UA_STRING("TestLightSensor1");
variablenode_ns_1_i_2094_variant_DataContents[0].dataType = UA_NODEID_NUMERIC(ns[0], 1LU);
variablenode_ns_1_i_2094_variant_DataContents[0].valueRank = (UA_Int32) -1;
variablenode_ns_1_i_2094_variant_DataContents[0].description = UA_LOCALIZEDTEXT("", "Manuel test LS1");

UA_init(&variablenode_ns_1_i_2094_variant_DataContents[1], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_1_i_2094_variant_DataContents[1].name = UA_STRING("TestLightSensor2");
variablenode_ns_1_i_2094_variant_DataContents[1].dataType = UA_NODEID_NUMERIC(ns[0], 1LU);
variablenode_ns_1_i_2094_variant_DataContents[1].valueRank = (UA_Int32) -1;
variablenode_ns_1_i_2094_variant_DataContents[1].description = UA_LOCALIZEDTEXT("", "Manuel test LS2");

UA_init(&variablenode_ns_1_i_2094_variant_DataContents[2], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_1_i_2094_variant_DataContents[2].name = UA_STRING("TestBelt");
variablenode_ns_1_i_2094_variant_DataContents[2].dataType = UA_NODEID_NUMERIC(ns[0], 1LU);
variablenode_ns_1_i_2094_variant_DataContents[2].valueRank = (UA_Int32) -1;
variablenode_ns_1_i_2094_variant_DataContents[2].description = UA_LOCALIZEDTEXT("", "DriveBelt 5s");
UA_Variant_setArray(&attr.value, &variablenode_ns_1_i_2094_variant_DataContents, (UA_Int32) 3, &UA_TYPES[UA_TYPES_ARGUMENT]);
attr.displayName = UA_LOCALIZEDTEXT("", "InputArguments");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "InputArguments");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2094LU),
UA_NODEID_NUMERIC(ns[1], 2093LU),
UA_NODEID_NUMERIC(ns[0], 46LU),
UA_QUALIFIEDNAME(ns[0], "InputArguments"),
UA_NODEID_NUMERIC(ns[0], 68LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);



return retVal;
}

static UA_StatusCode function_PaintingStationBelt_11_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2094LU)
);
}

/* Stop - ns=1;i=2092 */

static UA_StatusCode function_PaintingStationBelt_12_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "Stop");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Stop");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[1], 2092LU),
UA_NODEID_NUMERIC(ns[1], 2090LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Stop"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_PaintingStationBelt_12_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2092LU)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* Start - ns=1;i=2091 */

static UA_StatusCode function_PaintingStationBelt_13_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "Start");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Start");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[1], 2091LU),
UA_NODEID_NUMERIC(ns[1], 2090LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Start"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_PaintingStationBelt_13_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2091LU)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* Init - ns=1;i=2096 */

static UA_StatusCode function_PaintingStationBelt_14_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "Init");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Init");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[1], 2096LU),
UA_NODEID_NUMERIC(ns[1], 2090LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Init"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_PaintingStationBelt_14_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2096LU)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* MachineData - ns=1;i=2097 */

static UA_StatusCode function_PaintingStationBelt_15_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "MachineData");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "MachineData");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2097LU),
UA_NODEID_NUMERIC(ns[1], 3001LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "MachineData"),
UA_NODEID_NUMERIC(ns[0], 61LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_15_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2097LU)
);
}

/* LastStopTime - ns=1;i=2100 */

static UA_StatusCode function_PaintingStationBelt_16_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 13LU);
UA_DateTime *variablenode_ns_1_i_2100_variant_DataContents =  UA_DateTime_new();
if (!variablenode_ns_1_i_2100_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_DateTime_init(variablenode_ns_1_i_2100_variant_DataContents);
*variablenode_ns_1_i_2100_variant_DataContents = ( (UA_DateTime)(978307200000 * UA_DATETIME_MSEC) + UA_DATETIME_UNIX_EPOCH);
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2100_variant_DataContents, &UA_TYPES[UA_TYPES_DATETIME]);
attr.displayName = UA_LOCALIZEDTEXT("", "LastStopTime");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "LastStopTime");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2100LU),
UA_NODEID_NUMERIC(ns[1], 2097LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "LastStopTime"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_DateTime_delete(variablenode_ns_1_i_2100_variant_DataContents);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_16_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2100LU)
);
}

/* ProductIsReady - ns=1;i=2101 */

static UA_StatusCode function_PaintingStationBelt_17_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1LU);
UA_Boolean *variablenode_ns_1_i_2101_variant_DataContents =  UA_Boolean_new();
if (!variablenode_ns_1_i_2101_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Boolean_init(variablenode_ns_1_i_2101_variant_DataContents);
*variablenode_ns_1_i_2101_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2101_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "ProductIsReady");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "ProductIsReady");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2101LU),
UA_NODEID_NUMERIC(ns[1], 2097LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "ProductIsReady"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_1_i_2101_variant_DataContents);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_17_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2101LU)
);
}

/* State - ns=1;i=2102 */

static UA_StatusCode function_PaintingStationBelt_18_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12LU);
UA_String *variablenode_ns_1_i_2102_variant_DataContents =  UA_String_new();
if (!variablenode_ns_1_i_2102_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_1_i_2102_variant_DataContents);
*variablenode_ns_1_i_2102_variant_DataContents = UA_STRING_ALLOC("Off");
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2102_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "State");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "State");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2102LU),
UA_NODEID_NUMERIC(ns[1], 2097LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "State"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_1_i_2102_variant_DataContents);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_18_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2102LU)
);
}

/* LastStartTime - ns=1;i=2098 */

static UA_StatusCode function_PaintingStationBelt_19_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 13LU);
UA_DateTime *variablenode_ns_1_i_2098_variant_DataContents =  UA_DateTime_new();
if (!variablenode_ns_1_i_2098_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_DateTime_init(variablenode_ns_1_i_2098_variant_DataContents);
*variablenode_ns_1_i_2098_variant_DataContents = ( (UA_DateTime)(978307200000 * UA_DATETIME_MSEC) + UA_DATETIME_UNIX_EPOCH);
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2098_variant_DataContents, &UA_TYPES[UA_TYPES_DATETIME]);
attr.displayName = UA_LOCALIZEDTEXT("", "LastStartTime");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "LastStartTime");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2098LU),
UA_NODEID_NUMERIC(ns[1], 2097LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "LastStartTime"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_DateTime_delete(variablenode_ns_1_i_2098_variant_DataContents);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_19_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2098LU)
);
}

/* Control - ns=1;i=2005 */

static UA_StatusCode function_PaintingStationBelt_20_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Control");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Control");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2005LU),
UA_NODEID_NUMERIC(ns[1], 2003LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Control"),
UA_NODEID_NUMERIC(ns[0], 61LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2005LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_20_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2005LU)
);
}

/* Init - ns=1;i=2099 */

static UA_StatusCode function_PaintingStationBelt_21_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "Init");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Init");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[1], 2099LU),
UA_NODEID_NUMERIC(ns[1], 2005LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Init"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2099LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_PaintingStationBelt_21_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2099LU)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* Test - ns=1;i=2020 */

static UA_StatusCode function_PaintingStationBelt_22_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "Test");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Test");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[1], 2020LU),
UA_NODEID_NUMERIC(ns[1], 2005LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Test"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2020LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_PaintingStationBelt_22_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2020LU)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* OutputArguments - ns=1;i=2027 */

static UA_StatusCode function_PaintingStationBelt_23_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 0;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 296LU);
UA_Argument variablenode_ns_1_i_2027_variant_DataContents[1];

UA_init(&variablenode_ns_1_i_2027_variant_DataContents[0], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_1_i_2027_variant_DataContents[0].name = UA_STRING("Sucess");
variablenode_ns_1_i_2027_variant_DataContents[0].dataType = UA_NODEID_NUMERIC(ns[0], 1LU);
variablenode_ns_1_i_2027_variant_DataContents[0].valueRank = (UA_Int32) -1;
UA_Variant_setArray(&attr.value, &variablenode_ns_1_i_2027_variant_DataContents, (UA_Int32) 1, &UA_TYPES[UA_TYPES_ARGUMENT]);
attr.displayName = UA_LOCALIZEDTEXT("", "OutputArguments");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "OutputArguments");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2027LU),
UA_NODEID_NUMERIC(ns[1], 2020LU),
UA_NODEID_NUMERIC(ns[0], 46LU),
UA_QUALIFIEDNAME(ns[0], "OutputArguments"),
UA_NODEID_NUMERIC(ns[0], 68LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2027LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_23_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2027LU)
);
}

/* InputArguments - ns=1;i=2021 */

static UA_StatusCode function_PaintingStationBelt_24_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 0;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 296LU);
UA_Argument variablenode_ns_1_i_2021_variant_DataContents[3];

UA_init(&variablenode_ns_1_i_2021_variant_DataContents[0], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_1_i_2021_variant_DataContents[0].name = UA_STRING("TestLightSensor1");
variablenode_ns_1_i_2021_variant_DataContents[0].dataType = UA_NODEID_NUMERIC(ns[0], 1LU);
variablenode_ns_1_i_2021_variant_DataContents[0].valueRank = (UA_Int32) -1;
variablenode_ns_1_i_2021_variant_DataContents[0].description = UA_LOCALIZEDTEXT("", "Manuel test LS1");

UA_init(&variablenode_ns_1_i_2021_variant_DataContents[1], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_1_i_2021_variant_DataContents[1].name = UA_STRING("TestLightSensor2");
variablenode_ns_1_i_2021_variant_DataContents[1].dataType = UA_NODEID_NUMERIC(ns[0], 1LU);
variablenode_ns_1_i_2021_variant_DataContents[1].valueRank = (UA_Int32) -1;
variablenode_ns_1_i_2021_variant_DataContents[1].description = UA_LOCALIZEDTEXT("", "Manuel test LS2");

UA_init(&variablenode_ns_1_i_2021_variant_DataContents[2], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_1_i_2021_variant_DataContents[2].name = UA_STRING("TestBelt");
variablenode_ns_1_i_2021_variant_DataContents[2].dataType = UA_NODEID_NUMERIC(ns[0], 1LU);
variablenode_ns_1_i_2021_variant_DataContents[2].valueRank = (UA_Int32) -1;
variablenode_ns_1_i_2021_variant_DataContents[2].description = UA_LOCALIZEDTEXT("", "DriveBelt 5s");
UA_Variant_setArray(&attr.value, &variablenode_ns_1_i_2021_variant_DataContents, (UA_Int32) 3, &UA_TYPES[UA_TYPES_ARGUMENT]);
attr.displayName = UA_LOCALIZEDTEXT("", "InputArguments");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "InputArguments");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2021LU),
UA_NODEID_NUMERIC(ns[1], 2020LU),
UA_NODEID_NUMERIC(ns[0], 46LU),
UA_QUALIFIEDNAME(ns[0], "InputArguments"),
UA_NODEID_NUMERIC(ns[0], 68LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);



retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2021LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_24_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2021LU)
);
}

/* Start - ns=1;i=2025 */

static UA_StatusCode function_PaintingStationBelt_25_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "Start");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Start");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[1], 2025LU),
UA_NODEID_NUMERIC(ns[1], 2005LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Start"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2025LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_PaintingStationBelt_25_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2025LU)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* Stop - ns=1;i=2026 */

static UA_StatusCode function_PaintingStationBelt_26_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "Stop");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Stop");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[1], 2026LU),
UA_NODEID_NUMERIC(ns[1], 2005LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Stop"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2026LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_PaintingStationBelt_26_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2026LU)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* MachineData - ns=1;i=2006 */

static UA_StatusCode function_PaintingStationBelt_27_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "MachineData");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "MachineData");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2006LU),
UA_NODEID_NUMERIC(ns[1], 2003LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "MachineData"),
UA_NODEID_NUMERIC(ns[0], 61LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2006LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_27_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2006LU)
);
}

/* ProductIsReady - ns=1;i=2055 */

static UA_StatusCode function_PaintingStationBelt_28_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1LU);
UA_Boolean *variablenode_ns_1_i_2055_variant_DataContents =  UA_Boolean_new();
if (!variablenode_ns_1_i_2055_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Boolean_init(variablenode_ns_1_i_2055_variant_DataContents);
*variablenode_ns_1_i_2055_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2055_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "ProductIsReady");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "ProductIsReady");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2055LU),
UA_NODEID_NUMERIC(ns[1], 2006LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "ProductIsReady"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_1_i_2055_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2055LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_28_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2055LU)
);
}

/* State - ns=1;i=2072 */

static UA_StatusCode function_PaintingStationBelt_29_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12LU);
UA_String *variablenode_ns_1_i_2072_variant_DataContents =  UA_String_new();
if (!variablenode_ns_1_i_2072_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_1_i_2072_variant_DataContents);
*variablenode_ns_1_i_2072_variant_DataContents = UA_STRING_ALLOC("Off");
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2072_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "State");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "State");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2072LU),
UA_NODEID_NUMERIC(ns[1], 2006LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "State"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_1_i_2072_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2072LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_29_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2072LU)
);
}

/* LastStartTime - ns=1;i=2023 */

static UA_StatusCode function_PaintingStationBelt_30_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 13LU);
UA_DateTime *variablenode_ns_1_i_2023_variant_DataContents =  UA_DateTime_new();
if (!variablenode_ns_1_i_2023_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_DateTime_init(variablenode_ns_1_i_2023_variant_DataContents);
*variablenode_ns_1_i_2023_variant_DataContents = ( (UA_DateTime)(978307200000 * UA_DATETIME_MSEC) + UA_DATETIME_UNIX_EPOCH);
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2023_variant_DataContents, &UA_TYPES[UA_TYPES_DATETIME]);
attr.displayName = UA_LOCALIZEDTEXT("", "LastStartTime");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "LastStartTime");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2023LU),
UA_NODEID_NUMERIC(ns[1], 2006LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "LastStartTime"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_DateTime_delete(variablenode_ns_1_i_2023_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2023LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_30_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2023LU)
);
}

/* LastStopTime - ns=1;i=2024 */

static UA_StatusCode function_PaintingStationBelt_31_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 13LU);
UA_DateTime *variablenode_ns_1_i_2024_variant_DataContents =  UA_DateTime_new();
if (!variablenode_ns_1_i_2024_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_DateTime_init(variablenode_ns_1_i_2024_variant_DataContents);
*variablenode_ns_1_i_2024_variant_DataContents = ( (UA_DateTime)(978307200000 * UA_DATETIME_MSEC) + UA_DATETIME_UNIX_EPOCH);
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2024_variant_DataContents, &UA_TYPES[UA_TYPES_DATETIME]);
attr.displayName = UA_LOCALIZEDTEXT("", "LastStopTime");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "LastStopTime");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2024LU),
UA_NODEID_NUMERIC(ns[1], 2006LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "LastStopTime"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_DateTime_delete(variablenode_ns_1_i_2024_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2024LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_31_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2024LU)
);
}

/* KPITYPE - ns=1;i=2031 */

static UA_StatusCode function_PaintingStationBelt_32_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectTypeAttributes attr = UA_ObjectTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "KPITYPE");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "KPITYPE");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECTTYPE,
UA_NODEID_NUMERIC(ns[1], 2031LU),
UA_NODEID_NUMERIC(ns[0], 58LU),
UA_NODEID_NUMERIC(ns[0], 45LU),
UA_QUALIFIEDNAME(ns[1], "KPITYPE"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTTYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_32_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2031LU)
);
}

/* KPI - ns=1;i=2007 */

static UA_StatusCode function_PaintingStationBelt_33_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "KPI");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "KPITYPE");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2007LU),
UA_NODEID_NUMERIC(ns[1], 3001LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "KPI"),
UA_NODEID_NUMERIC(ns[1], 2031LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_33_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2007LU)
);
}

/* HealtMeter - ns=1;i=2008 */

static UA_StatusCode function_PaintingStationBelt_34_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "HealtMeter");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "HealtMeter");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2008LU),
UA_NODEID_NUMERIC(ns[1], 2007LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "HealtMeter"),
UA_NODEID_NUMERIC(ns[0], 61LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_34_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2008LU)
);
}

/* OperationTimeFailureCount - ns=1;i=2012 */

static UA_StatusCode function_PaintingStationBelt_35_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 5LU);
UA_UInt16 *variablenode_ns_1_i_2012_variant_DataContents =  UA_UInt16_new();
if (!variablenode_ns_1_i_2012_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_UInt16_init(variablenode_ns_1_i_2012_variant_DataContents);
*variablenode_ns_1_i_2012_variant_DataContents = (UA_UInt16) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2012_variant_DataContents, &UA_TYPES[UA_TYPES_UINT16]);
attr.displayName = UA_LOCALIZEDTEXT("", "OperationTimeFailureCount");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "OperationTimeFailureCount");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2012LU),
UA_NODEID_NUMERIC(ns[1], 2008LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "OperationTimeFailureCount"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_UInt16_delete(variablenode_ns_1_i_2012_variant_DataContents);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_35_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2012LU)
);
}

/* StoppageCount - ns=1;i=2010 */

static UA_StatusCode function_PaintingStationBelt_36_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 5LU);
UA_UInt16 *variablenode_ns_1_i_2010_variant_DataContents =  UA_UInt16_new();
if (!variablenode_ns_1_i_2010_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_UInt16_init(variablenode_ns_1_i_2010_variant_DataContents);
*variablenode_ns_1_i_2010_variant_DataContents = (UA_UInt16) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2010_variant_DataContents, &UA_TYPES[UA_TYPES_UINT16]);
attr.displayName = UA_LOCALIZEDTEXT("", "StoppageCount");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "StoppageCount");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2010LU),
UA_NODEID_NUMERIC(ns[1], 2008LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "StoppageCount"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_UInt16_delete(variablenode_ns_1_i_2010_variant_DataContents);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_36_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2010LU)
);
}

/* FailureCount - ns=1;i=2011 */

static UA_StatusCode function_PaintingStationBelt_37_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 5LU);
UA_UInt16 *variablenode_ns_1_i_2011_variant_DataContents =  UA_UInt16_new();
if (!variablenode_ns_1_i_2011_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_UInt16_init(variablenode_ns_1_i_2011_variant_DataContents);
*variablenode_ns_1_i_2011_variant_DataContents = (UA_UInt16) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2011_variant_DataContents, &UA_TYPES[UA_TYPES_UINT16]);
attr.displayName = UA_LOCALIZEDTEXT("", "FailureCount");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "FailureCount");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2011LU),
UA_NODEID_NUMERIC(ns[1], 2008LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "FailureCount"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_UInt16_delete(variablenode_ns_1_i_2011_variant_DataContents);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_37_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2011LU)
);
}

/* ReqTaktTime - ns=1;i=2009 */

static UA_StatusCode function_PaintingStationBelt_38_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 290LU);
UA_Double *variablenode_ns_1_i_2009_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_1_i_2009_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_1_i_2009_variant_DataContents);
*variablenode_ns_1_i_2009_variant_DataContents = (UA_Double) 0.0;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2009_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "ReqTaktTime");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "ReqTaktTime");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2009LU),
UA_NODEID_NUMERIC(ns[1], 2008LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "ReqTaktTime"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_1_i_2009_variant_DataContents);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_38_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2009LU)
);
}

/* Efficiency - ns=1;i=2016 */

static UA_StatusCode function_PaintingStationBelt_39_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Efficiency");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Efficiency");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2016LU),
UA_NODEID_NUMERIC(ns[1], 2007LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Efficiency"),
UA_NODEID_NUMERIC(ns[0], 61LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_39_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2016LU)
);
}

/* Quality - ns=1;i=2018 */

static UA_StatusCode function_PaintingStationBelt_40_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 5LU);
UA_UInt16 *variablenode_ns_1_i_2018_variant_DataContents =  UA_UInt16_new();
if (!variablenode_ns_1_i_2018_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_UInt16_init(variablenode_ns_1_i_2018_variant_DataContents);
*variablenode_ns_1_i_2018_variant_DataContents = (UA_UInt16) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2018_variant_DataContents, &UA_TYPES[UA_TYPES_UINT16]);
attr.displayName = UA_LOCALIZEDTEXT("", "Quality");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Quality");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2018LU),
UA_NODEID_NUMERIC(ns[1], 2016LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Quality"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_UInt16_delete(variablenode_ns_1_i_2018_variant_DataContents);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_40_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2018LU)
);
}

/* Utilization - ns=1;i=2017 */

static UA_StatusCode function_PaintingStationBelt_41_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 5LU);
UA_UInt16 *variablenode_ns_1_i_2017_variant_DataContents =  UA_UInt16_new();
if (!variablenode_ns_1_i_2017_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_UInt16_init(variablenode_ns_1_i_2017_variant_DataContents);
*variablenode_ns_1_i_2017_variant_DataContents = (UA_UInt16) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2017_variant_DataContents, &UA_TYPES[UA_TYPES_UINT16]);
attr.displayName = UA_LOCALIZEDTEXT("", "Utilization");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Utilization");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2017LU),
UA_NODEID_NUMERIC(ns[1], 2016LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Utilization"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_UInt16_delete(variablenode_ns_1_i_2017_variant_DataContents);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_41_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2017LU)
);
}

/* Availability - ns=1;i=2053 */

static UA_StatusCode function_PaintingStationBelt_42_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 5LU);
UA_UInt16 *variablenode_ns_1_i_2053_variant_DataContents =  UA_UInt16_new();
if (!variablenode_ns_1_i_2053_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_UInt16_init(variablenode_ns_1_i_2053_variant_DataContents);
*variablenode_ns_1_i_2053_variant_DataContents = (UA_UInt16) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2053_variant_DataContents, &UA_TYPES[UA_TYPES_UINT16]);
attr.displayName = UA_LOCALIZEDTEXT("", "Availability");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Availability");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2053LU),
UA_NODEID_NUMERIC(ns[1], 2016LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Availability"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_UInt16_delete(variablenode_ns_1_i_2053_variant_DataContents);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_42_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2053LU)
);
}

/* Performance - ns=1;i=2019 */

static UA_StatusCode function_PaintingStationBelt_43_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 5LU);
UA_UInt16 *variablenode_ns_1_i_2019_variant_DataContents =  UA_UInt16_new();
if (!variablenode_ns_1_i_2019_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_UInt16_init(variablenode_ns_1_i_2019_variant_DataContents);
*variablenode_ns_1_i_2019_variant_DataContents = (UA_UInt16) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2019_variant_DataContents, &UA_TYPES[UA_TYPES_UINT16]);
attr.displayName = UA_LOCALIZEDTEXT("", "Performance");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Performance");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2019LU),
UA_NODEID_NUMERIC(ns[1], 2016LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Performance"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_UInt16_delete(variablenode_ns_1_i_2019_variant_DataContents);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_43_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2019LU)
);
}

/* OEE - ns=1;i=2054 */

static UA_StatusCode function_PaintingStationBelt_44_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 5LU);
UA_UInt16 *variablenode_ns_1_i_2054_variant_DataContents =  UA_UInt16_new();
if (!variablenode_ns_1_i_2054_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_UInt16_init(variablenode_ns_1_i_2054_variant_DataContents);
*variablenode_ns_1_i_2054_variant_DataContents = (UA_UInt16) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2054_variant_DataContents, &UA_TYPES[UA_TYPES_UINT16]);
attr.displayName = UA_LOCALIZEDTEXT("", "OEE");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "OEE");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2054LU),
UA_NODEID_NUMERIC(ns[1], 2016LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "OEE"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_UInt16_delete(variablenode_ns_1_i_2054_variant_DataContents);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_44_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2054LU)
);
}

/* Quality - ns=1;i=2013 */

static UA_StatusCode function_PaintingStationBelt_45_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Quality");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Quality");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2013LU),
UA_NODEID_NUMERIC(ns[1], 2007LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Quality"),
UA_NODEID_NUMERIC(ns[0], 61LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_45_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2013LU)
);
}

/* Yield - ns=1;i=2014 */

static UA_StatusCode function_PaintingStationBelt_46_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 5LU);
UA_UInt16 *variablenode_ns_1_i_2014_variant_DataContents =  UA_UInt16_new();
if (!variablenode_ns_1_i_2014_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_UInt16_init(variablenode_ns_1_i_2014_variant_DataContents);
*variablenode_ns_1_i_2014_variant_DataContents = (UA_UInt16) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2014_variant_DataContents, &UA_TYPES[UA_TYPES_UINT16]);
attr.displayName = UA_LOCALIZEDTEXT("", "Yield");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Yield");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2014LU),
UA_NODEID_NUMERIC(ns[1], 2013LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Yield"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_UInt16_delete(variablenode_ns_1_i_2014_variant_DataContents);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_46_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2014LU)
);
}

/* MTBF - ns=1;i=2015 */

static UA_StatusCode function_PaintingStationBelt_47_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 290LU);
UA_Double *variablenode_ns_1_i_2015_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_1_i_2015_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_1_i_2015_variant_DataContents);
*variablenode_ns_1_i_2015_variant_DataContents = (UA_Double) 0.0;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2015_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "MTBF");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "MTBF");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2015LU),
UA_NODEID_NUMERIC(ns[1], 2013LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "MTBF"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_1_i_2015_variant_DataContents);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_47_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2015LU)
);
}

/* Responsiveness - ns=1;i=2056 */

static UA_StatusCode function_PaintingStationBelt_48_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Responsiveness");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Responsiveness");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2056LU),
UA_NODEID_NUMERIC(ns[1], 2007LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Responsiveness"),
UA_NODEID_NUMERIC(ns[0], 61LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_48_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2056LU)
);
}

/* AverageCycleTime - ns=1;i=2057 */

static UA_StatusCode function_PaintingStationBelt_49_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 290LU);
UA_Double *variablenode_ns_1_i_2057_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_1_i_2057_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_1_i_2057_variant_DataContents);
*variablenode_ns_1_i_2057_variant_DataContents = (UA_Double) 0.0;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2057_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "AverageCycleTime");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "AverageCycleTime");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2057LU),
UA_NODEID_NUMERIC(ns[1], 2056LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "AverageCycleTime"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_1_i_2057_variant_DataContents);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_49_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2057LU)
);
}

/* AverageProductionTime - ns=1;i=2059 */

static UA_StatusCode function_PaintingStationBelt_50_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 290LU);
UA_Double *variablenode_ns_1_i_2059_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_1_i_2059_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_1_i_2059_variant_DataContents);
*variablenode_ns_1_i_2059_variant_DataContents = (UA_Double) 0.0;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2059_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "AverageProductionTime");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "AverageProductionTime");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2059LU),
UA_NODEID_NUMERIC(ns[1], 2056LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "AverageProductionTime"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_1_i_2059_variant_DataContents);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_50_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2059LU)
);
}

/* AverageWaitTime - ns=1;i=2058 */

static UA_StatusCode function_PaintingStationBelt_51_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 290LU);
UA_Double *variablenode_ns_1_i_2058_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_1_i_2058_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_1_i_2058_variant_DataContents);
*variablenode_ns_1_i_2058_variant_DataContents = (UA_Double) 0.0;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2058_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "AverageWaitTime");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "AverageWaitTime");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2058LU),
UA_NODEID_NUMERIC(ns[1], 2056LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "AverageWaitTime"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_1_i_2058_variant_DataContents);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_51_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2058LU)
);
}

/* RealTimeInformation - ns=1;i=2060 */

static UA_StatusCode function_PaintingStationBelt_52_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "RealTimeInformation");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "RealTimeInformation");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2060LU),
UA_NODEID_NUMERIC(ns[1], 2007LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "RealTimeInformation"),
UA_NODEID_NUMERIC(ns[0], 61LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_52_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2060LU)
);
}

/* LastProductionTime - ns=1;i=2063 */

static UA_StatusCode function_PaintingStationBelt_53_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 290LU);
UA_Double *variablenode_ns_1_i_2063_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_1_i_2063_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_1_i_2063_variant_DataContents);
*variablenode_ns_1_i_2063_variant_DataContents = (UA_Double) 0.0;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2063_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "LastProductionTime");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "LastProductionTime");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2063LU),
UA_NODEID_NUMERIC(ns[1], 2060LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "LastProductionTime"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_1_i_2063_variant_DataContents);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_53_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2063LU)
);
}

/* LastWaitTime - ns=1;i=2062 */

static UA_StatusCode function_PaintingStationBelt_54_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 290LU);
UA_Double *variablenode_ns_1_i_2062_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_1_i_2062_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_1_i_2062_variant_DataContents);
*variablenode_ns_1_i_2062_variant_DataContents = (UA_Double) 0.0;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2062_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "LastWaitTime");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "LastWaitTime");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2062LU),
UA_NODEID_NUMERIC(ns[1], 2060LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "LastWaitTime"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_1_i_2062_variant_DataContents);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_54_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2062LU)
);
}

/* LastCycleTime - ns=1;i=2061 */

static UA_StatusCode function_PaintingStationBelt_55_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 290LU);
UA_Double *variablenode_ns_1_i_2061_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_1_i_2061_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_1_i_2061_variant_DataContents);
*variablenode_ns_1_i_2061_variant_DataContents = (UA_Double) 0.0;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2061_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "LastCycleTime");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "LastCycleTime");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2061LU),
UA_NODEID_NUMERIC(ns[1], 2060LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "LastCycleTime"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_1_i_2061_variant_DataContents);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_55_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2061LU)
);
}

/* Efficiency - ns=1;i=2034 */

static UA_StatusCode function_PaintingStationBelt_56_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Efficiency");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Efficiency");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2034LU),
UA_NODEID_NUMERIC(ns[1], 2031LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Efficiency"),
UA_NODEID_NUMERIC(ns[0], 61LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2034LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_56_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2034LU)
);
}

/* Performance - ns=1;i=2039 */

static UA_StatusCode function_PaintingStationBelt_57_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 5LU);
UA_UInt16 *variablenode_ns_1_i_2039_variant_DataContents =  UA_UInt16_new();
if (!variablenode_ns_1_i_2039_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_UInt16_init(variablenode_ns_1_i_2039_variant_DataContents);
*variablenode_ns_1_i_2039_variant_DataContents = (UA_UInt16) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2039_variant_DataContents, &UA_TYPES[UA_TYPES_UINT16]);
attr.displayName = UA_LOCALIZEDTEXT("", "Performance");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Performance");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2039LU),
UA_NODEID_NUMERIC(ns[1], 2034LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Performance"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_UInt16_delete(variablenode_ns_1_i_2039_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2039LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_57_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2039LU)
);
}

/* Availability - ns=1;i=2040 */

static UA_StatusCode function_PaintingStationBelt_58_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 5LU);
UA_UInt16 *variablenode_ns_1_i_2040_variant_DataContents =  UA_UInt16_new();
if (!variablenode_ns_1_i_2040_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_UInt16_init(variablenode_ns_1_i_2040_variant_DataContents);
*variablenode_ns_1_i_2040_variant_DataContents = (UA_UInt16) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2040_variant_DataContents, &UA_TYPES[UA_TYPES_UINT16]);
attr.displayName = UA_LOCALIZEDTEXT("", "Availability");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Availability");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2040LU),
UA_NODEID_NUMERIC(ns[1], 2034LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Availability"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_UInt16_delete(variablenode_ns_1_i_2040_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2040LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_58_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2040LU)
);
}

/* Utilization - ns=1;i=2037 */

static UA_StatusCode function_PaintingStationBelt_59_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 5LU);
UA_UInt16 *variablenode_ns_1_i_2037_variant_DataContents =  UA_UInt16_new();
if (!variablenode_ns_1_i_2037_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_UInt16_init(variablenode_ns_1_i_2037_variant_DataContents);
*variablenode_ns_1_i_2037_variant_DataContents = (UA_UInt16) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2037_variant_DataContents, &UA_TYPES[UA_TYPES_UINT16]);
attr.displayName = UA_LOCALIZEDTEXT("", "Utilization");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Utilization");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2037LU),
UA_NODEID_NUMERIC(ns[1], 2034LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Utilization"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_UInt16_delete(variablenode_ns_1_i_2037_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2037LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_59_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2037LU)
);
}

/* OEE - ns=1;i=2004 */

static UA_StatusCode function_PaintingStationBelt_60_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 5LU);
UA_UInt16 *variablenode_ns_1_i_2004_variant_DataContents =  UA_UInt16_new();
if (!variablenode_ns_1_i_2004_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_UInt16_init(variablenode_ns_1_i_2004_variant_DataContents);
*variablenode_ns_1_i_2004_variant_DataContents = (UA_UInt16) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2004_variant_DataContents, &UA_TYPES[UA_TYPES_UINT16]);
attr.displayName = UA_LOCALIZEDTEXT("", "OEE");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "OEE");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2004LU),
UA_NODEID_NUMERIC(ns[1], 2034LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "OEE"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_UInt16_delete(variablenode_ns_1_i_2004_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2004LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_60_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2004LU)
);
}

/* Quality - ns=1;i=2038 */

static UA_StatusCode function_PaintingStationBelt_61_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 5LU);
UA_UInt16 *variablenode_ns_1_i_2038_variant_DataContents =  UA_UInt16_new();
if (!variablenode_ns_1_i_2038_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_UInt16_init(variablenode_ns_1_i_2038_variant_DataContents);
*variablenode_ns_1_i_2038_variant_DataContents = (UA_UInt16) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2038_variant_DataContents, &UA_TYPES[UA_TYPES_UINT16]);
attr.displayName = UA_LOCALIZEDTEXT("", "Quality");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Quality");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2038LU),
UA_NODEID_NUMERIC(ns[1], 2034LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Quality"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_UInt16_delete(variablenode_ns_1_i_2038_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2038LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_61_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2038LU)
);
}

/* Responsiveness - ns=1;i=2035 */

static UA_StatusCode function_PaintingStationBelt_62_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Responsiveness");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Responsiveness");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2035LU),
UA_NODEID_NUMERIC(ns[1], 2031LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Responsiveness"),
UA_NODEID_NUMERIC(ns[0], 61LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2035LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_62_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2035LU)
);
}

/* AverageProductionTime - ns=1;i=2052 */

static UA_StatusCode function_PaintingStationBelt_63_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 290LU);
UA_Double *variablenode_ns_1_i_2052_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_1_i_2052_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_1_i_2052_variant_DataContents);
*variablenode_ns_1_i_2052_variant_DataContents = (UA_Double) 0.0;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2052_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "AverageProductionTime");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "AverageProductionTime");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2052LU),
UA_NODEID_NUMERIC(ns[1], 2035LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "AverageProductionTime"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_1_i_2052_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2052LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_63_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2052LU)
);
}

/* AverageCycleTime - ns=1;i=2050 */

static UA_StatusCode function_PaintingStationBelt_64_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 290LU);
UA_Double *variablenode_ns_1_i_2050_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_1_i_2050_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_1_i_2050_variant_DataContents);
*variablenode_ns_1_i_2050_variant_DataContents = (UA_Double) 0.0;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2050_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "AverageCycleTime");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "AverageCycleTime");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2050LU),
UA_NODEID_NUMERIC(ns[1], 2035LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "AverageCycleTime"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_1_i_2050_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2050LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_64_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2050LU)
);
}

/* AverageWaitTime - ns=1;i=2051 */

static UA_StatusCode function_PaintingStationBelt_65_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 290LU);
UA_Double *variablenode_ns_1_i_2051_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_1_i_2051_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_1_i_2051_variant_DataContents);
*variablenode_ns_1_i_2051_variant_DataContents = (UA_Double) 0.0;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2051_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "AverageWaitTime");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "AverageWaitTime");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2051LU),
UA_NODEID_NUMERIC(ns[1], 2035LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "AverageWaitTime"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_1_i_2051_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2051LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_65_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2051LU)
);
}

/* RealTimeInformation - ns=1;i=2036 */

static UA_StatusCode function_PaintingStationBelt_66_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "RealTimeInformation");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "RealTimeInformation");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2036LU),
UA_NODEID_NUMERIC(ns[1], 2031LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "RealTimeInformation"),
UA_NODEID_NUMERIC(ns[0], 61LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2036LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_66_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2036LU)
);
}

/* LastCycleTime - ns=1;i=2047 */

static UA_StatusCode function_PaintingStationBelt_67_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 290LU);
UA_Double *variablenode_ns_1_i_2047_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_1_i_2047_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_1_i_2047_variant_DataContents);
*variablenode_ns_1_i_2047_variant_DataContents = (UA_Double) 0.0;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2047_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "LastCycleTime");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "LastCycleTime");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2047LU),
UA_NODEID_NUMERIC(ns[1], 2036LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "LastCycleTime"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_1_i_2047_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2047LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_67_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2047LU)
);
}

/* LastWaitTime - ns=1;i=2048 */

static UA_StatusCode function_PaintingStationBelt_68_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 290LU);
UA_Double *variablenode_ns_1_i_2048_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_1_i_2048_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_1_i_2048_variant_DataContents);
*variablenode_ns_1_i_2048_variant_DataContents = (UA_Double) 0.0;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2048_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "LastWaitTime");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "LastWaitTime");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2048LU),
UA_NODEID_NUMERIC(ns[1], 2036LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "LastWaitTime"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_1_i_2048_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2048LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_68_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2048LU)
);
}

/* LastProductionTime - ns=1;i=2049 */

static UA_StatusCode function_PaintingStationBelt_69_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 290LU);
UA_Double *variablenode_ns_1_i_2049_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_1_i_2049_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_1_i_2049_variant_DataContents);
*variablenode_ns_1_i_2049_variant_DataContents = (UA_Double) 0.0;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2049_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "LastProductionTime");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "LastProductionTime");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2049LU),
UA_NODEID_NUMERIC(ns[1], 2036LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "LastProductionTime"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_1_i_2049_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2049LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_69_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2049LU)
);
}

/* HealtMeter - ns=1;i=2032 */

static UA_StatusCode function_PaintingStationBelt_70_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "HealtMeter");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "HealtMeter");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2032LU),
UA_NODEID_NUMERIC(ns[1], 2031LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "HealtMeter"),
UA_NODEID_NUMERIC(ns[0], 61LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2032LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_70_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2032LU)
);
}

/* ReqTaktTime - ns=1;i=2041 */

static UA_StatusCode function_PaintingStationBelt_71_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 290LU);
UA_Double *variablenode_ns_1_i_2041_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_1_i_2041_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_1_i_2041_variant_DataContents);
*variablenode_ns_1_i_2041_variant_DataContents = (UA_Double) 0.0;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2041_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "ReqTaktTime");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "ReqTaktTime");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2041LU),
UA_NODEID_NUMERIC(ns[1], 2032LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "ReqTaktTime"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_1_i_2041_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2041LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_71_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2041LU)
);
}

/* StoppageCount - ns=1;i=2042 */

static UA_StatusCode function_PaintingStationBelt_72_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 5LU);
UA_UInt16 *variablenode_ns_1_i_2042_variant_DataContents =  UA_UInt16_new();
if (!variablenode_ns_1_i_2042_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_UInt16_init(variablenode_ns_1_i_2042_variant_DataContents);
*variablenode_ns_1_i_2042_variant_DataContents = (UA_UInt16) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2042_variant_DataContents, &UA_TYPES[UA_TYPES_UINT16]);
attr.displayName = UA_LOCALIZEDTEXT("", "StoppageCount");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "StoppageCount");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2042LU),
UA_NODEID_NUMERIC(ns[1], 2032LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "StoppageCount"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_UInt16_delete(variablenode_ns_1_i_2042_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2042LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_72_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2042LU)
);
}

/* FailureCount - ns=1;i=2043 */

static UA_StatusCode function_PaintingStationBelt_73_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 5LU);
UA_UInt16 *variablenode_ns_1_i_2043_variant_DataContents =  UA_UInt16_new();
if (!variablenode_ns_1_i_2043_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_UInt16_init(variablenode_ns_1_i_2043_variant_DataContents);
*variablenode_ns_1_i_2043_variant_DataContents = (UA_UInt16) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2043_variant_DataContents, &UA_TYPES[UA_TYPES_UINT16]);
attr.displayName = UA_LOCALIZEDTEXT("", "FailureCount");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "FailureCount");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2043LU),
UA_NODEID_NUMERIC(ns[1], 2032LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "FailureCount"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_UInt16_delete(variablenode_ns_1_i_2043_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2043LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_73_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2043LU)
);
}

/* OperationTimeFailureCount - ns=1;i=2044 */

static UA_StatusCode function_PaintingStationBelt_74_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 5LU);
UA_UInt16 *variablenode_ns_1_i_2044_variant_DataContents =  UA_UInt16_new();
if (!variablenode_ns_1_i_2044_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_UInt16_init(variablenode_ns_1_i_2044_variant_DataContents);
*variablenode_ns_1_i_2044_variant_DataContents = (UA_UInt16) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2044_variant_DataContents, &UA_TYPES[UA_TYPES_UINT16]);
attr.displayName = UA_LOCALIZEDTEXT("", "OperationTimeFailureCount");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "OperationTimeFailureCount");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2044LU),
UA_NODEID_NUMERIC(ns[1], 2032LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "OperationTimeFailureCount"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_UInt16_delete(variablenode_ns_1_i_2044_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2044LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_74_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2044LU)
);
}

/* Quality - ns=1;i=2033 */

static UA_StatusCode function_PaintingStationBelt_75_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Quality");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Quality");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2033LU),
UA_NODEID_NUMERIC(ns[1], 2031LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Quality"),
UA_NODEID_NUMERIC(ns[0], 61LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2033LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_75_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2033LU)
);
}

/* Yield - ns=1;i=2045 */

static UA_StatusCode function_PaintingStationBelt_76_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 5LU);
UA_UInt16 *variablenode_ns_1_i_2045_variant_DataContents =  UA_UInt16_new();
if (!variablenode_ns_1_i_2045_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_UInt16_init(variablenode_ns_1_i_2045_variant_DataContents);
*variablenode_ns_1_i_2045_variant_DataContents = (UA_UInt16) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2045_variant_DataContents, &UA_TYPES[UA_TYPES_UINT16]);
attr.displayName = UA_LOCALIZEDTEXT("", "Yield");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Yield");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2045LU),
UA_NODEID_NUMERIC(ns[1], 2033LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Yield"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_UInt16_delete(variablenode_ns_1_i_2045_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2045LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_76_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2045LU)
);
}

/* MTBF - ns=1;i=2046 */

static UA_StatusCode function_PaintingStationBelt_77_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 290LU);
UA_Double *variablenode_ns_1_i_2046_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_1_i_2046_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_1_i_2046_variant_DataContents);
*variablenode_ns_1_i_2046_variant_DataContents = (UA_Double) 0.0;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2046_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "MTBF");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "MTBF");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2046LU),
UA_NODEID_NUMERIC(ns[1], 2033LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "MTBF"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_1_i_2046_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2046LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
}

static UA_StatusCode function_PaintingStationBelt_77_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2046LU)
);
}

UA_StatusCode PaintingStationBelt(UA_Server *server) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
/* Use namespace ids generated by the server */
UA_UInt16 ns[2];
ns[0] = UA_Server_addNamespace(server, "http://opcfoundation.org/UA/");
ns[1] = UA_Server_addNamespace(server, "http://deteconFischertechnik/UA/");

/* Load custom datatype definitions into the server */
bool dummy = (
!(retVal = function_PaintingStationBelt_0_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_1_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_2_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_3_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_4_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_5_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_6_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_7_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_8_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_9_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_10_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_11_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_12_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_13_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_14_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_15_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_16_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_17_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_18_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_19_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_20_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_21_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_22_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_23_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_24_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_25_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_26_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_27_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_28_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_29_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_30_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_31_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_32_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_33_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_34_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_35_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_36_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_37_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_38_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_39_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_40_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_41_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_42_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_43_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_44_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_45_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_46_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_47_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_48_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_49_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_50_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_51_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_52_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_53_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_54_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_55_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_56_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_57_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_58_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_59_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_60_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_61_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_62_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_63_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_64_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_65_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_66_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_67_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_68_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_69_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_70_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_71_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_72_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_73_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_74_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_75_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_76_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_77_begin(server, ns))
&& !(retVal = function_PaintingStationBelt_77_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_76_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_75_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_74_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_73_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_72_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_71_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_70_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_69_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_68_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_67_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_66_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_65_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_64_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_63_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_62_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_61_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_60_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_59_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_58_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_57_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_56_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_55_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_54_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_53_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_52_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_51_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_50_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_49_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_48_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_47_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_46_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_45_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_44_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_43_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_42_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_41_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_40_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_39_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_38_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_37_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_36_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_35_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_34_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_33_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_32_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_31_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_30_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_29_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_28_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_27_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_26_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_25_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_24_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_23_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_22_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_21_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_20_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_19_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_18_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_17_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_16_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_15_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_14_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_13_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_12_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_11_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_10_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_9_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_8_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_7_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_6_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_5_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_4_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_3_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_2_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_1_finish(server, ns))
&& !(retVal = function_PaintingStationBelt_0_finish(server, ns))
); (void)(dummy);
return retVal;
}
