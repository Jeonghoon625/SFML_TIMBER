#pragma once
#include <random>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "ObjectManager.h"
#include "SoundManager.h"
#include "TextManager.h"

using namespace sf;
using namespace std;

class GameManager
{
private:
    //System Object
    random_device rd;
    mt19937 gen;
    VideoMode vm;
    RenderWindow window;
    bool isPause;
    int score;
    bool acceptInput;
    Timer timer;

    //Sound Object
    SoundManager soundm;

    //InGame Object
    ObjectManager objm;

    //Input

    //Update

    //Draw

public:
    GameManager();
    void Run();
    void UpdateBranches(side sides[], int length, mt19937& gen);
};

