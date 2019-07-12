#include "TestClass.h"
#include "Logger.h"

IMPLEMENT_LOGGER(TestClass);

TestClass::TestClass()
{
}


TestClass::~TestClass()
{
}

void TestClass::Test()
{
	LOG_TRACE("ConfigurationFile:this is a TRACE" << "message" << std::endl);
	LOG_DEBUG("ConfigurationFile:this is a DEBUG" << "message" << std::endl);
	LOG_INFO("ConfigurationFile:this is a INFO" << "message" << std::endl);
	LOG_WARN("ConfigurationFile:this is a WARN" << "message" << std::endl);
	LOG_ERROR("ConfigurationFile:this is a ERROR" << "message" << std::endl);
}
