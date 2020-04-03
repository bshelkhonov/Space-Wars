#include <ICartridgeBuilder.hpp>


ICartridgeBuilder::ICartridgeBuilder() : cartridge_() {}


void ICartridgeBuilder::create_cartridge() {
    cartridge_.reset(new Cartridge());
};


std::shared_ptr<Cartridge> ICartridgeBuilder::get_cartridge() {
    return cartridge_;
}


