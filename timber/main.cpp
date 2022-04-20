#include <random>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>

#define LR_MACRO 470

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
	Text textScore1;
	textScore1.setFont(fontKOMIKAP);
	Text textScore2;
	textScore2.setFont(fontKOMIKAP);

	textMessage.setString("Press Enter to start!");
	textScore1.setString("Score 1P = 0");
	textScore2.setString("Score 2P = 0");

	textMessage.setCharacterSize(75);
	textScore1.setCharacterSize(100);
	textScore2.setCharacterSize(100);

	textMessage.setFillColor(Color::White);
	textScore1.setFillColor(Color::White);
	textScore2.setFillColor(Color::White);

	textScore1.setPosition(20, 20);
	textScore2.setPosition(960, 20);

	FloatRect textRect = textMessage.getLocalBounds();
	textMessage.setOrigin(
		textRect.left + textRect.width * 0.5f,
		textRect.top + textRect.height * 0.5f
	);

	textMessage.setPosition(1920 * 0.5f, 1080 * 0.5f);

	// Prepare the player
	Texture texturePlayer1;
	texturePlayer1.loadFromFile("graphics/player1.png");
	Texture texturePlayer2;
	texturePlayer2.loadFromFile("graphics/player2.png");
	Sprite spritePlayer1;
	spritePlayer1.setTexture(texturePlayer1);
	spritePlayer1.setPosition(580 - LR_MACRO, 720);
	Sprite spritePlayer2;
	spritePlayer2.setTexture(texturePlayer2);
	spritePlayer2.setPosition(580 + LR_MACRO, 720);
	// The player starts on the left
	side playerSide1 = side::LEFT;
	side playerSide2 = side::LEFT;

	// Prepare the gravestone
	Texture textureRIP;
	textureRIP.loadFromFile("graphics/rip.png");
	Sprite spriteRIP;
	spriteRIP.setTexture(textureRIP);
	spriteRIP.setPosition(-500, 0);

	// Prepare the axe
	Texture textureAxe;
	textureAxe.loadFromFile("graphics/axe.png");
	Sprite spriteAxe1;
	spriteAxe1.setTexture(textureAxe);
	spriteAxe1.setPosition(-500, 830);
	Sprite spriteAxe2;
	spriteAxe2.setTexture(textureAxe);
	spriteAxe2.setPosition(-500, 830);

	// Line the axe up with the tree
	const float AXE_POSITION_LEFT1 = 700 - LR_MACRO;
	const float AXE_POSITION_RIGHT1 = 1075 - LR_MACRO;
	const float AXE_POSITION_LEFT2 = 700 + LR_MACRO;
	const float AXE_POSITION_RIGHT2 = 1075 + LR_MACRO;

	// Prepare the flying log
	Texture textureLog;
	textureLog.loadFromFile("graphics/log.png");
	Sprite spriteLog1;
	spriteLog1.setTexture(textureLog);
	spriteLog1.setPosition(810 - LR_MACRO, 720);
	Sprite spriteLog2;
	spriteLog2.setTexture(textureLog);
	spriteLog2.setPosition(810 + LR_MACRO, 720);

	// Some other useful log related variables
	bool logActive1 = false;
	bool logActive2 = false;
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

	Sprite spriteTree1;
	spriteTree1.setTexture(textureTree);
	spriteTree1.setPosition(810 - LR_MACRO, 0);
	Sprite spriteTree2;
	spriteTree2.setTexture(textureTree);
	spriteTree2.setPosition(810 + LR_MACRO, 0);

	Sprite spriteBee;
	spriteBee.setTexture(textureBee);
	spriteBee.setPosition(2000, 500);

	const int countBranches = 6;
	Sprite spriteBranches1[countBranches];
	side sideBranches1[countBranches];
	for (int i = 0; i < countBranches; ++i)
	{
		spriteBranches1[i].setTexture(textureBranch);
		spriteBranches1[i].setPosition(-2000, -2000);
		spriteBranches1[i].setOrigin(220, 40);

		sideBranches1[i] = side::NONE;
	}
	Sprite spriteBranches2[countBranches];
	side sideBranches2[countBranches];
	for (int i = 0; i < countBranches; ++i)
	{
		spriteBranches2[i].setTexture(textureBranch);
		spriteBranches2[i].setPosition(-2000, -2000);
		spriteBranches2[i].setOrigin(220, 40);

		sideBranches2[i] = side::NONE;
	}

	RectangleShape timerBar1;
	RectangleShape timerBar2;
	float timerBarWidth = 400;
	float timerBarHeight = 80;
	Vector2f timerBarSize1 = Vector2f(timerBarWidth, timerBarHeight);
	Vector2f timerBarSize2 = Vector2f(timerBarWidth, timerBarHeight);
	timerBar1.setSize(timerBarSize1);
	timerBar2.setSize(timerBarSize2);
	Vector2f timerPos1 = Vector2f((1920 * 0.5f - LR_MACRO) - timerBarWidth * 0.5f, 980.f);
	Vector2f timerPos2 = Vector2f((1920 * 0.5f + LR_MACRO) - timerBarWidth * 0.5f, 980.f);
	timerBar1.setPosition(timerPos1);
	timerBar1.setFillColor(Color::Red);
	timerBar2.setPosition(timerPos2);
	timerBar2.setFillColor(Color::Red);

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

	int score1 = 0;
	int score2 = 0;

	const float timeMax = 6.0f;
	float timeRemaining1 = timeMax;
	float timeRemaining2 = timeMax;
	float timerBarWidthPerSecond1 = timerBarWidth / timeMax;
	float timerBarWidthPerSecond2 = timerBarWidth / timeMax;

	bool acceptInput1 = false;
	bool acceptInput2 = false;

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

					score1 = 0;
					score2 = 0;
					timeRemaining1 = timeMax;
					timeRemaining2 = timeMax;
					acceptInput1 = true;
					acceptInput2 = true;

					for (int i = 0; i < countBranches; ++i)
					{
						sideBranches1[i] = side::NONE;
					}
					for (int i = 0; i < countBranches; ++i)
					{
						sideBranches2[i] = side::NONE;
					}

					spriteRIP.setPosition(-500, 2000);
					spritePlayer1.setPosition(580 - LR_MACRO, 720);
					spritePlayer2.setPosition(580 + LR_MACRO, 720);
				}
				break;
				case Keyboard::A:
					if (acceptInput1 && !isPause)
					{
						chop.play();
						playerSide1 = side::LEFT;
						++score1;
						timeRemaining1 += (2 / score1) + 0.15f;
						if (timeRemaining1 > timeMax)
						{
							timeRemaining1 = timeMax;
						}
						spriteAxe1.setPosition(AXE_POSITION_LEFT1,
							spriteAxe1.getPosition().y);
						spritePlayer1.setPosition(580 - LR_MACRO, 720);

						UpdateBranches(sideBranches1, countBranches, gen);

						spriteLog1.setPosition(810 - LR_MACRO, 720);
						logSpeedX = 5000;
						logActive1 = true;

						acceptInput1 = false;
					}
					break;
				case Keyboard::Left:
					if (acceptInput2 && !isPause)
					{
						chop.play();
						playerSide2 = side::LEFT;
						++score2;
						timeRemaining2 += (2 / score2) + 0.15f;
						if (timeRemaining2 > timeMax)
						{
							timeRemaining2 = timeMax;
						}
						spriteAxe2.setPosition(AXE_POSITION_LEFT2,
							spriteAxe2.getPosition().y);
						spritePlayer2.setPosition(580 + LR_MACRO, 720);

						UpdateBranches(sideBranches2, countBranches, gen);

						spriteLog2.setPosition(810 + LR_MACRO, 720);
						logSpeedX = 5000;
						logActive2 = true;

						acceptInput2 = false;
					}
					break;

				case Keyboard::D:
					if (acceptInput1 && !isPause)
					{
						chop.play();
						playerSide1 = side::RIGHT;
						++score1;
						timeRemaining1 += (2 / score1) + 0.15f;
						if (timeRemaining1 > timeMax)
						{
							timeRemaining1 = timeMax;
						}
						spriteAxe1.setPosition(AXE_POSITION_RIGHT1,
							spriteAxe1.getPosition().y);
						spritePlayer1.setPosition(1200 - LR_MACRO, 720);

						UpdateBranches(sideBranches1, countBranches, gen);

						spriteLog1.setPosition(810 - LR_MACRO, 720);
						logSpeedX = -5000;
						logActive1 = true;

						acceptInput1 = false;
					}
					break;
				case Keyboard::Right:
					if (acceptInput2 && !isPause)
					{
						chop.play();
						playerSide2 = side::RIGHT;
						++score2;
						timeRemaining2 += (2 / score2) + 0.15f;
						if (timeRemaining2 > timeMax)
						{
							timeRemaining2 = timeMax;
						}
						spriteAxe2.setPosition(AXE_POSITION_RIGHT2,
							spriteAxe2.getPosition().y);
						spritePlayer2.setPosition(1200 + LR_MACRO, 720);

						UpdateBranches(sideBranches2, countBranches, gen);

						spriteLog2.setPosition(810 + LR_MACRO, 720);
						logSpeedX = -5000;
						logActive2 = true;

						acceptInput2 = false;
					}
					break;
				default:
					break;
				}
				break;
			case Event::KeyReleased:
				if (event.key.code == Keyboard::Left || event.key.code == Keyboard::Right)
				{
					acceptInput1 = true;
					spriteAxe1.setPosition(2000, spriteAxe1.getPosition().y);
				}
				{
					if (!isPause)
					{
						acceptInput1 = true;
						spriteAxe1.setPosition(2000, spriteAxe1.getPosition().y);
					}
				}

				if (event.key.code == Keyboard::A || event.key.code == Keyboard::D)
				{
					acceptInput2 = true;
					spriteAxe2.setPosition(2000, spriteAxe2.getPosition().y);
				}
				{
					if (!isPause)
					{
						acceptInput2 = true;
						spriteAxe2.setPosition(2000, spriteAxe2.getPosition().y);
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

			stringstream ss1;
			ss1 << "Score 1P = " << score1;
			textScore1.setString(ss1.str());
			stringstream ss2;
			ss2 << "Score 2P = " << score2;
			textScore2.setString(ss2.str());

			timeRemaining1 -= dt.asSeconds();
			timeRemaining2 -= dt.asSeconds();
			timerBarSize1.x = timeRemaining1 * timerBarWidthPerSecond1;
			timerBarSize2.x = timeRemaining2 * timerBarWidthPerSecond2;
			timerBar1.setSize(timerBarSize1);
			timerBar2.setSize(timerBarSize2);

			if (timeRemaining1 < 0.f)
			{
				timerBarSize1.x = 0.f;
				timerBar1.setSize(timerBarSize1);

				isPause = true;

				textMessage.setString("1P Out of time!!");
				FloatRect textRect = textMessage.getLocalBounds();
				textMessage.setOrigin(
					textRect.left + textRect.width * 0.5f,
					textRect.top + textRect.height * 0.5f
				);

				oot.play();
			}
			else if (timeRemaining2 < 0.f)
			{
				timerBarSize2.x = 0.f;
				timerBar2.setSize(timerBarSize2);

				isPause = true;

				textMessage.setString("2P Out of time!!");
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

				switch (sideBranches1[i])
				{
				case side::LEFT:
					spriteBranches1[i].setPosition(610 - LR_MACRO, height);
					spriteBranches1[i].setRotation(180);
					break;

				case side::RIGHT:
					spriteBranches1[i].setPosition(1330 - LR_MACRO, height);
					spriteBranches1[i].setRotation(0);
					break;

				default:
					spriteBranches1[i].setPosition(-2000, -2000);
					break;
				}
			}
			for (int i = 0; i < countBranches; ++i)
			{
				float height = 150 * i;

				switch (sideBranches2[i])
				{
				case side::LEFT:
					spriteBranches2[i].setPosition(610 + LR_MACRO, height);
					spriteBranches2[i].setRotation(180);
					break;

				case side::RIGHT:
					spriteBranches2[i].setPosition(1330 + LR_MACRO, height);
					spriteBranches2[i].setRotation(0);
					break;

				default:
					spriteBranches2[i].setPosition(-2000, -2000);
					break;
				}
			}

			if (logActive1)
			{
				Vector2f logPos = spriteLog1.getPosition();
				logPos.x += logSpeedX * dt.asSeconds();
				logPos.y += logSpeedY * dt.asSeconds();
				spriteLog1.setPosition(logPos);

				if (logPos.x < -100 || logPos.x > 2000)
				{
					logActive1 = false;
					spriteLog1.setPosition(810 - LR_MACRO, 720);
				}
			}
			if (logActive2)
			{
				Vector2f logPos = spriteLog2.getPosition();
				logPos.x += logSpeedX * dt.asSeconds();
				logPos.y += logSpeedY * dt.asSeconds();
				spriteLog2.setPosition(logPos);

				if (logPos.x < -100 || logPos.x > 2000)
				{
					logActive2 = false;
					spriteLog2.setPosition(810 + LR_MACRO, 720);
				}
			}

			if (sideBranches1[countBranches - 1] == playerSide1)
			{
				isPause = true;
				acceptInput1 = false;

				spriteRIP.setPosition(spritePlayer1.getPosition().x, 760);
				spritePlayer1.setPosition(2000, 660);

				textMessage.setString("1P SQUIESSED");
				FloatRect textRect = textMessage.getLocalBounds();
				textMessage.setOrigin(
					textRect.left + textRect.width * 0.5f,
					textRect.top + textRect.height * 0.5f
				);

				death.play();
			}
			else if (sideBranches2[countBranches - 1] == playerSide2)
			{
				isPause = true;
				acceptInput2 = false;

				spriteRIP.setPosition(spritePlayer2.getPosition().x, 760);
				spritePlayer2.setPosition(2000, 660);

				textMessage.setString("2P SQUIESSED");
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
		window.draw(spriteTree1);
		window.draw(spriteTree2);

		for (int i = 0; i < countBranches; ++i)
		{
			window.draw(spriteBranches1[i]);
		}
		for (int i = 0; i < countBranches; ++i)
		{
			window.draw(spriteBranches2[i]);
		}

		window.draw(spritePlayer1);
		window.draw(spritePlayer2);
		window.draw(spriteAxe1);
		window.draw(spriteAxe2);
		window.draw(spriteLog1);
		window.draw(spriteLog2);
		window.draw(spriteRIP);
		window.draw(spriteBee);
		window.draw(timerBar1);
		window.draw(timerBar2);

		//UI Draw
		if (isPause)
		{
			window.draw(textMessage);
		}
		window.draw(textScore1);
		window.draw(textScore2);
		window.display(); // 더블 버퍼(Front, Back)
	}

	return 0;
}