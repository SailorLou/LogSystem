#ifndef MYLOGGERHEAD
#define MYLOGGERHEAD

#include <log4cplus/logger.h>
#include <log4cplus/configurator.h>
#include <log4cplus/layout.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/helpers/stringhelper.h>

#define MY_LOG_FILE_PATH "logger.cfg"

class MyLogger
{
private:
	MyLogger()
	{
		log4cplus::initialize();
		log4cplus::PropertyConfigurator::doConfigure(LOG4CPLUS_TEXT(MY_LOG_FILE_PATH));

		m_rootLog = log4cplus::Logger::getRoot();
	}
	~MyLogger()
	{
		if(m_logger) {
			delete m_logger;
		}
	}


	static MyLogger* m_logger;

public:
	static MyLogger * getInstance()
	{
		if(m_logger == nullptr) {
			m_logger = new MyLogger();
		}
		return m_logger;
	}

	log4cplus::Logger m_rootLog;

};

MyLogger* MyLogger::m_logger = nullptr;

#endif