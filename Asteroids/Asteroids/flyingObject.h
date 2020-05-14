

#ifndef flyingObject_h
#define flyingObject_h

#include "point.h"
#include "velocity.h"

#include <vector>

using namespace std;

class FlyingObject
{
private:
    bool alive;
    
protected:
    Point point;
    Velocity velocity;
    
public:
    
    FlyingObject(int x, int y, int dX, int Dy);
    
    bool isAlive() const { return alive; }
    
    Point getPoint() const { return point; }
    Velocity getVelocity() const { return velocity; }
    
    void setAlive(bool alive);
    void kill();
    void setPoint(Point & point);
    void setVelocity(Velocity & velocity);
    
    virtual void draw() const = 0;
    virtual void advance();
    
};




#endif /* flyingObject_h */
