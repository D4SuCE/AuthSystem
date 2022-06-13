#include "system.h"

System::~System()
{
	systemDB.reset();
}

void System::setPath(std::string path)
{
	this->path = path;
	systemDB->setPath(path);
}

bool System::IsImportedData()
{
	return !systemDB->database.empty();
}

void System::importDB()
{
	systemDB->importData();
}

bool System::validate(std::string username, std::string password)
{
	if (std::find_if(systemDB->database.begin(), systemDB->database.end(), [username, password](std::pair<std::string, std::string> data)
		{
			return data.first == username && data.second == password;
		}) != systemDB->database.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool System::validate(std::string username)
{
	if (std::find_if(systemDB->database.begin(), systemDB->database.end(), [username](std::pair<std::string, std::string> data)
		{
			return data.first == username;
		}) != systemDB->database.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void System::exportDB()
{
	if (IsImportedData())
	{
		systemDB->exportData();
	}
	else
	{
		std::cout << "Please import DataBase!" << std::endl;
	}
}

void System::exportDB(std::string path)
{
	if (IsImportedData())
	{
		systemDB->exportData(path);
	}
	else
	{
		std::cout << "Please import DataBase!" << std::endl;
	}
}

void System::printDB()
{
	if (IsImportedData())
	{
		systemDB->printData();
	}
	else
	{
		std::cout << "Please import DataBase!" << std::endl;
	}
}

void System::auth(std::string username, std::string password)
{
	if (IsImportedData())
	{
		if (validate(username, password))
		{
			std::cout << "Welcome Home, " << username << "!" << std::endl;
		}
		else
		{
			std::cout << "Incorrect username/password" << std::endl;
		}
	}
	else
	{
		std::cout << "Please import DataBase!" << std::endl;
	}
	
}

void System::reg(std::string username, std::string password)
{
	if (IsImportedData())
	{
		if (!validate(username))
		{
			systemDB->database.insert(std::make_pair(username, password));
			std::cout << "Account was created" << std::endl;
		}
		else
		{
			std::cout << "Username is already in use" << std::endl;
		}
	}
	else
	{
		std::cout << "Please import DataBase!" << std::endl;
	}
}