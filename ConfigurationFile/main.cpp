
#include "Logger.h"

#include <log4cplus/configurator.h> //PropertyConfigurator::doConfigure
#include <iostream>
#include<string>

#include "TestClass.h"

void main()
{
	log4cplus::PropertyConfigurator::doConfigure("logger.cfg");


	IMPLEMENT_LOGGER(test);



	LOG_DEBUG("Main:filename" << __FILE__ << "line " << __LINE__ << "test debug");

	TestClass tester;
	tester.Test();

	getchar();
}
