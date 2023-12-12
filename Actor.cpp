#include "Actor.h"
#include "StudentWorld.h"
#include "GraphObject.h"
#include <cmath>

using namespace std;

void Iceman::doSomething() {
    if (!this->isAlive()) {
        return;
    }
    
    if (this->getHealth() <= 0) {
        this->setDead();
        return;
    }
    
    //plays digging sound if ice is broken
    if(getWorld()->removeIce(getX(), getY()))
        this->getWorld()->playSound(SOUND_DIG);
    
    //All of the movement and actions for Iceman to do per tick
    int key;
    if (this->getWorld()->getKey(key)) {
        switch (key) {
                //moves left if possible
            case KEY_PRESS_LEFT:
                if (this->getDirection() != left) {
                    this->setDirection(left);
                }
                else if (getX() > 0) {
                    moveTo(getX() - 1, getY());
                }
                else if(getY() == 59) {
                    moveTo(getX(), getY());
                }
                break;
                
                //moves right if possible
            case KEY_PRESS_RIGHT:
                if (this->getDirection() != right) {
                    this->setDirection(right);
                }
                else if (getX() <= 59) {
                    moveTo(getX() + 1, getY());
                }
                else if(getY() == 60) {
                    moveTo(getX(), getY());
                }
                break;
                
                //moves up if possible
            case KEY_PRESS_UP:
                if (this->getDirection() != up) {
                    this->setDirection(up);
                }
                else if (getY() <= 59) {
                    moveTo(getX(), getY() + 1);
                }
                else if(getY() == 60) {
                    moveTo(getX(), getY());
                }
                break;
                
                //moves down if possible
            case KEY_PRESS_DOWN:
                if (this->getDirection() != down) {
                    this->setDirection(down);
                }
                else if (getY() >= 0) {
                    moveTo(getX(), getY() - 1);
                }
                else if(getY() == 0) {
                    moveTo(getX(), getY());
                }
                break;
                
                //uses squirt
            case KEY_PRESS_SPACE:
                if (this->m_squirts > 0) {
                    this->m_squirts -= 1;
                    this->useSquirt();
                }
                break;
                
                //ends game
            case KEY_PRESS_ESCAPE:
                this->setDead();
                break;
                
                //use gold nugget
            case KEY_PRESS_TAB:
                if (this->m_gold > 0) {
                    this->m_gold -= 1;
                    return this->useGold();
                }
                break;
                
                //use sonar
            case 'z':
                if (this->m_sonars > 0) {
                    this->m_sonars -= 1;
                    return this->useSonar();
                }
                break;
            case 'Z':
                if (this->m_sonars > 0) {
                    this->m_sonars -= 1;
                    return this->useSonar();
                }
                break;
        }
    }
}

