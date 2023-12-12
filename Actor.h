#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"
#include <cmath>

class StudentWorld;
//class GameController;

class Actor : public GraphObject{

private:
    bool m_alive;
    StudentWorld* m_world;
    
public:
    //constructor
    Actor(int imageID, int startX, int startY, StudentWorld* studentWorld, Direction dir, double size, int depth) : GraphObject(imageID, startX, startY, dir, size, depth) {
        m_world = studentWorld;
        m_alive = true;
    }
    //dosomething function is a pure virtual function
    virtual  void doSomething() = 0;
    
    //annoyed function only for iceman and protestors
    virtual void annoyed() { }
    
    //checks if object is alive
    bool isAlive() {
        return m_alive;
    }
    
    //sets object to dead
    void setDead() {
        m_alive = false;
    }
    //sets object to alive
    void setAlive() {
        m_alive = true;
    }
    
    //function gets distance between two coordinates
    double distance(int x1, int y1, int x2, int y2) {
        double distance = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
        distance = pow(distance, .5);
        return distance;
    }
    
    //used to access student world
    StudentWorld* getWorld()
    {
        return this->m_world;
    }
    
    //destructor
    virtual ~Actor() {
        m_alive = false;
    }
};

class Goodies : public Actor {
private:
    bool m_pickUp;
    
public:
    virtual void doSomething() = 0;
    Goodies(int imageID, int startX, int startY, StudentWorld* world, Direction dir, double size, int depth) : Actor(imageID, startX, startY, world, dir, size, depth) {
        m_pickUp = true;
    }
    
    bool getPickUp() {
        return this->m_pickUp;
    }
};

class Iceman : public Actor{
private:
    int m_sonars;
    int m_gold;
    int m_squirts;
    int m_health;
    int m_lives;

public:
    Iceman(int startX, int startY, StudentWorld* world) : Actor(IID_PLAYER, startX, startY, world, right, 1.0, 0) {
        m_sonars = 1;
        m_squirts = 5;
        m_gold = 0;
        m_health = 10;
        
        this->setVisible(true);
    }
    
    ~Iceman () { 
        setVisible(false);
    }
    
    void doSomething();
        
    
    //function to take care of damage done to player
    void takedamage() {
        this->m_health -= 1;
    }
    
    void move() {
        return;
    }
    
    void useSonar() {
        return;
    }
    
    void useSquirt() {
        return;
    }
    
    void useGold() {
        return;
    }
    
    void setHealth(int health){
        m_health = health;
    }
    int getHealth() {
        return m_health;
    }
    
    void setSquirts(int squirts){
        m_squirts = squirts;
    }
    int getSquirts() {
        return m_squirts;
    }
    void setGold(int gold) {
        m_gold = gold;
    }
    int getGold() {
        return m_gold;
    }
    
    void setSonar(int sonar) {
        m_sonars = sonar;
    }
    int getSonar() {
        return m_sonars;
    }
    
    //function to squirt
    void squirt() {
        return;
    }
    
};

class Ice : public Actor {
private:
    
public:
    Ice(int startX, int startY, StudentWorld* world) : Actor(IID_ICE, startX, startY, world, right, 0.25, 3) {
        this->setVisible(true);
    }
    
    ~Ice() {
        this->setDead();
    }
    
    void doSomething() {
        if (!this->isAlive()) {
            setVisible(false);
        }
    }
    
};

class Boulder : public Actor {
private:

    
public:
    
    Boulder(int startX, int startY, StudentWorld* world) : Actor(IID_BOULDER, startX, startY, world, down, 1.0, 1) {
        this->setVisible(true);
    }
    
    ~Boulder() {
        
    }
    
    void doSomething() {
        
    }
    
};

class Squirt : public Actor {
private:

    
public:
    
    void doSomething() {
        
    }
};

class Oil_barrel : public Goodies {
private:
    
public:
    
    Oil_barrel(int startX, int startY, StudentWorld* world) : Goodies(IID_BARREL, startX, startY, world, right, 1.0, 1) {
        this->setVisible(true);
    }
    
    void doSomething() {
        
    }
    
};

class Gold_nugget : public Goodies {
private:
    bool m_dropped;
    
public:
    
    Gold_nugget (int startX, int startY, bool dropped, StudentWorld* world) : Goodies(IID_GOLD, startX, startY, world, right, 1.0, 1) {
        this->setVisible(true);
        m_dropped = dropped;
    }
    
    void doSomething() {
        
    }
    
    void setDrop(bool drop){
        m_dropped = drop;
    }
    bool getDrop() {
        return m_dropped;
    }
    
};

class Sonar_kit : public Goodies {
private:
    int m_tick;
    
public:
    
    void doSomething() {
        this->m_tick -= 1;
    }
    
};

class Water_pool : public Goodies{
private:
    int m_tick;
    Iceman* m_Iceman;
    
public:
    
    Water_pool(int startX, int startY, int tick, StudentWorld* world) : Goodies(IID_WATER_POOL, startX,  startY, world, right, 1.0, 2) {
        setVisible(true);
        m_tick = tick;
    }
    
    ~Water_pool() {
        this->setDead();
        this->setVisible(false);
    }
    
    void doSomething() {
        if (!isAlive()) {
            return;
        }
        
        if (this->distance(this->getX(), this->m_Iceman->getX(), this->getY(), this->m_Iceman->getY()) <= 3) {
            this->setDead();
            //GameController::getInstance().playSound(SOUND_GOT_GOODIE);
            //add score +100
            //add water to Iceman's inventory
        }
        
        if (m_tick == 0) {
            this->setDead();
            return;
        }
        
        m_tick -= 1;
    }
    
    int getTick() {
        return m_tick;
    }
    
};

class Protestor : public Actor {
private:
    
public:
    
    void doSomething() {
        
    }
    
};

class Hardcore_protesters : public Protestor {
private:
    
public:
    
    void doSomething() {
        
    }

};



// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp

#endif // ACTOR_H_
