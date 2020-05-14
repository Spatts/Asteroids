#include "ship.h"
#include "velocity.h"
#include "flyingObject.h"
#include "uiDraw.h"
#include "point.h"


Ship :: Ship() : FlyingObject(0, 0, 0, 0)
{
    setAngle(0);
    power = 0;
}


void Ship :: draw() const
{
    drawShip(getPoint(), getAngle(), getThrust());
}


void Ship :: moveLeft()
{
    setAngle(getAngle() + ROTATE_AMOUNT);
    
    if (getAngle() > ANGLE_MAX)
    {
        setAngle(getAngle() - ANGLE_MAX);
    }
}


void Ship :: moveRight()
{
    setAngle(getAngle() - ROTATE_AMOUNT);
    
    if (angle < ANGLE_MIN)
    {
        setAngle(getAngle() + ANGLE_MAX);
    }
}


void Ship :: moveForward()
{
    velocity.setDy(velocity.getDy() + 0.5 * (cos(M_PI / 180.0 * angle)));
    velocity.setDx(velocity.getDx() + 0.5 * (-sin(M_PI / 180.0 * angle)));
    setThrust(true);
}


void Ship :: advance()
{

    point.addX(velocity.getDx());
    point.addY(velocity.getDy());

    if (getIsPowered())
    {
        power++;
    }

    if (power >= 200)
    {
        power = 0;
        setIsPowered(false);
    }

    if (point.getX() >= 210 || point.getX() <= -210)
        point.setX(point.getX() * -1);
    
    if (point.getY() >= 210 || point.getY() <= -210)
        point.setY(point.getY() * -1); 
}
