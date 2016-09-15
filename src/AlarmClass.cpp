/*----- PROTECTED REGION ID(AlarmClass.cpp) ENABLED START -----*/
static const char *RcsId      = "$Id:  $";
static const char *TagName    = "$Name:  $";
static const char *CvsPath    = "$Source:  $";
static const char *SvnPath    = "$HeadURL:  $";
static const char *HttpServer = "http://www.esrf.eu/computing/cs/tango/tango_doc/ds_doc/";
//=============================================================================
//
// file :        AlarmClass.cpp
//
// description : C++ source for the AlarmClass.
//               A singleton class derived from DeviceClass.
//               It implements the command and attribute list
//               and all properties and methods required
//               by the Alarm once per process.
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


#include <tango.h>
#include <Alarm.h>
#include <AlarmClass.h>

/*----- PROTECTED REGION END -----*/	//	AlarmClass.cpp

//-------------------------------------------------------------------
/**
 *	Create AlarmClass singleton and
 *	return it in a C function for Python usage
 */
//-------------------------------------------------------------------
extern "C" {
#ifdef _TG_WINDOWS_

__declspec(dllexport)

#endif

	Tango::DeviceClass *_create_Alarm_class(const char *name) {
		return Alarm_ns::AlarmClass::init(name);
	}
}

namespace Alarm_ns
{
//===================================================================
//	Initialize pointer for singleton pattern
//===================================================================
AlarmClass *AlarmClass::_instance = NULL;

//--------------------------------------------------------
/**
 * method : 		AlarmClass::AlarmClass(string &s)
 * description : 	constructor for the AlarmClass
 *
 * @param s	The class name
 */
//--------------------------------------------------------
AlarmClass::AlarmClass(string &s):Tango::DeviceClass(s)
{
	cout2 << "Entering AlarmClass constructor" << endl;
	set_default_property();
	write_class_property();

	/*----- PROTECTED REGION ID(AlarmClass::constructor) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AlarmClass::constructor

	cout2 << "Leaving AlarmClass constructor" << endl;
}

//--------------------------------------------------------
/**
 * method : 		AlarmClass::~AlarmClass()
 * description : 	destructor for the AlarmClass
 */
//--------------------------------------------------------
AlarmClass::~AlarmClass()
{
	/*----- PROTECTED REGION ID(AlarmClass::destructor) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AlarmClass::destructor

	_instance = NULL;
}


//--------------------------------------------------------
/**
 * method : 		AlarmClass::init
 * description : 	Create the object if not already done.
 *                  Otherwise, just return a pointer to the object
 *
 * @param	name	The class name
 */
//--------------------------------------------------------
AlarmClass *AlarmClass::init(const char *name)
{
	if (_instance == NULL)
	{
		try
		{
			string s(name);
			_instance = new AlarmClass(s);
		}
		catch (bad_alloc &)
		{
			throw;
		}
	}
	return _instance;
}

//--------------------------------------------------------
/**
 * method : 		AlarmClass::instance
 * description : 	Check if object already created,
 *                  and return a pointer to the object
 */
//--------------------------------------------------------
AlarmClass *AlarmClass::instance()
{
	if (_instance == NULL)
	{
		cerr << "Class is not initialised !!" << endl;
		exit(-1);
	}
	return _instance;
}



//===================================================================
//	Command execution method calls
//===================================================================
//--------------------------------------------------------
/**
 * method : 		AckClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *AckClass::execute(Tango::DeviceImpl *device, const CORBA::Any &in_any)
{
	cout2 << "AckClass::execute(): arrived" << endl;
	const Tango::DevVarStringArray *argin;
	extract(in_any, argin);
	((static_cast<Alarm *>(device))->ack(argin));
	return new CORBA::Any();
}

//--------------------------------------------------------
/**
 * method : 		LoadClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *LoadClass::execute(Tango::DeviceImpl *device, const CORBA::Any &in_any)
{
	cout2 << "LoadClass::execute(): arrived" << endl;
	Tango::DevString argin;
	extract(in_any, argin);
	((static_cast<Alarm *>(device))->load(argin));
	return new CORBA::Any();
}

//--------------------------------------------------------
/**
 * method : 		RemoveClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *RemoveClass::execute(Tango::DeviceImpl *device, const CORBA::Any &in_any)
{
	cout2 << "RemoveClass::execute(): arrived" << endl;
	Tango::DevString argin;
	extract(in_any, argin);
	((static_cast<Alarm *>(device))->remove(argin));
	return new CORBA::Any();
}

//--------------------------------------------------------
/**
 * method : 		ConfiguredClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *ConfiguredClass::execute(Tango::DeviceImpl *device, const CORBA::Any &in_any)
{
	cout2 << "ConfiguredClass::execute(): arrived" << endl;
	Tango::DevString argin;
	extract(in_any, argin);
	return insert((static_cast<Alarm *>(device))->configured(argin));
}

//--------------------------------------------------------
/**
 * method : 		StopNewClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *StopNewClass::execute(Tango::DeviceImpl *device, TANGO_UNUSED(const CORBA::Any &in_any))
{
	cout2 << "StopNewClass::execute(): arrived" << endl;
	((static_cast<Alarm *>(device))->stop_new());
	return new CORBA::Any();
}

//--------------------------------------------------------
/**
 * method : 		SilenceClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *SilenceClass::execute(Tango::DeviceImpl *device, const CORBA::Any &in_any)
{
	cout2 << "SilenceClass::execute(): arrived" << endl;
	const Tango::DevVarStringArray *argin;
	extract(in_any, argin);
	((static_cast<Alarm *>(device))->silence(argin));
	return new CORBA::Any();
}

//--------------------------------------------------------
/**
 * method : 		ModifyClass::execute()
 * description : 	method to trigger the execution of the command.
 *
 * @param	device	The device on which the command must be executed
 * @param	in_any	The command input data
 *
 *	returns The command output data (packed in the Any object)
 */
//--------------------------------------------------------
CORBA::Any *ModifyClass::execute(Tango::DeviceImpl *device, const CORBA::Any &in_any)
{
	cout2 << "ModifyClass::execute(): arrived" << endl;
	Tango::DevString argin;
	extract(in_any, argin);
	((static_cast<Alarm *>(device))->modify(argin));
	return new CORBA::Any();
}


//===================================================================
//	Properties management
//===================================================================
//--------------------------------------------------------
/**
 *	Method      : AlarmClass::get_class_property()
 *	Description : Get the class property for specified name.
 */
//--------------------------------------------------------
Tango::DbDatum AlarmClass::get_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_prop.size() ; i++)
		if (cl_prop[i].name == prop_name)
			return cl_prop[i];
	//	if not found, returns  an empty DbDatum
	return Tango::DbDatum(prop_name);
}

//--------------------------------------------------------
/**
 *	Method      : AlarmClass::get_default_device_property()
 *	Description : Return the default value for device property.
 */
//--------------------------------------------------------
Tango::DbDatum AlarmClass::get_default_device_property(string &prop_name)
{
	for (unsigned int i=0 ; i<dev_def_prop.size() ; i++)
		if (dev_def_prop[i].name == prop_name)
			return dev_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}

//--------------------------------------------------------
/**
 *	Method      : AlarmClass::get_default_class_property()
 *	Description : Return the default value for class property.
 */
//--------------------------------------------------------
Tango::DbDatum AlarmClass::get_default_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_def_prop.size() ; i++)
		if (cl_def_prop[i].name == prop_name)
			return cl_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}


//--------------------------------------------------------
/**
 *	Method      : AlarmClass::set_default_property()
 *	Description : Set default property (class and device) for wizard.
 *                For each property, add to wizard property name and description.
 *                If default value has been set, add it to wizard property and
 *                store it in a DbDatum.
 */
//--------------------------------------------------------
void AlarmClass::set_default_property()
{
	string	prop_name;
	string	prop_desc;
	string	prop_def;
	vector<string>	vect_data;

	//	Set Default Class Properties

	//	Set Default device Properties
	prop_name = "AlarmStatus";
	prop_desc = "Persistent storage of the alarms status";
	prop_def  = "";
	vect_data.clear();
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "GroupNames";
	prop_desc = "Labels for Group mask, first is for mask 0x00";
	prop_def  = "";
	vect_data.clear();
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "ErrThreshold";
	prop_desc = "Threshold for Tango error for being internal alarms";
	prop_def  = "";
	vect_data.clear();
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "DbHost";
	prop_desc = "Host of the MySQL db";
	prop_def  = "";
	vect_data.clear();
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "DbUser";
	prop_desc = "Username for the MySQL db";
	prop_def  = "";
	vect_data.clear();
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "DbPasswd";
	prop_desc = "Password for the MySQL db";
	prop_def  = "";
	vect_data.clear();
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "DbName";
	prop_desc = "Db name for the MySQL db";
	prop_def  = "";
	vect_data.clear();
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "DbPort";
	prop_desc = "Port of the MySQL db";
	prop_def  = "";
	vect_data.clear();
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "InstanceName";
	prop_desc = "Name used to associate configured alarm rules to this instance";
	prop_def  = "";
	vect_data.clear();
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "SubscribeRetryPeriod";
	prop_desc = "retry period in seconds";
	prop_def  = "";
	vect_data.clear();
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
}

//--------------------------------------------------------
/**
 *	Method      : AlarmClass::write_class_property()
 *	Description : Set class description fields as property in database
 */
//--------------------------------------------------------
void AlarmClass::write_class_property()
{
	//	First time, check if database used
	if (Tango::Util::_UseDb == false)
		return;

	Tango::DbData	data;
	string	classname = get_name();
	string	header;
	string::size_type	start, end;

	//	Put title
	Tango::DbDatum	title("ProjectTitle");
	string	str_title("Elettra alarm device server");
	title << str_title;
	data.push_back(title);

	//	Put Description
	Tango::DbDatum	description("Description");
	vector<string>	str_desc;
	str_desc.push_back("Elettra alarm device server");
	description << str_desc;
	data.push_back(description);

	//	put cvs or svn location
	string	filename("Alarm");
	filename += "Class.cpp";

	// check for cvs information
	string	src_path(CvsPath);
	start = src_path.find("/");
	if (start!=string::npos)
	{
		end   = src_path.find(filename);
		if (end>start)
		{
			string	strloc = src_path.substr(start, end-start);
			//	Check if specific repository
			start = strloc.find("/cvsroot/");
			if (start!=string::npos && start>0)
			{
				string	repository = strloc.substr(0, start);
				if (repository.find("/segfs/")!=string::npos)
					strloc = "ESRF:" + strloc.substr(start, strloc.length()-start);
			}
			Tango::DbDatum	cvs_loc("cvs_location");
			cvs_loc << strloc;
			data.push_back(cvs_loc);
		}
	}

	// check for svn information
	else
	{
		string	src_path(SvnPath);
		start = src_path.find("://");
		if (start!=string::npos)
		{
			end = src_path.find(filename);
			if (end>start)
			{
				header = "$HeadURL: ";
				start = header.length();
				string	strloc = src_path.substr(start, (end-start));
				
				Tango::DbDatum	svn_loc("svn_location");
				svn_loc << strloc;
				data.push_back(svn_loc);
			}
		}
	}

	//	Get CVS or SVN revision tag
	
	// CVS tag
	string	tagname(TagName);
	header = "$Name: ";
	start = header.length();
	string	endstr(" $");
	
	end   = tagname.find(endstr);
	if (end!=string::npos && end>start)
	{
		string	strtag = tagname.substr(start, end-start);
		Tango::DbDatum	cvs_tag("cvs_tag");
		cvs_tag << strtag;
		data.push_back(cvs_tag);
	}
	
	// SVN tag
	string	svnpath(SvnPath);
	header = "$HeadURL: ";
	start = header.length();
	
	end   = svnpath.find(endstr);
	if (end!=string::npos && end>start)
	{
		string	strloc = svnpath.substr(start, end-start);
		
		string tagstr ("/tags/");
		start = strloc.find(tagstr);
		if ( start!=string::npos )
		{
			start = start + tagstr.length();
			end   = strloc.find(filename);
			string	strtag = strloc.substr(start, end-start-1);
			
			Tango::DbDatum	svn_tag("svn_tag");
			svn_tag << strtag;
			data.push_back(svn_tag);
		}
	}

	//	Get URL location
	string	httpServ(HttpServer);
	if (httpServ.length()>0)
	{
		Tango::DbDatum	db_doc_url("doc_url");
		db_doc_url << httpServ;
		data.push_back(db_doc_url);
	}

	//  Put inheritance
	Tango::DbDatum	inher_datum("InheritedFrom");
	vector<string> inheritance;
	inheritance.push_back("TANGO_BASE_CLASS");
	inher_datum << inheritance;
	data.push_back(inher_datum);

	//	Call database and and values
	get_db_class()->put_property(data);
}

//===================================================================
//	Factory methods
//===================================================================

//--------------------------------------------------------
/**
 *	Method      : AlarmClass::device_factory()
 *	Description : Create the device object(s)
 *                and store them in the device list
 */
//--------------------------------------------------------
void AlarmClass::device_factory(const Tango::DevVarStringArray *devlist_ptr)
{
	/*----- PROTECTED REGION ID(AlarmClass::device_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	AlarmClass::device_factory_before

	//	Create devices and add it into the device list
	for (unsigned long i=0 ; i<devlist_ptr->length() ; i++)
	{
		cout4 << "Device name : " << (*devlist_ptr)[i].in() << endl;
		device_list.push_back(new Alarm(this, (*devlist_ptr)[i]));
	}

	//	Manage dynamic attributes if any
	erase_dynamic_attributes(devlist_ptr, get_class_attr()->get_attr_list());

	//	Export devices to the outside world
	for (unsigned long i=1 ; i<=devlist_ptr->length() ; i++)
	{
		//	Add dynamic attributes if any
		Alarm *dev = static_cast<Alarm *>(device_list[device_list.size()-i]);
		dev->add_dynamic_attributes();

		//	Check before if database used.
		if ((Tango::Util::_UseDb == true) && (Tango::Util::_FileDb == false))
			export_device(dev);
		else
			export_device(dev, dev->get_name().c_str());
	}

	/*----- PROTECTED REGION ID(AlarmClass::device_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	AlarmClass::device_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : AlarmClass::attribute_factory()
 *	Description : Create the attribute object(s)
 *                and store them in the attribute list
 */
//--------------------------------------------------------
void AlarmClass::attribute_factory(vector<Tango::Attr *> &att_list)
{
	/*----- PROTECTED REGION ID(AlarmClass::attribute_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	AlarmClass::attribute_factory_before
	//	Attribute : alarm
	alarmAttrib	*alarm = new alarmAttrib();
	Tango::UserDefaultAttrProp	alarm_prop;
	//	description	not set for alarm
	//	label	not set for alarm
	//	unit	not set for alarm
	//	standard_unit	not set for alarm
	//	display_unit	not set for alarm
	//	format	not set for alarm
	//	max_value	not set for alarm
	//	min_value	not set for alarm
	//	max_alarm	not set for alarm
	//	min_alarm	not set for alarm
	//	max_warning	not set for alarm
	//	min_warning	not set for alarm
	//	delta_t	not set for alarm
	//	delta_val	not set for alarm
	
	alarm->set_default_properties(alarm_prop);
	//	Not Polled
	alarm->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(alarm);


	//	Create a list of static attributes
	create_static_attribute_list(get_class_attr()->get_attr_list());
	/*----- PROTECTED REGION ID(AlarmClass::attribute_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	AlarmClass::attribute_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : AlarmClass::pipe_factory()
 *	Description : Create the pipe object(s)
 *                and store them in the pipe list
 */
//--------------------------------------------------------
void AlarmClass::pipe_factory()
{
	/*----- PROTECTED REGION ID(AlarmClass::pipe_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	AlarmClass::pipe_factory_before
	/*----- PROTECTED REGION ID(AlarmClass::pipe_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	AlarmClass::pipe_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : AlarmClass::command_factory()
 *	Description : Create the command object(s)
 *                and store them in the command list
 */
//--------------------------------------------------------
void AlarmClass::command_factory()
{
	/*----- PROTECTED REGION ID(AlarmClass::command_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	AlarmClass::command_factory_before


	//	Command Ack
	AckClass	*pAckCmd =
		new AckClass("Ack",
			Tango::DEVVAR_STRINGARRAY, Tango::DEV_VOID,
			"String array containing the alarms to be acknowledged",
			"",
			Tango::OPERATOR);
	command_list.push_back(pAckCmd);

	//	Command Load
	LoadClass	*pLoadCmd =
		new LoadClass("Load",
			Tango::DEV_STRING, Tango::DEV_VOID,
			"Alarm entry",
			"",
			Tango::OPERATOR);
	command_list.push_back(pLoadCmd);

	//	Command Remove
	RemoveClass	*pRemoveCmd =
		new RemoveClass("Remove",
			Tango::DEV_STRING, Tango::DEV_VOID,
			"Alarm name",
			"",
			Tango::OPERATOR);
	command_list.push_back(pRemoveCmd);

	//	Command Configured
	ConfiguredClass	*pConfiguredCmd =
		new ConfiguredClass("Configured",
			Tango::DEV_STRING, Tango::DEVVAR_STRINGARRAY,
			"String containing a filter for output, if empty return all alarms",
			"Alarms configured",
			Tango::OPERATOR);
	command_list.push_back(pConfiguredCmd);

	//	Command StopNew
	StopNewClass	*pStopNewCmd =
		new StopNewClass("StopNew",
			Tango::DEV_VOID, Tango::DEV_VOID,
			"",
			"",
			Tango::OPERATOR);
	command_list.push_back(pStopNewCmd);

	//	Command Silence
	SilenceClass	*pSilenceCmd =
		new SilenceClass("Silence",
			Tango::DEVVAR_STRINGARRAY, Tango::DEV_VOID,
			"String array containing the alarms to be silenced",
			"",
			Tango::OPERATOR);
	command_list.push_back(pSilenceCmd);

	//	Command Modify
	ModifyClass	*pModifyCmd =
		new ModifyClass("Modify",
			Tango::DEV_STRING, Tango::DEV_VOID,
			"Alarm entry",
			"",
			Tango::OPERATOR);
	command_list.push_back(pModifyCmd);

	/*----- PROTECTED REGION ID(AlarmClass::command_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	AlarmClass::command_factory_after
}

//===================================================================
//	Dynamic attributes related methods
//===================================================================

//--------------------------------------------------------
/**
 * method : 		AlarmClass::create_static_attribute_list
 * description : 	Create the a list of static attributes
 *
 * @param	att_list	the ceated attribute list
 */
//--------------------------------------------------------
void AlarmClass::create_static_attribute_list(vector<Tango::Attr *> &att_list)
{
	for (unsigned long i=0 ; i<att_list.size() ; i++)
	{
		string att_name(att_list[i]->get_name());
		transform(att_name.begin(), att_name.end(), att_name.begin(), ::tolower);
		defaultAttList.push_back(att_name);
	}

	cout2 << defaultAttList.size() << " attributes in default list" << endl;

	/*----- PROTECTED REGION ID(AlarmClass::create_static_att_list) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AlarmClass::create_static_att_list
}


//--------------------------------------------------------
/**
 * method : 		AlarmClass::erase_dynamic_attributes
 * description : 	delete the dynamic attributes if any.
 *
 * @param	devlist_ptr	the device list pointer
 * @param	list of all attributes
 */
//--------------------------------------------------------
void AlarmClass::erase_dynamic_attributes(const Tango::DevVarStringArray *devlist_ptr, vector<Tango::Attr *> &att_list)
{
	Tango::Util *tg = Tango::Util::instance();

	for (unsigned long i=0 ; i<devlist_ptr->length() ; i++)
	{
		Tango::DeviceImpl *dev_impl = tg->get_device_by_name(((string)(*devlist_ptr)[i]).c_str());
		Alarm *dev = static_cast<Alarm *> (dev_impl);

		vector<Tango::Attribute *> &dev_att_list = dev->get_device_attr()->get_attribute_list();
		vector<Tango::Attribute *>::iterator ite_att;
		for (ite_att=dev_att_list.begin() ; ite_att != dev_att_list.end() ; ++ite_att)
		{
			string att_name((*ite_att)->get_name_lower());
			if ((att_name == "state") || (att_name == "status"))
				continue;
			vector<string>::iterator ite_str = find(defaultAttList.begin(), defaultAttList.end(), att_name);
			if (ite_str == defaultAttList.end())
			{
				cout2 << att_name << " is a UNWANTED dynamic attribute for device " << (*devlist_ptr)[i] << endl;
				Tango::Attribute &att = dev->get_device_attr()->get_attr_by_name(att_name.c_str());
				dev->remove_attribute(att_list[att.get_attr_idx()], true, false);
				--ite_att;
			}
		}
	}
	/*----- PROTECTED REGION ID(AlarmClass::erase_dynamic_attributes) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	AlarmClass::erase_dynamic_attributes
}

//--------------------------------------------------------
/**
 *	Method      : AlarmClass::get_attr_by_name()
 *	Description : returns Tango::Attr * object found by name
 */
//--------------------------------------------------------
Tango::Attr *AlarmClass::get_attr_object_by_name(vector<Tango::Attr *> &att_list, string attname)
{
	vector<Tango::Attr *>::iterator it;
	for (it=att_list.begin() ; it<att_list.end() ; ++it)
		if ((*it)->get_name()==attname)
			return (*it);
	//	Attr does not exist
	return NULL;
}


/*----- PROTECTED REGION ID(AlarmClass::Additional Methods) ENABLED START -----*/

/*----- PROTECTED REGION END -----*/	//	AlarmClass::Additional Methods
} //	namespace
