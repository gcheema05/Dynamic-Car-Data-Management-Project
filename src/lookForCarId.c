#include "../include/headerA3.h"

/*
This function will look for a car within the linked list based on carId and return the position.
*/
int lookForCarId (struct car * headLL, int key) {
    // Declare and initalize all needed variables
    int counter = 0;

    // If headLL is empty then return -1
    if (headLL == NULL) {
        return -1;
    }

    // Continue to loop while headLL is not NULL
    while (headLL != NULL) {
        // Check if headLL's carId matches given carId and return counter+1 if true
        if (headLL->carId == key) {
            return counter + 1;
        }
        headLL = headLL->nextCar; // Move on to the next car
        counter++; // Add one to the counter
    }
    return -1; // Return -1 in all other cases
}
