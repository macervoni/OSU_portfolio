main: labRat.o holoRadio.o specimenTransferUnitFull.o specimenTransferUnitEmpty.o dataTransferUnitFull.o  dataTransferUnitEmpty.o sixDigitCode.o spacesuit.o crewQuartersMenu.o commsMenu.o escapePodMenu.o transportationMenu.o equipmentMenu.o scienceLabMenu.o galleyMenu.o navigationMenu.o mainCabinMenu.o scienceLab.o equipment.o transportation.o escapePod.o comms.o crewQuarters.o galley.o navigation.o main_cabin.o item.o menu.o inventory.o spaceship.o module.o main.o inputValidation.o 
	g++ -std=c++11 labRat.o holoRadio.o specimenTransferUnitFull.o specimenTransferUnitEmpty.o dataTransferUnitFull.o  dataTransferUnitEmpty.o sixDigitCode.o spacesuit.o crewQuartersMenu.o commsMenu.o escapePodMenu.o transportationMenu.o equipmentMenu.o  scienceLabMenu.o galleyMenu.o navigationMenu.o mainCabinMenu.o scienceLab.o equipment.o transportation.o escapePod.o comms.o crewQuarters.o galley.o navigation.o main_cabin.o item.o menu.o inventory.o spaceship.o module.o main.o inputValidation.o -o space


main.o: main.cpp
		g++ -std=c++11 -g -Wall -pedantic-errors -c main.cpp

labRat.o: labRat.cpp labRat.hpp
	g++ -std=c++11 -g -Wall -pedantic-errors -c labRat.cpp


holoRadio.o: holoRadio.cpp holoRadio.hpp
	g++ -std=c++11 -g -Wall -pedantic-errors -c holoRadio.cpp

specimenTransferUnitFull.o: specimenTransferUnitFull.cpp specimenTransferUnitFull.hpp
	g++ -std=c++11 -g -Wall -pedantic-errors -c specimenTransferUnitFull.cpp

specimenTransferUnitEmpty.o: specimenTransferUnitEmpty.cpp specimenTransferUnitEmpty.hpp
	g++ -std=c++11 -g -Wall -pedantic-errors -c specimenTransferUnitEmpty.cpp

dataTransferUnitFull.o: dataTransferUnitFull.cpp dataTransferUnitFull.hpp
	g++ -std=c++11 -g -Wall -pedantic-errors -c dataTransferUnitFull.cpp

dataTransferUnitEmpty.o: dataTransferUnitEmpty.cpp	dataTransferUnitEmpty.hpp
	g++ -std=c++11 -g -Wall -pedantic-errors -c dataTransferUnitEmpty.cpp

sixDigitCode.o: sixDigitCode.cpp sixDigitCode.hpp
	g++ -std=c++11 -g -Wall -pedantic-errors -c sixDigitCode.cpp

spacesuit.o: spacesuit.cpp spacesuit.hpp
	g++ -std=c++11 -g -Wall -pedantic-errors -c spacesuit.cpp

crewQuartersMenu.o: crewQuartersMenu.cpp crewQuartersMenu.hpp
	g++ -std=c++11 -g -Wall -pedantic-errors -c crewQuartersMenu.cpp

commsMenu.o: commsMenu.cpp commsMenu.hpp
	g++ -std=c++11 -g -Wall -pedantic-errors -c commsMenu.cpp

escapePodMenu.o: escapePodMenu.cpp escapePodMenu.hpp
	g++ -std=c++11 -g -Wall -pedantic-errors -c escapePodMenu.cpp

transportationMenu.o: transportationMenu.cpp transportationMenu.hpp
	g++ -std=c++11 -g -Wall -pedantic-errors -c transportationMenu.cpp

equipmentMenu.o: equipmentMenu.cpp equipmentMenu.hpp
	g++ -std=c++11 -g -Wall -pedantic-errors -c equipmentMenu.cpp

scienceLabMenu.o: scienceLabMenu.cpp scienceLabMenu.hpp
	g++ -std=c++11 -g -Wall -pedantic-errors -c scienceLabMenu.cpp

galleyMenu.o: galleyMenu.cpp galleyMenu.hpp
	g++ -std=c++11 -g -Wall -pedantic-errors -c galleyMenu.cpp

navigationMenu.o: navigationMenu.cpp navigationMenu.hpp
	g++ -std=c++11 -g -Wall -pedantic-errors -c navigationMenu.cpp

mainCabinMenu.o: mainCabinMenu.cpp mainCabinMenu.hpp
	g++ -std=c++11 -g -Wall -pedantic-errors -c mainCabinMenu.cpp

scienceLab.o: scienceLab.cpp scienceLab.hpp
	g++ -std=c++11 -g -Wall -pedantic-errors -c scienceLab.cpp

equipment.o: equipment.cpp equipment.hpp
	g++ -std=c++11 -g -Wall -pedantic-errors -c equipment.cpp

transportation.o: transportation.cpp transportation.hpp
	g++ -std=c++11 -g -Wall -pedantic-errors -c transportation.cpp

escapePod.o: escapePod.cpp escapePod.hpp
	g++ -std=c++11 -g -Wall -pedantic-errors -c escapePod.cpp

comms.o: comms.cpp comms.hpp
	g++ -std=c++11 -g -Wall -pedantic-errors -c comms.cpp

crewQuarters.o: crewQuarters.cpp crewQuarters.hpp
	g++ -std=c++11 -g -Wall -pedantic-errors -c crewQuarters.cpp

inputValidation.o: inputValidation.cpp inputValidation.hpp
	g++ -std=c++11 -g -Wall -pedantic-errors -c inputValidation.cpp

spaceship.o: spaceship.cpp spaceship.hpp
	g++ -std=c++11 -g -Wall -pedantic-errors -c spaceship.cpp

module.o: module.cpp module.hpp
	g++ -std=c++11 -g -Wall -pedantic-errors -c module.cpp

inventory.o: inventory.cpp inventory.hpp
	g++ -std=c++11 -g -Wall -pedantic-errors -c inventory.cpp

menu.o: menu.cpp menu.hpp
	g++ -std=c++11 -g -Wall -pedantic-errors -c menu.cpp

item.o: item.cpp item.hpp
	g++ -std=c++11 -g -Wall -pedantic-errors -c item.cpp

main_cabin.o: main_cabin.cpp main_cabin.hpp
	g++ -std=c++11 -g -Wall -pedantic-errors -c main_cabin.cpp

galley.o: galley.cpp galley.hpp
	g++ -std=c++11 -g -Wall -pedantic-errors -c galley.cpp

navigation.o: navigation.cpp navigation.hpp
	g++ -std=c++11 -g -Wall -pedantic-errors -c navigation.cpp


clean:
	rm *.o

