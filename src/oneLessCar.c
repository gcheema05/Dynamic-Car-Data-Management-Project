#include "../include/headerA3.h"

/*
This function will delete a car based on postion given within the linked list.
*/
void oneLessCar (a3Car ** headLL, int whichOne) {
    // Declare and initalize all needed variables
    a3Car * toChange;
    a3Car * toDelete;
    int empty = 0;
    int counter = 1;

    // Check if headLL is NULL and set empty to 1 if true
    if (*headLL == NULL) {
        empty = 1;
    }
    // Set empty to 0 if not true
    else {
        empty = 0;
    }

    // Check if whichOne is 1 (head of the list) and if empty is 0
    if (whichOne == 1 && empty == 0) {
        toDelete = *headLL; // Set toDelete to the current headLL (dereferenced)
        *headLL = (*headLL)->nextCar; // Move head to the next car
    }
    // Check if whichOne is the last node (or tail) and check if empty is 0
    else if (whichOne == countCars(*headLL) && empty == 0) {
        // Set toDelete and toChange to current headLL
        toDelete = *headLL;
        toChange = *headLL;

        // Continue to loop till whichOne is not reached
        while (counter != whichOne) {
            // Move toDelete to next car and add one to the counter
            toDelete = toDelete->nextCar;
            counter++;
        }
        // Set counter to 1
        counter = 1;

        // Continue to loop till whichOne-1 is not reached
        while (counter != whichOne-1) {
            toChange = toChange->nextCar; // Set toChange to the nextCar
            counter++; // Add one to the counter
        }
        toChange->nextCar = NULL; // Set toChange->nextCar to NULL
    }
    // Check empty is equal to 0
    else if (empty == 0) {
        // Set toChange and toDelete to the current headLL
        toChange = *headLL;
        toDelete = *headLL;

        // Continue to loop till whichOne is not reached
        while (counter != whichOne) {
            toDelete = toDelete->nextCar; // Move toDelete to the next car
            counter++; // Add one to the counter
        }
        counter = 1; // Set counter to 1

        // Continue to loop till whichOne-1 is not reached
        while (counter != whichOne-1) {
            toChange = toChange->nextCar; // Move toChange to the next car
            counter++; // Add one to the counter
        }
        toChange->nextCar = toDelete->nextCar; // Set toChange next car to toDelete next car
    }
}
