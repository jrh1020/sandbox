// stdafx.cpp : source file that includes just the standard includes
// ConsoleApplication3.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

void OutputDebugString(std::string s) {
	OutputDebugString(s.c_str());
	OutputDebugString("\n");
}
