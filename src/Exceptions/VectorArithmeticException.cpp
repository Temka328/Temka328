#include "../headers/Exceptions/VectorArithmeticException.h"

VectorArithmeticException::VectorArithmeticException(std::string operation, int dimA, int dimB) : logic_error("bad operation")
{
    message = "Can't " + operation + " a vector of dimension " + std::to_string(dimA) + " with a vector of dimension " + std::to_string(dimB) + ".";
};

const char *VectorArithmeticException::what() const noexcept
{
    return message.c_str();
};
