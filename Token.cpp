#include "Token.h"

Token::Token()
{
	m_sourceIP = "";
	m_destinationIP = "";
	m_message = "mesaj";
	m_occupied = false;
	m_arrived = false;
}

Token::Token(const std::string& sourceIP, const std::string& destinationIp, const std::string& message, const bool& occupied, const bool& arrived)
	:m_sourceIP(sourceIP), m_destinationIP(destinationIp), m_message(message), m_occupied(occupied), m_arrived(arrived)
{}

Token::~Token(){}

const std::string Token::getSourceIP()
{
	return m_sourceIP;
}

const std::string Token::getDestinationIP()
{
	return m_destinationIP;
}

const std::string Token::getMessage()
{
	return m_message;
}

const bool Token::getOcuppied()
{
	return m_occupied;
}

const bool Token::getArrived()
{
	return m_arrived;
}

void Token::setSourceIP(const std::string& ip)
{
	m_sourceIP = ip;
}

void Token::setDestinationIP(const std::string& ip)
{
	m_destinationIP = ip;
}

void Token::setMessage(const std::string& message)
{
	m_message = message;
}

void Token::setOccupied(const bool& state)
{
	m_occupied = state;
}

void Token::setArrived(const bool& state)
{
	m_arrived = state;
}


