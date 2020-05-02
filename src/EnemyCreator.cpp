#include "EnemyCreator.hpp"
#include "Settings.hpp"
#include "EnemyMover.hpp"
#include <chrono>


EnemyCreator::EnemyCreator() : random_(std::chrono::high_resolution_clock::now().time_since_epoch().count()) {
    for (const auto& path : ENEMIES_FILES) {
        auto texture = new sf::Texture();
        texture->loadFromFile(path);
        sprites_.emplace_back();
        sprites_.back().setTexture(*texture);
        sprites_.back().setScale(ENEMY_SPRITE_SCALE);
    }
}




Spaceship EnemyCreator::get_random_enemy_() {
    Spaceship spaceship;
    spaceship.setSprite(sprites_[random() % sprites_.size()]);
    spaceship.setGun(nullptr);
    spaceship.setBulletOffset({0, 0});
    spaceship.setMover(new EnemyMover(DEFAULT_ENEMY_VELOCITY));
    spaceship.setPosition(DEFAULT_ENEMY_POS);

    return spaceship;
}


std::vector<Spaceship> EnemyCreator::get() {

    uint32_t enemies_num = MIN_ENEMIES_SPAWNED + (random_() % (MAX_ENEMIES_SPAWNED - MIN_ENEMIES_SPAWNED + 1));

    std::vector<Spaceship> result;

    for (uint32_t i = 0; i < enemies_num; ++i) {
        result.push_back(get_random_enemy_());
        result.back().move({i * 100.0f, random_() % 300 * (random() % 2 == 0 ? -1.f : 1.f)});
    }

    return result;
}

