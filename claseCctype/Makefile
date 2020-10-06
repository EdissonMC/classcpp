output: prueba.o mycctype.o
	g++ -o -std=c++17 -Wall prueba.o mycctype.o -o mycctype

main.o: prueba.cpp
	g++ -c -std=c++17 -Wall prueba.cpp

counter.o: mycctype.cpp mycctype.h
	g++ -c -std=c++17 -Wall mycctype.cpp

# output2: prueba.o burrito.o 
# 	g++ -o -std=c++17 -Wall prueba.o burrito.o -o output2

# main.o: prueba.cpp
# 	g++ -c -std=c++17 -Wall prueba.cpp

# burrito.o: burrito.cpp burrito.h
# 	g++ -c -std=c++17 -Wall burrito.cpp

clean:
	rm *.o