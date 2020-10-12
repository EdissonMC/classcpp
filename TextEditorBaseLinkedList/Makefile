output: testEditor.o editorbuffer.o charstack.o
	g++ -o -std=c++17 -Wall testEditor.o editorbuffer.o charstack.o -o testEB

main.o: testEditor.cpp
	g++ -c -std=c++17 -Wall testEditor.cpp


counter.o: editorbuffer.cpp editorbuffer.h
	g++ -c -std=c++17 -Wall editorbuffer.cpp

charstack.o: charstack.cpp charstack.h
	g++ -c -std=c++17 -Wall charstack.cpp
	

# main.o: prueba.cpp
# 	g++ -c -std=c++17 -Wall prueba.cpp

# burrito.o: burrito.cpp burrito.h
# 	g++ -c -std=c++17 -Wall burrito.cpp

clean:
	rm *.o