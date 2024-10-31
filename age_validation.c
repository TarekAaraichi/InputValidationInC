#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validateAgeInput() {
    char ageInput[10]; // Create an array for the age input
    int age;

    // Loop for age input
    while (1) {
        // Prompt the user to enter their age
        printf("Enter your age (whole number, no decimals, must be > 0): ");
        fgets(ageInput, sizeof(ageInput), stdin); // Read the age input

        // Remove the newline character at the end if it exists
        ageInput[strcspn(ageInput, "\n")] = 0;

        // Check if the age input is empty
        if (strlen(ageInput) == 0) {
            printf("Error: Age cannot be empty. Please try again.\n");
            continue; 
        }

        // Check if the input contains only digits (0-9)
        int isValid = 1; // Flag for valid age input
        for (int i = 0; ageInput[i] != '\0'; i++) {
            // Check if character is not between '0' and '9'
            if (ageInput[i] < '0' || ageInput[i] > '9') { 
                isValid = 0; // Mark as invalid
                break; 
            }
        }

        if (!isValid) {
            printf("Error: Age must be a whole number (digits only). Please try again.\n");
            continue; 
        }

        // Convert age input to an integer
        age = atoi(ageInput);

        // Check if age is greater than 0
        if (age <= 0) {
            printf("Error: Age must be greater than zero. Please try again.\n");
            continue; 
        }

        break; // Exit the loop if the age is valid
    }

    return age; // Return the valid age
}
