#pragma once
#include "SaveBuilder.h"
#include "CustomExceptions.h"
#include <memory>
#include <string>
#include <ctime>
class SaveInterface {

	std::shared_ptr<SaveBuilder> builder;
	std::shared_ptr<Saver> saver;
	std::string today;

public:
	SaveInterface(std::string dest);
	SaveInterface();

	void run();

	


};