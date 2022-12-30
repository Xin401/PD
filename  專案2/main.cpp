#include "game.hpp"
int main()
{
    chdir("/Users/xin/Desktop/程設/ 專案2");

    // window建立
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Eggplant v.s. Chillypepper!");

    // 建立4個音效buffer
    sf::SoundBuffer shootbuffer;
    sf::SoundBuffer clickbuffer;
    sf::SoundBuffer deathbuffer;
    sf::SoundBuffer hitbuffer;
    sf::Music bgmusic;
    bool playdeathsound = false;
    // 輸入檔案
    if (!shootbuffer.loadFromFile("src/shoot.wav"))
    {
        return -1;
    }
    if (!clickbuffer.loadFromFile("src/click.wav"))
    {
        return -1;
    }
    if (!deathbuffer.loadFromFile("src/death.wav"))
    {
        return -1;
    }
    if (!hitbuffer.loadFromFile("src/hit.wav"))
    {
        return -1;
    }
    // 初始化射擊音
    sf::Sound shootsound;
    shootsound.setBuffer(shootbuffer);
    shootsound.setVolume(50);
    // 點擊音效
    sf::Sound clicksound;
    clicksound.setBuffer(clickbuffer);
    // 死亡音效
    sf::Sound deathsound;
    deathsound.setBuffer(deathbuffer);
    // 擊中音效
    sf::Sound hitsound;
    hitsound.setBuffer(hitbuffer);
    // 播放背景音
    bgmusic.setVolume(50);
    bgmusic.openFromFile("src/bgm.wav");
    bgmusic.setLoop(true);
    bgmusic.play();

    ////////HP////////
    sf::Texture fullHeart;
    fullHeart.loadFromFile("src/heart.png");
    sf::Texture emptyHeart;
    emptyHeart.loadFromFile("src/emptyHeart.png");
    sf::Sprite *p1hp = new sf::Sprite[HEALTH];
    sf::Sprite *p2hp = new sf::Sprite[HEALTH];
    for (int i = 0; i < HEALTH; i++)
    {
        p1hp[i].setTexture(fullHeart);
        p2hp[i].setTexture(fullHeart);
    }
    for (int i = 0; i < HEALTH; i++)
    {
        p1hp[i].setOrigin(p1hp[i].getLocalBounds().height / 2, p1hp[i].getLocalBounds().width / 2);
        p2hp[i].setOrigin(p2hp[i].getLocalBounds().height / 2, p2hp[i].getLocalBounds().width / 2);
        p1hp[i].setScale(0.5, 0.5);
        p2hp[i].setScale(0.5, 0.5);
        p1hp[i].setPosition(100 + 100 * i, 450);
        p2hp[i].setPosition(WIDTH - 25 - 100 * i, 450);
    }

    ////////player1 初始化///////////
    sf::Texture eggplant;
    eggplant.loadFromFile("src/eggplant.png");
    sf::Sprite player1(eggplant);
    player1.setOrigin(100, 100);
    player1.setPosition(0, HEIGHT / 2);
    bool player1IsExist = true;
    int player1Health = HEALTH;

    ////////player2 初始化///////////
    sf::Texture chillypepper;
    chillypepper.loadFromFile("src/chillypepper.png");
    sf::Sprite player2;
    player2.setOrigin(100, 100);
    player2.setPosition(WIDTH, HEIGHT / 2);
    bool player2IsExist = true;
    int player2Health = HEALTH;

    //////bullets1 初始化/////////
    sf::Texture droplet;
    droplet.loadFromFile("src/droplet.png");
    sf::Sprite *bullets1[BULLet_NUM];
    bool bullet1IsExist[BULLet_NUM] = {false};
    for (int i = 0; i < BULLet_NUM; i++)
    {
        bullets1[i] = new sf::Sprite(droplet);
        bullets1[i]->setOrigin(100, 100);
        bullets1[i]->setPosition(WIDTH * 2, HEIGHT * 2);
    }
    int bullets1Remain = BULLet_NUM;
    int currentBullet1 = 0;
    sf::Clock bulletClock1;
    sf::Clock clock1; //控制發射的間隔

    ///////bullets2 初始化//////
    sf::Texture fire;
    fire.loadFromFile("src/fire.png");
    sf::Sprite *bullets2[BULLet_NUM];
    bool bullet2IsExist[BULLet_NUM] = {false};
    for (int i = 0; i < BULLet_NUM; i++)
    {
        bullets2[i] = new sf::Sprite(fire);
        bullets2[i]->setOrigin(100, 100);
        bullets2[i]->setPosition(WIDTH * 2, HEIGHT * 2);
    }
    int bullets2Remain = BULLet_NUM;
    int currentBullet2 = 0;
    sf::Clock bulletClock2;
    sf::Clock clock2; //控制發射的間隔

    ///////傳入字體font////////
    sf::Font font;
    if (!font.loadFromFile("src/英文遊戲字體.ttf"))
    {
        std::cout << "no font" << std::endl;
    }

    float bullet1move[2][BULLet_NUM] = {0};
    float bullet2move[2][BULLet_NUM] = {0};
    ////////bullet1文字////////
    std::string bullets1Str = "W : up\nS : down\nD : right\nA : left\nspace : shot\nremain ";
    sf::Text bullets1Text(bullets1Str, font, 40);
    bullets1Text.setPosition(50, 50);
    sf::Text bullets1Cd;
    bullets1Cd.setFont(font);
    bullets1Cd.setCharacterSize(40);
    bullets1Cd.setPosition(50, 380);
    ////////bullet2文字////////
    std::string bullets2Str = "up : up\ndown : down\nright : right\nleft : left\nL : shot\nremain  ";
    sf::Text bullets2Text(bullets2Str, font, 40);
    bullets2Text.setPosition(WIDTH - 450, 50);
    sf::Text bullets2Cd;
    bullets2Cd.setFont(font);
    bullets2Cd.setCharacterSize(40);
    bullets2Cd.setPosition(WIDTH - 450, 380);

    ///////血量文字//////
    std::string health1 = "health :  ";
    sf::Text currnetHealth1(health1, font, 40);
    currnetHealth1.setPosition(50, 430);
    std::string health2 = "health :  ";
    sf::Text currnetHealth2(health2, font, 40);
    currnetHealth2.setPosition(WIDTH - 450, 430);
    //////game over 文字///////
    sf::Text gameOver1("GAME OVER!!!\nplayer2 win!!!", font, 100);
    gameOver1.setOrigin(gameOver1.getLocalBounds().width / 2, gameOver1.getLocalBounds().height / 2);
    gameOver1.setPosition(WIDTH / 2, (HEIGHT / 2) - 400);
    gameOver1.setFillColor(sf::Color::Blue);
    sf::Text gameOver2("GAME OVER!!!\nplayer1 win!!!", font, 100);
    gameOver2.setOrigin(gameOver2.getLocalBounds().width / 2, gameOver2.getLocalBounds().height / 2);
    gameOver2.setPosition(WIDTH / 2, (HEIGHT / 2) - 400);
    gameOver2.setFillColor(sf::Color::Blue);
    /////擊中畫面////
    sf::Texture fuckFace;
    fuckFace.loadFromFile("src/explode.png");
    sf::Sprite ouch(fuckFace);
    ouch.setOrigin(85, 85);
    bool isBoom = false;
    sf::Clock clockForFuck;
    /////障礙物初始化/////
    sf::Texture wall;
    wall.loadFromFile("src/obstacle.png");
    sf::Sprite obstacle1(wall);
    obstacle1.setPosition(WIDTH / 2, HEIGHT / 2);
    obstacle1.setOrigin(150, 157);
    //////Background//////
    sf::Texture farm;
    farm.loadFromFile("src/gg.png");
    sf::Sprite bg;
    bg.setTexture(farm);
    //////Restart Button Variables//////
    sf::Texture forRestart;
    forRestart.loadFromFile("src/restart.png");
    sf::Sprite restartButton;
    restartButton.setTexture(forRestart);
    restartButton.setOrigin(restartButton.getTexture()->getSize().x / 2, restartButton.getTexture()->getSize().y / 2);
    restartButton.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    //////Exit Button Variables//////
    sf::Texture forExit;
    forExit.loadFromFile("src/exitButton.png");
    sf::Sprite exitButton;
    exitButton.setTexture(forExit);
    exitButton.setOrigin(exitButton.getTexture()->getSize().x / 2, exitButton.getTexture()->getSize().y / 2);
    exitButton.setPosition(window.getSize().x / 2, window.getSize().y / 2 + 300);
    //////Button Variables//////
    sf::Texture buttonNotPressed;
    buttonNotPressed.loadFromFile("src/startButtonNotPressed.png");
    sf::Sprite startButton;
    startButton.setTexture(buttonNotPressed);
    bool pressed = false;
    bool mouseHeld = false;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;
    startButton.setOrigin(startButton.getTexture()->getSize().x / 2, startButton.getTexture()->getSize().y / 2);
    startButton.setPosition(window.getSize().x / 2, window.getSize().y / 2);

    // 道具
    sf::Texture speeduptex;
    speeduptex.loadFromFile("src/speedUP.png");
    sf::Sprite speedUP;
    speedUP.setTexture(speeduptex);
    speedUP.setScale(1.5f, 1.5f);
    speedUP.setOrigin(speedUP.getGlobalBounds().width / 2, speedUP.getGlobalBounds().height / 2);
    //////Start Menu//////
    while (window.isOpen() && !pressed)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(bg);
        mousePosWindow = sf::Mouse::getPosition(window);
        mousePosView = window.mapPixelToCoords(mousePosWindow);
        if (startButton.getGlobalBounds().contains(mousePosView))
        {
            startButton.setScale(1.2f, 1.2f);
        }
        else
        {
            startButton.setScale(1.f, 1.f);
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (mouseHeld == false)
            {
                mouseHeld = true;
                if (startButton.getGlobalBounds().contains(mousePosView))
                {
                    pressed = true;
                }
            }
            clicksound.play();
        }
        else
        {
            mouseHeld = false;
        }
        window.draw(startButton);

        window.display();
    }
    pressed = false;
    mouseHeld = false;
    farm.loadFromFile("src/background3.png");
    /////Text Choose//////
    std::string p1Choose = "Choose Player1's character";
    sf::Text player1Choose(p1Choose, font, 100);
    player1Choose.setOrigin(player1Choose.getLocalBounds().width / 2, player1Choose.getLocalBounds().height / 2);
    player1Choose.setColor(sf::Color::Black);
    player1Choose.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    for (int i = 0; i < 1000; i++)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(bg);
        window.draw(player1Choose);
        window.display();
    }
    //////Character page//////
    sf::Texture **clothes = new sf::Texture *[ROW];
    for (int i = 0; i < ROW; i++)
    {
        clothes[i] = new sf::Texture[COLUNM];
    }
    sf::Sprite **character = new sf::Sprite *[ROW];
    for (int i = 0; i < ROW; i++)
    {
        character[i] = new sf::Sprite[COLUNM];
    }
    clothes[0][0].loadFromFile("src/monkey.png");
    character[0][0].setTexture(clothes[0][0]);
    clothes[0][1].loadFromFile("src/eggplant.png");
    character[0][1].setTexture(clothes[0][1]);
    clothes[0][2].loadFromFile("src/unicorn.png");
    character[0][2].setTexture(clothes[0][2]);
    clothes[1][0].loadFromFile("src/chillypepper.png");
    character[1][0].setTexture(clothes[1][0]);
    clothes[1][1].loadFromFile("src/couple.png");
    character[1][1].setTexture(clothes[1][1]);
    clothes[1][2].loadFromFile("src/cow.png");
    character[1][2].setTexture(clothes[1][2]);
    clothes[2][0].loadFromFile("src/have.png");
    character[2][0].setTexture(clothes[2][0]);
    clothes[2][1].loadFromFile("src/finger.png");
    character[2][1].setTexture(clothes[2][1]);
    clothes[2][2].loadFromFile("src/kissing.png");
    character[2][2].setTexture(clothes[2][2]);
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUNM; j++)
        {
            character[i][j].setOrigin(character[i][j].getTexture()->getSize().x / 2, character[i][j].getTexture()->getSize().y / 2);
            character[i][j].setPosition((window.getSize().x / 2) - 1000.f + 1000 * i, (window.getSize().y / 2) - 500.f + 500 * j);
        }
    }
    //////Weapon//////
    sf::Texture **clothesWeapon = new sf::Texture *[ROW];
    for (int i = 0; i < ROW; i++)
    {
        clothesWeapon[i] = new sf::Texture[COLUNM];
    }
    sf::Sprite **characterWeapon = new sf::Sprite *[ROW];
    for (int i = 0; i < ROW; i++)
    {
        characterWeapon[i] = new sf::Sprite[COLUNM];
    }
    clothesWeapon[0][0].loadFromFile("src/monkeyWeapon.png");
    characterWeapon[0][0].setTexture(clothesWeapon[0][0]);
    clothesWeapon[0][1].loadFromFile("src/droplet.png");
    characterWeapon[0][1].setTexture(clothesWeapon[0][1]);
    clothesWeapon[0][2].loadFromFile("src/unicornWeapon.png");
    characterWeapon[0][2].setTexture(clothesWeapon[0][2]);
    clothesWeapon[1][0].loadFromFile("src/fire.png");
    characterWeapon[1][0].setTexture(clothesWeapon[1][0]);
    clothesWeapon[1][1].loadFromFile("src/coupleWeapon.png");
    characterWeapon[1][1].setTexture(clothesWeapon[1][1]);
    clothesWeapon[1][2].loadFromFile("src/cowWeapon.png");
    characterWeapon[1][2].setTexture(clothesWeapon[1][2]);
    clothesWeapon[2][0].loadFromFile("src/haveWeapon.png");
    characterWeapon[2][0].setTexture(clothesWeapon[2][0]);
    clothesWeapon[2][1].loadFromFile("src/fingerWeapon.png");
    characterWeapon[2][1].setTexture(clothesWeapon[2][1]);
    clothesWeapon[2][2].loadFromFile("src/kissingWeapon.png");
    characterWeapon[2][2].setTexture(clothesWeapon[2][2]);
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUNM; j++)
        {
            characterWeapon[i][j].setOrigin(characterWeapon[i][j].getTexture()->getSize().x / 2, characterWeapon[i][j].getTexture()->getSize().y / 2);
            characterWeapon[i][j].setPosition((window.getSize().x / 2) - 400.f + 400 * i, (window.getSize().y / 2) - 200.f + 200 * j);
        }
    }

    //////Player 1選角//////
    while (window.isOpen() && !pressed)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(bg);
        mousePosWindow = sf::Mouse::getPosition(window);
        mousePosView = window.mapPixelToCoords(mousePosWindow);
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COLUNM; j++)
            {
                window.draw(character[i][j]);
            }
        }
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COLUNM; j++)
            {
                mousePosWindow = sf::Mouse::getPosition(window);
                mousePosView = window.mapPixelToCoords(mousePosWindow);
                if (character[i][j].getGlobalBounds().contains(mousePosView))
                {
                    character[i][j].setScale(1.2f, 1.2f);
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        clicksound.play();
                        player1.setTexture(clothes[i][j]);
                        for (int k = 0; k < BULLet_NUM; k++)
                        {
                            bullets1[k]->setTexture(clothesWeapon[i][j]);
                            bullets1[k]->setOrigin(100, 100);
                            bullets1[k]->setPosition(WIDTH * 2, HEIGHT * 2);
                        }
                        character[i][j].setScale(0, 0);
                        pressed = true;
                    }
                }
                else
                {
                    character[i][j].setScale(1.f, 1.f);
                }
            }
        }

        window.display();
    }
    pressed = false;
    mouseHeld = false;
    std::string p2Choose = "Choose Player2's character";
    sf::Text player2Choose(p2Choose, font, 100);
    player2Choose.setOrigin(player2Choose.getLocalBounds().width / 2, player2Choose.getLocalBounds().height / 2);
    player2Choose.setColor(sf::Color::Black);
    player2Choose.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    for (int i = 0; i < 1000; i++)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(bg);
        window.draw(player2Choose);
        window.display();
    }
    //////Player 2選角//////
    while (window.isOpen() && !pressed)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(bg);
        mousePosWindow = sf::Mouse::getPosition(window);
        mousePosView = window.mapPixelToCoords(mousePosWindow);
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COLUNM; j++)
            {
                window.draw(character[i][j]);
            }
        }
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COLUNM; j++)
            {
                mousePosWindow = sf::Mouse::getPosition(window);
                mousePosView = window.mapPixelToCoords(mousePosWindow);
                if (character[i][j].getGlobalBounds().contains(mousePosView))
                {
                    character[i][j].setScale(1.2f, 1.2f);
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        clicksound.play();
                        player2.setTexture(clothes[i][j]);
                        for (int k = 0; k < BULLet_NUM; k++)
                        {
                            bullets2[k]->setTexture(clothesWeapon[i][j]);
                            bullets2[k]->setOrigin(100, 100);
                            bullets2[k]->setPosition(WIDTH * 2, HEIGHT * 2);
                        }
                        character[i][j].setScale(0, 0);
                        pressed = true;
                    }
                }
                else
                {
                    character[i][j].setScale(1.f, 1.f);
                }
            }
        }

        window.display();
    }

    farm.loadFromFile("src/scene-3_env.png");
    bg.setTexture(farm);
    // Game Start
    while (window.isOpen())
    {
        ////window event//////
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        ///////window behavior//////
        window.clear();
        window.draw(bg);
        window.draw(speedUP);
        mousePosWindow = sf::Mouse::getPosition(window);
        mousePosView = window.mapPixelToCoords(mousePosWindow);
        if (player1IsExist)
        {
            window.draw(player1);
        }
        if (player2IsExist)
        {
            window.draw(player2);
        }
        window.draw(bullets1Text);
        window.draw(bullets1Cd);
        window.draw(bullets2Text);
        window.draw(bullets2Cd);
        window.draw(obstacle1);
        // draw hearth
        for (int i = 0; i < HEALTH; i++)
        {
            window.draw(p1hp[i]);
            window.draw(p2hp[i]);
        }
        for (int i = 0; i < BULLet_NUM; i++)
        {
            if (bullet1IsExist[i])
            {
                window.draw(*bullets1[i]);
            }
        }
        for (int i = 0; i < BULLet_NUM; i++)
        {
            if (bullet2IsExist[i])
            {
                window.draw(*bullets2[i]);
            }
        }
        if (!player1IsExist)
        {
            window.clear();
            window.draw(gameOver1);
            window.draw(restartButton);
            window.draw(exitButton);
        }
        if (!player2IsExist)
        {
            window.clear();
            window.draw(gameOver2);
            window.draw(restartButton);
            window.draw(exitButton);
        }
        //////restart button//////
        if (restartButton.getGlobalBounds().contains(mousePosView))
        {
            restartButton.setScale(1.2f, 1.2f);
        }
        else
        {
            restartButton.setScale(1.f, 1.f);
        }

        if (exitButton.getGlobalBounds().contains(mousePosView))
        {
            exitButton.setScale(1.2f, 1.2f);
        }
        else
        {
            exitButton.setScale(1.f, 1.f);
        }

        /////End Menu//////
        if (isBoom)
        {
            window.draw(ouch);
        }
        /////文字處理//////
        std::string bullets1StrCur = bullets1Str + std::to_string(bullets1Remain) + " shot";
        bullets1Text.setString(bullets1StrCur);
        if (bulletClock1.getElapsedTime().asSeconds() < SHOT_INTERVAL)
        {
            float cd = SHOT_INTERVAL - bulletClock1.getElapsedTime().asSeconds();
            int icd = static_cast<int>(cd * 10);
            int a = icd / 10;
            int b = icd % 10;
            if (SHOT_INTERVAL - bulletClock1.getElapsedTime().asSeconds() < 0.03)
            {
                bullets1Cd.setString(std::to_string(0));
            }
            else
            {
                bullets1Cd.setString(std::to_string(a) + "." + std::to_string(b));
            }
            if (bullets1Remain == BULLet_NUM)
            {
                bullets1Cd.setString("shot is full");
            }
        }
        health1.replace(health1.length() - 1, 1, std::to_string(player1Health));
        currnetHealth1.setString(health1);
        health2.replace(health2.length() - 1, 1, std::to_string(player2Health));
        currnetHealth2.setString(health2);
        std::string bullets2StrCur = bullets2Str + std::to_string(bullets2Remain) + " shot";
        bullets2Text.setString(bullets2StrCur);
        if (bulletClock2.getElapsedTime().asSeconds() < SHOT_INTERVAL)
        {
            float cd = SHOT_INTERVAL - bulletClock2.getElapsedTime().asSeconds();
            int icd = static_cast<int>(cd * 10);
            int a = icd / 10;
            int b = icd % 10;
            if (SHOT_INTERVAL - bulletClock2.getElapsedTime().asSeconds() < 0.03)
            {
                bullets2Cd.setString(std::to_string(0));
            }
            else
            {
                bullets2Cd.setString(std::to_string(a) + "." + std::to_string(b));
            }
            if (bullets2Remain == BULLet_NUM)
            {
                bullets2Cd.setString("shot is full");
            }
        }

        //////shot bullet1///////
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            if (clock1.getElapsedTime().asSeconds() >= 0.2f && bullets1Remain > 0)
            {
                sf::Vector2f vecA = player1.getPosition();
                sf::Vector2f vecB = player2.getPosition();
                float dis = sqrt(pow(abs(vecA.x - vecB.x), 2) + pow(abs(vecA.y - vecB.y), 2));
                bullet1IsExist[currentBullet1] = true;
                bullets1[currentBullet1]->setPosition(player1.getPosition());
                bullets1[currentBullet1]->setRotation(-player1.getRotation() + 90);
                bullet1move[0][currentBullet1] = (vecA.x - vecB.x) / dis;
                bullet1move[1][currentBullet1] = (vecA.y - vecB.y) / dis;
                clock1.restart();
                currentBullet1++;
                if (currentBullet1 == BULLet_NUM)
                {
                    currentBullet1 = 0;
                }
                bullets1Remain--;
                shootsound.play();
            }
        }
        //////shot bullet2///////
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
        {
            if (clock2.getElapsedTime().asSeconds() >= 0.2f && bullets2Remain > 0)
            {
                sf::Vector2f vecA = player1.getPosition();
                sf::Vector2f vecB = player2.getPosition();
                float dis = sqrt(pow(abs(vecA.x - vecB.x), 2) + pow(abs(vecA.y - vecB.y), 2));
                bullet2IsExist[currentBullet2] = true;
                bullets2[currentBullet2]->setPosition(player2.getPosition());
                bullets2[currentBullet2]->setRotation(-player2.getRotation() + 90);
                bullet2move[0][currentBullet2] = (vecA.x - vecB.x) / dis;
                bullet2move[1][currentBullet2] = (vecA.y - vecB.y) / dis;
                clock2.restart();
                currentBullet2++;
                if (currentBullet2 == BULLet_NUM)
                {
                    currentBullet2 = 0;
                }
                bullets2Remain--;
                shootsound.play();
            }
        }
        /////bullet1 behavior/////
        if (bulletClock1.getElapsedTime().asSeconds() > SHOT_INTERVAL && bullets1Remain < BULLet_NUM)
        {
            bullets1Remain++;
            bulletClock1.restart();
        }
        for (int i = 0; i < BULLet_NUM; i++)
        {
            if (touchBoundery(*bullets1[i]))
            {
                bullet1IsExist[i] = false;
            }
        }
        for (int i = 0; i < BULLet_NUM; i++)
        {
            bullets1[i]->move(-bullet1move[0][i] * BULLET_SPEED, -bullet1move[1][i] * BULLET_SPEED);
        }
        /////bullet2 behavior/////
        if (bulletClock2.getElapsedTime().asSeconds() > SHOT_INTERVAL && bullets2Remain < BULLet_NUM)
        {
            bullets2Remain++;
            bulletClock2.restart();
        }

        for (int i = 0; i < BULLet_NUM; i++)
        {
            if (touchBoundery(*bullets2[i]))
            {
                bullet2IsExist[i] = false;
            }
        }
        for (int i = 0; i < BULLet_NUM; i++)
        {
            bullets2[i]->move(bullet2move[0][i] * BULLET_SPEED, bullet2move[1][i] * BULLET_SPEED);
        }
        /////player1 behavior/////
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && player1.getPosition().x >= 0)
        {
            if (player1.getPosition().x - WIDTH / 2 <= 0 || player1.getPosition().x - WIDTH / 2 >= 150 ||
                abs(player1.getPosition().y - HEIGHT / 2) >= 150)
            {
                player1.move(-PLAYER_SPEED, 0);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && player1.getPosition().x <= WIDTH)
        {
            if (player1.getPosition().x - WIDTH / 2 >= 0 || player1.getPosition().x - WIDTH / 2 <= -150 || abs(player1.getPosition().y - HEIGHT / 2) >= 150)
            {
                player1.move(PLAYER_SPEED, 0);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && player1.getPosition().y > 300)
        {
            if ((player1.getPosition().y - HEIGHT / 2 >= 150 || player1.getPosition().y - HEIGHT / 2 <= 0 || abs(player1.getPosition().x - WIDTH / 2) >= 150))
            {
                player1.move(0, -PLAYER_SPEED);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && player1.getPosition().y <= HEIGHT)
        {
            if (player1.getPosition().y - HEIGHT / 2 <= -150 || player1.getPosition().y - HEIGHT / 2 >= 0 || abs(player1.getPosition().x - WIDTH / 2) >= 150)
            {
                player1.move(0, PLAYER_SPEED);
            }
        }
        if (player1Health == 0)
        {
            player1IsExist = false;
            playdeathsound = true;
            player1Health++;
        }
        ////player2 behavior//////
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && player2.getPosition().x >= 0)
        {
            if (player2.getPosition().x - WIDTH / 2 <= 0 || player2.getPosition().x - WIDTH / 2 >= 150 ||
                abs(player2.getPosition().y - HEIGHT / 2) >= 150)
            {
                player2.move(-PLAYER_SPEED, 0);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && player2.getPosition().x <= WIDTH)
        {
            if (player2.getPosition().x - WIDTH / 2 >= 0 || player2.getPosition().x - WIDTH / 2 <= -150 ||
                abs(player2.getPosition().y - HEIGHT / 2) >= 150)
            {
                player2.move(PLAYER_SPEED, 0);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && player2.getPosition().y >= 0)
        {
            if ((player2.getPosition().y - HEIGHT / 2 >= 150 || player2.getPosition().y - HEIGHT / 2 <= 0 || abs(player2.getPosition().x - WIDTH / 2) >= 150) && player2.getPosition().y > 300)
            {
                player2.move(0, -PLAYER_SPEED);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && player2.getPosition().y <= HEIGHT)
        {
            if (player2.getPosition().y - HEIGHT / 2 <= -150 || player2.getPosition().y - HEIGHT / 2 >= 0 || abs(player2.getPosition().x - WIDTH / 2) >= 150)
                player2.move(0, PLAYER_SPEED);
        }
        if (player2Health == 0)
        {
            player2IsExist = false;
            playdeathsound = true;
            player2Health++;
        }
        // rotate
        player1.setScale(1.f, -1.f);
        player2.setScale(-1.f, -1.f);
        if (player1.getPosition().y < player2.getPosition().y)
        {
            player1.setScale(-1.f, 1.f);
            player2.setScale(1.f, 1.f);
            if (player1.getPosition().x > player2.getPosition().x)
            {
                player1.setScale(-1.f, -1.f);
                player2.setScale(1.f, -1.f);
            }
        }
        if (player1.getPosition().y > player2.getPosition().y)
        {
            player2.setScale(-1.f, 1.f);
            player1.setScale(1.f, 1.f);
            if (player1.getPosition().x < player2.getPosition().x)
            {
                player1.setScale(1.f, -1.f);
                player2.setScale(-1.f, -1.f);
            }
        }
        player1.setRotation((-atan((player1.getPosition().x - player2.getPosition().x) / (player1.getPosition().y - player2.getPosition().y)) * 180 / M_PI + 90));
        player2.setRotation((-atan((player1.getPosition().x - player2.getPosition().x) / (player1.getPosition().y - player2.getPosition().y)) * 180 / M_PI + 90));

        player1.setRotation((-atan((player1.getPosition().x - player2.getPosition().x) / (player1.getPosition().y - player2.getPosition().y)) * 180 / M_PI + 90));
        player2.setRotation((-atan((player1.getPosition().x - player2.getPosition().x) / (player1.getPosition().y - player2.getPosition().y)) * 180 / M_PI + 90));
        // 播放死亡音效
        if (playdeathsound)
        {
            deathsound.play();
            playdeathsound = false;
        }
        /////event when touch///////
        for (int i = 0; i < BULLet_NUM; i++)
        {
            if (isTouch(player1, *bullets2[i]) && player1IsExist && bullet2IsExist[i])
            {
                hitsound.play();
                bullet2IsExist[i] = false;
                bullets1[i]->setPosition(WIDTH * 2, HEIGHT * 2);
                if (player1Health > 0)
                {
                    player1Health--;
                    p1hp[player1Health].setTexture(emptyHeart);
                }
                if (clockForFuck.getElapsedTime().asSeconds() > BOOM_INTERVAL)
                {
                    isBoom = true;
                    clockForFuck.restart();
                    ouch.setPosition(player1.getPosition());
                }
            }
        }
        for (int i = 0; i < BULLet_NUM; i++)
        {
            if (isTouch(player2, *bullets1[i]) && player2IsExist && bullet1IsExist[i])
            {
                hitsound.play();
                bullet1IsExist[i] = false;
                bullets2[i]->setPosition(WIDTH * 2, HEIGHT * 2);
                if (player2Health > 0)
                {
                    player2Health--;
                    p2hp[player2Health].setTexture(emptyHeart);
                }
                if (clockForFuck.getElapsedTime().asSeconds() > BOOM_INTERVAL)
                {
                    isBoom = true;
                    clockForFuck.restart();
                    ouch.setPosition(player2.getPosition());
                }
            }
        }
        if (clockForFuck.getElapsedTime().asSeconds() > BOOM_INTERVAL / 5)
        {
            isBoom = false;
        }
        for (int i = 0; i < BULLet_NUM; i++)
        {
            if (isTouch(obstacle1, *bullets1[i]) && bullet1IsExist[i])
            {
                bullet1IsExist[i] = false;
            }
            if (isTouch(obstacle1, *bullets2[i]) && bullet2IsExist[i])
            {
                bullet2IsExist[i] = false;
            }
        }
        if (!player1IsExist || !player2IsExist)
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                clicksound.play();
                if (mouseHeld == false)
                {
                    mouseHeld = true;
                    if (restartButton.getGlobalBounds().contains(mousePosView))
                    {
                        player1.setPosition(0, HEIGHT / 2);
                        player1IsExist = true;
                        player1Health = HEALTH;
                        player2.setPosition(WIDTH, HEIGHT / 2);
                        for (int i = 0; i < HEALTH; i++)
                        {
                            p1hp[i].setTexture(fullHeart);
                            p2hp[i].setTexture(fullHeart);
                        }
                        player2IsExist = true;
                        player2Health = HEALTH;
                        bullets1Remain = BULLet_NUM;
                        currentBullet1 = 0;
                        bullets2Remain = BULLet_NUM;
                        currentBullet2 = 0;
                        for (int i = 0; i < 5; i++)
                        {
                            bullets1[i]->setPosition(WIDTH * 2, HEIGHT * 2);
                        }
                        for (int i = 0; i < 5; i++)
                        {
                            bullets2[i]->setPosition(WIDTH * 2, HEIGHT * 2);
                        }
                    }
                    else if (exitButton.getGlobalBounds().contains(mousePosView))
                    {
                        window.close();
                    }
                }
            }
            else
            {
                mouseHeld = false;
            }
        }

        window.display();
    }
}
