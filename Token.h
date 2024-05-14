#pragma once
#include <string>

class Token
{
public:
	Token();
	Token(const std::string& sourceIP, const std::string& destinationIp, const std::string& message, const bool& occupied, const bool& arrived);
	~Token();

	const std::string getSourceIP();
	const std::string getDestinationIP();
	const std::string getMessage();
	const bool getOcuppied();
	const bool getArrived();

	void setSourceIP(const std::string& ip);
	void setDestinationIP(const std::string& ip);
	void setMessage(const std::string& message);
	void setOccupied(const bool& state);
	void setArrived(const bool& state);
private:
	std::string m_sourceIP;
	std::string m_destinationIP;
	std::string m_message;
	bool m_occupied;
	bool m_arrived;
};

