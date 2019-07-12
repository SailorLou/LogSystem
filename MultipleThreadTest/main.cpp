
#include "Logger.h"

#include <log4cplus/configurator.h> //PropertyConfigurator::doConfigure
#include <iostream>
#include<string>
#include<thread>
#include <conio.h>
#include <iostream>
#include<fstream>

void main()
{
	log4cplus::PropertyConfigurator::doConfigure("logger.cfg");
	IMPLEMENT_LOGGER(main);

	std::fstream out;
	out.open("stdFileStream.txt",std::ios::app);
	if(!out.is_open()) {
		std::cout << "failed to open file" << std::endl;
	}

	// compare
	std::function<void()> threadFunc = [=]() {
		static int x = 0;// no thread-safty
		LOG_DEBUG("x=" <<++x << std::endl);
	};

	std::function<void()> threadFunc1 = [=, &out]() {
		static int x = 0;// no thread-safty
		out <<"x=" << ++x << std::endl;
		//std::cout << "x=" << ++x << std::endl;
	};

	while(!_kbhit()) {
		//std::thread log(threadFunc);
		//log.detach();

		std::thread stdStream(threadFunc1);
		stdStream.detach();
	}

	out.close();

	getchar();
}
