#pragma once
class SysLogger
{
public:

	~SysLogger()= default;
	static SysLogger * GetInstance();

	void Debug();

private:
	SysLogger();
	SysLogger(const SysLogger&) =delete;
	SysLogger& operator=(const SysLogger&) = delete;

	static SysLogger* _instance;
};

