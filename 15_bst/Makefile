all: clean tests.out

tests.out:
	g++ tests.cpp -o tests.out

andTest: tests.out
	./tests.out

clean:
	rm tests.out
