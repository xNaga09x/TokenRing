#include "Computer.h"

Computer::Computer()
{
	m_IP = "";
	m_buffer = "null";
}

Computer::Computer(const std::string& IP, const std::string& buffer)
	:m_IP(IP), m_buffer(buffer)
{
}

Computer::~Computer(){}

const std::string Computer::getIP()
{
	return m_IP;
}

const std::string Computer::getBuffer()
{
	return m_buffer;
}

void Computer::setIP(const std::string& ip)
{
	m_IP = ip;
}

void Computer::setBuffer(const std::string& buffer)
{
	m_buffer = buffer;
}
