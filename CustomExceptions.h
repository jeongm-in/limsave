#pragma once
#include <iostream>
#include <exception>


class InvalidSourceDirectoryException : public std::exception {
public:
	const char* what() const throw() {
		return "Invalid Source Directory";
	}

};


class InvalidDestinationDirectoryException : public std::exception {
public:
	const char* what() const throw() {
		return "Invalid Destination Directory";
	}

};
