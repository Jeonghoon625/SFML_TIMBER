#include "GameManager.h"

GameManager::GameManager() : gen(rd()), vm(1920, 1080), window(vm, "Timber!", Style::Default), isPause(true), score(0), acceptInput(false)
{
}

void GameManager::Run()
{
    while (window.isOpen())
    {
        Time dt = timer.GetClock().restart();

        Event event;

        //while (window.pollEvent(event))
        //{
        //    switch (event.type)
        //    {
        //    case Event::Closed:
        //        window.close();
        //        break;
        //    case Event::KeyPressed:
        //       
        //        break;
        //    case Event::KeyReleased:
        //        if (event.key.code == Keyboard::Left || event.key.code == Keyboard::Right)
        //        {
        //            acceptInput = true;
        //            spriteAxe.setPosition(2000, spriteAxe.getPosition().y);
        //        }
        //        if (!isPause)
        //        {
        //            acceptInput = true;
        //            spriteAxe.setPosition(2000, spriteAxe.getPosition().y);
        //        }
        //        break;
        //    default:
        //        break;
        //    }
        //}

        //// Update
        //if (!isPause)
        //{
        //    if (!beeActive)
        //    {
        //        beeSpeed = gen() % 200 + 200;
        //        beeSpeed *= -1.f;
        //        float y = gen() % 500 + 500;
        //        spriteBee.setPosition(2000, y);
        //        beeActive = true;
        //    }
        //    else
        //    {
        //        float deltaX = beeSpeed * dt.asSeconds();
        //        Vector2f currPos = spriteBee.getPosition();
        //        currPos.x += deltaX;
        //        spriteBee.setPosition(currPos);

        //        if (currPos.x < -100)
        //        {
        //            beeActive = false;
        //        }
        //    }

        //    if (!cloud1Active)
        //    {
        //        cloud1Speed = gen() % 200 + 200;
        //        cloud1Speed *= -1.f;
        //        spriteCloud1.setPosition(1920, 0);
        //        cloud1Active = true;
        //    }
        //    else
        //    {
        //        float deltaX = cloud1Speed * dt.asSeconds();
        //        Vector2f currPos = spriteCloud1.getPosition();
        //        currPos.x += deltaX;
        //        spriteCloud1.setPosition(currPos);

        //        if (currPos.x < -100)
        //        {
        //            cloud1Active = false;
        //        }
        //    }

        //    stringstream ss;
        //    ss << "Score = " << score;
        //    textScore.setString(ss.str());

        //    timeRemaining -= dt.asSeconds();
        //    timerBarSize.x = timeRemaining * timerBarWidthPerSecond;
        //    timerBar.setSize(timerBarSize);

        //    if (timeRemaining < 0.f)
        //    {
        //        timerBarSize.x = 0.f;
        //        timerBar.setSize(timerBarSize);

        //        isPause = true;

        //        textMessage.setString("Out of time!!");
        //        FloatRect textRect = textMessage.getLocalBounds();
        //        textMessage.setOrigin(
        //            textRect.left + textRect.width * 0.5f,
        //            textRect.top + textRect.height * 0.5f
        //        );

        //        oot.play();
        //    }

        //    for (int i = 0; i < countBranches; ++i)
        //    {
        //        float height = 150 * i;

        //        switch (sideBranches[i])
        //        {
        //        case side::LEFT:
        //            spriteBranches[i].setPosition(610, height);
        //            spriteBranches[i].setRotation(180);
        //            break;

        //        case side::RIGHT:
        //            spriteBranches[i].setPosition(1330, height);
        //            spriteBranches[i].setRotation(0);
        //            break;

        //        default:
        //            spriteBranches[i].setPosition(-2000, -2000);
        //            break;
        //        }
        //    }

        //    if (logActive)
        //    {
        //        Vector2f logPos = spriteLog.getPosition();
        //        logPos.x += logSpeedX * dt.asSeconds();
        //        logPos.y += logSpeedY * dt.asSeconds();
        //        spriteLog.setPosition(logPos);

        //        if (logPos.x < -100 || logPos.x > 2000)
        //        {
        //            logActive = false;
        //            spriteLog.setPosition(810, 720);
        //        }
        //    }

        //    if (sideBranches[countBranches - 1] == playerSide)
        //    {
        //        isPause = true;
        //        acceptInput = false;

        //        spritePlayer.setPosition(2000, 660);
        //        spriteRIP.setPosition(525, 760);

        //        textMessage.setString("SQUIESSED");
        //        FloatRect textRect = textMessage.getLocalBounds();
        //        textMessage.setOrigin(
        //            textRect.left + textRect.width * 0.5f,
        //            textRect.top + textRect.height * 0.5f
        //        );

        //        death.play();
        //    }
        //}

        // Draw
        window.clear();

        //World Draw
        window.draw(objm.background.spriteBackground);
        //window.draw(spriteCloud1);
        //window.draw(spriteCloud2);
        //window.draw(spriteCloud3);
        //window.draw(spriteTree);

        //for (int i = 0; i < countBranches; ++i)
        //{
        //    window.draw(spriteBranches[i]);
        //}
        //window.draw(spritePlayer);
        //window.draw(spriteAxe);
        //window.draw(spriteLog);
        //window.draw(spriteRIP);
        //window.draw(spriteBee);
        //window.draw(timerBar);

        ////UI Draw
        //if (isPause)
        //{
        //    window.draw(textMessage);
        //}
        //window.draw(textScore);
        window.display(); // 더블 버퍼(Front, Back)
    }
}

void GameManager::UpdateBranches(side sides[], int length, mt19937& gen)
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