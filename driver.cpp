// limsave.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "SaveInterface.h"
#include <iostream>
#include <string>
#include <memory>
using namespace std;

int main(int argc, char* argv[])
{
	// get drive code
	// https://stackoverflow.com/a/810281 
	// getenv is not safe, not thread-safe
	// https://stackoverflow.com/a/48573082


	// would be good to ask user where to store files. Need GUI for this option.. 
	unique_ptr<string> dest = make_unique<string>();
	bool isCustom = false;

	if (argc == EXPECTED_ARG) {
		isCustom = true;
		*dest = argv[1];
	}
	else if (argc == DEFAULT_ARG) {
		cout << "SAVING IMAGES TO DEFAULT LOCATION" << endl;
	}
	else if (argc > EXPECTED_ARG) {
		cout << argv[0] << "  <DESTINATION/DIRECTORY>" << endl;
		return INSUFFICIENT_ARG;
	}

	if (isCustom) {
		try {
			SaveInterface si(*dest);
			si.run();
		}
		catch (std::filesystem::filesystem_error & fe) {
			cout << fe.what() << endl;
			return INVALID_TARGET_DIR;
		}
		catch (InvalidSourceDirectoryException & ide) {
			cout << ide.what() << endl;
			return INVALID_SOURCE_DIR;
		}
	}
	else {
		try {
			SaveInterface si = SaveInterface();
			si.run();
		}
		catch (InvalidSourceDirectoryException & ide) {
			cout << ide.what() << endl;
			return INVALID_SOURCE_DIR;
		}
	}




	return SUCCESS;






}
