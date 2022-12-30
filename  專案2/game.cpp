#include "game.hpp"

// 邊界判定
bool touchBoundery(sf::Sprite &object)
{
    sf::Vector2f vec = object.getPosition();
    if (vec.x >= WIDTH + 10 || vec.x <= -10)
    {
        return true;
    }
    if (vec.y >= HEIGHT + 10 || vec.y <= 280)
    {
        return true;
    }
    return false;
}
// 角色碰撞
bool isTouch(sf::Sprite &a, sf::Sprite &b)
{
    sf::Vector2f vecA = a.getPosition();
    sf::Vector2f vecB = b.getPosition();
    if (abs(vecA.x - vecB.x) <= TOUCH_DIST && abs(vecA.y - vecB.y) <= TOUCH_DIST)
    {
        return true;
    }
    return false;
}
