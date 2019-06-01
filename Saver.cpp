#include "Saver.h"
#include <ctime>
#include <sstream>
#include <iomanip>
#include <filesystem>

Saver::Saver(std::string p, std::filesystem::path d)
	:source(p), dest(d)
{
	// 3. Get today's Time
	// using localtime_s
	// https://stackoverflow.com/q/14386923
	std::time_t t = std::time(nullptr);
	struct tm timeinfo;
	localtime_s(&timeinfo, &t);
	std::ostringstream oss;
	oss << std::put_time(&timeinfo, "%m_%d_%Y_");

	today = oss.str();

}

std::filesystem::path Saver::getSource()
{
	return source;
}

std::filesystem::path Saver::getDestination()
{
	return dest;
}

std::string Saver::getToday()
{
	return today;
}
