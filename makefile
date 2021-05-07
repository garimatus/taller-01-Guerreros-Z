MKDIR=mkdir
CP=cp



taller01: dir main.o funciones.o
	g++ build/main.o build/funciones.o -o bin/taller01
	rm -fr build/*.o build

dir:
	mkdir -p build bin

main.o: main.cpp
	g++ -c main.cpp -o build/main.o

funciones.o: dependencias/funciones.cpp dependencias/funciones.h
	g++ -c dependencias/funciones.cpp -o build/funciones.o

clean:
	rm -fr build/*.o bin/* build bin maximos.csv artistico.csv humanismo.csv tecnicos.csv 
