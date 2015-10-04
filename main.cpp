/* 
 * DSA 2 Project 2
 * Jason Katz
 */

#include <iostream>
#include "Heap.h"

using namespace std;

int main() {

	heap h(5);

	h.insert("id1", 1);
	h.insert("id2", 3);
	h.insert("id3", 5);
	h.insert("id4", 4);
	h.insert("id5", 2);
	
	system("pause");
	return 0;
}