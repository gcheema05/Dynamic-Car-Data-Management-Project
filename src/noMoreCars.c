#include "../include/headerA3.h"

/*
This function will delete all nodes within a linked list or fire all cars.
*/
void noMoreCars (a3Car ** headLL) {
    // Declare all needed variables
    char userAns;
    a3Car * temp;

    // Use a do while loop that continues to loop till 'n' is entered
    do {
        // Prompt the user for confirmation
        printf("Are you sure you want to remove all car data (enter y for yes, n for no): ");
        scanf(" %c", &userAns);
        printf("\n");

        // If user enters 'y'
        if (userAns == 'y') {
            // Check if headLL (dereferenced) is already empty and inform the user if true
            if (*headLL == NULL) {
                printf("List is already empty!\n\n");
                userAns ='n'; // Set userAns to 'n' to exist the loop
            }
            // If headLL is not empty
            else {
                // Continue to loop while headLL (dereferenced) is not NULL
                while (*headLL != NULL) {
                    // Set temp to headLL (dereferenced)
                    temp = *headLL;
                    // Set headLL to temp next car
                    *headLL = temp->nextCar;
                    free(temp); // Free temp
                }
                // Inform the user that the linked list is empty now
                printf("All removed. Linked list is now empty\n\n");
                userAns = 'n'; // Set userAns to 'n' to exist the loop
            }
        }

    } while (userAns != 'n');
}
