#pragma once
#include "FileHandler.h"

class CFileLogger
{

public:
	CFileHandler *fileHandler = new CFileHandler();
	CFileLogger();
	~CFileLogger();

};

