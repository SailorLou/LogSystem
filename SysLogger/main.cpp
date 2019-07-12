#include "SysLogger.h"

void main()
{
	std::string debug("this is DEBUG message");
	SysLogger::GetInstance()->Debug(debug,"MAIN");

	std::string warn("this is WARN message");
	SysLogger::GetInstance()->Warn(warn);

	std::string note("this is INFO message");
	SysLogger::GetInstance()->Note(note);

	std::string er("this is ERROR message");
	SysLogger::GetInstance()->Error(er);

	std::string fata("this is FATAL message");
	SysLogger::GetInstance()->Fatal(fata);

	getchar();
}