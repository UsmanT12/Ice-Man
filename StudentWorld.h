#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "GameConstants.h"
#include "Actor.h"
#include <string>
#include "GraphObject.h"
// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp
class Actor;

class StudentWorld : public GameWorld
{
public:
	StudentWorld(std::string assetDir)
		: GameWorld(assetDir)
	{
	}

	virtual int init()
	{
        //create iceman player
        Iceman *player = new Iceman(0, 30, 60, this);
        player->setVisible(true);
        
        //create the field of ice
        Ice *field [60][60];
        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 60; j++) {
                field[i][j] = new Ice(6, i, j, this);
                field[i][j]->setVisible(true);
            }
        }
        //creates mining lane
        for (int i = 30; i < 34; i++) {
            for (int j = 0; j < 4; j++) {
                field[i][j] = new Ice(6, i, j, this);
                field[i][j]->setVisible(true);
            }
        }
        for (int i = 34; i < 60; i++) {
            for (int j = 0; j < 60; j++) {
                field[i][j] = new Ice(6, i, j, this);
                field[i][j]->setVisible(true);
            }
        }
        
        //sets oils, gold, sonars, and water
        
		return GWSTATUS_CONTINUE_GAME;
	}

	virtual int move()
	{
		// This code is here merely to allow the game to build, run, and terminate after you hit enter a few times.
		// Notice that the return value GWSTATUS_PLAYER_DIED will cause our framework to end the current level.
		decLives();
        
        //TODO: Work on the score keeping string here
        std::string lvl = std::to_string(getLevel());
        std::string lives = std::to_string(getLives());
        //figure out how to get health from player
        //std::string health = std::to_string(get_health() * 10);
        setGameStatText("Lvl: " + lvl +  " Lives: " " Hlth: "  + "% " "Wtr:  Gld:   Oil Left:   Sonar:   Scr: " );
        
        return GWSTATUS_CONTINUE_GAME;
		//return GWSTATUS_PLAYER_DIED;
	}

	virtual void cleanUp()
	{
	}

private:
    int x;
    int y;
};

#endif // STUDENTWORLD_H_
