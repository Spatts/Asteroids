/*********************************************************************
 * File: game.cpp
 * Description: Contains the implementaiton of the game class
 *  methods.
 *
 *********************************************************************/

#include "game.h"

#include <limits>
#include <algorithm>
#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
using namespace std;

#define OFF_SCREEN_BORDER_AMOUNT 5


Game :: ~Game()
{
    if (ship != NULL)
    {
        delete ship;
        ship = NULL;
    }
    
    vector<Rocks *>::iterator rockIt = rocks.begin();
    while (rockIt != rocks.end())
    {
        Rocks* pRock = *rockIt;
        delete pRock;
        pRock = NULL;
        rockIt = rocks.erase(rockIt);
    }
}


Game :: Game(Point tl, Point br)
: topLeft(tl), bottomRight(br)
{
    for (int i = 0; i < 5; i++)
    {
        rocks.push_back(createRock());
    }
    
    ship = new Ship();
}


Rocks* Game :: createRock()
{
    Rocks* newRock = new LargeRock();
    return newRock;
}


void Game :: advance()
{
    advanceBullets();
    advanceRocks();
    
    if (ship->isAlive())
    {
        ship->advance();
    }

    handleCollisions();
    cleanUpZombies();
}


void Game :: advanceRocks()
{
    for (int i = 0; i < rocks.size(); i++)
        if (rocks[i]->isAlive())
        {
            rocks[i]->advance();
        }
}


void Game :: advanceBullets()
{
    for (int i = 0; i < bullets.size(); i++)
    {
        if (bullets[i].isAlive())
        {
            bullets[i].advance();
        }
    }
}


void Game :: handleCollisions()
{
    for (int i = 0; i < bullets.size(); i++)
    {
        if (bullets[i].isAlive())
        {
            for (int j = 0; j < rocks.size(); j++)
            {
                if (rocks[j] != NULL && rocks[j]->isAlive())
                {
                    if (getClosestDistance(bullets[i], *rocks[j]) < (2 + rocks[j]->getSize()))
                    {
                        rocks[j]->collision(rocks);
                        bullets[i].kill();
                    }
                }
            }
        }
    }
    
    if (ship->isAlive())
    {
        for (int i = 0; i < rocks.size(); i++)
        {
            if (rocks[i] != NULL && rocks[i]->isAlive())
            {
                if (getClosestDistance(*ship, *rocks[i]) < (rocks[i]->getSize() + 10))
                {
                    rocks[i]->collision(rocks);
                    
                    ship->kill();
                }
            }
        }
    }
}


float Game :: getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const
{
    float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
    dMax = max(dMax, abs(obj2.getVelocity().getDx()));
    dMax = max(dMax, abs(obj2.getVelocity().getDy()));
    dMax = max(dMax, 0.1f);
    
    float distMin = std::numeric_limits<float>::max();
    for (float i = 0.0; i <= dMax; i++)
    {
        Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
                     obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
        Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
                     obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));
        
        float xDiff = point1.getX() - point2.getX();
        float yDiff = point1.getY() - point2.getY();
        
        float distSquared = (xDiff * xDiff) +(yDiff * yDiff);
        
        distMin = min(distMin, distSquared);
    }
    
    return sqrt(distMin);
}


void Game :: cleanUpZombies()
{
    vector<Bullet>::iterator bulletIt = bullets.begin();
    while (bulletIt != bullets.end())
    {
        Bullet bullet = *bulletIt;
        
        if (!bullet.isAlive())
        {
            bulletIt = bullets.erase(bulletIt);
        }
        else
        {
            bulletIt++;
        }
    }
    
    vector<Rocks *>::iterator rockIt = rocks.begin();
    while (rockIt != rocks.end())
    {
        Rocks* pRock = *rockIt;
        
        if (!pRock->isAlive())
        {
            delete pRock;
            pRock = NULL;
            rockIt = rocks.erase(rockIt);
        }
        else
        {
            rockIt++;
        }
    }
}


void Game :: handleInput(const Interface & ui)
{
    if (ship->isAlive())
    {
        if (ui.isLeft())
        {
            ship->moveLeft();
        }
        
        if (ui.isRight())
        {
            ship->moveRight();
        }
        
        if (ui.isUp())
        {
            ship->moveForward();
        }
        else if (!ui.isUp())
        {
            ship->setThrust(false);
        }
        
        if (ui.isSpace())
        {
            if (ship->getIsPowered())
            {
                int powerAngleLeft = ship->getAngle() + 25;
                int powerAngleRight = ship->getAngle() - 25;
                
                if (powerAngleLeft > 360)
                {
                    powerAngleLeft -= 360;
                }
                
                if (powerAngleRight < 0)
                {
                    powerAngleRight += 360;
                }
                
                Bullet newBullet1;
                newBullet1.fire(ship->getPoint(), ship->getAngle(), ship->getVelocity());
                bullets.push_back(newBullet1);
                
                Bullet newBullet2;
                newBullet2.fire(ship->getPoint(), powerAngleLeft, ship->getVelocity());
                bullets.push_back(newBullet2);
                
                Bullet newBullet3;
                newBullet3.fire(ship->getPoint(), powerAngleRight, ship->getVelocity());
                bullets.push_back(newBullet3);
            }
            else
            {
                Bullet newBullet;
                newBullet.fire(ship->getPoint(), ship->getAngle(), ship->getVelocity());
                bullets.push_back(newBullet);
            }
        }
    }
}


void Game :: draw(const Interface & ui)
{
    for (int i = 0; i < rocks.size(); i++)
        if (rocks[i]->isAlive())
        {
            rocks[i]->draw();
        }
    
    if (ship->isAlive())
        ship->draw();
    
    for (int i = 0; i < bullets.size(); i++)
    {
        if (bullets[i].isAlive())
        {
            bullets[i].draw();
        }
    }
}

