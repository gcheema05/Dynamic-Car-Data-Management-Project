#include "../include/headerA3.h"

/*
This function will look for a car and return the position based on the model and type.
*/
int lookForCarModelType (struct car * headLL, char key [100]) {
    // Declare and initalize all needed variables
    char * carInfo [2];
    int counter = 0;

    // Get the model and type from the given string using strtok
    carInfo[0] = strtok(key, " ");
    carInfo[1] = strtok(NULL, "\n");

    // Check if list is empty and if true then return -1 (no cars to look for)
    if (headLL == NULL) {
        return -1;
    }

    // Continue to loop while headLL is not NULL
    while (headLL != NULL) {
        // Use strcmp to find if the current node's model and type match the given model and type
        if (strcmp(headLL->model, carInfo[0]) == 0 && strcmp(headLL->type, carInfo[1]) == 0) {
            return counter + 1; // If found then return the counter + 1
        }
        // Move the headLL to the next car
        headLL = headLL->nextCar;
        counter++; // Add one to counter
    }
    return -1; // Return -1 in all other cases
}
