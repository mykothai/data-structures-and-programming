all: listDifference

listDifference: listDifference.o
	g++ -o listDifference listDifference.o

listDifference.o: listDifference.cpp priority_queue.h
	g++ -c listDifference.cpp

clean:
	rm -f listDifference *.o
