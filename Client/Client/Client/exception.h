#pragma once
#include <iostream>
#include <exception>

using namespace std;

class excep : public exception {
public:
	virtual const char* what(const char* s) {
		return s;
	}
};
