#ifndef ship_h
#define ship_h

#define SHIP_SIZE 10

#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5

#define ANGLE_MIN 0
#define ANGLE_MAX 360

#include "point.h"
#include "flyingObject.h"
#include "velocity.h"

class Ship : public FlyingObject
{
private:
    int angle;
    bool thrust;
    bool isPowered;
    int power;
    
public:
    
    Ship();
    
    int getAngle() const { return angle; }
    void setAngle(int angle) { this->angle = angle; }
    
    bool getThrust() const { return thrust; }
    void setThrust(bool thrust) { this->thrust = thrust; }
    
    bool getIsPowered() const { return isPowered; }
    void setIsPowered(bool isPowered) { this->isPowered = isPowered; }
    
    virtual void draw() const;
    
    void moveLeft();
    void moveRight();
    void moveForward();
    
    virtual void advance();
};



#endif /* ship_h */
