//
//  Log.cpp
//  Log.cpp with a capital L
//
//
//  Created by Thomas Lessard on 2020-03-02.
//


#define LOG_INFO 1
#define LOG_WARN 2
#define LOG_ERROR 3
#define LOG_CRITICAL 4

#define LOG_LEVEL 0 //LOG_INFO //LOG_WARN //LOG_ERROR



#include "Log.h"

#include <iostream>
#include <time.h>
#include <stdio.h>



/*void Log::Init(std::ofstream &logFile)
{
	m_LogFile = logFile;
	m_LogFile.open("log/debug.log", std::ios::out);
}*/

void Log::Critical(const char* msg, unsigned int error)
{
	std::cerr << "["<< Log::GetTime() << "] CRITICAL ERROR: " << msg << " [Error : " << error << "]" <<'\n';
	Log::WriteLog(LOG_CRITICAL, msg, error);
	exit(error);
}

void Log::Error(const char* msg)
{
	if (LOG_LEVEL < LOG_ERROR)
	{
		std::cerr << "["<< Log::GetTime() << "] ERROR: " << msg << '\n';
		Log::WriteLog(LOG_ERROR, msg);
	}
}

void Log::Warn(const char* msg)
{
	if (LOG_LEVEL < LOG_WARN)
	{
		std::cerr << "["<< Log::GetTime() << "] WARN: " << msg << '\n';
		Log::WriteLog(LOG_WARN, msg);
	}
}

void Log::Info(const char* msg)
{
	if (LOG_LEVEL < LOG_INFO)
	{
		std::cerr << "["<< Log::GetTime() << "] INFO: " << msg << '\n';
		Log::WriteLog(LOG_INFO, msg);
	}
}

void Log::WriteLog(const int logLevel, const char* msg, unsigned int error)
{
	/*if(!m_LogFile)
		Log::Error("Log file not created or unuseable");
	else
	{
		switch (logLevel)
		{
			case LOG_INFO:
				m_LogFile << "["<< Log::GetTime() << "] INFO: " << msg << "\n";
				break;
			case LOG_WARN:
				m_LogFile << "["<< Log::GetTime() << "] WARN: " << msg << "\n";
				break;
			case LOG_ERROR:
				m_LogFile << "["<< Log::GetTime() << "] ERROR: " << msg << "\n";
				break;
			case LOG_CRITICAL:
				m_LogFile << "["<< Log::GetTime() << "] CRITICAL ERROR: " << msg << " [Error : " << error << "]" <<'\n';
				break;
		}
	}*/
}

const std::string Log::GetTime()
{
	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

	return buf;
}
