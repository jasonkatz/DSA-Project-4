#include "Heap.h"

heap::heap(int cap) {
	data.resize(capacity + 1);
	mapping = new hashTable(capacity * 2);
	capacity = cap;
	size = 0;
}

int heap::insert(const std::string &id, int key, void * pv) {
	if (size == capacity) {
		return 1;
	}

	if (mapping->contains(id)) {
		return 2;
	}

	// Percolate up
	int hole = ++size;
	for (; hole > 1 && key < data[hole / 2].key; hole /= 2) {
		data[hole] = data[hole / 2];
	}
	
	data[hole] = node(id, key, pv);
	mapping->insert(id, pv);
	return 0;
}

heap::node::node(const std::string &i, int k, void * pv) {
	id = i;
	key = k;
	pData = pv;
}