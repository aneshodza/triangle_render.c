CC = gcc
CFLAGS = -Wall -Wextra -g

SDL = -I/opt/homebrew/opt/sdl2/include \
	-L/opt/homebrew/opt/sdl2/lib \
	-D_THREAD_SAFE -lSDL2

SRC := $(wildcard src/*.c)

TARGET = out/executable

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SDL) $^ -o $@

clean:
	rm -f $(TARGET) $(TEST_TARGET)

