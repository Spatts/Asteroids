/*********************************************************************
 * File: game.h
 * Description: Defines the game class for Asteroids
 *
 *********************************************************************/

#ifndef GAME_H
#define GAME_H

#include <vector>

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "rocks.h"
#include "bullet.h"
#include "velocity.h"
#include "ship.h"


class Game
{
public:
    Game(Point tl, Point br);
    ~Game();
    
    void handleInput(const Interface & ui);
    void draw(const Interface & ui);
    void advance();
    
private:
    Point bottomRight;
    Point topLeft;
    
    Ship * ship;

    std::vector<Bullet> bullets;
    std::vector<Rocks *> rocks;
    
    Rocks* createRock();
    bool isOnScreen(const Point & point);
    void advanceBullets();
    void advanceShip();
    void advanceRocks();
    void handleCollisions();
    void cleanUpZombies();
    float getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const;
};


#endif /* GAME_H */
