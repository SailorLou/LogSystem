#include <log4cplus/logger.h>
#include <log4cplus/consoleappender.h>
#include <log4cplus/layout.h>
#include <log4cplus/ndc.h>
#include <log4cplus/mdc.h>
#include <log4cplus/helpers/loglog.h>
#include <log4cplus/thread/threads.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/fileappender.h>
#include <log4cplus/filter.h>
#include <iostream>
#include <string>
#include<thread>

using namespace std;
using namespace log4cplus;
using namespace log4cplus::helpers;

int
main()
{
	// define appender
	SharedAppenderPtr pConsoleAppender(new ConsoleAppender());
	SharedAppenderPtr pFileAppender(new FileAppender("..\Basic_testfile.log"));
	SharedAppenderPtr pFileAppenderWithPattern(new FileAppender("..\Basic_pattern.log"));
	//SharedAppenderPtr rollingFile(new RollingFileAppender("..\Basic_rollingFile.log", 5 * 1024, 5));

	// define layout
	auto_ptr<Layout> pSimpleLayout(new SimpleLayout());
	pConsoleAppender->setLayout(pSimpleLayout);

	auto_ptr<Layout> pTTCLayout(new TTCCLayout());
	pFileAppender->setLayout(pTTCLayout);

	auto_ptr<Layout> pPatternLayout(new PatternLayout("%d{%m/%d/%y %H:%M:%S,%Q} [%t] %-5p %c{2} %%%x%% - %X{key} - %m [%l]%n"));
	pFileAppenderWithPattern->setLayout(pPatternLayout);

	// define Logger
	Logger rootLogger = Logger::getInstance("root");

	// Note£ºchildLogger is child of rootLogger and will inherit all appenders.
	Logger childLogger = Logger::getInstance("root.child");

	// attach appender to logger
	rootLogger.addAppender(pConsoleAppender);
	rootLogger.addAppender(pFileAppender);
	childLogger.addAppender(pFileAppenderWithPattern);

	//childLogger.setLogLevel(log4cplus::ALL_LOG_LEVEL);
	//rootLogger.setLogLevel(log4cplus::WARN_LOG_LEVEL);
	//
	childLogger.setLogLevel(log4cplus::ERROR_LOG_LEVEL);

	// Note : Regarding Filter ,code is difficult but configuration file is very easy
	// please refer to https://github.com/log4cplus/log4cplus/blob/master/tests/filter_test/log4cplus.properties.in
	//log4cplus::spi::FilterPtr loglevelFilter(new log4cplus::spi::LogLevelMatchFilter);
	//pFileAppenderWithPattern->setFilter(loglevelFilter);

	// print syslog
	LOG4CPLUS_WARN(rootLogger, "rootLogger:this is a warning message...");
	LOG4CPLUS_TRACE(Logger::getRoot(), "Logger::getRoot:this is a TRACE message...");

	LOG4CPLUS_DEBUG(childLogger, "childLogger:this is a DEBUG message...");
	LOG4CPLUS_INFO(childLogger, "childLogger:this is a INFO message...");
	LOG4CPLUS_ERROR(childLogger, "childLogger:this is a ERROR message...");
	LOG4CPLUS_FATAL(childLogger, "childLogger:this is a FATAL message...");

	getchar();

	return 0;
}
