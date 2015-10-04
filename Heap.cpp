#include "Heap.h"

heap::heap(int cap) {
	capacity = cap;
	size = 0;
	data.resize(capacity + 1);
	mapping = new hashTable(capacity * 2);
}

int heap::insert(const std::string &id, int key, void * pv) {
	if (size == capacity) {
		return 1;
	}

	if (mapping->contains(id)) {
		return 2;
	}

	// Percolate up
	int hole = percolateUp(++size, key);
	
	data[hole] = node(id, key, pv);
	mapping->insert(id, pv);
	return 0;
}

int heap::percolateUp(int posCur, int key) {
	for (; posCur > 1 && key < data[posCur / 2].key; posCur/= 2) {
		data[posCur] = data[posCur / 2];
	}
	return posCur;
}

heap::node::node(const std::string &i, int k, void * pv) {
	id = i;
	key = k;
	pData = pv;
}