#include <stdio.h>
#include <string.h>
#include <ctype.h>

void validateNameInput(char *name, int maxLength, const char *prompt, const char *errorMsg) {
    while (1) {
        printf("\n%s : ", prompt);
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

        // Check if the name is empty or consists only of spaces
        int isEmpty = 1;
        for (int i = 0; name[i] != '\0'; i++) {
            if (name[i] != ' ') { // Check if character is not a space
                isEmpty = 0;
                break;
            }
        }

        if (isEmpty) {
            printf(errorMsg, "an empty input or a string with only spaces"); // Use error message template for empty input
            continue; // Retry input for the first name
        }

        // Check for numeric characters in the name
        int hasDigit = 0;
        for (int i = 0; name[i] != '\0'; i++) {
            if (isdigit(name[i])) {
                hasDigit = 1;
                break;
            }
        }

        if (hasDigit) {
            printf(errorMsg, "a number or a name containing numbers"); // Use error message template for digits in input
            continue; // Retry input for the first name
        }

        break; // Exit the loop if the name is valid
    }
}
