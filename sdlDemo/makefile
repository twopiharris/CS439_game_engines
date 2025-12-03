game: main.o scene.o sprite.o
	g++ main.o scene.o sprite.o $(shell pkg-config --cflags --libs sdl2) -o game

main.o: main.cpp scene.h sprite.h
	g++ main.cpp $(shell pkg-config --cflags --libs sdl2) -c

scene.o: scene.cpp scene.h
	g++ scene.cpp $(shell pkg-config --cflags --libs sdl2) -c

sprite.o: sprite.cpp sprite.h scene.h
	g++ sprite.cpp $(shell pkg-config --cflags --libs sdl2) -c

clean:
	rm *.o
	rm game

run: game
	./game
	
