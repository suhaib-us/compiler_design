#include <stdio.h>

void countCharacters(const char *str, int *tabs, int *newlines, int *spaces) {
    *tabs = *newlines = *spaces = 0;

    while (*str) {
        if (*str == '\t') (*tabs)++;
        else if (*str == '\n') (*newlines)++;
        else if (*str == ' ') (*spaces)++;
        str++;
    }
}

int main() {
    char input[1000];
    int tabs, newlines, spaces;

    printf("Enter a string (press Enter to finish):\n");
    fgets(input, sizeof(input), stdin);

    countCharacters(input, &tabs, &newlines, &spaces);

    printf("Tabs: %d\n", tabs);
    printf("Newlines: %d\n", newlines);
    printf("Spaces: %d\n", spaces);

    return 0;
}
