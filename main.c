/* 
String & int safe input handling and error messaging for invalid entries.
It validates user input for names and age, 
ensuring names are non-empty and free of digits, 
while ages are positive integers. 
*/

#include <stdio.h>
#include "name_validation.h"
#include "age_validation.h"

int main() {
    char firstName[50];
    char lastName[50];
    
    // Validate first name
    printf("\n");
    validateNameInput(firstName, 49, "Enter your first name", 
                      "You entered %s. Please try again!\n");

    // Validate last name
    validateNameInput(lastName, 49, "Enter your last name", 
                      "You entered %s. Please try again!\n");

    // Validate age
    int age = validateAgeInput();

    // Output the collected data
    printf("\nYour Full Name: %s, %s\n", lastName, firstName);
    printf("Your Age: %d\n", age);

    // "Special" message for users older than 50
    if (age > 50) {
        printf("\nWhoa! At %d, you must have seen so much in life. You must be a sage! :)\n", age);
    }

    return 0;
}
