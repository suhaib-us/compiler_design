#include <stdio.h>
#include <string.h>

#define MAX_KEYWORDS 10
#define MAX_LENGTH 30

int main() {
    char keywords[MAX_KEYWORDS][MAX_LENGTH], search_keyword[MAX_LENGTH];
    int n;

    printf("Enter the number of keywords (max 10): ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Keyword %d: ", i + 1);
        scanf("%s", keywords[i]);
    }

    printf("Enter keyword to search: ");
    scanf("%s", search_keyword);

    for (int i = 0; i < n; i++) {
        if (strcmp(keywords[i], search_keyword) == 0) {
            printf("'%s' found in the list.\n", search_keyword);
            return 0;
        }
    }

    printf("'%s' not found in the list.\n", search_keyword);
    return 0;
}
