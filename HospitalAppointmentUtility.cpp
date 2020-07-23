// HospitalAppointmentUtility.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Appointment
{
private:
	string status[3] = {"Confirmed", "Pending", "Cancelled" };


public:
	void GetAppointmentStatus()
	{
		// Gives appointment status according to the Hospital policy
	}
	
};

class IAppointmentStatusObserver
{
public:
	virtual void NotifyAppointmentStatus(string) = 0;
};

class PatientNotifier  : public IAppointmentStatusObserver
{
	string appointmentStatus;

	void NotifyAppointmentStatus(string appointStatus)
	{
		this->appointmentStatus = appointmentStatus;

		cout << "Sends an SMS to the Patient about the appointment status...";
	}

};

class DoctorNotifier : public IAppointmentStatusObserver
{
	string appointmentStatus;

	void NotifyAppointmentStatus(string appointStatus)
	{
		this->appointmentStatus = appointmentStatus;

		cout << "Sends an SMS to the Doctor about the appointment status...";
	}

};

class DigitalDisplayNotifier : public IAppointmentStatusObserver
{
	string appointmentStatus;

	void NotifyAppointmentStatus(string appointStatus)
	{
		this->appointmentStatus = appointmentStatus;

		cout << "Sends info to the digital display of the hospital about the appointment status...";
	}

};

class HospitalAppointmentManager 
{

	vector<IAppointmentStatusObserver> listOfNotifier;

public:
	void Subscribe( )
	{

		//Add all the notifier objects for subscription
		//listOfNotifier.push_back("patientNotifier");
		//listOfNotifier.push_back("DoctorNotifier");
		//listOfNotifier.push_back("DisplayNotifier");
	}

	void Unsubscribe()
	{
		// remove the requested object out of list
	}


	void NotifyAppointmentStatus(string sAppointmentStatus)
	{
		for (vector<IAppointmentStatusObserver>::const_iterator iter = listOfNotifier.begin(); iter != listOfNotifier.end(); iter++)
		{
			cout << "Send the appointment status to all the list of notifiers";
			// *iter-> NotifyAppointmentStatus(sAppointmentStatus);
		}
	}

};

class UpdateAppointmentInfo : public HospitalAppointmentManager
{

public:

	void UpdateAppointmentStatus(string sAppointmentStatus)
	{
		NotifyAppointmentStatus(sAppointmentStatus);
	}

};

int main()
{

	PatientNotifier patientNotify;
	DoctorNotifier  doctorNotify;
	DigitalDisplayNotifier digDisplayNotify;



	UpdateAppointmentInfo updAppInfo;

	updAppInfo.Subscribe(patientNotify);
	updAppInfo.Subscribe(doctorNotify);
	updAppInfo.Subscribe(digDisplayNotify);

	updAppInfo.UpdateAppointmentStatus("Confirmed");
    return 0;
}

