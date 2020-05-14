

#include "bullet.h"
#include "point.h"
#include "velocity.h"
#include "flyingObject.h"
#include "uiDraw.h"
#include "bullet.h"
#include <cmath>

#include <cassert>

Bullet :: Bullet() : FlyingObject(0, 0, 0, 0)
{
    setLife(0);
}


void Bullet :: draw() const
{
    drawDot(getPoint());
}


void Bullet :: fire(const Point & p, float angle, const Velocity & v)
{
    point.setX(p.getX());
    point.setY(p.getY());
    
    velocity.setDy(v.getDy() + BULLET_SPEED * (cos(M_PI / 180.0 * angle)));
    velocity.setDx(v.getDx() + BULLET_SPEED * (-sin(M_PI / 180.0 * angle)));
    
}


void Bullet :: advance()
{
    point.addX(velocity.getDx());
    point.addY(velocity.getDy());
    setLife(getLife() + 1);
    
    if (point.getX() >= 200 || point.getX() <= -200)
        point.setX(point.getX() * -1);
    
    if (point.getY() >= 200 || point.getY() <= -200)
        point.setY(point.getY() * -1);
    
    if (getLife() >= BULLET_LIFE)
        kill();
}
