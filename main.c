/* Lab 1 String and int 
Skapar en variabel name med ditt namn 
Skapar en int age med din ålder.
Skriver sedan ut värdena i en printf "Your name is Name and you are AGE years old."
*/

#include <stdio.h>
#include "name_validation.h"
#include "age_validation.h"

int main() {
    char firstName[100];
    char lastName[100];
    
    // Validate first name
    validateNameInput(firstName, 99, "Enter your first name", 
                      "Error: You entered an %s or a name with only spaces. Please try again.\n");

    // Validate last name
    validateNameInput(lastName, 99, "Enter your last name", 
                      "Error: You entered an %s or a last name with only spaces. Please try again.\n");

    // Validate age
    int age = validateAgeInput();

    // Output the collected data
    printf("Full Name: %s %s\n", firstName, lastName);
    printf("Age: %d\n", age);

    return 0;
}
