all: inhale.cpp lzm.cpp
	g++ -c inhale.cpp -o inhale
	g++ -c lzm.cpp -o lzm
	g++ inhale lzm -o out
clean:
	rm inhale lzm