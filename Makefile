Lab7: main.o
	g++ -std=c++11 -g main.o -o Lab7

main.o: main.cpp LinkedList.h Node.h Test.h LinkedList.hpp Node.hpp Test.hpp
	g++ -std=c++11 -g -c main.cpp


clean:
	rm *.o Lab7
	clean done
