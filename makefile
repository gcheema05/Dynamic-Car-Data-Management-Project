carBase: addNewCar.o loadCarData.o printAll.o printOne.o lookForCarId.o lookForCarModelType.o countCars.o sortCarId.o oneLessCar.o noMoreCars.o mainA3.o
	gcc addNewCar.o loadCarData.o printAll.o printOne.o lookForCarId.o lookForCarModelType.o countCars.o sortCarId.o oneLessCar.o noMoreCars.o mainA3.o -g -o bin/carBase
addNewCar.o: src/addNewCar.c include/headerA3.h
	gcc -Wall -std=c99 -c -g src/addNewCar.c
loadCarData.o: src/loadCarData.c include/headerA3.h
	gcc -Wall -std=c99 -c -g src/loadCarData.c
printAll.o: src/printAll.c include/headerA3.h
	gcc -Wall -std=c99 -c -g src/printAll.c
printOne.o: src/printOne.c include/headerA3.h
	gcc -Wall -std=c99 -c -g src/printOne.c
lookForCarId.o: src/lookForCarId.c include/headerA3.h
	gcc -Wall -std=c99 -c -g src/lookForCarId.c
lookForCarModelType.o: src/lookForCarModelType.c include/headerA3.h
	gcc -Wall -std=c99 -c -g src/lookForCarModelType.c
countCars.o: src/countCars.c include/headerA3.h
	gcc -Wall -std=c99 -c -g src/countCars.c
sortCarId.o: src/sortCarId.c include/headerA3.h
	gcc -Wall -std=c99 -c -g src/sortCarId.c
oneLessCar.o: src/oneLessCar.c include/headerA3.h
	gcc -Wall -std=c99 -c -g src/oneLessCar.c
noMoreCars.o: src/noMoreCars.c include/headerA3.h
	gcc -Wall -std=c99 -c -g src/noMoreCars.c
mainA3.o: src/mainA3.c include/headerA3.h
	gcc -Wall -std=c99 -c -g src/mainA3.c
clean:
	rm *.o bin/carBase
