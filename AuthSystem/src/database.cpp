#include "database.h"
#include "cipher.h"
#include <sstream>
#include <fstream>

void DataBase::setPath(std::string path)
{
	this->path = path;
}

void DataBase::importData()
{	
	std::fstream file;
	file.open(path, std::fstream::in);
	std::string data;
	std::string username, password, item;
	while (file >> data)
	{
		data = Cipher::decode(data);
		std::stringstream ss(data);
		int i = 0;
		while (std::getline(ss, item, ':'))
		{
			if ((i & 1) == 0)
			{
				username = item;
			}
			else
			{
				password = item;
			}
			i++;
		}
		database.insert(std::make_pair(username, password));
	}
	file.close();
}

void DataBase::exportData()
{
	std::fstream file;
	file.open(path, std::fstream::out);
	for (const auto& e : database)
	{
		file << Cipher::encode(e.first) << ":" << Cipher::encode(e.second) << std::endl;
	}
	file.close();	
}

void DataBase::exportData(std::string path)
{
	std::fstream file;
	file.open(path, std::fstream::out);
	for (const auto& e : database)
	{
		file << Cipher::encode(e.first) << ":" << Cipher::encode(e.second) << std::endl;
	}
	file.close();
}

void DataBase::printData()
{
	for (const auto& e : database)
	{
		std::cout << "*---------------------------------------*" << std::endl;
		std::cout << "Username: " << e.first << std::endl;
		std::cout << "Password: " << e.second << std::endl;
		std::cout << "*---------------------------------------*" << std::endl;
	}
}