#ifndef SPACE_WARS_TESTIDRAWABLES_HPP
#define SPACE_WARS_TESTIDRAWABLES_HPP


#include "Bullet.hpp"
#include "Spaceship.hpp"
#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>


template<typename T>
class TestDrawables : public testing::Test {
protected:

    T drawable_;

public:
    TestDrawables() : drawable_() {}

    void SetUp() override {
        drawable_.setPosition({42, 42});
    }
};


using Drawables = testing::Types<Bullet, Spaceship>;

TYPED_TEST_CASE(TestDrawables, Drawables);


TYPED_TEST(TestDrawables, TestMove) {
    this->drawable_.move({32, -123});
    ASSERT_EQ(this->drawable_.getPosition(), sf::Vector2f(74, -81));
}


TYPED_TEST(TestDrawables, TestSetPosition) {
    this->drawable_.setPosition({32, -123});
    ASSERT_EQ(this->drawable_.getPosition(), sf::Vector2f(32, -123));
}


TYPED_TEST(TestDrawables, TestIsOutside) {
    this->drawable_.setPosition({99999, 9999});
    ASSERT_TRUE(this->drawable_.isOutside());
    this->drawable_.setPosition({0, 1});
    ASSERT_FALSE(this->drawable_.isOutside());
}


#endif //SPACE_WARS_TESTIDRAWABLES_HPP
