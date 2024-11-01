#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int validateAgeInput() {
    char ageInput[10]; // Create an array for the age input
    int age;

    // Loop for age input
    while (1) {
        // Prompt the user to enter their age
        printf("\nEnter your age : ");
        
        // Check if fgets returns NULL (EOF or error)
        if (fgets(ageInput, sizeof(ageInput), stdin) == NULL) {
            printf("\nError: Unexpected end of input (EOF detected). Exiting input.\n");
            return -1; // Use -1 or a specific return value to indicate EOF
        }

        // Remove the newline character at the end if it exists
        ageInput[strcspn(ageInput, "\n")] = 0;

        // Check if the age input is empty
        if (strlen(ageInput) == 0) {
            printf("Invalid: Age cannot be empty. Please try again.\n");
            continue; 
        }

        // Validate that input is numeric
        int isValid = 1;
        for (int i = 0; ageInput[i] != '\0'; i++) {
            if (!isdigit(ageInput[i])) { 
                isValid = 0;
                break;
            }
        }

        if (!isValid) {
            printf("Invalid: Age must be a whole number (digits only). Please try again.\n");
            continue; 
        }

        age = atoi(ageInput);
        if (age <= 0) {
            printf("Invalid: Age must be greater than zero. Please try again.\n");
            continue; 
        }

        break; // Exit the loop if the age is valid
    }

    return age; // Return the valid age
}
