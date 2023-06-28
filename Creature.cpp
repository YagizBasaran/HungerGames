/*
 * Creature.cpp
 *
 *  Created on: Apr 20, 2023
 *      Author: süleyman yağız başaran
 *      id: 22103782
 *      sec: 3
 *      hw: 3
 */

#include <string.h>
#include <iostream>
#include <cmath>
using namespace std;
#include "Creature.h"

Creature::Creature(){};

Creature::~Creature(){};

Creature::Creature(int ID, double x, double y, int health){

	this->ID = ID;
	this->x = x;
	this->y = y;
	this->health = health;

}
bool Creature::ifRadiusEatFood(Food food) {
    if( this->health > 0) {
        double diffX = this->x - food.x;
        double tempPowdiffX = pow(diffX,2);
        double diffY = this->y - food.y;
        double tempPowdiffY = pow(diffY,2);

        double realDistance = sqrt(tempPowdiffX + tempPowdiffY);

        if (realDistance < 1)
            return true;
        else return false;
    }
    else return false;

}

bool Creature::checkFight(Creature creature) {
    if((this->health < creature.health) || this->health == 0 || creature.health == 0)
        return false;
    else {
        double diffX = this->x - creature.x;
        double tempPowdiffX = pow(diffX,2);
        double diffY = this->y - creature.y;
        double tempPowdiffY = pow(diffY,2);

        double realDistance = sqrt(tempPowdiffX + tempPowdiffY);

        if (realDistance < 2)
            return true;
        else return false;
    }
     //?
}






