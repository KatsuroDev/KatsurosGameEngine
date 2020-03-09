//
//  Log.h
//
//
//  Created by Thomas Lessard on 2020-03-02.
//

#ifndef LOG_H
#define LOG_H

class Log
{
public:
	static void Critical(const char* msg, unsigned int error);

	static void Error(const char* msg);

	static void Warn(const char* msg);

	static void Info(const char* msg);

private:
	/*
	enum LogLevel
	{
		LogInfo, LogWarn, LogError, LogCritical
	};

	static unsigned int m_LogLevel;
	*/
};

#endif /* LOG_H */
