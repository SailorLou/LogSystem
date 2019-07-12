#pragma once
#include <log4cplus/logger.h>
#include <log4cplus/helpers/loglog.h>
#include <log4cplus/loggingmacros.h>


#define IMPLEMENT_LOGGER(loggerName) static log4cplus::Logger logger = log4cplus::Logger::getInstance(#loggerName);


#define LOG_TRACE(msg) LOG4CPLUS_TRACE(logger, msg)
#define LOG_DEBUG(msg) LOG4CPLUS_DEBUG(logger, msg)
#define LOG_INFO(msg) LOG4CPLUS_INFO(logger, msg)
#define LOG_WARN(msg) LOG4CPLUS_WARN(logger, msg)
#define LOG_ERROR(msg) LOG4CPLUS_ERROR(logger, msg)

