classI:
	g++ ClassI.cpp -o ClassI.exe

classII:
	g++ ClassII.cpp -o ClassII.exe

specialmember:
	g++ SpecialMembers.cpp -o SpecialMembers.exe

runI:
	./ClassI.exe > ClassI.out

runII:
	./ClassII.exe > ClassII.out

runSpecialMembers:
	./SpecialMembers.exe > SpecialMembers.out

run:
	make classI
	make classII
	make specialmember
	make runI
	make runII
	make runSpecialMembers
	make clean

clean:
	rm *.exe