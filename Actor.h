#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"
class StudentWorld;


//Used to access student world from the actors
//class Actor : public GraphObject {
//public:
//    //functions all classes will use
//    Actor(int imageID, int startX, int startY, StudentWorld* sw, Direction startDirection, double size, unsigned int depth) : GraphObject(imageID, startX, startY, startDirection, size, depth)
//    {
//        world = sw;
//        lives = 1;
//    }
//    
//    int get_lives() {
//        return lives;
//    }
//    
//    StudentWorld* get_world() 
//    { 
//        return world;
//    }
//    
//private:
//    int lives;
//    int health;
//    StudentWorld* world;
//};

class Actor : public GraphObject{
    
public:
    Actor(int imageID, int startX, int startY, Direction dir, double size, int depth) : GraphObject(imageID, startX, startY, dir, size, depth) {
        alive = true;
    }
    virtual  void dosomething() { }
    virtual void annoyed() { }
    virtual bool isalive() { return alive; }
    virtual void set_alive(bool status) { alive = status; }
    
    virtual ~Actor() { alive = false; }
    
private:
    bool alive;
    
};

class Goodies : public Actor {
private:
    
public:
    
};

class Iceman : public Actor{
private:
    int sonars;
    int nuggets;
    int water;
    int x;
    int y;
    int ID;
    
public:
    //initializes player to 10 health and sets all goodies
    //TODO: fix Iceman constructor so that it can be called in StudentWorld
    //Iceman(int imageID, int startX, int startY, d, size, depth) : GraphObject(imageID, startX, startY, Direction d, double size, int depth) {
    Iceman(int imageID, int startX, int startY, StudentWorld* sw) : Actor(imageID, startX, startY, right, 1.0, 0) {
        //health = 10;
        sonars = 1;
        water = 5;
        nuggets = 0;
        
        x  = startX;
        y = startY;
    }
    
    ~Iceman () { }
    
    void dosomething() {
        
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

class Ice  : public Actor {
private:
    int x;
    int y;
    int ID;
    
public:
    Ice(int imageID, int startX, int startY, StudentWorld* sw) : Actor(imageID, startX, startY, right, .25, 3) {
        x = startX;
        y = startY;
        ID = imageID;
    }
    
    ~Ice() { }
    
};

class Boulders : public Actor {
private:
    
public:
    
};

class Squirt : public Actor {
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

class Protestor : public Actor {
private:
    
public:
    
};

class Hardcore_protesters : public Protestor {
private:
    
public:
    
};



// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp

#endif // ACTOR_H_
