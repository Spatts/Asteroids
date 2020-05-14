

#include "flyingObject.h"

#include "point.h"
#include "velocity.h"
#include "uiDraw.h"
#include "flyingObject.h"

#include <cassert>


FlyingObject :: FlyingObject(int x, int y, int Dx, int Dy)
{
    setAlive(true);
    
    point.setX(x);
    point.setY(y);
    
    velocity.setDx(Dx);
    velocity.setDy(Dy);
}


void FlyingObject :: kill()
{
    this->alive = false;
}


void FlyingObject :: setPoint(Point & point)
{
    this->point = point;
}


void FlyingObject :: setVelocity(Velocity & velocity)
{
    this->velocity = velocity;
}


void FlyingObject :: advance()
{
    point.addX(velocity.getDx());
    point.addY(velocity.getDy());
}


void FlyingObject :: setAlive(bool alive)
{
    this->alive = alive;
}
