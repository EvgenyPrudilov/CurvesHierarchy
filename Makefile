
all: main

curves.o: curves.cpp
	g++ -std=c++14 -fPIC -c curves.cpp -o curves.o

libcurves.so: curves.o
	g++ -std=c++14 -shared curves.o -o libcurves.so

main: main.cpp libcurves.so
	g++ -std=c++14 main.cpp -L. -lcurves -o main

run: main
	env LD_LIBRARY_PATH=$$LD_LIBRARY_PATH:. ./main

test: test.cpp libcurves.so
	g++ -std=c++14 test.cpp -L. -lcurves -lgtest -pthread  -o test

run-test: test
	env LD_LIBRARY_PATH=$$LD_LIBRARY_PATH:. ./test

install-google-test:
	sudo apt-get update; \
	sudo apt-get install libgtest-dev; \
	cd /usr/src/gtest; \
	sudo cmake .; \
	sudo make; \
	sudo cp lib*.a /usr/lib; 

.PHONY: clean

clean:
	rm -f curves.o libcurves.so main test
