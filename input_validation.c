#include <stdio.h>
#include <string.h>
#include <stdlib.h> // For atoi
#include <ctype.h> // For isdigit
#include "input_validation.h"

void getFullName(char *firstName, char *lastName) {
    // Loop for first name input
    while (1) {
        printf("Enter your first name (max 99 characters): ");
        fgets(firstName, 100, stdin); // Read the first name

        // Check if the input is too long
        if (firstName[strlen(firstName) - 1] != '\n') {
            printf("Error: Input is too long. Please try again.\n");
            // Clear stdin to remove excess characters
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }

        // Remove the newline character at the end if it exists
        firstName[strcspn(firstName, "\n")] = 0;

        // Check if the name is empty or consists only of spaces
        int isEmpty = 1; 
        for (int i = 0; firstName[i] != '\0'; i++) {
            if (firstName[i] != ' ') { // Check if character is not a space
                isEmpty = 0; 
                break; 
            }
        }

        if (isEmpty) {
            printf("Error: You entered an empty name or a name with only spaces. Please try again.\n");
            continue; 
        }

        // Check for numeric characters in the first name
        for (int i = 0; firstName[i] != '\0'; i++) {
            if (isdigit(firstName[i])) {
                printf("Error: First name cannot contain numbers. Please try again.\n");
                continue;
            }
        }

        break; 
    }

    // Loop for last name input
    while (1) {
        printf("Enter your last name (max 99 characters): ");
        fgets(lastName, 100, stdin); // Read the last name

        // Check if the input is too long
        if (lastName[strlen(lastName) - 1] != '\n') {
            printf("Error: Input is too long. Please try again.\n");
            // Clear stdin to remove excess characters
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }

        // Remove the newline character at the end if it exists
        lastName[strcspn(lastName, "\n")] = 0;

        // Check if the last name is empty or consists only of spaces
        int isEmpty = 1; 
        for (int i = 0; lastName[i] != '\0'; i++) {
            if (lastName[i] != ' ') { // Check if character is not a space
                isEmpty = 0; 
                break; 
            }
        }

        if (isEmpty) {
            printf("Error: You entered an empty last name or a last name with only spaces. Please try again.\n");
            continue; 
        }

        // Check for numeric characters in the last name
        for (int i = 0; lastName[i] != '\0'; i++) {
            if (isdigit(lastName[i])) {
                printf("Error: Last name cannot contain numbers. Please try again.\n");
                continue;
            }
        }

        break; 
    }
}

int getAge() {
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

