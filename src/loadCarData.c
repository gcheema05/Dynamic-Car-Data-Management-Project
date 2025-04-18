#include "../include/headerA3.h"

/*
This function will load car data from a given file and add the data to the tail of the existing linked list.
*/
void loadCarData (struct car ** headLL, char fileName [MAX_LENGTH]) {
    // Declare and initalize all needed variables
    FILE * fileIn;
    a3Car * temp;
    a3Car * newNode;
    char tempString [100];
    char * carInfo [5];

    fileIn = fopen (fileName, "r"); // Open the file in read mode

    srand(time (NULL)); // Ensure that randNum will be a new random number everytime

    // Continue looping till fgets isn't returning NULL
    while (fgets(tempString, sizeof(tempString), fileIn) != NULL) {
        // Use malloc to assign space for newNode
        newNode = malloc (sizeof (a3Car));

        // Use strtok to split tempString by comma and the last one by \n
        carInfo[0] = strtok(tempString, ",");
        carInfo[1] = strtok(NULL, ",");
        carInfo[2] = strtok(NULL, ",");
        carInfo[3] = strtok(NULL, ",");
        carInfo[4] = strtok(NULL, "\n");

        // Use the atoi function, which is part of the <ctype.h> library to convert the string into an integer
        // adn add the carId to newNode
        newNode->carId = atoi(carInfo[0]);

        strcpy(newNode->model, carInfo[1]); // Add the model to the newNode
        strcpy(newNode->type, carInfo[2]); // Add the type to the newNode

        // Use the atoi function, which is part of the <ctype.h> library to convert the string into an integer
        // and add the year to newNode
        newNode->year = atoi(carInfo[3]);

        // Use the atof function, which is part of the <ctype.h> library to convert the string into an double
        // and add the price to newNode
        newNode->price = atof(carInfo[4]);

        // Set the newNode->next to NULL
        newNode->nextCar = NULL;

        // Set temp to headLL (dereferenced)
        temp = *headLL;

        // Continue to loop while temp is not NULL
        while (temp != NULL) {
            // Check if newNode's carId matches with another carId in the linked list
            if (newNode->carId == temp->carId) {
                // Add a random value from 1 to 999 to carId
                newNode->carId = newNode->carId + (rand () % 999) + 1;
                temp = *headLL; // Set temp to headLL (dereferenced)
            }
            // If id's do not match, then move on to next car
            else {
                temp = temp->nextCar;
            }
        }

        // Checking if headLL is empty and if true then set headLL (dereference) to newNode
        if (*headLL == NULL) {
            *headLL = newNode;
        }
        // If linked list is not empty
        else {
            temp = *headLL; // Set temp to headLL (dereferenced)

            // Continue to loop while temp->nextCar is not NULL and move temp to the next car
            while (temp->nextCar != NULL) {
                temp = temp->nextCar;
            }

            // Add the newNode to the tail side of the existing linked list
            temp->nextCar = newNode;
        }
    }
    fclose(fileIn); // Close the file
}
