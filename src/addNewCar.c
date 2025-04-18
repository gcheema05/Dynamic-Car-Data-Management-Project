#include "../include/headerA3.h"

/*
This function will add a new node to the tail side of the given linked list. The user will be
prompted within the function to enter the elements for the new node.
*/
void addNewCar (struct car ** headLL) {
    // Declare and initalize all needed variables
    a3Car * newNode = NULL;
    a3Car * temp = NULL;
    int lenOfModel = 0;
    int lenOfType = 0;
    int sumOfModel = 0;
    char tempCharacters [MAX_LENGTH];

    srand(time (NULL)); // Ensure that randNum will be a new random number everytime

    // Use malloc to assign space for newNode
    newNode = malloc (sizeof (a3Car));

    // Prompt the user for the car model
    printf("Enter the car model: ");
    fgets(tempCharacters, MAX_LENGTH, stdin); // Remove any characters in stream before input
    fgets(newNode->model, MAX_LENGTH, stdin); // Read user input
    newNode->model[strlen(newNode->model) - 1] = 0; // Remove \n

    // Prompt the user for the car type
    printf("Enter the car type: ");
    fgets(newNode->type, MAX_LENGTH, stdin); // Read user input
    newNode->type[strlen(newNode->type) - 1] = 0; // Remove \n
    printf("\n");

    // Prompt the user for the year of manufacture
    printf("Enter its year of manufacture: ");
    scanf("%d", &(newNode->year));

    // Prompt the user for the price
    printf("Enter its price: CDN $ ");
    scanf("%lf", &(newNode->price));
    printf("\n");

    newNode->nextCar = NULL; // Set newNode->nextCar to NULL

    // Find the length of model and type given by user and store in respective variables
    lenOfModel = strlen(newNode->model);
    lenOfType = strlen(newNode->type);

    // Use a for loop for the lenOfModel to add all the ASCII values for each character by casting and store in sumOfModel
    for (int i = 0; i < lenOfModel; i++) {
        sumOfModel = sumOfModel + (int)(newNode->model[i]);
    }

    // Set the newNode carId to the sum of sumOfModel and lenOfType
    newNode->carId = sumOfModel + lenOfType;

    // Set temp to headLL (dereferenced)
    temp = *headLL;

    // Continue to loop till temp is NULL
    while (temp != NULL) {
        // Check if newNode's carId matches with another id in the linked list
        if (newNode->carId == temp->carId) {
            // Change the newNode's carId by adding a random value from 1 to 999
            newNode->carId = newNode->carId + (rand () % 999) + 1;
            temp = *headLL; // Set temp to headLL (dereferenced)
        }
        // If id does not match, then look at next node by moving temp
        else {
            temp = temp->nextCar;
        }
    }

    // Inform the user of the carId
    printf("Your computer-generated carId is %d\n\n", newNode->carId);

    // Checking if headLL is empty and if true, then set headLL (dereferenced) to newNode
    if (*headLL == NULL) {
        *headLL = newNode;
    }
    // If linked list is not empty
    else {
        // Set temp to headLL (dereferenced)
        temp = *headLL;

        // Continue looping and moving temp to the next node till the next node is NULL
        while (temp->nextCar != NULL) {
            temp = temp->nextCar;
        }

        // Add the newNode to the end of the tail of the linked list
        temp->nextCar = newNode;
    }
}
