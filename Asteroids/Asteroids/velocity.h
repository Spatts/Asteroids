#ifndef VELOCITY_H
#define VELOCITY_H


class Velocity
{
public:
    Velocity();
    Velocity(float x, float y);
    
    float getDx() const { return Dx; }
    float getDy() const { return Dy; }
    
    void setDx(float x);
    void setDy(float y);
    
private:
    float Dx;
    float Dy;
    
};


#endif /* velocity_h */
