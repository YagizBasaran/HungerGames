/*
 * Creature.h
 *
 *  Created on: Apr 20, 2023
 *      Author: süleyman yağız başaran
 *      id: 22103782
 *      sec: 3
 *      hw: 3
 */

#ifndef CREATURE_H_
#define CREATURE_H_
#include <string>
using namespace std;
#include "Food.h"

class Creature{

public:
	~Creature();
	Creature();
	Creature(int ID, double x, double y, int health);

	int ID;
	double x;
	double y;
	int health;

	//helpers
    bool checkFight(Creature creature);
    bool ifRadiusEatFood(Food food);

};


#endif /* CREATURE_H_ */
