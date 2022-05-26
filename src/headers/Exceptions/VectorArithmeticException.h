#pragma once

#include <string>
#include <stdexcept>

class VectorArithmeticException : public std::logic_error
{
private:
    std::string message;

public:
    VectorArithmeticException(std::string operation, int dimA, int dimB);

    const char *what() const noexcept;

    ~VectorArithmeticException() = default;
};
