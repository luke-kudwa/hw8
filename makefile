CXX = g++
CXXFLAGS = -Wall

cfile: cfile.c
	gcc cfile.c -o cfile

cplus: cplus.cpp
	$(CXX) $(CXXFLAGS) cplus.cpp -o cplus


run:
	./cfile

run1:
	./cplus



clean:
	rm *~
	rm *.o

clean1:
	rm *.o
	rm *~
