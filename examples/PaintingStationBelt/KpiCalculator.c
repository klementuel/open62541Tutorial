#include "KpiCalculator.h"

/**
 * @brief Pointer to the Orgin Namespace Index for KPI
 * 
 */
UA_UInt16 *_kpiNsIdx;

/**
 * @brief Pointer to the Orgin open62541 Server for KPI
 * 
 */
UA_Server *_kpiServer;

/**
 * @brief Pointer to the Orgin OPC UA Object that has the know Schemantic desricptes for the KPI
 * 
 */
UA_NodeId *_kpiParent;

time_t startTime;


void Kpi_ReadValues(void)
{
    UA_Variant variant;
    UA_Variant_init(&variant);     

    UA_NodeId node;
    UA_QualifiedName targetNameArr[3] = {UA_QUALIFIEDNAME(*_kpiNsIdx, "KPI"), 
                                        UA_QUALIFIEDNAME(*_kpiNsIdx, "Efficiency"), 
                                        UA_QUALIFIEDNAME(*_kpiNsIdx, "Availability")};
    findChildNode(_kpiServer, *_kpiParent, 3, targetNameArr, &node);
    UA_Server_readValue(_kpiServer, node, &variant);
    efficiency.availability = *(UA_UInt16*)variant.data;
    targetNameArr[2] = UA_QUALIFIEDNAME(*_kpiNsIdx, "Performance");
    findChildNode(_kpiServer, *_kpiParent, 3, targetNameArr, &node);
    UA_Server_readValue(_kpiServer, node, &variant);
    efficiency.performance = *(UA_UInt16*)variant.data;
    targetNameArr[2] = UA_QUALIFIEDNAME(*_kpiNsIdx, "Quality");
    findChildNode(_kpiServer, *_kpiParent, 3, targetNameArr, &node);
    UA_Server_readValue(_kpiServer, node, &variant);
    efficiency.quality = *(UA_UInt16*)variant.data;
    targetNameArr[2] = UA_QUALIFIEDNAME(*_kpiNsIdx, "Utilization");
    findChildNode(_kpiServer, *_kpiParent, 3, targetNameArr, &node);
    UA_Server_readValue(_kpiServer, node, &variant);
    efficiency.utilization = *(UA_UInt16*)variant.data;
    targetNameArr[2] = UA_QUALIFIEDNAME(*_kpiNsIdx, "OEE");
    findChildNode(_kpiServer, *_kpiParent, 3, targetNameArr, &node);
    UA_Server_readValue(_kpiServer, node, &variant);
    efficiency.oee = *(UA_UInt16*)variant.data;

    //Values only for Reading Update from python script during Machine Running
    targetNameArr[1] = UA_QUALIFIEDNAME(*_kpiNsIdx, "HealtMeter");
    targetNameArr[2] = UA_QUALIFIEDNAME(*_kpiNsIdx, "FailureCount");
    findChildNode(_kpiServer, *_kpiParent, 3, targetNameArr, &node);
    UA_Server_readValue(_kpiServer, node, &variant);
    healtMeter.failureCount = *(UA_UInt16*)variant.data;
    targetNameArr[2] = UA_QUALIFIEDNAME(*_kpiNsIdx, "OperationTimeFailureCount"); //Auto Set with Callback
    findChildNode(_kpiServer, *_kpiParent, 3, targetNameArr, &node);
    UA_Server_readValue(_kpiServer, node, &variant);
    healtMeter.operationTimeFailureCount = *(UA_UInt16*)variant.data;
    targetNameArr[2] = UA_QUALIFIEDNAME(*_kpiNsIdx, "ReqTaktTime"); //This must set from User
    findChildNode(_kpiServer, *_kpiParent, 3, targetNameArr, &node);
    UA_Server_readValue(_kpiServer, node, &variant);
    healtMeter.ReqTaktTime = *(UA_Duration*)variant.data;
    targetNameArr[2] = UA_QUALIFIEDNAME(*_kpiNsIdx, "StoppageCount"); 
    findChildNode(_kpiServer, *_kpiParent, 3, targetNameArr, &node);
    UA_Server_readValue(_kpiServer, node, &variant);
    healtMeter.StoppageCount = *(UA_UInt16*)variant.data;

    targetNameArr[1] = UA_QUALIFIEDNAME(*_kpiNsIdx, "Quality");
    targetNameArr[2] = UA_QUALIFIEDNAME(*_kpiNsIdx, "MTBF");
    findChildNode(_kpiServer, *_kpiParent, 3, targetNameArr, &node);
    UA_Server_readValue(_kpiServer, node, &variant);
    quality.mtbf = *(UA_Duration*)variant.data;
    targetNameArr[2] = UA_QUALIFIEDNAME(*_kpiNsIdx, "Yield");
    findChildNode(_kpiServer, *_kpiParent, 3, targetNameArr, &node);
    UA_Server_readValue(_kpiServer, node, &variant);
    quality.yield = *(UA_UInt16*)variant.data;

    //Values only for Reading Update from python script during Machine Running
    targetNameArr[1] = UA_QUALIFIEDNAME(*_kpiNsIdx, "RealTimeInformation");
    targetNameArr[2] = UA_QUALIFIEDNAME(*_kpiNsIdx, "LastCycleTime");
    findChildNode(_kpiServer, *_kpiParent, 3, targetNameArr, &node);
    UA_Server_readValue(_kpiServer, node, &variant);
    realTimeInformation.lastCycleTime = *(UA_Duration*)variant.data;
    targetNameArr[2] = UA_QUALIFIEDNAME(*_kpiNsIdx, "LastProductionTime");
    findChildNode(_kpiServer, *_kpiParent, 3, targetNameArr, &node);
    UA_Server_readValue(_kpiServer, node, &variant);
    realTimeInformation.lastProductionTime = *(UA_Duration*)variant.data;
    targetNameArr[2] = UA_QUALIFIEDNAME(*_kpiNsIdx, "LastWaitTime");
    findChildNode(_kpiServer, *_kpiParent, 3, targetNameArr, &node);
    UA_Server_readValue(_kpiServer, node, &variant);
    realTimeInformation.lastWaitTime = *(UA_Duration*)variant.data;

    //Values only for Reading Update during Callback
    targetNameArr[1] = UA_QUALIFIEDNAME(*_kpiNsIdx, "Responsiveness");
    targetNameArr[2] = UA_QUALIFIEDNAME(*_kpiNsIdx, "AverageCycleTime");
    findChildNode(_kpiServer, *_kpiParent, 3, targetNameArr, &node);
    UA_Server_readValue(_kpiServer, node, &variant);
    responsiveness.averageCycleTime = *(UA_Duration*)variant.data;
    targetNameArr[2] = UA_QUALIFIEDNAME(*_kpiNsIdx, "AverageProductionTime");
    findChildNode(_kpiServer, *_kpiParent, 3, targetNameArr, &node);
    UA_Server_readValue(_kpiServer, node, &variant);
    responsiveness.averageProductionTime = *(UA_Duration*)variant.data;
    targetNameArr[2] = UA_QUALIFIEDNAME(*_kpiNsIdx, "AverageWaitTime");
    findChildNode(_kpiServer, *_kpiParent, 3, targetNameArr, &node);
    UA_Server_readValue(_kpiServer, node, &variant);
    responsiveness.averageWaitTime = *(UA_Duration*)variant.data;

}

void Kpi_CalculateValues(void)
{
    //Calc Performance
    if (responsiveness.averageProductionTime != 0) 
    {
        double perform = responsiveness.averageProductionTime / responsiveness.averageCycleTime * 100 + 0.5;
        efficiency.performance = (UA_UInt16)perform;
    }
    else efficiency.performance = 0;
    
    //Calc utilization
    if (responsiveness.averageCycleTime != 0) 
    {
        double utilz = responsiveness.averageWaitTime / responsiveness.averageCycleTime * 100 + 0.5;
        efficiency.utilization = (UA_UInt16)utilz;
    }
    else efficiency.utilization = 0;
    
    //Calc Yield and Quality //Only MockUP no Input Faktor for Yield and Quality
    if (healtMeter.StoppageCount != 0 ) 
    {
        double yield = 100 - ((double)healtMeter.failureCount / (double)healtMeter.StoppageCount) * 100 + 0.5;
        quality.yield = (UA_UInt16)yield;
        efficiency.quality = quality.yield;
    }
    else
    {
        quality.yield = 0;
        efficiency.quality = quality.yield;
    }

    //Calc Availability
    if (healtMeter.StoppageCount != 0 ) 
    {
        double avail = (double)healtMeter.StoppageCount / ((double)healtMeter.StoppageCount + (double)healtMeter.failureCount) * 100 + 0.5;
        efficiency.availability = (UA_UInt16)avail;

    }
    else
    {
        efficiency.availability = 0;
    }
    
    //Calc MTBF
    if (healtMeter.failureCount != 0 ) 
    {
        quality.mtbf = (double)(time(NULL) - startTime ) / (double)healtMeter.failureCount;
    }
    else
    {
        quality.mtbf = (double)(time(NULL) - startTime );
    }
    
    //Calc OEE
    double oee = (((double)efficiency.availability/100) * ((double)efficiency.performance/100) * ((double)efficiency.quality/100) * 100) + 0.5;
    efficiency.oee = oee;

}

void Kpi_WriteValues(void)
{
    UA_Variant variant;
    UA_NodeId node;
    UA_QualifiedName targetNameArr[3] = {UA_QUALIFIEDNAME(*_kpiNsIdx, "KPI"), 
                                        UA_QUALIFIEDNAME(*_kpiNsIdx, "Efficiency"), 
                                        UA_QUALIFIEDNAME(*_kpiNsIdx, "Availability")};
    findChildNode(_kpiServer, *_kpiParent, 3, targetNameArr, &node);
    UA_Variant_setScalar(&variant, &efficiency.availability, &UA_TYPES[UA_TYPES_UINT16]);
    UA_Server_writeValue(_kpiServer, node, variant);
    targetNameArr[2] = UA_QUALIFIEDNAME(*_kpiNsIdx, "Performance");
    findChildNode(_kpiServer, *_kpiParent, 3, targetNameArr, &node);
    UA_Variant_setScalar(&variant, &efficiency.performance, &UA_TYPES[UA_TYPES_UINT16]);
    UA_Server_writeValue(_kpiServer, node, variant);

    targetNameArr[2] = UA_QUALIFIEDNAME(*_kpiNsIdx, "Quality");
    findChildNode(_kpiServer, *_kpiParent, 3, targetNameArr, &node);
    UA_Variant_setScalar(&variant, &efficiency.quality, &UA_TYPES[UA_TYPES_UINT16]);
    UA_Server_writeValue(_kpiServer, node, variant);
    
    targetNameArr[2] = UA_QUALIFIEDNAME(*_kpiNsIdx, "Utilization");
    findChildNode(_kpiServer, *_kpiParent, 3, targetNameArr, &node);
    UA_Variant_setScalar(&variant, &efficiency.utilization, &UA_TYPES[UA_TYPES_UINT16]);
    UA_Server_writeValue(_kpiServer, node, variant);
    
    targetNameArr[2] = UA_QUALIFIEDNAME(*_kpiNsIdx, "OEE");
    findChildNode(_kpiServer, *_kpiParent, 3, targetNameArr, &node);
    UA_Variant_setScalar(&variant, &efficiency.oee, &UA_TYPES[UA_TYPES_UINT16]);
    UA_Server_writeValue(_kpiServer, node, variant);

    targetNameArr[1] = UA_QUALIFIEDNAME(*_kpiNsIdx, "Quality");
    targetNameArr[2] = UA_QUALIFIEDNAME(*_kpiNsIdx, "MTBF");
    findChildNode(_kpiServer, *_kpiParent, 3, targetNameArr, &node);
       UA_Variant_setScalar(&variant, &quality.mtbf, &UA_TYPES[UA_TYPES_DURATION]);
    UA_Server_writeValue(_kpiServer, node, variant);

    targetNameArr[2] = UA_QUALIFIEDNAME(*_kpiNsIdx, "Yield");
    findChildNode(_kpiServer, *_kpiParent, 3, targetNameArr, &node);
    UA_Variant_setScalar(&variant, &quality.yield, &UA_TYPES[UA_TYPES_UINT16]);
    UA_Server_writeValue(_kpiServer, node, variant);
}



void Kpi_Init(UA_Server *server, UA_NodeId *parent, UA_UInt16 *nsIdx)
{
    startTime = time(NULL);
    _kpiNsIdx = nsIdx;
    _kpiServer = server;
    _kpiParent = parent;
}

void Kpi_Update(void)
{
 Kpi_ReadValues();
 Kpi_CalculateValues();
 Kpi_WriteValues();
}

