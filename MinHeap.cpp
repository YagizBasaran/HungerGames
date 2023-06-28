/*
 * MinHeap.cpp
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
#include "MinHeap.h"
#include "Food.h"

// Default constructor
MinHeap::MinHeap() {
	size = 0;
}

bool MinHeap::heapIsEmpty() {
	return (size == 0);
}

void MinHeap::heapDelete(Food &rootItem) {
	//if (heapIsEmpty())
	//	return;
	//else {
		rootItem = items[0];
		items[0] = items[--size];
		heapRebuild(0);
	//}
}

void MinHeap::heapRebuild(int root) {
	int leftChild = 2 * root + 1; 	// index of root's left child, if any
	if ( leftChild < size ) {
		// root is not a leaf so that it has a left child
		int rightChild = leftChild + 1; 	// index of a right child, if any
		// If root has right child, find larger child
		if ( (rightChild < size) && (items[rightChild].spawnTime < items[leftChild].spawnTime) )
		{//<=
				leftChild = rightChild;
		}


		// If root’s item is smaller than larger child, swap values
		if ( items[root].spawnTime > items[leftChild].spawnTime ) { // >=
			Food temp = items[root];
			items[root] = items[leftChild];
			items[leftChild] = temp;
			/*
			}*/
			// transform the new subtree into a heap
			heapRebuild(leftChild);
		}
	}
}

//helpers

int MinHeap::getSize(){
	return size;
}

Food MinHeap::peek(){
	return items[0];
}

void MinHeap::heapInsert(Food &newItem){

	//if (size >= MIN_HEAP)
	//	return;

	items[size] = newItem;

	int place = size;
	int parent = (place - 1)/2;
	while ( (place > 0) && (items[place].spawnTime < items[parent].spawnTime) ) { // <


			Food temp = items[parent];
			items[parent] = items[place];
			items[place] = temp;

			place = parent;
			parent = (place - 1)/2;
	//	}
			/*
		else if(
		else break;*/
	}
 	++size;
}


