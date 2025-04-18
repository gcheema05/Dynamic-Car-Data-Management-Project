#include "../include/headerA3.h"

/*
This function will sort the given linked list in ascending order based on carId.
*/
void sortCarId (struct car ** headLL) {
    // Declare and initalize all needed variables
    a3Car * current;
    a3Car * next;
    int numOfCars = 0;
    numOfCars = countCars(*headLL);
    int i, j;
    int tempYear = 0;
    double tempPrice = 0;
    char tempModel [MAX_LENGTH];
    char tempType [MAX_LENGTH];
    int tempId = 0;

    // Set current to headLL (dereferenced)
    current = *headLL;

    // Outer for loop to loop through each car (or node within the linked list)
    for (i = 0; i < numOfCars - 1; i++) {
        // Move next to the current next car
        next = current->nextCar;

        // Inner for loop to loop through each remaining car (or node within the linked list)
        for (j = 0; j < numOfCars - i - 1; j++) {
            // Check if current's carId is greater than the next
            if (current->carId > next->carId) {
                // Swap the years from current to next and next to current
                tempYear = current->year;
                current->year = next->year;
                next->year = tempYear;

                // Swap the price from current to next and next to current
                tempPrice = current->price;
                current->price = next->price;
                next->price = tempPrice;

                // Swap the model from current to next and next to current
                strcpy (tempModel, current->model);
                strcpy (current->model, next->model);
                strcpy(next->model, tempModel);

                // Swap the type from current to next and next to current
                strcpy (tempType, current->type);
                strcpy (current->type, next->type);
                strcpy(next->type, tempType);

                // Swap the carId from current to next and next to currrent
                tempId = current->carId;
                current->carId = next->carId;
                next->carId = tempId;
            }
            // Move on to the next car (or node)
            next = next->nextCar;
        }
        // Move on to the next car for the new current (or node)
        current = current->nextCar;
    }
}
