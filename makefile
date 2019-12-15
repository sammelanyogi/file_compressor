all: param.cpp inhale.cpp lzm.cpp
	g++ -c param.cpp -o param
	g++ -c inhale.cpp -o inhale
	g++ -c lzm.cpp -o lzm
	g++ param inhale lzm -o a.out
	rm inhale lzm param

clean:
	rm sammelan