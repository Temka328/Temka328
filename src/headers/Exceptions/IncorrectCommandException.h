#pragma once

#include <stdexcept>
#include <string>

class IncorrectCommandException : public std::logic_error
{
private:
    std::string message;

public:
    IncorrectCommandException(std::string error) : logic_error(error), message(error){};

    const char *what() const noexcept;
};
