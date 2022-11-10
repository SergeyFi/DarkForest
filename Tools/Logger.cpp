#include "Logger.h"
#include <iostream>

void Logger::Print(const std::string& Message, LogType Type)
{
    std::string Prefix;
    Prefix = "Log";

    if (Type == LogType::Warning)
    {
        Prefix = "Warning";
    }
    else if (Type == LogType::Error)
    {
        Prefix = "Error";
    }

    std::cout << Prefix << ": " << Message << std::endl;
}
