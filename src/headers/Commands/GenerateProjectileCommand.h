#pragma once

#include "../ICommand.h"
#include "../Capabilities/IShootable.h"
#include "../IObject.h"
#include "../Factories/IFactory.h"
#include "../Exceptions/IncorrectCommandException.h"

#include <map>
#include <memory>

template <typename T>
class GenerateProjectileCommand : public IComand
{
private:
    IShootable<T> &shoot;
    std::unique_ptr<IObject> &container;
    IFactory &factory;

public:
    GenerateProjectileCommand(IShootable<T> &iShoot, std::unique_ptr<IObject> &returnRef, IFactory &f) : shoot(iShoot), container(returnRef), factory(f){};

    void execute();
};

template <typename T>
void GenerateProjectileCommand<T>::execute()
{
    if (!shoot.get_isShootable())
        throw IncorrectCommandException("This object can't shoot");
    container = factory.create_game_object({{"speed", shoot.get_projectile_speed()},
                                            {"direction", shoot.get_direction()},
                                            {"position", shoot.get_projectile_start_point()}});
};
