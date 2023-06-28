/*
 * Food.cpp
 *
 *  Created on: Apr 20, 2023
 *      Author: süleyman yağız başaran
 *      id: 22103782
 *      sec: 3
 *      hw: 3
 */

#include <string.h>
#include <iostream>
using namespace std;
#include "Food.h"

Food::Food( int ID, double x, double y, int quality, int spawnTime){

	this->x = x;
	this->y = y;
	this->ID = ID;
	this->quality = quality;
	this->spawnTime = spawnTime;

}

Food::Food(){
/*
	this->x = 0;
	this->y = 0;
	this->ID = 0;
	this->quality = 0;
	this->spawnTime = 0;*/

};

Food::~Food(){};
