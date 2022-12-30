#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <unistd.h>
#pragma once
const int WIDTH = 2560;
const int HEIGHT = 1600;
const int BULLet_NUM = 10;
const float SHOT_INTERVAL = 1.0;
const float PLAYER_SPEED = 1;
const float BULLET_SPEED = 3;
const float TOUCH_DIST = 150;
const int HEALTH = 5;
const int ROW = 3;
const int COLUNM = 3;
const float BOOM_INTERVAL = 0.69;
bool touchBoundery(sf::Sprite &object);
bool isTouch(sf::Sprite &a, sf::Sprite &b);
