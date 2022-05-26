#include "../headers/Exceptions/IncorrectCommandException.h"

const char *IncorrectCommandException::what() const noexcept
{
    return message.c_str();
};
