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
    int ID;
    
    int health;
    int sonars;
    int squirts;
    int nuggets;
    int water;
    
public:
    //initializes player to 10 health and sets all goodies
    //TODO: fix Iceman constructor so that it can be called in StudentWorld
    //Iceman(int imageID, int startX, int startY, d, size, depth) : GraphObject(imageID, startX, startY, Direction d, double size, int depth) {
    Iceman(int imageID, int startX, int startY) : GraphObject(imageID, startX, startY) {
        health = 10;
        sonars = 1;
        squirts = 5;
        nuggets = 0;
        ID = 0;
        
        setdepth();
    }
    
    int get_x () {
        return x;
    }
    
    int get_y() {
        return y;
    }
    
    int get_ID() {
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
