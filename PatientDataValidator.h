#pragma once
#include "FileLogger.h"
class CPatientDataValidator
{
public:
	
	CPatientDataValidator();
	CFileLogger *fileErrorLogger = new CFileLogger();
	~CPatientDataValidator();
};

