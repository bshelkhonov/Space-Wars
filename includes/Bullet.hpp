#ifndef SPACE_WARS_BULLET_HPP
#define SPACE_WARS_BULLET_HPP


#include "IDrawable.hpp"
#include "IObjectMover.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>


class Bullet : public IDrawable {
private:
    sf::Sprite sprite_;

    std::shared_ptr<IObjectMover> mover_;

public:
    Bullet();

    void setSprite(const sf::Sprite&);

    void setColor(const sf::Color&);

    void setMover(IObjectMover*);

    void setPosition(const sf::Vector2f&) override;

    const sf::Sprite& getSprite() const override;

    bool isSpriteColliding(const IDrawable&) override;

    void move();

    void pause();

    void unpause();

    void draw(sf::RenderWindow&) override;

    void move(const sf::Vector2f&) override;

    sf::Vector2f getPosition() const override;

    bool isOutside() const override;

    ~Bullet() override = default;
};


using Cartridge = std::vector<Bullet>;


#endif //SPACE_WARS_BULLET_HPP
