output: ejemploPoint.o point.o
	g++ -o -std=c++17 -Wall ejemploPoint.o point.o -o point

ejemploPoint.o: ejemploPoint.cpp
	g++ -c -std=c++17 -Wall ejemploPoint.cpp

point.o: point.cpp point.h
	g++ -c -std=c++17 -Wall point.cpp

# output2: prueba.o burrito.o 
# 	g++ -o -std=c++17 -Wall prueba.o burrito.o -o output2

# main.o: prueba.cpp
# 	g++ -c -std=c++17 -Wall prueba.cpp

# burrito.o: burrito.cpp burrito.h
# 	g++ -c -std=c++17 -Wall burrito.cpp

clean:
	rm *.o