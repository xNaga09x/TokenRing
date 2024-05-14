#pragma once
#include <string>
#include <iostream>

class Computer
{
public:
	Computer();
	Computer(const std::string& IP, const std::string& buffer);
	~Computer();

	const std::string getIP();
	const std::string getBuffer();

	void setIP(const std::string& ip);
	void setBuffer(const std::string& buffer);
private:
	std::string m_IP;
	std::string m_buffer;
};

