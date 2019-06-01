#pragma once
#include <string>
#include <filesystem>
class Saver {
	
protected:
	std::string source;
	std::filesystem::path dest;
	std::string today;

public:


	Saver(std::string p, std::filesystem::path d);
	std::filesystem::path getSource();
	std::filesystem::path getDestination();
	std::string getToday();

};