#include "SaveBuilder.h"
#include <string>

std::shared_ptr<Saver> SaveBuilder::buildSaver(std::string userName, std::string code, std::filesystem::path dest) {
	
	path = code + DIR_1 + userName + DIR_2;

	mySaver = std::make_shared<Saver>(path, dest);

	return mySaver;
}

