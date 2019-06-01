#include "SaveInterface.h"
#include "CustomExceptions.h"
#include "UtilityFunctions.h"
#include <windows.h>
#include <iostream>
#include <memory>
#include <filesystem>
#include <string>
#include <sstream>



SaveInterface::SaveInterface(std::string dest) {
	const std::filesystem::path destPath = std::filesystem::absolute(dest);
	if (std::filesystem::create_directory(destPath)) {
		std::cout << "DESTINATION CREATION SUCCESS" << std::endl;
	}
	else {
		std::cout << "DIR ALREADY EXISTS " << std::endl;
	}

	char* pValue;
	size_t len;

	// 1. Get systemdrive
	errno_t err = _dupenv_s(&pValue, &len, "SystemDrive");
	if (err || pValue == NULL) {
		throw InvalidSourceDirectoryException();
	}
	std::string driveCode(pValue);
	free(pValue);

	// 2. Get Username
	err = _dupenv_s(&pValue, &len, "USERNAME");
	if (err || pValue == NULL) {
		throw InvalidSourceDirectoryException();
	}

	std::string username(pValue);
	free(pValue);

	builder = std::make_shared<SaveBuilder>();
	saver = builder->buildSaver(username, driveCode, destPath);



}

SaveInterface::SaveInterface() {

	char* pValue;
	size_t len;

	// 1. Get systemdrive
	errno_t err = _dupenv_s(&pValue, &len, "SystemDrive");
	if (err || pValue == NULL) {
		throw InvalidSourceDirectoryException();
	}
	std::string driveCode(pValue);
	free(pValue);

	// 2. Get Username
	err = _dupenv_s(&pValue, &len, "USERNAME");
	if (err || pValue == NULL) {
		throw InvalidSourceDirectoryException();
	}

	std::string username(pValue);
	free(pValue);

	std::string destString = driveCode + DIR_1 + username + DEST_DEFAULT;

	const std::filesystem::path destPath = std::filesystem::absolute(destString);

	if (std::filesystem::create_directory(destPath)) {
		std::cout << "DESTINATION CREATION SUCCESS" << std::endl;
	}
	else {
		std::cout << "DIR ALREADY EXISTS " << std::endl;
	}


	builder = std::make_shared<SaveBuilder>();
	saver = builder->buildSaver(username, driveCode, destPath);



}


// https://stackoverflow.com/a/41305019
// https://stackoverflow.com/a/26293322
// https://en.cppreference.com/w/cpp/filesystem/directory_iterator

void SaveInterface::run() {
	if (!std::filesystem::is_directory(saver->getSource())) {
		throw InvalidSourceDirectoryException();
	}

	int count = 1;
	std::filesystem::path tempPath = saver->getDestination();
	std::filesystem::path& targetPath = tempPath;

	int width = 0;
	int height = 0;

	for (auto& p : std::filesystem::directory_iterator(saver->getSource())) {

		if (p.file_size() > MINIMUM_FILE_SIZE) {

			if (getJPEGWidth(width, height, p.path().u8string().c_str())) {


				if (width > height) {

					std::ostringstream oss;
					oss << saver->getToday() << count << EXTENSION_JPG;
					targetPath = saver->getDestination() / oss.str();

					if (std::filesystem::copy_file(p.path(), targetPath)) {
						std::cout << oss.str() << " Copied to DEST folder\n";
					}

					count++;
				}
			}


		}
	}

	std::cout << "Total " << (count - 1) << " Images copied!" << std::endl;
	std::string c = "explorer " + saver->getDestination().u8string();
	system(c.c_str());

}