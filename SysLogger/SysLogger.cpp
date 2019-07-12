#include "SysLogger.h"
#include <log4cplus/configurator.h>

//SysLogger* SysLogger::_instance = new SysLogger;
SysLogger* SysLogger::_instance = nullptr;
SysLogger::SysLogger()
{
	log4cplus::PropertyConfigurator::doConfigure("logger.cfg");
}
//NO thread-safety
SysLogger *SysLogger::GetInstance()
{
	if(_instance == nullptr)
		_instance = new SysLogger;
	return _instance;

}

bool SysLogger::AskLogger(const char * loggerName, log4cplus::Logger &logger)
{
	if(loggerName == nullptr)
		return false;

	std::string fileName = ParseName(loggerName);
	if(fileName.empty())
		return false;

	if(_loggerMap.find(loggerName) == _loggerMap.end()) {
		_loggerMap[fileName] = log4cplus::Logger::getInstance(loggerName);
	}

	logger = _loggerMap[fileName];

	return true;
}

void SysLogger::Debug(std::string &message, const char * logger)
{
	log4cplus::Logger log;
	if(!AskLogger(logger, log))
		return;

	LOG4CPLUS_DEBUG(log, message.c_str());
}

std::string SysLogger::ParseName(const char* logger)
{
	if(logger == nullptr)
		return std::string();
	char drive[_MAX_DRIVE];
	char dir[_MAX_DIR];
	char fname[_MAX_FNAME];
	char ext[_MAX_EXT];

	_splitpath_s(logger, drive, dir, fname, ext);

	return std::string(fname);
}

void SysLogger::Warn(std::string &message, const char * logger)
{
	log4cplus::Logger log;
	if(!AskLogger(logger, log))
		return;

	LOG4CPLUS_WARN(log, message.c_str() << std::endl);
}
void SysLogger::Note(std::string &message, const char * logger)
{
	log4cplus::Logger log;
	if(!AskLogger(logger, log))
		return;

	LOG4CPLUS_INFO(log, message.c_str() << std::endl);
}
void SysLogger::Error(std::string &message, const char * logger)
{
	log4cplus::Logger log;
	if(!AskLogger(logger, log))
		return;

	LOG4CPLUS_ERROR(log, message.c_str()<<std::endl);
}
void SysLogger::Fatal(std::string &message, const char * logger)
{
	log4cplus::Logger log;
	if(!AskLogger(logger, log))
		return;

	LOG4CPLUS_FATAL(log, message.c_str() << std::endl);
}


