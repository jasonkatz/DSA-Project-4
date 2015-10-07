useHeap.exe: useHeap.o Heap.o Hash.o
	g++ -o useHeap.exe useHeap.o Heap.o Hash.o

useHeap.o: useHeap.cpp
	g++ -c useHeap.cpp

Heap.o: Heap.cpp Heap.h
	g++ -c Heap.cpp

Hash.o: Hash.cpp Hash.h
	g++ -c Hash.cpp

debug:
	g++ -g -o useHeapDebug.exe useHeap.cpp Heap.cpp Hash.cpp

clean:
	rm -f *.exe *.o *.stackdump *~

backup:
	test -d backups || mkdir backups
	cp *.cpp backups
	cp *.h backups
	cp Makefile backups
