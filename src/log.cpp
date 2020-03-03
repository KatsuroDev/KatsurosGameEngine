//
//  log.cpp
//
//
//  Created by Thomas Lessard on 2020-03-02.
//

#include "log.h"

#include <iostream>

void Log::Error(const char* msg)
{
    std::cout << "ERROR: " << msg << '\n';
}

void Log::Warn(const char* msg)
{
    std::cout << "WARN: " << msg << '\n';
}

void Log::Info(const char* msg)
{
    std::cout << "INFO: " << msg << '\n';
}
