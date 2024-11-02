#include <stdio.h>
#include <string.h>
#include <ctype.h>

void validateNameInput(char *name, int maxLength, const char *prompt, const char *errorMsg) {
    while (1) {
        printf("%s: ", prompt);
        fgets(name, maxLength + 1, stdin); // Read the name

        // Check if the input is too long
        if (name[strlen(name) - 1] != '\n') {
            printf("Error: Input is too long. Please try again.\n");
            // Clear stdin to remove excess characters
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue; // Retry input
        }

        // Remove the newline character at the end if it exists
        name[strcspn(name, "\n")] = 0;

        // Check if the name is empty
        // int isEmpty = 1;
        // for (int i = 0; name[i] != '\0'; i++) {
        //     if (name[i] != ' ') { // Check if character is not a space
        //         isEmpty = 0;
        //         break;
        //     }
        // }
        // if (isEmpty) {
        //     printf(errorMsg, " an empty name or a name with only spaces");
        //     continue; // Retry input for the first name
        //}

        // Check if the input is empty
        if (strlen(name) == 0 || (name[0] == '\n')) { // Check if it's empty or just a newline  
            printf(errorMsg, "an empty name"); // Use error message template for empty input
            continue; // Retry input for the first name
        }

        // Check if the string is just spaces
        int isOnlySpaces = 1; // Assume it is only spaces until we find a non-space character
        for (int i = 0; i < strlen(name); i++) {
            if (name[i] != ' ' && name[i] != '\n') { // Check for non-space character and ignore newline
                isOnlySpaces = 0; // Found a non-space character
                break;
            }
        }

        if (isOnlySpaces) {
            printf(errorMsg, "an empty name"); // Use error message template for empty input
            continue; // Retry input for the first name
        }
        // Check for invalid characters in the name (Non Alphabetics)
        // int hasInvalidChar = 0;
        // for (int i = 0; name[i] != '\0'; i++) {
        //     if (!isalpha(name[i])) {
        //         hasInvalidChar = 1;
        //         break;
        //     }
        // }

        // if (hasInvalidChar) {
        //     printf(errorMsg, "Invalid characters (Alphabets only)"); // Use error message template for digits in input
        //     continue; // Retry input for the first name
        // }

        // Check for digits in the name
        int hasDigit = 0;
        for (int i = 0; name[i] != '\0'; i++) {
            if (isdigit(name[i])) {
                hasDigit = 1;
                break;
            }
        }

        if (hasDigit) {
            printf(errorMsg, "a number or a name containing number(s)"); // Use error message template for digits in input
            continue; // Retry input for the first name
        }

        break; // Exit the loop if the name is valid
    }
}
