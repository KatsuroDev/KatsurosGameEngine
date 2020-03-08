//
//  Log.cpp with a capital L
//
//
//  Created by Thomas Lessard on 2020-03-02.
//

#include "Log.h"

#include <iostream>

void Log::Critical(const char* msg, unsigned int error)
{
	std::cerr << "ERROR: " << msg << '\n';
	exit(error);
}

void Log::Error(const char* msg)
{
	//if (m_LogLevel < Log::LogLevel::LogCritical)
		std::cerr << "ERROR: " << msg << '\n';
}

void Log::Warn(const char* msg)
{
	//if (m_LogLevel < Log::LogLevel::LogError)
		std::cerr << "WARN: " << msg << '\n';
}

void Log::Info(const char* msg)
{
	//if (m_LogLevel < Log::LogLevel::LogWarn)
		std::cerr << "INFO: " << msg << '\n';
}
