/* WARNING: This is a generated file.
 * Any manual changes will be overwritten. */

#include "MotorSteuerung.h"


/* MotorTyp - ns=1;i=2001 */

static UA_StatusCode function_MotorSteuerung_0_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectTypeAttributes attr = UA_ObjectTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "MotorTyp");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "MotorTyp");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECTTYPE,
UA_NODEID_NUMERIC(ns[1], 2001LU),
UA_NODEID_NUMERIC(ns[0], 58LU),
UA_NODEID_NUMERIC(ns[0], 45LU),
UA_QUALIFIEDNAME(ns[1], "MotorTyp"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTTYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_MotorSteuerung_0_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2001LU)
);
}

/* Motor1 - ns=1;i=2009 */

static UA_StatusCode function_MotorSteuerung_1_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Motor1");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "MotorTyp");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[1], 2009LU),
UA_NODEID_NUMERIC(ns[0], 85LU),
UA_NODEID_NUMERIC(ns[0], 35LU),
UA_QUALIFIEDNAME(ns[1], "Motor1"),
UA_NODEID_NUMERIC(ns[1], 2001LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_MotorSteuerung_1_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2009LU)
);
}

/* EmergencyStop - ns=1;i=2016 */

static UA_StatusCode function_MotorSteuerung_2_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "EmergencyStop");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "EmergencyStop");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[1], 2016LU),
UA_NODEID_NUMERIC(ns[1], 2009LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "EmergencyStop"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_MotorSteuerung_2_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2016LU)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* Speed - ns=1;i=2011 */

static UA_StatusCode function_MotorSteuerung_3_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 4LU);
UA_Int16 *variablenode_ns_1_i_2011_variant_DataContents =  UA_Int16_new();
if (!variablenode_ns_1_i_2011_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Int16_init(variablenode_ns_1_i_2011_variant_DataContents);
*variablenode_ns_1_i_2011_variant_DataContents = (UA_Int16) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2011_variant_DataContents, &UA_TYPES[UA_TYPES_INT16]);
attr.displayName = UA_LOCALIZEDTEXT("", "Speed");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Speed");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2011LU),
UA_NODEID_NUMERIC(ns[1], 2009LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Speed"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Int16_delete(variablenode_ns_1_i_2011_variant_DataContents);
return retVal;
}

static UA_StatusCode function_MotorSteuerung_3_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2011LU)
);
}

/* Running - ns=1;i=2010 */

static UA_StatusCode function_MotorSteuerung_4_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1LU);
UA_Boolean *variablenode_ns_1_i_2010_variant_DataContents =  UA_Boolean_new();
if (!variablenode_ns_1_i_2010_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Boolean_init(variablenode_ns_1_i_2010_variant_DataContents);
*variablenode_ns_1_i_2010_variant_DataContents = (UA_Boolean) true;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2010_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "Running");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Running");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2010LU),
UA_NODEID_NUMERIC(ns[1], 2009LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Running"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_1_i_2010_variant_DataContents);
return retVal;
}

static UA_StatusCode function_MotorSteuerung_4_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2010LU)
);
}

/* Control - ns=1;i=2013 */

static UA_StatusCode function_MotorSteuerung_5_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "Control");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Control");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[1], 2013LU),
UA_NODEID_NUMERIC(ns[1], 2009LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Control"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_MotorSteuerung_5_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2013LU)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* OutputArguments - ns=1;i=2015 */

static UA_StatusCode function_MotorSteuerung_6_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 0;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 296LU);
UA_Argument variablenode_ns_1_i_2015_variant_DataContents[1];

UA_init(&variablenode_ns_1_i_2015_variant_DataContents[0], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_1_i_2015_variant_DataContents[0].name = UA_STRING("Sucess");
variablenode_ns_1_i_2015_variant_DataContents[0].dataType = UA_NODEID_NUMERIC(ns[0], 1LU);
variablenode_ns_1_i_2015_variant_DataContents[0].valueRank = (UA_Int32) -1;
UA_Variant_setArray(&attr.value, &variablenode_ns_1_i_2015_variant_DataContents, (UA_Int32) 1, &UA_TYPES[UA_TYPES_ARGUMENT]);
attr.displayName = UA_LOCALIZEDTEXT("", "OutputArguments");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "OutputArguments");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2015LU),
UA_NODEID_NUMERIC(ns[1], 2013LU),
UA_NODEID_NUMERIC(ns[0], 46LU),
UA_QUALIFIEDNAME(ns[0], "OutputArguments"),
UA_NODEID_NUMERIC(ns[0], 68LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

return retVal;
}

static UA_StatusCode function_MotorSteuerung_6_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2015LU)
);
}

/* InputArguments - ns=1;i=2014 */

static UA_StatusCode function_MotorSteuerung_7_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 0;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 296LU);
UA_Argument variablenode_ns_1_i_2014_variant_DataContents[3];

UA_init(&variablenode_ns_1_i_2014_variant_DataContents[0], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_1_i_2014_variant_DataContents[0].name = UA_STRING("Speed");
variablenode_ns_1_i_2014_variant_DataContents[0].dataType = UA_NODEID_NUMERIC(ns[0], 4LU);
variablenode_ns_1_i_2014_variant_DataContents[0].valueRank = (UA_Int32) -1;

UA_init(&variablenode_ns_1_i_2014_variant_DataContents[1], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_1_i_2014_variant_DataContents[1].name = UA_STRING("Distance");
variablenode_ns_1_i_2014_variant_DataContents[1].dataType = UA_NODEID_NUMERIC(ns[0], 4LU);
variablenode_ns_1_i_2014_variant_DataContents[1].valueRank = (UA_Int32) -1;

UA_init(&variablenode_ns_1_i_2014_variant_DataContents[2], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_1_i_2014_variant_DataContents[2].name = UA_STRING("Direction");
variablenode_ns_1_i_2014_variant_DataContents[2].dataType = UA_NODEID_NUMERIC(ns[0], 1LU);
variablenode_ns_1_i_2014_variant_DataContents[2].valueRank = (UA_Int32) -1;
UA_Variant_setArray(&attr.value, &variablenode_ns_1_i_2014_variant_DataContents, (UA_Int32) 3, &UA_TYPES[UA_TYPES_ARGUMENT]);
attr.displayName = UA_LOCALIZEDTEXT("", "InputArguments");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "InputArguments");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2014LU),
UA_NODEID_NUMERIC(ns[1], 2013LU),
UA_NODEID_NUMERIC(ns[0], 46LU),
UA_QUALIFIEDNAME(ns[0], "InputArguments"),
UA_NODEID_NUMERIC(ns[0], 68LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);



return retVal;
}

static UA_StatusCode function_MotorSteuerung_7_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2014LU)
);
}

/* Direction - ns=1;i=2012 */

static UA_StatusCode function_MotorSteuerung_8_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1LU);
UA_Boolean *variablenode_ns_1_i_2012_variant_DataContents =  UA_Boolean_new();
if (!variablenode_ns_1_i_2012_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Boolean_init(variablenode_ns_1_i_2012_variant_DataContents);
*variablenode_ns_1_i_2012_variant_DataContents = (UA_Boolean) true;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2012_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "Direction");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Direction");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2012LU),
UA_NODEID_NUMERIC(ns[1], 2009LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Direction"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_1_i_2012_variant_DataContents);
return retVal;
}

static UA_StatusCode function_MotorSteuerung_8_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2012LU)
);
}

/* EmergencyStop - ns=1;i=2008 */

static UA_StatusCode function_MotorSteuerung_9_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "EmergencyStop");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "EmergencyStop");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[1], 2008LU),
UA_NODEID_NUMERIC(ns[1], 2001LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "EmergencyStop"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2008LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_MotorSteuerung_9_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2008LU)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* Direction - ns=1;i=2004 */

static UA_StatusCode function_MotorSteuerung_10_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1LU);
UA_Boolean *variablenode_ns_1_i_2004_variant_DataContents =  UA_Boolean_new();
if (!variablenode_ns_1_i_2004_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Boolean_init(variablenode_ns_1_i_2004_variant_DataContents);
*variablenode_ns_1_i_2004_variant_DataContents = (UA_Boolean) true;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2004_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "Direction");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Direction");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2004LU),
UA_NODEID_NUMERIC(ns[1], 2001LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Direction"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_1_i_2004_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2004LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
}

static UA_StatusCode function_MotorSteuerung_10_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2004LU)
);
}

/* Control - ns=1;i=2005 */

static UA_StatusCode function_MotorSteuerung_11_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "Control");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Control");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[1], 2005LU),
UA_NODEID_NUMERIC(ns[1], 2001LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Control"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2005LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_MotorSteuerung_11_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2005LU)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* OutputArguments - ns=1;i=2007 */

static UA_StatusCode function_MotorSteuerung_12_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 0;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 296LU);
UA_Argument variablenode_ns_1_i_2007_variant_DataContents[1];

UA_init(&variablenode_ns_1_i_2007_variant_DataContents[0], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_1_i_2007_variant_DataContents[0].name = UA_STRING("Sucess");
variablenode_ns_1_i_2007_variant_DataContents[0].dataType = UA_NODEID_NUMERIC(ns[0], 1LU);
variablenode_ns_1_i_2007_variant_DataContents[0].valueRank = (UA_Int32) -1;
UA_Variant_setArray(&attr.value, &variablenode_ns_1_i_2007_variant_DataContents, (UA_Int32) 1, &UA_TYPES[UA_TYPES_ARGUMENT]);
attr.displayName = UA_LOCALIZEDTEXT("", "OutputArguments");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "OutputArguments");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2007LU),
UA_NODEID_NUMERIC(ns[1], 2005LU),
UA_NODEID_NUMERIC(ns[0], 46LU),
UA_QUALIFIEDNAME(ns[0], "OutputArguments"),
UA_NODEID_NUMERIC(ns[0], 68LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2007LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
}

static UA_StatusCode function_MotorSteuerung_12_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2007LU)
);
}

/* InputArguments - ns=1;i=2006 */

static UA_StatusCode function_MotorSteuerung_13_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 0;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 296LU);
UA_Argument variablenode_ns_1_i_2006_variant_DataContents[3];

UA_init(&variablenode_ns_1_i_2006_variant_DataContents[0], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_1_i_2006_variant_DataContents[0].name = UA_STRING("Speed");
variablenode_ns_1_i_2006_variant_DataContents[0].dataType = UA_NODEID_NUMERIC(ns[0], 4LU);
variablenode_ns_1_i_2006_variant_DataContents[0].valueRank = (UA_Int32) -1;

UA_init(&variablenode_ns_1_i_2006_variant_DataContents[1], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_1_i_2006_variant_DataContents[1].name = UA_STRING("Distance");
variablenode_ns_1_i_2006_variant_DataContents[1].dataType = UA_NODEID_NUMERIC(ns[0], 4LU);
variablenode_ns_1_i_2006_variant_DataContents[1].valueRank = (UA_Int32) -1;

UA_init(&variablenode_ns_1_i_2006_variant_DataContents[2], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_1_i_2006_variant_DataContents[2].name = UA_STRING("Direction");
variablenode_ns_1_i_2006_variant_DataContents[2].dataType = UA_NODEID_NUMERIC(ns[0], 1LU);
variablenode_ns_1_i_2006_variant_DataContents[2].valueRank = (UA_Int32) -1;
UA_Variant_setArray(&attr.value, &variablenode_ns_1_i_2006_variant_DataContents, (UA_Int32) 3, &UA_TYPES[UA_TYPES_ARGUMENT]);
attr.displayName = UA_LOCALIZEDTEXT("", "InputArguments");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "InputArguments");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2006LU),
UA_NODEID_NUMERIC(ns[1], 2005LU),
UA_NODEID_NUMERIC(ns[0], 46LU),
UA_QUALIFIEDNAME(ns[0], "InputArguments"),
UA_NODEID_NUMERIC(ns[0], 68LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);



retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2006LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
}

static UA_StatusCode function_MotorSteuerung_13_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2006LU)
);
}

/* Running - ns=1;i=2002 */

static UA_StatusCode function_MotorSteuerung_14_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1LU);
UA_Boolean *variablenode_ns_1_i_2002_variant_DataContents =  UA_Boolean_new();
if (!variablenode_ns_1_i_2002_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Boolean_init(variablenode_ns_1_i_2002_variant_DataContents);
*variablenode_ns_1_i_2002_variant_DataContents = (UA_Boolean) true;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2002_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "Running");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Running");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2002LU),
UA_NODEID_NUMERIC(ns[1], 2001LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Running"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_1_i_2002_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2002LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
}

static UA_StatusCode function_MotorSteuerung_14_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2002LU)
);
}

/* Speed - ns=1;i=2003 */

static UA_StatusCode function_MotorSteuerung_15_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 4LU);
UA_Int16 *variablenode_ns_1_i_2003_variant_DataContents =  UA_Int16_new();
if (!variablenode_ns_1_i_2003_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Int16_init(variablenode_ns_1_i_2003_variant_DataContents);
*variablenode_ns_1_i_2003_variant_DataContents = (UA_Int16) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_1_i_2003_variant_DataContents, &UA_TYPES[UA_TYPES_INT16]);
attr.displayName = UA_LOCALIZEDTEXT("", "Speed");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Speed");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[1], 2003LU),
UA_NODEID_NUMERIC(ns[1], 2001LU),
UA_NODEID_NUMERIC(ns[0], 47LU),
UA_QUALIFIEDNAME(ns[1], "Speed"),
UA_NODEID_NUMERIC(ns[0], 63LU),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Int16_delete(variablenode_ns_1_i_2003_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[1], 2003LU), UA_NODEID_NUMERIC(ns[0], 37LU), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78LU), true);
return retVal;
}

static UA_StatusCode function_MotorSteuerung_15_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[1], 2003LU)
);
}

UA_StatusCode MotorSteuerung(UA_Server *server) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
/* Use namespace ids generated by the server */
UA_UInt16 ns[2];
ns[0] = UA_Server_addNamespace(server, "http://opcfoundation.org/UA/");
ns[1] = UA_Server_addNamespace(server, "http://helloWorld.com/UA/");

/* Load custom datatype definitions into the server */
bool dummy = (
!(retVal = function_MotorSteuerung_0_begin(server, ns))
&& !(retVal = function_MotorSteuerung_1_begin(server, ns))
&& !(retVal = function_MotorSteuerung_2_begin(server, ns))
&& !(retVal = function_MotorSteuerung_3_begin(server, ns))
&& !(retVal = function_MotorSteuerung_4_begin(server, ns))
&& !(retVal = function_MotorSteuerung_5_begin(server, ns))
&& !(retVal = function_MotorSteuerung_6_begin(server, ns))
&& !(retVal = function_MotorSteuerung_7_begin(server, ns))
&& !(retVal = function_MotorSteuerung_8_begin(server, ns))
&& !(retVal = function_MotorSteuerung_9_begin(server, ns))
&& !(retVal = function_MotorSteuerung_10_begin(server, ns))
&& !(retVal = function_MotorSteuerung_11_begin(server, ns))
&& !(retVal = function_MotorSteuerung_12_begin(server, ns))
&& !(retVal = function_MotorSteuerung_13_begin(server, ns))
&& !(retVal = function_MotorSteuerung_14_begin(server, ns))
&& !(retVal = function_MotorSteuerung_15_begin(server, ns))
&& !(retVal = function_MotorSteuerung_15_finish(server, ns))
&& !(retVal = function_MotorSteuerung_14_finish(server, ns))
&& !(retVal = function_MotorSteuerung_13_finish(server, ns))
&& !(retVal = function_MotorSteuerung_12_finish(server, ns))
&& !(retVal = function_MotorSteuerung_11_finish(server, ns))
&& !(retVal = function_MotorSteuerung_10_finish(server, ns))
&& !(retVal = function_MotorSteuerung_9_finish(server, ns))
&& !(retVal = function_MotorSteuerung_8_finish(server, ns))
&& !(retVal = function_MotorSteuerung_7_finish(server, ns))
&& !(retVal = function_MotorSteuerung_6_finish(server, ns))
&& !(retVal = function_MotorSteuerung_5_finish(server, ns))
&& !(retVal = function_MotorSteuerung_4_finish(server, ns))
&& !(retVal = function_MotorSteuerung_3_finish(server, ns))
&& !(retVal = function_MotorSteuerung_2_finish(server, ns))
&& !(retVal = function_MotorSteuerung_1_finish(server, ns))
&& !(retVal = function_MotorSteuerung_0_finish(server, ns))
); (void)(dummy);
return retVal;
}
