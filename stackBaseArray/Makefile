output: test.o
	g++ -o -std=c++17 -Wall test.o -o testStack


main.o: test.cpp
	g++ -c -std=c++17 -Wall test.cpp

stack.o: stack.h stack.cpp
	g++ -c -std=c++17 -Wall stack.h

# output2: prueba.o burrito.o 
# 	g++ -o -std=c++17 -Wall prueba.o burrito.o -o output2

# main.o: prueba.cpp
# 	g++ -c -std=c++17 -Wall prueba.cpp

# burrito.o: burrito.cpp burrito.h
# 	g++ -c -std=c++17 -Wall burrito.cpp

clean:
	rm *.o