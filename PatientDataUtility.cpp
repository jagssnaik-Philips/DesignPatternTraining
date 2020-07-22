// PatientDataUtility.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


class PatientDataRetrieverInterface
{
	
	public:

		virtual void GetPatientData() const = 0;
};

class PatientDataMRN : public PatientDataRetrieverInterface
{
	public:

		void GetPatientData() const override
		{
			cout << "Getting Patient Data by MRN";
		}
};

class PatientDataCity : public PatientDataRetrieverInterface
{
public:

	void GetPatientData() const override
	{
		cout << "Getting Patient Data by City";
	}
};

class PatientDataName: public PatientDataRetrieverInterface
{
public:

	void GetPatientData() const override
	{
		cout << "Getting Patient Data by Name";
	}
};

class PatientContext
{
	private:
		PatientDataRetrieverInterface *patientContext_;

	public:
		explicit PatientContext(PatientDataRetrieverInterface *patientContext) : patientContext_(patientContext)
		{
		}

		void SetPatientContext(PatientDataRetrieverInterface *patientContext)
		{
			patientContext_ = patientContext;
		}


		void GetPatientData() const
		{
			patientContext_->GetPatientData();
		}
};

int main()
{
	PatientDataMRN patientDataMRN;
	PatientDataCity patientDataCity;
	PatientDataName patientDataName;

	PatientContext patientContextMRN(&patientDataMRN);
	PatientContext patientContextCity(&patientDataCity);
	PatientContext patientContextName(&patientDataName);


	//patientContextMRN.GetPatientData(); // Retrieves PatientData By MRN
	//patientContextCity.GetPatientData(); // Retrieves PatientData By City
	//patientContextName.GetPatientData(); // Retrieves PatientData By NAme

	patientContextMRN.SetPatientContext(&patientDataMRN);
	patientContextMRN.GetPatientData();
	patientContextCity.SetPatientContext(&patientDataCity);
	patientContextCity.GetPatientData();
	patientContextName.SetPatientContext(&patientDataName);
	patientContextName.GetPatientData();



	return 0;
}