//
//  Log.h
//
//
//  Created by Thomas Lessard on 2020-03-02.
//

#ifndef LOG_H
#define LOG_H


#include <string>
#include <fstream>

class Log
{
public:
	static void Init();

	static void Critical(const char* msg, unsigned int error);

	static void Error(const char* msg);

	static void Warn(const char* msg);

	static void Info(const char* msg);

	inline static std::ofstream& GetLogFile() {return m_LogFile;}



private:
	static void WriteLog(const int logLevel, const char* msg, unsigned int error = 0);
	static const std::string GetTime();
	static std::ofstream m_LogFile;

	/*
	enum LogLevel
	{
		LogInfo, LogWarn, LogError, LogCritical
	};

	static unsigned int m_LogLevel;
	*/
};

#endif /* LOG_H */
