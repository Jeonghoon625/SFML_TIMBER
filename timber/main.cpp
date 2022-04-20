#include <random>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>

using namespace sf;
using namespace std;

enum class side
{
    LEFT,
    RIGHT,
    NONE,
};

void UpdateBranches(side sides[], int length, mt19937& gen)
{
    for (int i = length - 1; i >= 0; --i)
    {
        sides[i] = sides[i - 1];
    }

    int rnd = gen() % 5;

    switch (rnd)
    {
    case 0:
        sides[0] = side::LEFT;
        break;

    case 1:
        sides[0] = side::RIGHT;
        break;

    default:
        sides[0] = side::NONE;
        break;
    }
}

int main()
{
    random_device rd;
    mt19937 gen(rd()); //사용할때 gen();
 
    VideoMode vm(1920, 1080); //해상도

    RenderWindow window(vm, "Timber!", Style::Default); //3번째인자는 화면모드(default:창모드, fullscreen:전체화면)

    Font fontKOMIKAP;
    fontKOMIKAP.loadFromFile("fonts/KOMIKAP_.ttf");

    Text textMessage;
    textMessage.setFont(fontKOMIKAP);
    Text textScore;
    textScore.setFont(fontKOMIKAP);

    textMessage.setString("Press Enter to start!");
    textScore.setString("Score = 0");

    textMessage.setCharacterSize(75);
    textScore.setCharacterSize(100);

    textMessage.setFillColor(Color::White);
    textScore.setFillColor(Color::White);

    textScore.setPosition(20, 20);

    FloatRect textRect = textMessage.getLocalBounds();
    textMessage.setOrigin(
        textRect.left + textRect.width * 0.5f,
        textRect.top + textRect.height * 0.5f
    );

    textMessage.setPosition(1920 * 0.5f, 1080 * 0.5f);

    // Prepare the player
    Texture texturePlayer;
    texturePlayer.loadFromFile("graphics/player.png");
    Sprite spritePlayer;
    spritePlayer.setTexture(texturePlayer);
    spritePlayer.setPosition(580, 720);
    // The player starts on the left
    side playerSide = side::LEFT;

    // Prepare the gravestone
    Texture textureRIP;
    textureRIP.loadFromFile("graphics/rip.png");
    Sprite spriteRIP;
    spriteRIP.setTexture(textureRIP);
    spriteRIP.setPosition(600, 860);

    // Prepare the axe
    Texture textureAxe;
    textureAxe.loadFromFile("graphics/axe.png");
    Sprite spriteAxe;
    spriteAxe.setTexture(textureAxe);
    spriteAxe.setPosition(700, 830);

    // Line the axe up with the tree
    const float AXE_POSITION_LEFT = 700;
    const float AXE_POSITION_RIGHT = 1075;

    // Prepare the flying log
    Texture textureLog;
    textureLog.loadFromFile("graphics/log.png");
    Sprite spriteLog;
    spriteLog.setTexture(textureLog);
    spriteLog.setPosition(810, 720);

    // Some other useful log related variables
    bool logActive = false;
    float logSpeedX = 1000;
    float logSpeedY = -1500;

    Texture textureBackground;
    textureBackground.loadFromFile("graphics/background.png"); //이미지 로드

    Texture textureCloud;
    textureCloud.loadFromFile("graphics/cloud.png");

    Texture textureBee;
    textureBee.loadFromFile("graphics/bee.png");

    Texture textureTree;
    textureTree.loadFromFile("graphics/tree.png");

    Texture textureBranch;
    textureBranch.loadFromFile("graphics/branch.png");

    Sprite spriteBackground;
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setPosition(0, 0);// 위치

    Sprite spriteCloud1;
    spriteCloud1.setTexture(textureCloud);
    spriteCloud1.setPosition(2000, 0);

    Sprite spriteCloud2;
    spriteCloud2.setTexture(textureCloud);
    spriteCloud2.setPosition(2000, 150);

    Sprite spriteCloud3;
    spriteCloud3.setTexture(textureCloud);
    spriteCloud3.setPosition(2000, 300);

    Sprite spriteTree;
    spriteTree.setTexture(textureTree);
    spriteTree.setPosition(810, 0);

    Sprite spriteBee;
    spriteBee.setTexture(textureBee);
    spriteBee.setPosition(2000, 500);

    const int countBranches = 6;
    Sprite spriteBranches[countBranches];
    side sideBranches[countBranches];
    for(int i = 0; i < countBranches; ++i)
    {
        spriteBranches[i].setTexture(textureBranch);
        spriteBranches[i].setPosition(-2000, -2000);
        spriteBranches[i].setOrigin(220, 40);

        sideBranches[i] = side::NONE;
    }

    RectangleShape timerBar;
    float timerBarWidth = 400;
    float timerBarHeight = 80;
    Vector2f timerBarSize = Vector2f(timerBarWidth, timerBarHeight);
    timerBar.setSize(timerBarSize);
    Vector2f timerPos = Vector2f(1920 * 0.5f - timerBarWidth * 0.5f, 980.f);
    timerBar.setPosition(timerPos);
    timerBar.setFillColor(Color::Red);

    bool beeActive = false; //상태를 표현하기위해 쓰는 변수. 화면밖으로 나갔는지 check
    float beeSpeed = 0.0f;
    
    bool cloud1Active = false;
    float cloud1Speed = 0.0f;

    bool cloud2Active = false;
    float cloud2Speed = 0.0f;

    bool cloud3Active = false;
    float cloud3Speed = 0.0f;

    Clock clock;

    bool isPause = true;

    int score = 100;

    const float timeMax = 6.0f;
    float timeRemaining = timeMax;
    float timerBarWidthPerSecond = timerBarWidth / timeMax;

    bool acceptInput = false;

    SoundBuffer chopBuffer;
    chopBuffer.loadFromFile("sound/chop.wav");
    Sound chop;
    chop.setBuffer(chopBuffer);

    SoundBuffer deathBuffer;
    deathBuffer.loadFromFile("sound/death.wav");
    Sound death;
    death.setBuffer(deathBuffer);

    SoundBuffer ootBuffer;
    ootBuffer.loadFromFile("sound/out_of_time.wav");
    Sound oot;
    oot.setBuffer(ootBuffer);

    while (window.isOpen())
    {
        Time dt = clock.restart();

        Event event;

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
                window.close();
                break;
            case Event::KeyPressed:
                switch (event.key.code)
                {
                case Keyboard::Escape:
                    window.close();
                    break;
                case Keyboard::Return:
                {
                    isPause = false;

                    score = 0;
                    timeRemaining = timeMax;
                    acceptInput = true;

                    for (int i = 0; i < countBranches; ++i)
                    {
                        sideBranches[i] = side::NONE;
                    }
                     
                    spriteRIP.setPosition(675, 2000);
                    spritePlayer.setPosition(580, 720);
                }
                    break;
                case Keyboard::Space:
                    UpdateBranches(sideBranches, countBranches, gen);
                    break;

                case Keyboard::Left:
                    if (acceptInput && !isPause)
                    {
                        chop.play();
                        playerSide = side::LEFT;
                        ++score;
                        timeRemaining += (2 / score) + 0.15f;
                        if (timeRemaining > timeMax)
                        {
                            timeRemaining = timeMax;
                        }
                        spriteAxe.setPosition(AXE_POSITION_LEFT,
                            spriteAxe.getPosition().y);
                        spritePlayer.setPosition(580, 720);

                        UpdateBranches(sideBranches, countBranches, gen);

                        spriteLog.setPosition(810, 720);
                        logSpeedX = 5000;
                        logActive = true;

                        acceptInput = false;
                    }
                    break;

                case Keyboard::Right:
                    if (acceptInput && !isPause)
                    {
                        chop.play();
                        playerSide = side::RIGHT;
                        ++score;
                        timeRemaining += (2 / score) + 0.15f;
                        if (timeRemaining > timeMax)
                        {
                            timeRemaining = timeMax;
                        }
                        spriteAxe.setPosition(AXE_POSITION_RIGHT,
                            spriteAxe.getPosition().y);
                        spritePlayer.setPosition(1200, 720);

                        UpdateBranches(sideBranches, countBranches, gen);

                        spriteLog.setPosition(810, 720);
                        logSpeedX = -5000;
                        logActive = true;

                        acceptInput = false;
                    }
                    break;
                default:
                    break;
                }
                break;
            case Event::KeyReleased:
                if (event.key.code == Keyboard::Left || event.key.code == Keyboard::Right)
                {
                    acceptInput = true;
                    spriteAxe.setPosition(2000, spriteAxe.getPosition().y);
                }
                {
                    if (!isPause)
                    {
                        acceptInput = true;
                        spriteAxe.setPosition(2000, spriteAxe.getPosition().y);
                    }
                }
                break;
            default:
                break;
            }
        }

        // Update
        if (!isPause)
        {
            // Bee
            if (!beeActive)
            {
                // 벌 초기화
                beeSpeed = gen() % 200 + 200;
                beeSpeed *= -1.f;
                float y = gen() % 500 + 500;
                spriteBee.setPosition(2000, y);
                beeActive = true;
            }
            else
            {
                // 벌 이동
                float deltaX = beeSpeed * dt.asSeconds();
                Vector2f currPos = spriteBee.getPosition();
                currPos.x += deltaX;
                spriteBee.setPosition(currPos);

                // 화면 밖으로 나갔는지 테스트
                if (currPos.x < -100)
                {
                    beeActive = false;
                }
            }

            if (!cloud1Active)
            {
                cloud1Speed = gen() % 200 + 200;
                cloud1Speed *= -1.f;
                spriteCloud1.setPosition(1920, 0);
                cloud1Active = true;
            }
            else
            {
                float deltaX = cloud1Speed * dt.asSeconds();
                Vector2f currPos = spriteCloud1.getPosition();
                currPos.x += deltaX;
                spriteCloud1.setPosition(currPos);

                // 화면 밖으로 나갔는지 테스트
                if (currPos.x < -100)
                {
                    cloud1Active = false;
                }
            }

            if (!cloud2Active)
            {
                cloud2Speed = gen() % 200 + 200;
                spriteCloud2.setPosition(0, 150);
                cloud2Active = true;
            }
            else
            {
                float deltaX = cloud2Speed * dt.asSeconds();
                Vector2f currPos = spriteCloud2.getPosition();
                currPos.x += deltaX;
                spriteCloud2.setPosition(currPos);

                // 화면 밖으로 나갔는지 테스트
                if (currPos.x > 1920)
                {
                    cloud2Active = false;
                }
            }

            if (!cloud3Active)
            {
                cloud3Speed = gen() % 200 + 200;
                cloud3Speed *= -1.f;
                spriteCloud3.setPosition(1920, 300);
                cloud3Active = true;
            }
            else
            {
                float deltaX = cloud3Speed * dt.asSeconds();
                Vector2f currPos = spriteCloud3.getPosition();
                currPos.x += deltaX;
                spriteCloud3.setPosition(currPos);

                // 화면 밖으로 나갔는지 테스트
                if (currPos.x < -100)
                {
                    cloud3Active = false;
                }
            }

            stringstream ss;
            ss << "Score = " << score;
            textScore.setString(ss.str());

            timeRemaining -= dt.asSeconds();
            timerBarSize.x = timeRemaining * timerBarWidthPerSecond;
            timerBar.setSize(timerBarSize);

            if (timeRemaining < 0.f)
            {
                timerBarSize.x = 0.f;
                timerBar.setSize(timerBarSize);

                isPause = true;

                textMessage.setString("Out of time!!");
                FloatRect textRect = textMessage.getLocalBounds();
                textMessage.setOrigin(
                    textRect.left + textRect.width * 0.5f,
                    textRect.top + textRect.height * 0.5f
                );

                oot.play();
            }

            for (int i = 0; i < countBranches; ++i)
            {
                float height = 150 * i;

                switch (sideBranches[i])
                {
                case side::LEFT:
                    spriteBranches[i].setPosition(610, height);
                    spriteBranches[i].setRotation(180);
                    break;

                case side::RIGHT:
                    spriteBranches[i].setPosition(1330, height);
                    spriteBranches[i].setRotation(0);
                    break;

                default:
                    spriteBranches[i].setPosition(-2000, -2000);
                    break;
                }
            }

            if (logActive)
            {
                Vector2f logPos = spriteLog.getPosition();
                logPos.x += logSpeedX * dt.asSeconds();
                logPos.y += logSpeedY * dt.asSeconds();
                spriteLog.setPosition(logPos);

                if (logPos.x < -100 || logPos.x > 2000)
                {
                    logActive = false;
                    spriteLog.setPosition(810, 720);
                }
            }

            if (sideBranches[countBranches - 1] == playerSide)
            {
                isPause = true;
                acceptInput = false;

                spritePlayer.setPosition(2000, 660);
                spriteRIP.setPosition(525, 760);

                textMessage.setString("SQUIESSED");
                FloatRect textRect = textMessage.getLocalBounds();
                textMessage.setOrigin(
                    textRect.left + textRect.width * 0.5f,
                    textRect.top + textRect.height * 0.5f
                );

                death.play();
            }
        }

        // Draw
        window.clear();

        //World Draw
        window.draw(spriteBackground);
        window.draw(spriteCloud1);
        window.draw(spriteCloud2);
        window.draw(spriteCloud3);
        window.draw(spriteTree);

        for (int i = 0; i < countBranches; ++i)
        {
            window.draw(spriteBranches[i]);
        }
        window.draw(spritePlayer);
        window.draw(spriteAxe);
        window.draw(spriteLog);
        window.draw(spriteRIP);
        window.draw(spriteBee);
        window.draw(timerBar);

        //UI Draw
        if (isPause)
        {
            window.draw(textMessage);
        }
        window.draw(textScore);
        window.display(); // 더블 버퍼(Front, Back)
    }

    return 0;
}