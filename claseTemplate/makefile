output: usandobigger.o
	g++ -o -std=c++17 -Wall usandobigger.o -o obigger


main.o: usandobigger.cpp
	g++ -c -std=c++17 -Wall usandobigger.cpp

bigger.o: bigger.h bigger.cpp
	g++ -c -std=c++17 -Wall bigger.h

# output2: prueba.o burrito.o 
# 	g++ -o -std=c++17 -Wall prueba.o burrito.o -o output2

# main.o: prueba.cpp
# 	g++ -c -std=c++17 -Wall prueba.cpp

# burrito.o: burrito.cpp burrito.h
# 	g++ -c -std=c++17 -Wall burrito.cpp

clean:
	rm *.o