#include "../headers/Exceptions/ObjectPropertyException.h"

const char *ObjectPropertyException::what() const noexcept
{
    return message.c_str();
};
