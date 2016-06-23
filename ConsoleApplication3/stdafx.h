// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#ifdef DEBUG_BUILD
#  define DEBUG(x) OutputDebugString(x)
#else
#  define DEBUG(x)
#endif

#include "targetver.h"

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cstdint>
#include <stdio.h>
#include <tchar.h>
#include <Windows.h>
#include <list>
#include <conio.h>

void OutputDebugString(std::string s);
