#pragma once
#include <string>


// {1}/Users/{2}/AppData/Local/Packages/Microsoft.Windows.ContentDeliveryManager_cw5n1h2txyewy/LocalState/Assets
// drive + dir_1 + username + dir_2 

const std::string DIR_1 = "/Users/";
const std::string DIR_2 = "/AppData/Local/Packages/Microsoft.Windows.ContentDeliveryManager_cw5n1h2txyewy/LocalState/Assets";
const std::string DEST_DEFAULT_1 = "/Users/";
const std::string DEST_DEFAULT_2 = "/Desktop/spotlight";
const std::string SLASH = "/";
const std::string EXTENSION_JPG = ".jpg";
//C: / Users / jmlim / Desktop / myFolder

enum exit_code {
	SUCCESS = 0,
	INVALID_SOURCE_DIR = -1,
	INVALID_TARGET_DIR = -2,
	INSUFFICIENT_ARG = -3
};

enum named_constants {
	EXPECTED_ARG = 2,
	MINIMUM_FILE_SIZE = 50000,
};
