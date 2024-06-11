#ifndef TLC_PCH_H
#define TLC_PCH_H

#include <windows.h>

#include <cassert>
#include <cinttypes>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <atomic>
#include <chrono>
#include <deque>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <memory>
#include <mutex>
#include <optional>
#include <sstream>
#include <stack>
#include <string>
#include <thread>
#include <type_traits>
#include <unordered_map>
#include <vector>
#include <variant>
#include <utility>

#define TLC_WIDE_IMPL(str) L ## str
#define TLC_WIDE(str) TLC_WIDE_IMPL(str)

#define TLC_STRINGIZE_IMPL(x) #x
#define TLC_STRINGIZE(x) TLC_STRINGIZE_IMPL(x)

#define TLC_NAME "TrafficLightController"

namespace tlc
{
    namespace fs = std::filesystem;
    inline std::atomic_bool g_Running = true;
}

#include "../../../external/ScriptHookV/include/types.h"
#include "../../../external/ScriptHookV/include/natives.hpp"
#include "../../../external/ScriptHookV/include/enums.h"
#include "../../../external/ScriptHookV/include/main.h"

#include "Logger.h"

#endif //TLC_PCH_H