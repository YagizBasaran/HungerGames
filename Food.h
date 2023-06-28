/*
 * Food.h
 *
 *  Created on: Apr 20, 2023
 *      Author: süleyman yağız başaran
 *      id: 22103782
 *      sec: 3
 *      hw: 3
 */

#ifndef FOOD_H_
#define FOOD_H_
#include <string>
using namespace std;

class Food{

public:
	Food();
	~Food();
	Food( int ID, double x, double y, int quality, int spawnTime);

	double x;
	double y;
	int ID;
	int quality;
	int spawnTime;

};

#endif /* FOOD_H_ */
