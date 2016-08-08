CFLAGS=-Wall -g -std=c99

objects := $(patsubst src/%.c,src/%.o,$(wildcard src/*.c))
testObjects := $(patsubst tests/%.c,tests/%.o,$(wildcard tests/*.c))

check: compile
	@bin/test

compile: $(objects) $(testObjects)
	@mkdir -p bin
	@gcc $(CFLAGS) -o bin/test $(objects) $(testObjects) `pkg-config --cflags --libs check`

.PHONY: clean

clean:
	@rm -rf src/*.o tests/*.o bin
