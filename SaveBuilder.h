#pragma once
#include "Commons.h"
#include "Saver.h"
#include <filesystem>
#include <string>
#include <memory>
class SaveBuilder {
public:
	std::string username;
	std::string driveCode;
	std::string path;
	
	virtual std::shared_ptr<Saver> buildSaver(std::string userName, std::string code, std::filesystem::path dest);

protected:
	std::shared_ptr<Saver> mySaver;
};

