/*----- PROTECTED REGION ID(AlarmClass.h) ENABLED START -----*/
//=============================================================================
//
// file :        AlarmClass.h
//
// description : Include for the Alarm root class.
//               This class is the singleton class for
//                the Alarm device class.
//               It contains all properties and methods which the 
//               Alarm requires only once e.g. the commands.
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


#ifndef AlarmClass_H
#define AlarmClass_H

#include <tango.h>
#include <Alarm.h>

/*----- PROTECTED REGION END -----*/	//	AlarmClass.h


namespace Alarm_ns
{
/*----- PROTECTED REGION ID(AlarmClass::classes for dynamic creation) ENABLED START -----*/


/*----- PROTECTED REGION END -----*/	//	AlarmClass::classes for dynamic creation

//=========================================
//	Define classes for attributes
//=========================================
//	Attribute alarm class definition
class alarmAttrib: public Tango::SpectrumAttr
{
public:
	alarmAttrib():SpectrumAttr("alarm",
			Tango::DEV_STRING, Tango::READ, 1024) {};
	~alarmAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<Alarm *>(dev))->read_alarm(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<Alarm *>(dev))->is_alarm_allowed(ty);}
};


//=========================================
//	Define classes for dynamic attributes
//=========================================
//	Attribute AlarmState class definition
class AlarmStateAttrib: public Tango::Attr
{
public:
	AlarmStateAttrib(const string &att_name):Attr(att_name.c_str(), 
			Tango::DEV_BOOLEAN, Tango::READ) {};
	~AlarmStateAttrib() {};
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
		{(static_cast<Alarm *>(dev))->read_AlarmState(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
		{return (static_cast<Alarm *>(dev))->is_AlarmState_allowed(ty);}
};


//=========================================
//	Define classes for commands
//=========================================
//	Command Ack class definition
class AckClass : public Tango::Command
{
public:
	AckClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	AckClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~AckClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<Alarm *>(dev))->is_Ack_allowed(any);}
};

//	Command Load class definition
class LoadClass : public Tango::Command
{
public:
	LoadClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	LoadClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~LoadClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<Alarm *>(dev))->is_Load_allowed(any);}
};

//	Command Remove class definition
class RemoveClass : public Tango::Command
{
public:
	RemoveClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	RemoveClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~RemoveClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<Alarm *>(dev))->is_Remove_allowed(any);}
};

//	Command Configured class definition
class ConfiguredClass : public Tango::Command
{
public:
	ConfiguredClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	ConfiguredClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~ConfiguredClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<Alarm *>(dev))->is_Configured_allowed(any);}
};

//	Command StopNew class definition
class StopNewClass : public Tango::Command
{
public:
	StopNewClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	StopNewClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~StopNewClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<Alarm *>(dev))->is_StopNew_allowed(any);}
};

//	Command Silence class definition
class SilenceClass : public Tango::Command
{
public:
	SilenceClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	SilenceClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~SilenceClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<Alarm *>(dev))->is_Silence_allowed(any);}
};

//	Command Modify class definition
class ModifyClass : public Tango::Command
{
public:
	ModifyClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	ModifyClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~ModifyClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<Alarm *>(dev))->is_Modify_allowed(any);}
};


/**
 *	The AlarmClass singleton definition
 */

#ifdef _TG_WINDOWS_
class __declspec(dllexport)  AlarmClass : public Tango::DeviceClass
#else
class AlarmClass : public Tango::DeviceClass
#endif
{
	/*----- PROTECTED REGION ID(AlarmClass::Additionnal DServer data members) ENABLED START -----*/
	
	
	/*----- PROTECTED REGION END -----*/	//	AlarmClass::Additionnal DServer data members

	public:
		//	write class properties data members
		Tango::DbData	cl_prop;
		Tango::DbData	cl_def_prop;
		Tango::DbData	dev_def_prop;
	
		//	Method prototypes
		static AlarmClass *init(const char *);
		static AlarmClass *instance();
		~AlarmClass();
		Tango::DbDatum	get_class_property(string &);
		Tango::DbDatum	get_default_device_property(string &);
		Tango::DbDatum	get_default_class_property(string &);
	
	protected:
		AlarmClass(string &);
		static AlarmClass *_instance;
		void command_factory();
		void attribute_factory(vector<Tango::Attr *> &);
		void pipe_factory();
		void write_class_property();
		void set_default_property();
		void get_class_property();
		string get_cvstag();
		string get_cvsroot();
	
	private:
		void device_factory(const Tango::DevVarStringArray *);
		void create_static_attribute_list(vector<Tango::Attr *> &);
		void erase_dynamic_attributes(const Tango::DevVarStringArray *,vector<Tango::Attr *> &);
		vector<string>	defaultAttList;
		Tango::Attr *get_attr_object_by_name(vector<Tango::Attr *> &att_list, string attname);
};

}	//	End of namespace

#endif   //	Alarm_H
