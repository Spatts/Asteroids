

#ifndef bullet_h
#define bullet_h

#define BULLET_SPEED 5
#define BULLET_LIFE 40

#include "point.h"
#include "flyingObject.h"
#include "velocity.h"

class Bullet : public FlyingObject
{
private:
    int life;
    
public:
    Bullet();
    
    virtual void draw() const;
    
    void fire(const Point & p, float angle, const Velocity & v);
    
    int getLife() const { return life; }
    void setLife(int life) { this->life = life; }
    
    virtual void advance();
};



#endif /* bullet_h */
