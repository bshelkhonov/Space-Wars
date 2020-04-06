#ifndef SPACE_WARS_STOCKPLAYERCARTRIDGEBUILDER_HPP
#define SPACE_WARS_STOCKPLAYERCARTRIDGEBUILDER_HPP


#include "ICartridgeBuilder.hpp"
#include "SFML/Graphics.hpp"


class StockPlayerCartridgeBuilder : public ICartridgeBuilder {
private:

    sf::Sprite sprite_;

public:
    StockPlayerCartridgeBuilder();

    ~StockPlayerCartridgeBuilder();

    void create_cartridge() override;

    void setSprite() override;

    void setMover() override;
};


#endif //SPACE_WARS_STOCKPLAYERCARTRIDGEBUILDER_HPP
