#ifndef SPACE_WARS_ENEMYCREATOR_HPP
#define SPACE_WARS_ENEMYCREATOR_HPP


#include "Spaceship.hpp"
#include <vector>


class EnemyCreator {
public:
    static std::vector<Spaceship> get();
};


#endif //SPACE_WARS_ENEMYCREATOR_HPP
