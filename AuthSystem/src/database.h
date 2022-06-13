#pragma once
#include <map>
#include <string>
#include <iostream>

class DataBase
{
private:
	std::string path;
	std::map<std::string, std::string> database;
public:
	DataBase() {};
	DataBase(std::string path)
		:
		path(path) {};
	~DataBase() {};
	friend class System;
private:
	DataBase(const DataBase&) = delete;
	DataBase operator=(const DataBase&) = delete;
private:
	void setPath(std::string path);
private:
	void importData();
	void exportData();
	void exportData(std::string path);
	void printData();
};