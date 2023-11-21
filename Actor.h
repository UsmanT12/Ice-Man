#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"



class Goodies : public GraphObject {
private:
    
public:
    
};

class Iceman : public GraphObject {
private:
    int x;
    int y;
    std::string ID;
    
    int health;
    int sonars;
    int squirts;
    int nuggets;
    int water;
    
public:
    //initializes player to 100 health and sets all goodies to 0
    Iceman(int startX, int startY) {
        health = 10;
        sonars = 0;
        squirts = 0;
        nuggets = 0;
        water = 0;
        
        x = startX;
        y = startY;
        
        ID = "IID_PLAYER";
    }
    
    int get_x () {
        return x;
    }
    
    int get_y() {
        return y;
    }
    
    std::string get_ID() {
        return ID;
    }

    
    //function to squirt
    void squirt();
    
};

class Ice  : public GraphObject {
private:
    
public:
    
};

class Boulders : public GraphObject {
private:
    
public:
    
};

class Squirt : public GraphObject {
private:
    
public:
    
};

class Barrel_of_oil : public Goodies {
private:
    
public:
    
};

class Gold_nugget : public Goodies {
private:
    
public:
    
};

class Sonar_kit : public Goodies {
private:
    
public:
    
};

class Water_pool : public Goodies{
private:
    
public:
    
};

class Regular_protesters : public GraphObject {
private:
    
public:
    
};

class Hardcore_protesters : public GraphObject {
private:
    
public:
    
};



// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp

#endif // ACTOR_H_
