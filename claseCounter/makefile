output: test.o counter.o
	g++ -o -std=c++17 -Wall test.o counter.o -o countertest

main.o: test.cpp
	g++ -c -std=c++17 -Wall test.cpp

counter.o: counter.cpp counter.h
	g++ -c -std=c++17 -Wall counter.cpp

# output2: prueba.o burrito.o 
# 	g++ -o -std=c++17 -Wall prueba.o burrito.o -o output2

# main.o: prueba.cpp
# 	g++ -c -std=c++17 -Wall prueba.cpp

# burrito.o: burrito.cpp burrito.h
# 	g++ -c -std=c++17 -Wall burrito.cpp

clean:
	rm *.o