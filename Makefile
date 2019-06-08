project2.exe: project2.o class.o
	g++ -o project2.exe project2.o class.o -lncurses

project2.o: project2.cpp class.h
	g++ -c project2.cpp -lncurses

class.o: class.cpp class.h
	g++ -c class.cpp -lncurses

