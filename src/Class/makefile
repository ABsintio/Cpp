classI:
	g++ ClassI.cpp -o ClassI.exe

classII:
	g++ ClassII.cpp -o ClassII.exe

runI:
	./ClassI.exe > ClassI.out

runII:
	./ClassII.exe > ClassII.out

run:
	make classI
	make classII
	make runI
	make runII
	make clean

clean:
	rm *.exe