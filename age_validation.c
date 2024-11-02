#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "age_validation.h"
#include <ctype.h>

int validateAgeInput() {
    char ageInput[5]; // Create an array for the age input
    int age;

    // Loop for age input
    while (1) {
        // Prompt the user to enter their age
        printf("Enter your age: ");
        
        // Check if fgets returns NULL (EOF or error)
        if (fgets(ageInput, sizeof(ageInput), stdin) == NULL) {
            printf("\nError: Unexpected end of input (EOF detected). Exiting input.\n");
            return -1; // Use -1 or a specific return value to indicate EOF
        }

        // Check if the input is too long
        if (ageInput[strlen(ageInput) - 1] != '\n') {
            printf("Input is too long (3 digits MAX). Please try again!\n");
            // Clear stdin to remove excess characters
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue; // Retry input
        }

        // Remove the newline character at the end if it exists
        ageInput[strcspn(ageInput, "\n")] = 0;

        // Check if the age input is empty
        if (strlen(ageInput) == 0) {
            printf("Invalid: Age cannot be empty. Please try again!\n");
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
            printf("Age must be a whole number.\nPlease type only digits with no other characters!\n");
            continue; 
        }

        // // Check if the input is just spaces
        // int isOnlySpaces = 1; // Assume it is only spaces until we find a non-space character
        // for (int i = 0; i < strlen(ageInput); i++) {
        //     if (ageInput[i] != ' ' && ageInput[i] != '\n') { // Check for non-space character and ignore newline
        //         isOnlySpaces = 0; // Found a non-space character
        //         break;
        //     }
        // }

        // if (isOnlySpaces) {
        //     printf("Empty input. Please try again!\n"); // Use error message template for empty input
        //     continue; // Retry input for the first name
        // }

        age = atoi(ageInput);
        if (age <= 0) {
            printf("Age must be greater than zero. Please try again!\n");
            continue; 
        }

        break; // Exit the loop if the age is valid
    }

    return age; // Return the valid age
}
