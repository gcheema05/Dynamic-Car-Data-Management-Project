#include "../include/headerA3.h"

/*
This main will call on all functions and test them.
*/
int main () {
    // Declare and initalize all needed variables
    int userInput = 0;
    a3Car * headLL = NULL;
    a3Car * toFindId = NULL;
    a3Car * temp = NULL;
    int numOfCars = 0;
    int nCar = 0;
    int nCarReturn = 0;
    int key = 0;
    char fileName [MAX_LENGTH];
    char modelAndType [100];
    char tempHolder [100];
    strcpy(fileName, "inputFile.txt");
    int counter = 1;

    // Use a do while loop to continuously prompt the user the menu till the user enters '11' to exit
    do {
        // Display the program menu to the user and prompt them to enter a choice
        printf("Menu");
        printf("\n1 - Add Data");
        printf("\n2 - Load Data");
        printf("\n3 - Print All Cars");
        printf("\n4 - Print nth Car");
        printf("\n5 - Search with CarId");
        printf("\n6 - Search with Model and Type");
        printf("\n7 - Total Cars");
        printf("\n8 - Sort by CarId");
        printf("\n9 - Remove nth Car");
        printf("\n10 - Remove All Cars");
        printf("\n11 - Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &userInput);
        printf("\n");

        // Use a switch case based on userInput to call different function
        switch (userInput) {
            // Function 1 is called (add new data by prompting the user)
            case 1:
                addNewCar(&headLL); // Call the addNewCar with the address of headLL
                break;
            // Function 2 is called (load data into the linked list from a file)
            case 2:
                loadCarData(&headLL, fileName); // Call the loadCarData with the address of headLL and fileName
                printf("Cars have been added\n\n"); // Inform the user that the cars have been added
                break;
            // Function 3 is called (print all data within the LL)
            case 3:
                printAll(headLL); // Call printAll with headLL
                break;
            // Function 4 is called (display the nth car)
            case 4:
                // Call the countCars function with headLL and store return into numOfCars
                numOfCars = countCars(headLL);

                // Check if numOfCars is not -1 (empty LL)
                if (numOfCars != -1) {
                    // Set nCar to 0
                    nCar = 0;

                    // Continue to loop while till nCar is within the size of the linked list
                    while (nCar < 1 || nCar > numOfCars) {
                        // Prompt user for a valid position
                        printf("Enter a position between 1 and %d: ", numOfCars);
                        scanf("%d", &nCar);
                        printf("\n");
                    }
                    printOne(headLL, nCar); // Call the printOne function with headLL and nCar
                }
                // If numOfCars is -1, then inform the user that the list is empty
                else {
                    printf("List is empty!\n\n");
                }
                break;
            // Function 5 is called (look for a car based on carId)
            case 5:
                // Prompt the user for a carID
                printf("Enter a car ID: ");
                scanf("%d", &key);
                printf("\n");

                // Call the lookForCarID function with headLL and key and store return in nCarReturn
                nCarReturn = lookForCarId(headLL, key);

                // If the return is -1, then display that no car is found
                if (nCarReturn == -1) {
                    printf("No Car Found!\n\n");
                }
                // If return is valid then call printOne to print the car found
                else {
                    printOne(headLL, nCarReturn);
                }
                break;
            // Funtion 6 is called (look for a car based on model and type)
            case 6:
                // Prompt the user for the model and type
                printf("Enter the model and type (separted by a space): ");
                fgets(tempHolder, sizeof(tempHolder), stdin); // Remove the \n
                fgets(modelAndType, sizeof(modelAndType), stdin); // Take in the model and type
                printf("\n");

                // Call the lookForCarModelType function with headLL and the modelAndType and store return in nCarReturn
                nCarReturn = lookForCarModelType(headLL, modelAndType);

                // Check if return is -1 and display that no car is found
                if (nCarReturn == -1) {
                    printf("No Car Found!\n\n");
                }
                // If car is found then print the car found using printOne
                else {
                    printOne(headLL, nCarReturn);
                }
                break;
            // Function 7 is called (count the number of cars)
            case 7:
                // Call the countCars function with headLL and store the return in numOfCars
                numOfCars = countCars(headLL);

                // Check if return is not -1 and display the total amount of cars
                if (numOfCars != -1) {
                    printf("Total number of cars = %d\n\n", numOfCars);
                }
                // If return is not valid then inform the user that no cars are present
                else {
                    printf("Total number of cars = %d\n\n", 0);
                }
                break;
            // Function 8 is called (sort the list by carid in ascending order)
            case 8:
                // Call the sortCarId function with headLL (address) and display the new list with printAll
                sortCarId(&headLL);
                printAll(headLL);
                break;
            // Function 9 is called (delete a car based on carid)
            case 9:
                // Call the countCars function store return in numOfCars
                numOfCars = countCars(headLL);

                // Check if return is not -1
                if (numOfCars != -1) {
                    // Print the current number of cars
                    printf("Currently, there are %d cars.\n", numOfCars);

                    // Set nCar to 0
                    nCar = 0;

                    // Continue to loop till car chosen to delete is within the size of the list
                    while (nCar < 1 || nCar > numOfCars) {
                        // Prompt user to select a car to delete
                        printf("Which car do you wish to remove - enter a value between 1 and %d: ", numOfCars);
                        scanf("%d", &nCar);
                        printf("\n");
                    }
                    // Set toFindId to the headLL
                    toFindId = headLL;

                    // Continue to loop while counter does not equal to nCar
                    while (counter != nCar) {
                        toFindId = toFindId->nextCar; // Move on to the next car
                        counter++; // Add one to the counter
                    }

                    // Inform the user that the car with the id found is removed
                    printf("Car [ID: %d] removed.\n", toFindId->carId);

                    // Call the oneLessCar function to remove the nCar
                    oneLessCar(&headLL, nCar);

                    // Inform the user of the remaining cars and set counter to 1
                    printf("There are now %d cars remaining.\n\n", countCars(headLL));
                    counter = 1;
                }
                // If numOfCars is not valid then inform the user that the list is empty
                else {
                    printf("List is empty!\n\n");
                }
                break;
            // Function 10 is called (remove all the cars in the list)
            case 10:
                noMoreCars(&headLL); // Call noMoreCars with headLL (address)
                break;
            // If 11 is entered then display to the user that they are exiting and leave the do while loop
            case 11:
                printf("Exiting...\n\n");
                break;
            // If the user enters any other value then the menu, display that they entered the wrong choice
            default:
                printf("Wrong Choice!\n\n");
        }
    } while (userInput != 11);

    // Continue to loop while headLL is not null and continue deleted the list
    while (headLL != NULL) {
        temp = headLL;
        headLL = temp->nextCar;
        free(temp);
    }

    // Free the headLL and toFindId pointers
    free(headLL);
    free(toFindId);

    return 0; // Return 0 if no issues found
}
