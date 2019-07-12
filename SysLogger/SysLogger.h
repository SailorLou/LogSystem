#pragma once
#include <string>
#include <log4cplus/logger.h>
#include <log4cplus/helpers/loglog.h>
#include <log4cplus/loggingmacros.h>
#include <map>

class SysLogger
{
public:

	~SysLogger()= default;
	static SysLogger * GetInstance();

	void Debug(std::string &message, const char * logger = __FILE__);
	void Warn(std::string &message, const char * logger = __FILE__);
	void Note(std::string &message, const char * logger = __FILE__);
	void Error(std::string &message, const char * logger = __FILE__);
	void Fatal(std::string &message, const char * logger = __FILE__);

private:
	bool AskLogger(const char * loggerName, log4cplus::Logger &logger);
	std::string ParseName(const char* logger);
	SysLogger();
	SysLogger(const SysLogger&) =delete;
	SysLogger& operator=(const SysLogger&) = delete;

	static SysLogger* _instance;
	std::map<std::string, log4cplus::Logger> _loggerMap;
};

