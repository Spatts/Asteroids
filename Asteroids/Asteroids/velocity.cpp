#include "velocity.h"


Velocity :: Velocity()
{
    setDx(0.0);
    setDy(0.0);
}


Velocity :: Velocity(float x, float y)
{
    setDx(x);
    setDy(y);
}


void Velocity :: setDx(float x)
{
    Dx = x;
    
}


void Velocity :: setDy(float y)
{
    Dy = y;
}
