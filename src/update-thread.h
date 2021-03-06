/*
 * alarm-thread.h
 *
 * $Author: graziano $
 *
 * $Revision: 1.1 $
 *
 * $Log: update-thread.h,v $
 * Revision 1.1  2008-11-10 10:54:09  graziano
 * thread for update of alarms with time threshold > 0
 *
 *
 *
 *
 * copyleft: Sincrotrone Trieste S.C.p.A. di interesse nazionale
 *           Strada Statale 14 - km 163,5 in AREA Science Park
 *           34012 Basovizza, Trieste ITALY
 */

#ifndef UPDATE_THREAD_H
#define UPDATE_THREAD_H

#include <omnithread.h>
#include <tango.h>
#include <AlarmHandler.h>

class update_thread : public omni_thread, public Tango::TangoMonitor, public Tango::LogAdapter {
	public:
		update_thread(AlarmHandler_ns::AlarmHandler *p);
		~update_thread();
	protected:
		void run(void *);
	private:
		void abort_sleep(double time);
		AlarmHandler_ns::AlarmHandler *p_Alarm;
};

#endif	/* UPDATE_THREAD_H */

/* EOF */
