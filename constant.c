#include <stdio.h>
#include <ctype.h>

void checkIntegerConstant(const char *str) {
    int i = 0;
    int found = 0;

    printf("Integer constants found in the string:\n");

    while (str[i] != '\0') {
       
        if (isdigit(str[i])) {
            found = 1;
            
            while (isdigit(str[i])) {
                putchar(str[i]);
                i++;
            }
            printf("\n");
        } else {
            i++;
        }
    }

    if (!found) {
        printf("No integer constants found in the string.\n");
    }
}

int main() {
    char input[100];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    size_t len = 0;
    while (input[len] != '\0') len++;
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    checkIntegerConstant(input);

    return 0;
}
