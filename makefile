CXX = g++
CXXFLAGS = -Wall -g

main: main.cpp BrowserHistory.o
	$(CXX) $(CXXFLAGS) main.cpp BrowserHistory.o -o main

BrowserHistory.o: BrowserHistory.h BrowserHistory.cpp 
	$(CXX) $(CXXFLAGS) -c BrowserHistory.cpp

run:
	./main

clean:
	rm -f *.o main

leaks:
	leaks --atExit -- ./main
