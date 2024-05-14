#include "Computer.h"
#include "Token.h"
#include <array>
#include <stdlib.h>
#include <time.h>

void read(std::array<Computer,10>& computers)
{
	int i = 0;
	std::srand(std::time(nullptr));

	while (i < 10)
	{
		std::string IP="";
		for (int j = 0; j < 4; j++)
		{
			int random_number = rand() % 254 + 1;
			if (j < 3)
				IP += std::to_string(random_number) + ".";
			else
				IP += std::to_string(random_number);
		}
		computers[i].setIP(IP);
		++i;
	}
}

void print(std::array<Computer, 10>& computers)
{
	for (int i=0;i<computers.size();i++)
	{
		std::cout << "C" << i << "(" << computers[i].getIP() << ") -> " << computers[i].getBuffer()<<"\n";
	}
}

void generate(std::array<Computer, 10>& computers, Token& token)
{
	int source = rand() % 10 + 0;
	int destination = rand() % 10 + 0;
	//verificare ca sa nu fie aceeasi sursa/destinatie
	while(source==destination)
		destination = rand() % 10 + 0;

	for (int i = 0; i < computers.size(); i++)
		if (i == source)
		{
			std::cout << "Sursa: C" << i << " Destinatia: C";
			token.setSourceIP(computers[i].getIP());
		}
	for (int i = 0; i < computers.size(); i++)
		if (i == destination)
		{
			std::cout << i << "\n";
			token.setDestinationIP(computers[i].getIP());
		}
	token.setOccupied(true);
}

void step(std::array<Computer, 10>& computers, Token& token, const int& stepNo, int& pos)
{
	if (stepNo == 1)
	{
		pos = 0;
		for(int i=0;i<computers.size();i++)
			if (computers[i].getIP() == token.getSourceIP())
			{
				pos = i;
				std::cout << "C" << i << ": Muta jetonul\n";
			}
		for(int i=pos+1;i<computers.size();i++)
			if (computers[i].getIP() != token.getDestinationIP())
			{
				std::cout << "C" << i << ": Muta jetonul\n";
			}
			else
			{
				token.setArrived(true);
				std::cout << "C" << i << ": Am ajuns la destinatie\n";
				computers[i].setBuffer(computers[i].getBuffer()+";"+token.getMessage());
			}
		for (int i = 0; i <= pos; i++)
		{
			if (computers[i].getIP() != token.getDestinationIP() && computers[i].getIP() != token.getSourceIP())
			{
				std::cout << "C" << i << ": Muta jetonul\n";
			}
			if (computers[i].getIP() == token.getDestinationIP())
			{
				token.setArrived(true);
				std::cout << "C" << i << ": Am ajuns la destinatie\n";
				computers[i].setBuffer(computers[i].getBuffer() + ";" +token.getMessage());
			}
			if (computers[i].getIP() == token.getSourceIP())
			{
				token.setOccupied(false);
				token.setArrived(false);
				token.setDestinationIP("");
				token.setSourceIP("");
				std::cout << "C" << i << ": Am ajuns inapoi\n";
			}
		}
	}
	else
	{
		int auxpos = 10;
		for (int i = pos; i < computers.size(); i++)
		{
			if (computers[i].getIP() == token.getSourceIP())
			{
				std::cout << "C" << i << ": Am preluat jetonul\n";
				auxpos = i;
			}
			if (computers[i].getIP() != token.getDestinationIP())
			{
				std::cout << "C" << i << ": Muta jetonul\n";
			}
			else
			{
				if (auxpos < i)
				{
					token.setArrived(true);
					std::cout << "C" << i << ": Am ajuns la destinatie\n";
					computers[i].setBuffer(computers[i].getBuffer() + ";" + token.getMessage());
					pos = auxpos;
				}
				else
				{
					pos = 9;
					std::cout << "C" << i << ": Muta jetonul\n";
				}
			}
		}
		//pos = auxpos;
		for (int i = 0; i <= pos; i++)
		{
			if (computers[i].getIP() == token.getSourceIP())
			{
				if (!token.getArrived())
				{
					std::cout << "C" << i << ": Am preluat jetonul\n";
					auxpos = i;
				}
				else
				{
					std::cout << "C" << i << ": Am ajuns inapoi\n";
					token.setArrived(false);
					token.setOccupied(false);
					token.setSourceIP("");
					token.setDestinationIP("");
					pos = i;
				}
			}
			if (computers[i].getIP() != token.getDestinationIP())
			{
				if(token.getOcuppied())
				std::cout << "C" << i << ": Muta jetonul\n";
			}
			else
			{
				if (auxpos < 10)
				{
					token.setArrived(true);
					std::cout << "C" << i << ": Am ajuns la destinatie\n";
					computers[i].setBuffer(computers[i].getBuffer() + ";" + token.getMessage());
				}
			}
		}
		if (token.getOcuppied())
		{
			pos = auxpos;
			for (int i = 0; i <= pos; i++)
			{
				if (computers[i].getIP() == token.getSourceIP())
				{
					std::cout << "C" << i << ": Am ajuns inapoi\n";
					token.setArrived(false);
					token.setOccupied(false);
					token.setSourceIP("");
					token.setDestinationIP("");
				}
				if (computers[i].getIP() != token.getDestinationIP() && token.getOcuppied())
				{
					std::cout << "C" << i << ": Muta jetonul\n";
				}
			}
		}
	}
	print(computers);
}

void run(std::array<Computer, 10>& computers, Token& token)
{
	int stepNo = 0;
	int pos = 0;
	for (int i = 0; i < 10; i++)
	{
		++stepNo;
		generate(computers,token);
		step(computers, token, stepNo, pos);
	}
	std::cout << "Simulare terminata.";
}

int main()
{
	std::srand(std::time(nullptr));
	std::array<Computer, 10> computers;
	Token token;
	
	read(computers);
	print(computers);
	//generate(computers,token);
	run(computers, token);

	return 0;
}