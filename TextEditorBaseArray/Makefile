output: testEditor.o editorbuffer.o
	g++ -o -std=c++17 -Wall testEditor.o editorbuffer.o -o testEB

main.o: testEditor.cpp
	g++ -c -std=c++17 -Wall testEditor.cpp

counter.o: editorbuffer.cpp editorbuffer.h
	g++ -c -std=c++17 -Wall editorbuffer.cpp

# output2: prueba.o burrito.o 
# 	g++ -o -std=c++17 -Wall prueba.o burrito.o -o output2

# main.o: prueba.cpp
# 	g++ -c -std=c++17 -Wall prueba.cpp

# burrito.o: burrito.cpp burrito.h
# 	g++ -c -std=c++17 -Wall burrito.cpp

clean:
	rm *.o