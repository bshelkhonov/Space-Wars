#include <ICartridgeBuilder.hpp>


ICartridgeBuilder::ICartridgeBuilder() : cartridge_() {}


void ICartridgeBuilder::createCartridge() {
    cartridge_.reset(new Cartridge());
};


std::shared_ptr<Cartridge> ICartridgeBuilder::getCartridge() {
    return cartridge_;
}


