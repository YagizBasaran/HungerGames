/*
 * SimulationMgr.cpp
 *
 *  Created on: Apr 20, 2023
 *      Author: süleyman yağız başaran
 *      id: 22103782
 *      sec: 3
 *      hw: 3
 */

#include <string.h>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#include "Creature.h"
#include "MaxHeap.h"
#include "MinHeap.h"

int main(int argc, char* argv[]) { //int argc, char **argv

		Creature creatures[30];

		MaxHeap maxxHeap;
	//MinHeap minnHeap;
	    MinHeap minnHeap;

	    int numOfCreatures = 0;
	    int creatureCountFromFile = 0;
	    int lineCount = 0;


	    fstream file (argv[1], ios::in);
	    if(file.is_open())
		{

	        bool isEntrance = true;
	        bool isCreature = false;
	        int tempID;
	        double tempx;
	        double tempy;
	        int tempHealth;
	        bool isFood = false;
	        int tempQuality;
	        int tempSpawnTime;
	        int lineStoreVal = 0;
	        std::string line;
	        //File Reading Part
	        while(getline(file,line))
	        {
	            std::stringstream   linestream(line);
	            std::string         value;

	            while(getline(linestream,value,','))
	            {
	                if(isEntrance){
	                	numOfCreatures = stoi(value);
	                isEntrance = false;
	                }
	                else if(isCreature){
	                    if(lineStoreVal == 0){
	                        tempID = stoi(value);
	                    }
	                    else if(lineStoreVal == 1){
	                        tempx = std::stod(value);
	                    }
	                    else if(lineStoreVal == 2){
	                        tempy = std::stod(value);
	                    }
	                    else if(lineStoreVal == 3){
	                        tempHealth = stoi(value);
	                    }
	                }
	                else if(isFood){
	                    if(lineStoreVal == 0){
	                        tempID = stoi(value);
	                    }
	                    else if(lineStoreVal == 1){
	                        tempx = std::stod(value);
	                    }
	                    else if(lineStoreVal == 2){
	                        tempy = std::stod(value);
	                    }
	                    else if(lineStoreVal == 3){
	                        tempQuality = stoi(value);
	                    }
	                    else if(lineStoreVal == 4){
	                        tempSpawnTime = stoi(value);
	                    }
	                }

	                lineStoreVal++;
	            }

	            lineStoreVal = 0;

	            if(isCreature){
	                Creature cr1(tempID,tempx,tempy,tempHealth);
	                creatures[creatureCountFromFile] = cr1;
	                creatureCountFromFile++;
	            }

	            if(isFood){
	                Food f1(tempID,tempx,tempy,tempQuality,tempSpawnTime);
	                minnHeap.heapInsert(f1);
	            }

	            lineCount++;
	            if(lineCount == 1){
	                isCreature = true;
	            }
	            if(lineCount > numOfCreatures){
	                isCreature = false;
	                isFood = true;
	            }

	        }
		}
		else{

	    }
	    //End of file read

	    //Sort method for creatures array (selection sort)
	    for(int i=0; i<numOfCreatures; i++){
			int minID = creatures[i].ID;
			int minElement = i;
			for(int j=i+1; j<numOfCreatures; j++){
				if(creatures[j].ID < minID){
					minID = creatures[j].ID;
					minElement = j;
				}
			}
			Creature tempCreature(creatures[i].ID, creatures[i].x, creatures[i].y, creatures[i].health);
			creatures[i] = creatures[minElement];
			creatures[minElement] = tempCreature;
		}

	    //end of sort
	 	int timeTick = 0;
	    //int numOfCreatures = 4;
	    int numOfAliveCreatures = numOfCreatures;

/*
	    Creature ct1 = Creature(2,10,2,15);
	    Creature ct2 = Creature(1,1,1,15);
	    Creature ct3 = Creature(3,4,5,15);
	    Creature ct4 = Creature(4,3,5.5,15);

	    Creature creatures[numOfCreatures];

	    creatures[0] = ct2;
	    creatures[1] = ct1;
	    creatures[2] = ct3;
	    creatures[3] = ct4;*/

/*
	    Food f1 = Food(1,7,11,1,0);
	    Food f2 = Food(2,2,2,5,13);
	    Food f3 = Food(3,1,3,11,0);
	    Food f4 = Food(4,8,2,2,0);
	    Food f5 = Food(5,2,12,10,4);
	    minnHeap.heapInsert(f1);
	    minnHeap.heapInsert(f2);
	    minnHeap.heapInsert(f3);
	    minnHeap.heapInsert(f4);
	    minnHeap.heapInsert(f5);*/

	    cout << setprecision(2) << fixed;

	    while( numOfAliveCreatures > 0){

	        for(int i = 0; i < numOfCreatures; i++)
	            cout << "Creature " << creatures[i].ID << ": " << creatures[i].x << ", "<< creatures[i].y << endl;

	        if(!minnHeap.heapIsEmpty()){
	        	bool exit = false; //?
				while(!exit) { // Adding foods to the game
						Food tempFood = minnHeap.peek();
						if(minnHeap.peek().spawnTime == timeTick && maxxHeap.idCheck(tempFood.ID) == false){//?
						minnHeap.heapDelete(tempFood);
						maxxHeap.heapInsert(tempFood);
						}
						else exit = true;
				}
	        }

	        for(int i = 0; i < numOfCreatures; i++)
	        { // FIGHT
	            for(int j = 0; j < numOfCreatures; j++)
	            {
	                if(i != j)
	                {
	                    if(creatures[i].checkFight(creatures[j]))
	                    {
	                        creatures[j].health = 0;
	                    }
	                }
	            }
	        }


	        for(int i = 0; i < numOfCreatures; i++)
	        { // EATING
	        	if(!maxxHeap.heapIsEmpty())
	        	{
					if(creatures[i].ifRadiusEatFood(maxxHeap.peek()))
					{
							Food tempFood2 = maxxHeap.peek();
							creatures[i].health += maxxHeap.peek().quality;
							maxxHeap.heapDelete(tempFood2);
					}
	            }
	        }

	        for(int i = 0; i < numOfCreatures; i++)
	        { // MOVE
	        	if(!maxxHeap.heapIsEmpty() && creatures[i].health > 0){
	        		    double temp1 = creatures[i].x - maxxHeap.peek().x;
	        		    double temp11 = pow(temp1,2);
	        		    double temp2 = creatures[i].y - maxxHeap.peek().y;
	        		    double temp22 = pow(temp2,2);

	        		    double lastDistance = sqrt(temp11 + temp22);

	        		    if(creatures[i].health <= 10 )
	        		    {
	        		        double xMoveAmount = (maxxHeap.peek().x - creatures[i].x)/lastDistance;
	        		        double yMoveAmount = (maxxHeap.peek().y - creatures[i].y)/lastDistance;

	        		        creatures[i].x += xMoveAmount;
	        		        creatures[i].y += yMoveAmount;
	        		    }
	        		    else if(creatures[i].health > 10)
	        		    {
	        		         double xMoveAmount = ((maxxHeap.peek().x - creatures[i].x)/lastDistance) * ((10.00/creatures[i].health));
	        		         double yMoveAmount = ((maxxHeap.peek().y - creatures[i].y)/lastDistance) * ((10.00/creatures[i].health));

	        		         creatures[i].x += xMoveAmount;
	        		         creatures[i].y += yMoveAmount;
	        		    }
	        	}
	        }

	        for(int i = 0; i < numOfCreatures; i++)
	        { //DECREASE HEALTH
	            if(creatures[i].health > 0)
	                creatures[i].health--;
	        }

	        int count = 0;
	        for(int i = 0; i < numOfCreatures; i++)
	        {
	            if(creatures[i].health == 0)
	                count++;
	        }

	        /*
	        cout << "Time Tick: " << timeTick << endl;
	        cout << "Num Of Alive Creatures: " << numOfAliveCreatures << endl;
	        for(int i = 0; i<numOfCreatures; i++){
	        	if(creatures[i].health > 0)
	        		cout << "Alive cre: " <<creatures[i].ID << " Health: " << creatures[i].health << endl;
	        }
	        cout << endl;*/

	        numOfAliveCreatures = numOfCreatures - count;
	        timeTick++; //TIME TICK
	    }


	    return 0;

}




