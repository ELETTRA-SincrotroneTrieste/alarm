/*----- PROTECTED REGION ID(AlarmStateMachine.cpp) ENABLED START -----*/
static const char *RcsId = "$Id:  $";
//=============================================================================
//
// file :        AlarmStateMachine.cpp
//
// description : State machine file for the Alarm class
//
// project :     alarm
//
// This file is part of Tango device class.
// 
// Tango is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// Tango is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with Tango.  If not, see <http://www.gnu.org/licenses/>.
// 
// $Author:  $
//
// $Revision:  $
// $Date:  $
//
// $HeadURL:  $
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================

#include <Alarm.h>

/*----- PROTECTED REGION END -----*/	//	Alarm::AlarmStateMachine.cpp

//================================================================
//  States  |  Description
//================================================================


namespace Alarm_ns
{
//=================================================
//		Attributes Allowed Methods
//=================================================

//--------------------------------------------------------
/**
 *	Method      : Alarm::is_audibleAlarm_allowed()
 *	Description : Execution allowed for audibleAlarm attribute
 */
//--------------------------------------------------------
bool Alarm::is_audibleAlarm_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Not any excluded states for audibleAlarm attribute in read access.
	/*----- PROTECTED REGION ID(Alarm::audibleAlarmStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	Alarm::audibleAlarmStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Alarm::is_StatisticsResetTime_allowed()
 *	Description : Execution allowed for StatisticsResetTime attribute
 */
//--------------------------------------------------------
bool Alarm::is_StatisticsResetTime_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Not any excluded states for StatisticsResetTime attribute in read access.
	/*----- PROTECTED REGION ID(Alarm::StatisticsResetTimeStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	Alarm::StatisticsResetTimeStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Alarm::is_alarm_allowed()
 *	Description : Execution allowed for alarm attribute
 */
//--------------------------------------------------------
bool Alarm::is_alarm_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Not any excluded states for alarm attribute in read access.
	/*----- PROTECTED REGION ID(Alarm::alarmStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	Alarm::alarmStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Alarm::is_normalAlarms_allowed()
 *	Description : Execution allowed for normalAlarms attribute
 */
//--------------------------------------------------------
bool Alarm::is_normalAlarms_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Not any excluded states for normalAlarms attribute in read access.
	/*----- PROTECTED REGION ID(Alarm::normalAlarmsStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	Alarm::normalAlarmsStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Alarm::is_unacknowledgedAlarms_allowed()
 *	Description : Execution allowed for unacknowledgedAlarms attribute
 */
//--------------------------------------------------------
bool Alarm::is_unacknowledgedAlarms_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Not any excluded states for unacknowledgedAlarms attribute in read access.
	/*----- PROTECTED REGION ID(Alarm::unacknowledgedAlarmsStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	Alarm::unacknowledgedAlarmsStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Alarm::is_acknowledgedAlarms_allowed()
 *	Description : Execution allowed for acknowledgedAlarms attribute
 */
//--------------------------------------------------------
bool Alarm::is_acknowledgedAlarms_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Not any excluded states for acknowledgedAlarms attribute in read access.
	/*----- PROTECTED REGION ID(Alarm::acknowledgedAlarmsStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	Alarm::acknowledgedAlarmsStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Alarm::is_unacknowledgedNormalAlarms_allowed()
 *	Description : Execution allowed for unacknowledgedNormalAlarms attribute
 */
//--------------------------------------------------------
bool Alarm::is_unacknowledgedNormalAlarms_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Not any excluded states for unacknowledgedNormalAlarms attribute in read access.
	/*----- PROTECTED REGION ID(Alarm::unacknowledgedNormalAlarmsStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	Alarm::unacknowledgedNormalAlarmsStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Alarm::is_shelvedAlarms_allowed()
 *	Description : Execution allowed for shelvedAlarms attribute
 */
//--------------------------------------------------------
bool Alarm::is_shelvedAlarms_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Not any excluded states for shelvedAlarms attribute in read access.
	/*----- PROTECTED REGION ID(Alarm::shelvedAlarmsStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	Alarm::shelvedAlarmsStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Alarm::is_outOfServiceAlarms_allowed()
 *	Description : Execution allowed for outOfServiceAlarms attribute
 */
//--------------------------------------------------------
bool Alarm::is_outOfServiceAlarms_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Not any excluded states for outOfServiceAlarms attribute in read access.
	/*----- PROTECTED REGION ID(Alarm::outOfServiceAlarmsStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	Alarm::outOfServiceAlarmsStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Alarm::is_silencedAlarms_allowed()
 *	Description : Execution allowed for silencedAlarms attribute
 */
//--------------------------------------------------------
bool Alarm::is_silencedAlarms_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Not any excluded states for silencedAlarms attribute in read access.
	/*----- PROTECTED REGION ID(Alarm::silencedAlarmsStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	Alarm::silencedAlarmsStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Alarm::is_listAlarms_allowed()
 *	Description : Execution allowed for listAlarms attribute
 */
//--------------------------------------------------------
bool Alarm::is_listAlarms_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Not any excluded states for listAlarms attribute in read access.
	/*----- PROTECTED REGION ID(Alarm::listAlarmsStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	Alarm::listAlarmsStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Alarm::is_frequencyAlarms_allowed()
 *	Description : Execution allowed for frequencyAlarms attribute
 */
//--------------------------------------------------------
bool Alarm::is_frequencyAlarms_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Not any excluded states for frequencyAlarms attribute in read access.
	/*----- PROTECTED REGION ID(Alarm::frequencyAlarmsStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	Alarm::frequencyAlarmsStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Alarm::is_AlarmState_allowed()
 *	Description : Execution allowed for AlarmState attribute
 */
//--------------------------------------------------------
bool Alarm::is_AlarmState_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Not any excluded states for AlarmState attribute in read access.
	/*----- PROTECTED REGION ID(Alarm::AlarmStateStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	Alarm::AlarmStateStateAllowed_READ
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Alarm::is_AlarmFormula_allowed()
 *	Description : Execution allowed for AlarmFormula attribute
 */
//--------------------------------------------------------
bool Alarm::is_AlarmFormula_allowed(TANGO_UNUSED(Tango::AttReqType type))
{

	//	Not any excluded states for AlarmFormula attribute in read access.
	/*----- PROTECTED REGION ID(Alarm::AlarmFormulaStateAllowed_READ) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	Alarm::AlarmFormulaStateAllowed_READ
	return true;
}


//=================================================
//		Commands Allowed Methods
//=================================================

//--------------------------------------------------------
/**
 *	Method      : Alarm::is_Ack_allowed()
 *	Description : Execution allowed for Ack attribute
 */
//--------------------------------------------------------
bool Alarm::is_Ack_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for Ack command.
	/*----- PROTECTED REGION ID(Alarm::AckStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	Alarm::AckStateAllowed
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Alarm::is_Load_allowed()
 *	Description : Execution allowed for Load attribute
 */
//--------------------------------------------------------
bool Alarm::is_Load_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for Load command.
	/*----- PROTECTED REGION ID(Alarm::LoadStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	Alarm::LoadStateAllowed
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Alarm::is_Remove_allowed()
 *	Description : Execution allowed for Remove attribute
 */
//--------------------------------------------------------
bool Alarm::is_Remove_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for Remove command.
	/*----- PROTECTED REGION ID(Alarm::RemoveStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	Alarm::RemoveStateAllowed
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Alarm::is_SearchAlarm_allowed()
 *	Description : Execution allowed for SearchAlarm attribute
 */
//--------------------------------------------------------
bool Alarm::is_SearchAlarm_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for SearchAlarm command.
	/*----- PROTECTED REGION ID(Alarm::SearchAlarmStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	Alarm::SearchAlarmStateAllowed
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Alarm::is_StopAudible_allowed()
 *	Description : Execution allowed for StopAudible attribute
 */
//--------------------------------------------------------
bool Alarm::is_StopAudible_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for StopAudible command.
	/*----- PROTECTED REGION ID(Alarm::StopAudibleStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	Alarm::StopAudibleStateAllowed
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Alarm::is_Silence_allowed()
 *	Description : Execution allowed for Silence attribute
 */
//--------------------------------------------------------
bool Alarm::is_Silence_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for Silence command.
	/*----- PROTECTED REGION ID(Alarm::SilenceStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	Alarm::SilenceStateAllowed
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Alarm::is_Modify_allowed()
 *	Description : Execution allowed for Modify attribute
 */
//--------------------------------------------------------
bool Alarm::is_Modify_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for Modify command.
	/*----- PROTECTED REGION ID(Alarm::ModifyStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	Alarm::ModifyStateAllowed
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Alarm::is_Shelve_allowed()
 *	Description : Execution allowed for Shelve attribute
 */
//--------------------------------------------------------
bool Alarm::is_Shelve_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for Shelve command.
	/*----- PROTECTED REGION ID(Alarm::ShelveStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	Alarm::ShelveStateAllowed
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Alarm::is_Enable_allowed()
 *	Description : Execution allowed for Enable attribute
 */
//--------------------------------------------------------
bool Alarm::is_Enable_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for Enable command.
	/*----- PROTECTED REGION ID(Alarm::EnableStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	Alarm::EnableStateAllowed
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Alarm::is_Disable_allowed()
 *	Description : Execution allowed for Disable attribute
 */
//--------------------------------------------------------
bool Alarm::is_Disable_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for Disable command.
	/*----- PROTECTED REGION ID(Alarm::DisableStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	Alarm::DisableStateAllowed
	return true;
}

//--------------------------------------------------------
/**
 *	Method      : Alarm::is_ResetStatistics_allowed()
 *	Description : Execution allowed for ResetStatistics attribute
 */
//--------------------------------------------------------
bool Alarm::is_ResetStatistics_allowed(TANGO_UNUSED(const CORBA::Any &any))
{
	//	Not any excluded states for ResetStatistics command.
	/*----- PROTECTED REGION ID(Alarm::ResetStatisticsStateAllowed) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	Alarm::ResetStatisticsStateAllowed
	return true;
}


/*----- PROTECTED REGION ID(Alarm::AlarmStateAllowed.AdditionalMethods) ENABLED START -----*/

//	Additional Methods

/*----- PROTECTED REGION END -----*/	//	Alarm::AlarmStateAllowed.AdditionalMethods

}	//	End of namespace