/*
 * MaxHeap.h
 *
 *  Created on: Apr 20, 2023
 *      Author: süleyman yağız başaran
 *      id: 22103782
 *      sec: 3
 *      hw: 3
 */

#ifndef MAXHEAP_H_
#define MAXHEAP_H_

const int MAX_HEAP = 30;
#include "Food.h"// definition of KeyedItem
//typedef Food HeapItemType;

class MaxHeap {
public:
	MaxHeap();				// default constructor
	// copy constructor and destructor are supplied by the compiler

	bool heapIsEmpty();
	void heapInsert(Food &newItem); // const
	void heapDelete(Food &rootItem);

	//Helpers
	int getSize();
	bool idCheck(int id);
	// bool isIDFoodMatch
	Food peek();
//private
	Food items[30];	// array of heap items
	int          size;            	// number of heap items

//protected:
	void heapRebuild(int root);		// Converts the semiheap rooted at
					        // index root into a heap
};

#endif /* MAXHEAP_H_ */
