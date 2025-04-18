#include "../include/headerA3.h"

/*
This function will count cars (or nodes) within the given linked list.
*/
int countCars (a3Car * headLL) {
    // Declare and initalize all needed variables
    int counter = 0;

    // If the linked list is empty then return -1
    if (headLL == NULL) {
        return -1;
    }

    // Continue to loop while headLL is not NULL
    while (headLL != NULL) {
        counter++; // Add one to counter
        headLL = headLL->nextCar; // Move headLL to next car in the linked list
    }
    return counter; // Return the counter (number of cars within the linked list)
}
