#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "GameConstants.h"
#include "Actor.h"
#include <string>
#include "GraphObject.h"
#include <vector>
#include <algorithm>

using namespace std;

class Actor;
//class Iceman;
//class Ice;
//class Gold_nugget;
//class Sonar_kit;
//class Oil_barrel;
// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp

class StudentWorld : public GameWorld
{
private:
    int m_barrels;
    int m_gameScore;
    Iceman* m_player;
    //Ice* m_field[60][60];
    std::vector<Actor*> m_objects;
    int m_tick;
    
public:
    Ice* m_field[60][60];
    
	StudentWorld(std::string assetDir)
		: GameWorld(assetDir) {}

	virtual int init()
	{
        //create iceman player
        this->m_player = new Iceman(30, 60, this);
        //m_player = player;
        
        //sets oils, gold, sonars, and water
        Create_Ice_Field();
        

		return GWSTATUS_CONTINUE_GAME;
	}

	virtual int move()
	{
		// This code is here merely to allow the game to build, run, and terminate after you hit enter a few times.
		// Notice that the return value GWSTATUS_PLAYER_DIED will cause our framework to end the current level.
        //this->tick += 1;

        setGameStatText(setDisplayText());
        
        if (this->m_player->isAlive()) {
            this->m_player->doSomething();
        }
        else {
            this->decLives();
            return GWSTATUS_PLAYER_DIED;
        }
        
        for (int i = 0; i < this->m_objects.size(); i++) {
            this->m_objects[i]->doSomething();
        }
        
        return GWSTATUS_CONTINUE_GAME;
		//return GWSTATUS_PLAYER_DIED;
	}

	virtual void cleanUp()
	{
        for (int i = 0; i < this->m_objects.size(); i++){
            if (this->m_objects[i] != nullptr) {
                delete this->m_objects[i];
                this->m_objects[i] = nullptr;
            }
        }
        delete this->m_player;
	}
    
    void Create_Ice_Field() {
        
        //create the field of ice w/ mining lane
        //Ice *field [60][60];
        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 60; j++) {
                this->m_field[i][j] = new Ice(i, j, this);
            }
        }
        for (int i = 30; i < 34; i++) {
            for (int j = 0; j < 4; j++) {
                this->m_field[i][j] = new Ice(i, j, this);
            }
        }
        for (int i = 34; i < 60; i++) {
            for (int j = 0; j < 60; j++) {
                this->m_field[i][j] = new Ice(i, j, this);
            }
        }
        
        //sets the boulders on the ice field
        int B = fmin(getLevel()/2 + 2, 9);
        for (int i = 0; i < B; i++) {
            this->m_objects.push_back(new Boulder(i*6 +20, 20, this));
        }
        
        //sets the gold on the field
        int g = 5 - getLevel()/2;
        int G = std::max(g, 2);
        for (int i = 0; i < G; i++) {
            this->m_objects.push_back(new Gold_nugget(5*i + 15, 5, false, this));
        }
        
        //sets the oil barrels in the field
        int L = fmin(2+getLevel(), 21);
        for (int i = 0; i < L; i++) {
            this->m_objects.push_back(new Oil_barrel(5*i + 15, 30, this));
        }
    }
    
    
    bool removeIce(int x, int y) {
        bool destroyedIce = false;
        for (int i = 0; i < 60; i++) {
            for (int j = 0; j < 60; j++) {
                if (this->m_field[i] != nullptr && this->m_field[i][j] != nullptr) {
                    if (this->m_field[i][j]->getX() >= x && this->m_field[i][j]->getX() <= x + 3 && this->m_field[i][j]->getY() >= y && this->m_field[i][j]->getY() <= y + 3) {
                        delete this->m_field[i][j];
                        this->m_field[i][j] = nullptr;
                        destroyedIce = true;
                    }
                }
            }
        }
        return destroyedIce;
    }

    
    void spawnWater() {
        return;
    }
    
    //Sets the displayed text at the top
    std::string setDisplayText() {
        std::string level = std::to_string(getLevel());
        std::string lives = std::to_string(getLives());
        std::string health = std::to_string(this->m_player->getHealth() * 10) + "%";
        std::string squirts = std::to_string(this->m_player->getSquirts());
        std::string gold = std::to_string(this->m_player->getGold());
        std::string barrelsLeft = std::to_string(this->m_barrels);
        std::string sonar = std::to_string(this->m_player->getSonar());
        std::string score = std::to_string(this->m_gameScore);
        
        std::string stats = "Lvl: " + level + 
            " Lives: " + lives +
            " Hlth: " + health +
            " Wtr: " + squirts +
            " Gld: " + gold  +
            " Oil Left: " + barrelsLeft +
            " Sonar: " + sonar +
            " Scr: " + score;
        return stats;
    }
};

#endif // STUDENTWORLD_H_
