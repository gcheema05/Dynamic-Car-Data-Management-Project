#include "../include/headerA3.h"

/*
This function will print all the nodes within the linked list
*/
void printAll (struct car * headLL) {
    // Declare and initalize all needed variables
    int counter = 0;
    char tempPrice [100];
    char formattedPrice [100];
    int lenOfString = 0;

    // Check if headLL and inform the user if true
    if (headLL == NULL) {
         printf("No cars found.\n\n");
    }

    // Continue to loop while headLL is not NULL
    while (headLL != NULL) {
        // Print the car data (id, model, and type)
        printf("Car #%d: ", (counter+1));
        printf("\n");
        printf("\tCar id: %d\n", headLL->carId);
        printf("\tModel: %s\n", headLL->model);
        printf("\tType: %s\n", headLL->type);

        // Store the formatted price into tempPrice using sprintf (allows one to read without needing the command line)
        sprintf(tempPrice, "%.2f", headLL->price);

        // Set lenOfString to the length of tempPrice
        lenOfString = strlen(tempPrice);

        // Check if lenOfString is 8
        if (lenOfString == 8) {
            // Set the first 2 characters of formatted price to the first 2 characters of tempPrice
            formattedPrice[0] = tempPrice[0];
            formattedPrice[1] = tempPrice[1];

            // Add a comma for the 3 character
            formattedPrice[2] = ',';

            // Use a for loop that starts at 3 and ends at lenOfString + 1 to copy the rest of the characters
            for (int i = 3; i < lenOfString + 1; i++) {
                formattedPrice[i] = tempPrice[i-1];

                // Check if i equals to lenOfSting and add the string ending character
                if (i == lenOfString) {
                    formattedPrice[i+1] = '\0';
                }
            }
        }
        // Check if the string is 7 characters
        else if (lenOfString == 7) {
            // Copy the first character
            formattedPrice[0] = tempPrice[0];

            // Add the comma for the 2 character
            formattedPrice[1] = ',';

            // Use a for loop that starts at 2 and ends at lenOfString + 1 to copy the rest of the characters
            for (int i = 2; i < lenOfString + 1; i++) {
                formattedPrice[i] = tempPrice[i-1];

                // Check if i equals to lenOfString and add the string ending character
                if (i == lenOfString) {
                    formattedPrice[i+1] = '\0';
                }
            }
        }
        // If the string length is anything other than 8 or 7, then just copy the string without adding comma
        else {
            strcpy(formattedPrice, tempPrice);
        }

        // Print the formatted price and the year
        printf("\tPrice: CDN $%s\n", formattedPrice);
        printf("\tYear of Manufacture: %d\n\n", headLL->year);

        // Move the headLL to the next car and add one to the counter
        headLL = headLL->nextCar;
        counter++;
    }
    // Print the current amount of cars if counter is not 0
    if (counter != 0) {
        printf("Currently, there are %d cars.\n\n", counter);
    }
}
