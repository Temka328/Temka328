#pragma once

#include "gmock/gmock.h"
#include "../../src/headers/Capabilities/IState.h"

#include <string>

class Moke_IState : public IState
{
public:
    MOCK_METHOD(void, set_state, (std::string state), (override));
};
