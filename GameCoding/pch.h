#pragma once

#include <windows.h>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include "Defines.h"
#include "Types.h"
#include "Enum.h"
#include <format>
using namespace std;

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif