#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char *keywords[] = {"int", "float", "if", "else", "while", "return", "void", "main", "char", "double"};
const char *operators = "+-*/%=<>!&|";
const char *delimiters = "(),;{}[]";

int isKeyword(const char *word) {
    for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++)
        if (strcmp(word, keywords[i]) == 0) return 1;
    return 0;
}

void tokenize(const char *input) {
    char buffer[256];
    int i = 0, j = 0;
    while (input[i]) {
        if (isspace(input[i])) i++;
        else if (strchr(operators, input[i])) printf("Token: %c, Type: Operator\n", input[i++]);
        else if (strchr(delimiters, input[i])) printf("Token: %c, Type: Delimiter\n", input[i++]);
        else {
            j = 0;
            while (isalnum(input[i]) || input[i] == '_' || input[i] == '.') buffer[j++] = input[i++];
            buffer[j] = '\0';
            if (isKeyword(buffer)) printf("Token: %s, Type: Keyword\n", buffer);
            else if (isalpha(buffer[0]) || buffer[0] == '_') printf("Token: %s, Type: Identifier\n", buffer);
            else if (strchr(buffer, '.')) printf("Token: %s, Type: Real Number\n", buffer);
            else printf("Token: %s, Type: Constant\n", buffer);
        }
    }
}

int main() {
    char input[1024];
    printf("Enter a program: ");
    fgets(input, sizeof(input), stdin);
    tokenize(input);
    return 0;
}
