CC = gcc
CFLAGS = -O2 -Wall -Wextra `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs`

game:
	$(CC) $(CFLAGS) main.c -o $@ $(LDFLAGS)

clean:
	rm game

run: game
	./game
