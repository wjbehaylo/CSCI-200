Target= A1.exe
$(Target): main.o
	g++ -o $@ $^
main.o: main.cpp
	g++ -o $@ -c $<
