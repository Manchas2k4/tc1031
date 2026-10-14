all: tests.out speed.out

tests.out:
	g++ tests.cpp -o tests.out

speed.out:
	g++ speed.cpp -o speed.out

andTest: tests.out
	./tests.out

andSpeed:speed.out
	./speed.out

clean:
	rm tests.out speed.out
