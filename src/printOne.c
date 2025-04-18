#include "../include/headerA3.h"

/*
This function will print one car based on position given.
*/
void printOne (struct car * headLL, int whichOne) {
    // Declare and initalize all needed variables
    int counter = 1;
    char tempPrice [100];
    char formattedPrice [100];
    int lenOfString = 0;

    // Check if headLL is empty and if true then display to the user that the list is empty
    if (headLL == NULL) {
         printf("List is empty!\n\n");
    }

    // Continue to loop while headLL is not NULL
    while (headLL != NULL) {
        // Check if counter equals to whichOne
        if (counter == whichOne) {
            // Print the carId, model and type
            printf("Car #%d: ", counter);
            printf("\n");
            printf("\tCar id: %d\n", headLL->carId);
            printf("\tModel: %s\n", headLL->model);
            printf("\tType: %s\n", headLL->type);

            // Use sprintf to read the price of the car without the command line and store in tempPrice
            sprintf(tempPrice, "%.2f", headLL->price);

            // Find the length of the string and set the lenOfString to that value
            lenOfString = strlen(tempPrice);

            // Check if lenOfString is 8
            if (lenOfString == 8) {
                // Copy the first and second character
                formattedPrice[0] = tempPrice[0];
                formattedPrice[1] = tempPrice[1];
                formattedPrice[2] = ','; // Add a comma to the 3 character of formattedPrice

                // Use a for loop that starts at 3 and goes till lenOfString + 1
                for (int i = 3; i < lenOfString + 1; i++) {
                    formattedPrice[i] = tempPrice[i-1]; // Copy the remaining characters into formattedPrice
                    // Check if last character is reached and add a string ending character
                    if (i == lenOfString) {
                        formattedPrice[i+1] = '\0';
                    }
                }
            }
            // Check if lenOfString is 8
            else if (lenOfString == 7) {
                // Copy the first character
                formattedPrice[0] = tempPrice[0];
                formattedPrice[1] = ','; // Add the comma for the 2 second character

                // Use a for that starts at 2 and goes till lenOfString + 1
                for (int i = 2; i < lenOfString + 1; i++) {
                    formattedPrice[i] = tempPrice[i-1]; // Copy the remaining characters into formattedPrice
                    // Check if last character is reached and add a string ending character
                    if (i == lenOfString) {
                        formattedPrice[i+1] = '\0';
                    }
                }
            }
            // Copy the original string if none of the other cases
            else {
                strcpy(formattedPrice, tempPrice);
            }

            // Print the formatted price and year
            printf("\tPrice: CDN $%s\n", formattedPrice);
            printf("\tYear of Manufacture: %d\n\n", headLL->year);
            counter++;
        }
        // WhichOne is not reached yet
        else {
            headLL = headLL->nextCar; // Move headLL to the next car
            counter++; // Add one to the counter
        }
    }
}
