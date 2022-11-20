#pragma once
#include <string>

enum LogType
{
    Log,
    Warning,
    Error
};

class Logger
{
public:
    static void Print(const std::string& Message, LogType Type = LogType::Log);

private:
    Logger();
    ~Logger();
};
