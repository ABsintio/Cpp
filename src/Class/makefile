classI:
	g++ ClassI.cpp -o ClassI.exe

classII:
	g++ ClassII.cpp -o ClassII.exe

specialmember:
	g++ SpecialMembers.cpp -o SpecialMembers.exe

friendship:
	g++ Friendship.cpp -o Friendship.exe

polymorphism:
	g++ Polymorphism.cpp -o Polymorphism.exe

runI:
	./ClassI.exe > ClassI.out

runII:
	./ClassII.exe > ClassII.out

runSpecialMembers:
	./SpecialMembers.exe > SpecialMembers.out

runFriendship:
	./Friendship.exe > Friendship.out

runPolymorphism:
	./Polymorphism.exe > Polymorphism.out

run:
	make classI
	make classII
	make specialmember
	make friendship
	make polymorphism
	make runI
	make runII
	make runSpecialMembers
	make runFriendship
	make runPolymorphism
	make clean

clean:
	rm *.exe