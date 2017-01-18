CCC = g++
CCFLAGS = -ansi

calculator: calculator.o display.o
	$(CCC) -o calculator calculator.cc display.cc

testdriver: driver.o
	$(CCC) -o testdriver driver.o

clean:
	rm -f *.o

real_clean: clean
	rm -f testdriver calculator
