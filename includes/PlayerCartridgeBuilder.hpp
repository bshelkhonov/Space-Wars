#ifndef SPACE_WARS_PLAYERCARTRIDGEBUILDER_HPP
#define SPACE_WARS_PLAYERCARTRIDGEBUILDER_HPP


#include "ICartridgeBuilder.hpp"
#include "SFML/Graphics.hpp"


class PlayerCartridgeBuilder : public ICartridgeBuilder {
private:

    sf::Sprite sprite_;

public:
    PlayerCartridgeBuilder();

    void create_cartridge() override;

    void setSprite() override;

    void setVelocity() override;
};


#endif //SPACE_WARS_PLAYERCARTRIDGEBUILDER_HPP
