/*
 * MaxHeap.cpp
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
#include "MaxHeap.h"
#include "Food.h"

// Default constructor
MaxHeap::MaxHeap(){
	size = 0;
}

bool MaxHeap::heapIsEmpty(){
	return (size == 0);
}

void MaxHeap::heapDelete(Food &rootItem) {
	//if (heapIsEmpty())
	//	return;
	//else {
		rootItem = items[0];
		items[0] = items[--size];
		heapRebuild(0);
	//}
}

void MaxHeap::heapRebuild(int root) {
	int child = (2 * root) + 1; 	// index of root's left child, if any
	if ( child < size ) {
		// root is not a leaf so that it has a left child
		int rightChild = child + 1; 	// index of a right child, if any
		// If root has right child, find larger child
		if ( (rightChild < size) && (items[rightChild].quality >= items[child].quality) ){
			if((items[rightChild].quality == items[child].quality) && (items[rightChild].ID < items[child].ID))
				child = rightChild; 	// index of larger child
			else if((items[rightChild].quality != items[child].quality)) // else
				child = rightChild;
		}

		// If root’s item is smaller than larger child, swap values
		if ( items[root].quality <= items[child].quality ) {
			if( items[root].quality < items[child].quality ){
				Food temp = items[root];
				items[root] = items[child];
				items[child] = temp;
			}
			else if((items[root].quality == items[child].quality) && (items[root].ID > items[child].ID)){
				Food temp = items[root];
				items[root] = items[child];
				items[child] = temp;
			}
				// transform the new subtree into a heap
				heapRebuild(child);
		}
	}
}

//helpers

int MaxHeap::getSize(){
	return size;
}

Food MaxHeap::peek(){
	return items[0];
}
//nd
void MaxHeap::heapInsert(Food &newItem) {
	//if (size >= MAX_HEAP)
	//	return;

	items[size] = newItem;

	int place = size;
	int parent = (place - 1)/2;

	while ( (place > 0) && (items[place].quality >= items[parent].quality) ) {

		if((items[place].quality == items[parent].quality) && (items[place].ID < items[parent].ID)){
			Food temp = items[parent];
			items[parent] = items[place];
			items[place] = temp;

			place = parent;
			parent = (place - 1)/2;
		}
		else if(items[place].quality > items[parent].quality){ // (items[place].ID < items[parent].ID)
			Food temp = items[parent];
			items[parent] = items[place];
			items[place] = temp;

			place = parent;
			parent = (place - 1)/2;
		}
		else break;
	}
 	++size;
}

bool MaxHeap::idCheck(int id){
	bool ans = false;
	for(int i = 0; i <size; i++){
		if(items[i].ID == id){
			ans = true;
		}
	}
	return ans;
}


