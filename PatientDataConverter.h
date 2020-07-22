#pragma once
#include "PatientCSVDataReader.h"

class CPatientDataConverter
{
public:

	CPatientDataConverter();
	CPatientCSVDataReader *pPatientCSVdatareader = new CPatientCSVDataReader();
	~CPatientDataConverter();
};

