#include "rocks.h"

#include "point.h"
#include "velocity.h"
#include "uiDraw.h"
#include "flyingObject.h"

#include <cmath>


Rocks :: Rocks() : FlyingObject(0, 0, 0, 0)
{
    float angle = random(ANGLE_MIN, ANGLE_MAX);
    
    point.setX(random(-190, 190));
    point.setY(random(-190, 190));
    
    velocity.setDx(1 * (-cos(M_PI / 180.0 * angle)));
    velocity.setDy(1 * (sin(M_PI / 180.0 * angle)));
    rotation = 0;
}


SmallRock :: SmallRock()
{
    size = SMALL_ROCK_SIZE;
}


void SmallRock :: collision(std::vector<Rocks*> & rocks)
{
    kill();
}


void SmallRock :: draw() const
{
    drawSmallAsteroid(getPoint(), getRotation());
}


void SmallRock :: advance()
{
    setRotation(getRotation() + SMALL_ROCK_SPIN);
    point.addX(velocity.getDx());
    point.addY(velocity.getDy());
    
    
    if (point.getX() >= 210 || point.getX() <= -210)
        point.setX(point.getX() * -1);
    
    if (point.getY() >= 210 || point.getY() <= -210)
        point.setY(point.getY() * -1);
}


MediumRock :: MediumRock()
{
    size = MEDIUM_ROCK_SIZE;
}


void MediumRock :: collision(std::vector<Rocks*> & rocks)
{
    kill();
    
    Point p = getPoint();
    Velocity v1 = getVelocity();
    Velocity v2 = getVelocity();
    
    v1.setDx(v1.getDx() + 3);
    v2.setDx(v2.getDx() - 3);
    
    Rocks* newRock1 = new SmallRock();
    newRock1->setPoint(p);
    newRock1->setVelocity(v1);
    rocks.push_back(newRock1);
    
    Rocks* newRock2 = new SmallRock();
    newRock2->setPoint(p);
    newRock2->setVelocity(v2);
    rocks.push_back(newRock2);
}


void MediumRock :: draw() const
{
    drawMediumAsteroid(getPoint(), getRotation());
}


void MediumRock :: advance()
{
    setRotation(getRotation() + MEDIUM_ROCK_SPIN);
    point.addX(velocity.getDx());
    point.addY(velocity.getDy());
    
    
    if (point.getX() >= 210 || point.getX() <= -210)
        point.setX(point.getX() * -1);
    
    if (point.getY() >= 210 || point.getY() <= -210)
        point.setY(point.getY() * -1);
}


LargeRock :: LargeRock()
{
    size = BIG_ROCK_SIZE;
}


void LargeRock :: collision(std::vector<Rocks*> & rocks)
{
    kill();
    Point p = getPoint();
    Velocity v1 = getVelocity();
    Velocity v2 = getVelocity();
    Velocity v3 = getVelocity();
    
    v1.setDy(v1.getDy() + 1);
    v2.setDy(v2.getDy() - 1);
    v3.setDx(v3.getDx() + 3);
    
    
    Rocks* newRock1 = new MediumRock();
    newRock1->setPoint(p);
    newRock1->setVelocity(v1);
    rocks.push_back(newRock1);
    
    Rocks* newRock2 = new MediumRock();
    newRock2->setPoint(p);
    newRock2->setVelocity(v2);
    rocks.push_back(newRock2);
    
    Rocks* newRock3 = new SmallRock();
    newRock3->setPoint(p);
    newRock3->setVelocity(v3);
    rocks.push_back(newRock3);
}


void LargeRock :: draw() const
{
    drawLargeAsteroid(getPoint(), getRotation());
}


void LargeRock :: advance()
{
    setRotation(getRotation() + BIG_ROCK_SPIN);
    point.addX(velocity.getDx());
    point.addY(velocity.getDy());
    
    if (point.getX() >= 210 || point.getX() <= -210)
        point.setX(point.getX() * -1);
    
    if (point.getY() >= 210 || point.getY() <= -210)
        point.setY(point.getY() * -1);
}

