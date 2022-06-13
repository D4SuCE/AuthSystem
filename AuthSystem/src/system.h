#pragma once
#include "database.h"
#include <memory>

class System
{
private:
	std::string path;
	std::unique_ptr<DataBase> systemDB = std::make_unique<DataBase>(path);
public:
	System() {};
	System(std::string path)
		:
		path(path) {};
	~System();
private:
	System(const System&) = delete;
	System operator=(const System&) = delete;
private:
	bool validate(std::string username, std::string password);
	bool validate(std::string username);
public:
	void setPath(std::string path);
public:
	void importDB();
	void exportDB();
	void exportDB(std::string path);
	void printDB();
	bool IsImportedData();
public:
	void auth(std::string username, std::string password);
	void reg(std::string username, std::string password);
};