all: main.o graphics.o raster.o matrix.o mesh.o vect4.o
	g++ main.o graphics.o raster.o matrix.o mesh.o vect4.o

main.o: main.cpp
	g++ -c main.cpp

graphics.o: graphics.cpp graphics.h
	g++ -c graphics.cpp

raster.o: raster.cpp raster.h
	g++ -c raster.cpp

mesh.o: mesh.cpp mesh.h
	g++ -c mesh.cpp

matrix.o: matrix.cpp matrix.h
	g++ -c matrix.cpp

vect4.o: vect4.cpp vect4.h
	g++ -c vect4.cpp

display:
	display out.ppm

run:
	make
	./a.out
	make display

clean:
	rm *.o
	rm a.out
	rm *.ppm
