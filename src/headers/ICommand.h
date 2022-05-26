#pragma once

class IComand
{
public:
    virtual void execute() = 0;
    virtual ~IComand() = default;
};
