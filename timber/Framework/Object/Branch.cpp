#include "Branch.h"

Branch::Branch()
{
    textureBranch.loadFromFile("graphics/branch.png");

    spriteBranches = new Sprite[countBranches];
    sideBranches = new side[countBranches];

    for (int i = 0; i < countBranches; ++i)
    {
        spriteBranches[i].setTexture(textureBranch);
        spriteBranches[i].setPosition(-2000, -2000);
        spriteBranches[i].setOrigin(220, 40);

        sideBranches[i] = side::NONE;
    }
}

Branch::~Branch()
{
    delete[] spriteBranches;
    delete[] sideBranches;
}

