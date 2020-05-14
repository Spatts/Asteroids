#ifndef rocks_h
#define rocks_h

#include "point.h"
#include "flyingObject.h"
#include "velocity.h"
#include <vector>

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10

#define ANGLE_MIN 0
#define ANGLE_MAX 360


class Rocks : public FlyingObject
{
protected:
    int rotation;
    int size;
    
public:
    Rocks();
    
    virtual void draw() const = 0;
    virtual void advance() = 0;
    virtual void collision(std::vector<Rocks*> & rocks) { }
    int getRotation() const { return rotation; }
    void setRotation(int rotation) { this->rotation = rotation; }
    int getSize() const { return size; }
};


class LargeRock : public Rocks
{
public:
    LargeRock();
    virtual void draw() const;
    virtual void advance();
    virtual void collision(std::vector<Rocks*> & rocks);
};


class MediumRock : public Rocks
{
public:
    MediumRock();
    virtual void draw() const;
    virtual void advance();
    virtual void collision(std::vector<Rocks*> & rocks);
};


class SmallRock : public Rocks
{
public:
    SmallRock();
    virtual void draw() const;
    virtual void advance();
    virtual void collision(std::vector<Rocks*> & rocks);
};



#endif /* rocks_h */
