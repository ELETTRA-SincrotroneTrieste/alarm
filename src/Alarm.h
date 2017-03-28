/*----- PROTECTED REGION ID(Alarm.h) ENABLED START -----*/
//=============================================================================
//
// file :        Alarm.h
//
// description : Include file for the Alarm class
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


#ifndef Alarm_H
#define Alarm_H

#include <tango.h>
#include <mysql.h>

#include <boost/version.hpp>
#if BOOST_VERSION  >= 103600
#define BOOST_VER_1_36_0 1
#endif

#include "alarm_table.h"
#include "event_table.h"
#include "SubscribeThread.h"

#define MAX_ALARMS	10000

//#define _USE_ELETTRA_DB_RW

//using namespace Tango;

class alarm_thread;
class log_thread;
class update_thread;

#	define	DECLARE_TIME_VAR	struct timeval
#	define	GET_TIME(t)	gettimeofday(&t, NULL);
#	define	ELAPSED(before, after)	\
		1000.0*(after.tv_sec-before.tv_sec) + \
		((double)after.tv_usec-before.tv_usec) / 1000



/*----- PROTECTED REGION END -----*/	//	Alarm.h

/**
 *  Alarm class description:
 *    Elettra alarm device server
 */

namespace Alarm_ns
{
enum _AlarmStateEnum {
	_NORM,
	_UNACK,
	_ACKED,
	_RTNUN,
	_SHLVD,
	_DSUPR,
	_OOSRV,
} ;
typedef _AlarmStateEnum AlarmStateEnum;

/*----- PROTECTED REGION ID(Alarm::Additional Class Declarations) ENABLED START -----*/

//	Additional Class Declarations

/*----- PROTECTED REGION END -----*/	//	Alarm::Additional Class Declarations

class Alarm : public TANGO_BASE_CLASS
{

/*----- PROTECTED REGION ID(Alarm::Data Members) ENABLED START -----*/

//	Add your own data members
public:
	bool compare_without_domain(string str1, string str2);
	string remove_domain(string str);
	//TODO: real attributes
	Tango::DevLong attr_AttributeStartedNumber_read;
	Tango::DevLong attr_AttributePausedNumber_read;
	Tango::DevLong attr_AttributeStoppedNumber_read;
	Tango::DevLong attr_AttributeNumber_read;

	vector<string> normalAlarms_read;
	vector<string> unacknowledgedAlarms_read;
	vector<string> acknowledgedAlarms_read;
	vector<string> unacknowledgedNormalAlarms_read;
	vector<string> shelvedAlarms_read;
	vector<string> outOfServiceAlarms_read;
	vector<string> silencedAlarms_read;
	vector<string> listAlarms_read;

	size_t normalAlarms_sz;
	size_t unacknowledgedAlarms_sz;
	size_t acknowledgedAlarms_sz;
	size_t unacknowledgedNormalAlarms_sz;
	size_t shelvedAlarms_sz;
	size_t outOfServiceAlarms_sz;
	size_t silencedAlarms_sz;
	size_t listAlarms_sz;

	double last_statistics_reset_time;

/*----- PROTECTED REGION END -----*/	//	Alarm::Data Members

//	Device property data members
public:
	//	GroupNames:	Labels for Group mask, first is for mask 0x00
	vector<string>	groupNames;
	//	SubscribeRetryPeriod:	Retry subscription period in seconds
	Tango::DevLong	subscribeRetryPeriod;
	//	StatisticsTimeWindow:	Time window to compute statistics in seconds
	vector<Tango::DevLong>	statisticsTimeWindow;

//	Attribute data members
public:
	Tango::DevBoolean	*attr_audibleAlarm_read;
	Tango::DevDouble	*attr_StatisticsResetTime_read;
	Tango::DevString	*attr_alarm_read;
	Tango::DevString	*attr_normalAlarms_read;
	Tango::DevString	*attr_unacknowledgedAlarms_read;
	Tango::DevString	*attr_acknowledgedAlarms_read;
	Tango::DevString	*attr_unacknowledgedNormalAlarms_read;
	Tango::DevString	*attr_shelvedAlarms_read;
	Tango::DevString	*attr_outOfServiceAlarms_read;
	Tango::DevString	*attr_silencedAlarms_read;
	Tango::DevString	*attr_listAlarms_read;
	Tango::DevDouble	*attr_frequencyAlarms_read;

//	Constructors and destructors
public:
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	Alarm(Tango::DeviceClass *cl,string &s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	Alarm(Tango::DeviceClass *cl,const char *s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device name
	 *	@param d	Device description.
	 */
	Alarm(Tango::DeviceClass *cl,const char *s,const char *d);
	/**
	 * The device object destructor.
	 */
	~Alarm() {delete_device();};


//	Miscellaneous methods
public:
	/*
	 *	will be called at device destruction or at init command.
	 */
	void delete_device();
	/*
	 *	Initialize the device
	 */
	virtual void init_device();
	/*
	 *	Read the device properties from database
	 */
	void get_device_property();
	/*
	 *	Always executed method before execution command method.
	 */
	virtual void always_executed_hook();


//	Attribute methods
public:
	//--------------------------------------------------------
	/*
	 *	Method      : Alarm::read_attr_hardware()
	 *	Description : Hardware acquisition for attributes.
	 */
	//--------------------------------------------------------
	virtual void read_attr_hardware(vector<long> &attr_list);

/**
 *	Attribute audibleAlarm related methods
 *	Description: True if there is at least one alarm that needs audible indication on the GUI
 *
 *	Data type:	Tango::DevBoolean
 *	Attr type:	Scalar
 */
	virtual void read_audibleAlarm(Tango::Attribute &attr);
	virtual bool is_audibleAlarm_allowed(Tango::AttReqType type);
/**
 *	Attribute StatisticsResetTime related methods
 *	Description: Time elapsed in seconds since last Resetstatistics
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
	virtual void read_StatisticsResetTime(Tango::Attribute &attr);
	virtual bool is_StatisticsResetTime_allowed(Tango::AttReqType type);
/**
 *	Attribute alarm related methods
 *	Description: 
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Spectrum max = 1024
 */
	virtual void read_alarm(Tango::Attribute &attr);
	virtual bool is_alarm_allowed(Tango::AttReqType type);
/**
 *	Attribute normalAlarms related methods
 *	Description: List of alarms in normal state
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Spectrum max = 10000
 */
	virtual void read_normalAlarms(Tango::Attribute &attr);
	virtual bool is_normalAlarms_allowed(Tango::AttReqType type);
/**
 *	Attribute unacknowledgedAlarms related methods
 *	Description: List of alarms in unacknowledged state
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Spectrum max = 10000
 */
	virtual void read_unacknowledgedAlarms(Tango::Attribute &attr);
	virtual bool is_unacknowledgedAlarms_allowed(Tango::AttReqType type);
/**
 *	Attribute acknowledgedAlarms related methods
 *	Description: List of alarms in acknowledged state
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Spectrum max = 10000
 */
	virtual void read_acknowledgedAlarms(Tango::Attribute &attr);
	virtual bool is_acknowledgedAlarms_allowed(Tango::AttReqType type);
/**
 *	Attribute unacknowledgedNormalAlarms related methods
 *	Description: List of alarms in unacknowledged normal state
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Spectrum max = 10000
 */
	virtual void read_unacknowledgedNormalAlarms(Tango::Attribute &attr);
	virtual bool is_unacknowledgedNormalAlarms_allowed(Tango::AttReqType type);
/**
 *	Attribute shelvedAlarms related methods
 *	Description: List of alarms in shelved state
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Spectrum max = 10000
 */
	virtual void read_shelvedAlarms(Tango::Attribute &attr);
	virtual bool is_shelvedAlarms_allowed(Tango::AttReqType type);
/**
 *	Attribute outOfServiceAlarms related methods
 *	Description: List of alarms in out of service state
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Spectrum max = 10000
 */
	virtual void read_outOfServiceAlarms(Tango::Attribute &attr);
	virtual bool is_outOfServiceAlarms_allowed(Tango::AttReqType type);
/**
 *	Attribute silencedAlarms related methods
 *	Description: List of alarms in silenced state
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Spectrum max = 10000
 */
	virtual void read_silencedAlarms(Tango::Attribute &attr);
	virtual bool is_silencedAlarms_allowed(Tango::AttReqType type);
/**
 *	Attribute listAlarms related methods
 *	Description: List of all alarms
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Spectrum max = 10000
 */
	virtual void read_listAlarms(Tango::Attribute &attr);
	virtual bool is_listAlarms_allowed(Tango::AttReqType type);
/**
 *	Attribute frequencyAlarms related methods
 *	Description: List of frequency of evaluation of all alarms
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Spectrum max = 10000
 */
	virtual void read_frequencyAlarms(Tango::Attribute &attr);
	virtual bool is_frequencyAlarms_allowed(Tango::AttReqType type);

//	Dynamic attribute methods
public:

	/**
	 *	Attribute AlarmState related methods
	 *	Description: 
	 *
	 *	Data type:	Tango::DevEnum
	 *	Attr type:	Scalar
	 */
	virtual void read_AlarmState(Tango::Attribute &attr);
	virtual bool is_AlarmState_allowed(Tango::AttReqType type);
	void add_AlarmState_dynamic_attribute(string attname);
	void remove_AlarmState_dynamic_attribute(string attname);
	Tango::DevEnum *get_AlarmState_data_ptr(string &name);
	map<string,Tango::DevEnum>	   AlarmState_data;

	/**
	 *	Attribute AlarmFormula related methods
	 *	Description: 
	 *
	 *	Data type:	Tango::DevString
	 *	Attr type:	Scalar
	 */
	virtual void read_AlarmFormula(Tango::Attribute &attr);
	virtual bool is_AlarmFormula_allowed(Tango::AttReqType type);
	void add_AlarmFormula_dynamic_attribute(string attname);
	void remove_AlarmFormula_dynamic_attribute(string attname);
	Tango::DevString *get_AlarmFormula_data_ptr(string &name);
	map<string,Tango::DevString>	   AlarmFormula_data;

	//--------------------------------------------------------
	/**
	 *	Method      : Alarm::add_dynamic_attributes()
	 *	Description : Add dynamic attributes if any.
	 */
	//--------------------------------------------------------
	void add_dynamic_attributes();




//	Command related methods
public:
	/**
	 *	Command Ack related method
	 *	Description: Alarm acknowledge
	 *
	 *	@param argin String array containing the alarms to be acknowledged
	 */
	virtual void ack(const Tango::DevVarStringArray *argin);
	virtual bool is_Ack_allowed(const CORBA::Any &any);
	/**
	 *	Command Load related method
	 *	Description: Load a new alarm.
	 *
	 *	@param argin Alarm entry
	 */
	virtual void load(Tango::DevString argin);
	virtual bool is_Load_allowed(const CORBA::Any &any);
	/**
	 *	Command Remove related method
	 *	Description: Remove alarm.
	 *
	 *	@param argin Alarm name
	 */
	virtual void remove(Tango::DevString argin);
	virtual bool is_Remove_allowed(const CORBA::Any &any);
	/**
	 *	Command SearchAlarm related method
	 *	Description: Return list of configured alarms matching the filter string
	 *
	 *	@param argin String containing a filter for output, if empty or * return all alarms
	 *	@returns Configured alarms
	 */
	virtual Tango::DevVarStringArray *search_alarm(Tango::DevString argin);
	virtual bool is_SearchAlarm_allowed(const CORBA::Any &any);
	/**
	 *	Command StopAudible related method
	 *	Description: Stop audible indications on the GUI
	 *
	 */
	virtual void stop_audible();
	virtual bool is_StopAudible_allowed(const CORBA::Any &any);
	/**
	 *	Command Silence related method
	 *	Description: Alarm temporarily silence
	 *
	 *	@param argin String array containing the alarms to be silenced
	 */
	virtual void silence(const Tango::DevVarStringArray *argin);
	virtual bool is_Silence_allowed(const CORBA::Any &any);
	/**
	 *	Command Modify related method
	 *	Description: Modify an existing alarm.
	 *
	 *	@param argin Alarm entry
	 */
	virtual void modify(Tango::DevString argin);
	virtual bool is_Modify_allowed(const CORBA::Any &any);
	/**
	 *	Command Shelve related method
	 *	Description: Shelve an alarm: no state transition recorded, no audible nor visual indication
	 *
	 *	@param argin String array containing alarm to be shelved
	 */
	virtual void shelve(const Tango::DevVarStringArray *argin);
	virtual bool is_Shelve_allowed(const CORBA::Any &any);
	/**
	 *	Command Enable related method
	 *	Description: Enable an alarm from Out of service state
	 *
	 *	@param argin Alarm name
	 */
	virtual void enable(Tango::DevString argin);
	virtual bool is_Enable_allowed(const CORBA::Any &any);
	/**
	 *	Command Disable related method
	 *	Description: Put an alarm in Out of service state
	 *
	 *	@param argin Alarm name
	 */
	virtual void disable(Tango::DevString argin);
	virtual bool is_Disable_allowed(const CORBA::Any &any);
	/**
	 *	Command ResetStatistics related method
	 *	Description: Reset statistics
	 *
	 */
	virtual void reset_statistics();
	virtual bool is_ResetStatistics_allowed(const CORBA::Any &any);


	//--------------------------------------------------------
	/**
	 *	Method      : Alarm::add_dynamic_commands()
	 *	Description : Add dynamic commands if any.
	 */
	//--------------------------------------------------------
	void add_dynamic_commands();

/*----- PROTECTED REGION ID(Alarm::Additional Method prototypes) ENABLED START -----*/

//	Additional Method prototypes
friend class alarm_thread;
friend class SubscribeThread;
friend class event_table;

	alarm_table alarms;

protected :	

private:
	vector<alarm_t> stored;		/* property stored alarms (on exit) */
	event_table* events;
//	event_list evlist;				/* producer/consumer events list */		//gcc 4 problem??
//	EventCallBack ecb;				/* callback handles */
	alarm_thread *almloop;
	update_thread *updateloop;
	vector<alarm_t> alarmed;
	ReadersWritersLock *alarmedlock;
	vector<alarm_t> internal;
	ReadersWritersLock *internallock;
	ReadersWritersLock *dslock;
	int			period;		//subscribe thread period
	map<string, string> saved_alarms;
	
	static int instanceCounter;
	
	int internal_counter;
	int ds_num;
	Tango::DevString ds[MAX_ALARMS];
	char dss[MAX_ALARMS][10124];

	void init_events(vector<string> &evn);
#if 0
	void init_alarms(map< string,vector<string> > &alarm_events);
#endif
	void add_alarm(alarm_t& a) throw(string&);
	void add_event(alarm_t& a, vector<string> &evn) throw(string&);
#if 0
	void subscribe_event(alarm_t& a, EventCallBack& ecb, vector<string> &evn) throw(string&);
#endif
//	void do_alarm(bei_t& e);											//gcc 4 problem??
	bool remove_alarm(string& s) throw(string&);
	//void add_to_database(alarm_t& a) throw(string&);
	void set_internal_alarm(string name, Tango::TimeVal t, string msg, unsigned int count=1);
	
	void load_alarm(string alarm_string, alarm_t &alm, vector<string> &evn);

	formula_res_t eval_formula(tree_parse_info_t tree, string &attr_values);
	void find_event_formula(tree_parse_info_t tree, vector<string> &);
	
	formula_res_t eval_expression(iter_t const& i, string &attr_values, int ev_ind=0);			//recursive tree node evaluation
	void eval_node_event(iter_t const& i, vector<string> & ev);		//recursive tree node evaluation		

	void prepare_alarm_attr();	//for read attribute alarm and push_change_event

	SubscribeThread *thread;

public:
	void put_signal_property();
	void do_alarm(bei_t& e);											//public instead of protected for gcc 4 problem??
	bool do_alarm_eval(string alm_name, string ev_name, Tango::TimeVal ts);
	void timer_update();												//public instead of protected for gcc 4 problem??
	event_list evlist;				/* producer/consumer events list */		//public instead of protected for gcc 4 problem??
	bool abortflag;
	
#ifdef _USE_ELETTRA_DB_RW
private:
	string host_rw;
	long port_rw;
#endif

/*----- PROTECTED REGION END -----*/	//	Alarm::Additional Method prototypes
};

/*----- PROTECTED REGION ID(Alarm::Additional Classes Definitions) ENABLED START -----*/

//	Additional Classes Definitions

/*----- PROTECTED REGION END -----*/	//	Alarm::Additional Classes Definitions

}	//	End of namespace

#endif   //	Alarm_H
