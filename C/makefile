kepler.exe: main.o planete.o point.o
	gcc -o kepler.exe main.o planete.o point.o -lm
main.o: main.c planete.h
	gcc -g -Wall -c main.c
planete.o: planete.c planete.h
	gcc -g -Wall -c planete.c
point.o: point.c point.h
	gcc -g -Wall -c point.c
clean:
	rm *.o kepler.exe