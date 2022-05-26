#pragma once

#include <string>
#include <stdexcept>

class ObjectPropertyException : public std::invalid_argument
{
private:
    std::string message;

public:
    ObjectPropertyException(std::string error) : invalid_argument(error), message(error){};

    const char *what() const noexcept;
};
