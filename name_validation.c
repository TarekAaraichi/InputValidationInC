#include <stdio.h>
#include <string.h>
#include <ctype.h>

void validateNameInput(char *name, int maxLength, const char *prompt, const char *errorMsg) {
    while (1) {
        printf("%s (max %d characters): ", prompt, maxLength);
        fgets(name, maxLength + 1, stdin); // Read the name

        // Check if the input is too long
        if (name[strlen(name) - 1] != '\n') {
            printf("Error: Input is too long. Please try again.\n");
            // Clear stdin to remove excess characters
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
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
            printf(errorMsg, "empty"); // Use error message template
            continue; 
        }

        // Check for numeric characters in the name
        for (int i = 0; name[i] != '\0'; i++) {
            if (isdigit(name[i])) {
                printf(errorMsg, "numbers"); // Use error message template
                continue;
            }
        }

        break; // Exit the loop if the name is valid
    }
}
