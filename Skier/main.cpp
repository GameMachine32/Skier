#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include "random.h"
using namespace random;
int main()
{
    randomNumber();
    sf::Font font;
    if(!font.loadFromFile("Assets/Fonts/sansation.ttf"))
    {
        ::MessageBox(0, "Could not load asset 'sansation.ttf'. Make sure that you have the 'Assets' folder and all its contents installed properly.", "Error", MB_ICONERROR);
        return 1;
    }
    bool paused = false;
    bool drawFlag = true;
    int score = 0;
    int skierX = 200;
    double speed = 15;
    sf::Texture skierTexture;
    if(!skierTexture.loadFromFile("Assets/Images/Skier.png"))
    {
        ::MessageBox(0, "Could not load asset 'Skier.png'. Make sure that you have the 'Assets' folder and all its contents installed properly.", "Error", MB_ICONERROR);
        return 1;
    }
    sf::Texture treeTexture;
    if(!treeTexture.loadFromFile("Assets/Images/Tree.png"))
    {
        ::MessageBox(0, "Could not load asset 'Tree.png'. Make sure that you have the 'Assets' folder and all its contents installed properly.", "Error", MB_ICONERROR);
        return 1;
    }
    sf::Texture flagTexture;
    if(!flagTexture.loadFromFile("Assets/Images/Flag.png"))
    {
        ::MessageBox(0, "Could not load asset 'Flag.png'. Make sure that you have the 'Assets' folder and all its contents installed properly.", "Error", MB_ICONERROR);
        return 1;
    }
    sf::Sprite skier(skierTexture);
    skier.setScale(0.5f, 0.5f);
    sf::Sprite tree(treeTexture);
    sf::Sprite flag(flagTexture);
    int treex = randRange(150, 200), treey = randRange(300, 650);
    int flagx = randRange(50, 450), flagy = randRange(300, 650);
    flag.setPosition(flagx, flagy);
    if(flag.getGlobalBounds().intersects(tree.getGlobalBounds()))
    {
        while(flag.getGlobalBounds().intersects(tree.getGlobalBounds()))
        {
            flagx = randRange(150, 200);
        }
    }
    tree.setPosition(treex, treey);
    tree.setScale(3.0f, 3.0f);
    skier.setPosition(skierX, 50);
    sf::RenderWindow window(sf::VideoMode(500, 500), "Skier", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(100);
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }
        if(GetAsyncKeyState('R'))
        {
            paused = false;
        }
        if(!paused) {
        if(GetAsyncKeyState(VK_RIGHT))
        {
            skierX += 7;
        }
        else if(GetAsyncKeyState(VK_LEFT))
        {
            skierX -= 7;
        }
        else if(GetAsyncKeyState('P'))
        {
            paused = true;
        }
        tree.setPosition(treex, treey);
        skier.setPosition(skierX, 50);
        flag.setPosition(flagx, flagy);
        window.clear(sf::Color::White);
        window.draw(skier);
        window.draw(tree);
        if(drawFlag) {
            window.draw(flag);
        }
        window.display();
        treey -= 10;
        flagy -= 10;
        if(flagy < -100)
        {
            flagy = randRange(500, 650);
            flagx = randRange(50, 450);
            drawFlag = true;
        }
        if(treey < -100)
        {
            treey = randRange(500, 650);
            treex = randRange(50, 450);
        }
        if(skier.getGlobalBounds().intersects(tree.getGlobalBounds()))
        {
            window.close();
            break;
        }
        else if(skier.getGlobalBounds().intersects(flag.getGlobalBounds()))
        {
            drawFlag = false;
            score += 10;
        }
        if(flag.getGlobalBounds().intersects(tree.getGlobalBounds()))
        {
            flagx = randRange(150, 200);
        }
        Sleep(speed);
      }
    }
    return 0;
}
