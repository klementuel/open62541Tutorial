/**
 * @file KpiCalculator.h
 * @author Klemens Körner (klemens.koerner@detecon.com)
 * @brief Schematic KPI Calculator Modul
 * Here we need an parent Node wich has an KPIType Named as "KPI" inside
 * The Real Time KPIś need set from the machine
 * For Update the other KPIś we at best set it to Update in a Callback when KPI/HealtMeter/StoppageCount
 * @version 0.6
 * @date 21-03-2021
 * 
 * Mozzilla Public License V2.0
 * 
 */

#ifndef KPI_CALC
#define KPI_CALC
#include <open62541/plugin/log_stdout.h>
#include <open62541/server.h>
#include "OpcUaHelper.h"
#include "time.h"


/**
 * @brief Local Strcut for KPI/Efficiency
 * 
 */
struct efficiency
{
    UA_UInt16 availability;
    UA_UInt16 performance;
    UA_UInt16 quality;
    UA_UInt16 utilization;
    UA_UInt16 oee;
}efficiency;

/**
 * @brief Local Strcut for KPI/HelatMeter
 * 
 */
struct healtMeter
{
    UA_UInt16 failureCount;
    UA_UInt16 operationTimeFailureCount;
    UA_Duration ReqTaktTime;
    UA_UInt16 StoppageCount;
}healtMeter;

/**
 * @brief Local Strcut for KPI/Quality
 * 
 */
struct quality
{
    UA_Duration mtbf;
    UA_UInt16 yield;
}quality;

/**
 * @brief Local Strcut for KPI/RealTimeInformation
 * 
 */
struct realTimeInformation
{
    UA_Duration lastCycleTime;
    UA_Duration lastWaitTime;
    UA_Duration lastProductionTime;
}realTimeInformation;

/**
 * @brief Local Strcut for KPI/Responsiveness
 * 
 */
struct responsiveness
{
    UA_Duration averageCycleTime;
    UA_Duration averageWaitTime;
    UA_Duration averageProductionTime;;
}responsiveness;

/**
 * @brief Init the KPI Logic
 * 
 * @param server the server were the KPI Child can be found
 * @param parent the parent of the KPI Child
 * @param cbNsIdx the Node ID from the used Nodeset were the KPI Child can be found
 */
extern void Kpi_Init(UA_Server *server, UA_NodeId *parent, UA_UInt16 *cbNsIdx);

/**
 * @brief Update Logic for the KPI Values
 * It first read all Values from the server and save it to the local structs
 * Then it Calculate the KPIś
 * after that it write all change KPIś back to the server
 */
extern void Kpi_Update(void);


#endif