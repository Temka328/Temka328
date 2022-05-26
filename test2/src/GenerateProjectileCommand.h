#pragma once

#include "ICommand.h"
#include "IShootable.h"
#include "IObject.h"
#include "IFactory.h"
#include "IncorrectCommandException.h"

#include <map>
#include <memory>

class GenerateProjectileCommand : public IComand
{
private:
    IShootable &shoot;
    std::unique_ptr<IObject> &container;
    IFactory &factory;

public:
    GenerateProjectileCommand(IShootable &iShoot, std::unique_ptr<IObject> &returnRef, IFactory &f) : shoot(iShoot), container(returnRef), factory(f){};

    void execute()
    {
        if (!shoot.get_isShootable())
            throw IncorrectCommandException("This object can't shoot");
        container = factory.create_game_object(
            { 
                {"speed", shoot.get_projectile_speed()},
                {"direction", shoot.get_direction()},
                {"position", shoot.get_projectile_start_point()} 
            }
        );
    }
};
