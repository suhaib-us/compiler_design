#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

bool isValidCIdentifier(const char *id) { 
    if (!id[0]) return false;

    bool isValidFirstChar = isalpha(id[0]);
    if (!isValidFirstChar && id[0] != '_')
        return false;  

    for (int i = 1; id[i]; ++i) {
        bool isValidChar = isalpha(id[i]);
        if (!isValidChar && id[i] != '_')
            return false;
    }
    return true;
}

int main() {
    const char *test1 = "Hello";  
    const char *test2 = "123abc"; 
    const char *test3 = "_abc";  

    printf("%s is valid: %s\n", test1, isValidCIdentifier(test1) ? "yes" : "no");
    printf("%s is valid: %s\n", test2, isValidCIdentifier(test2) ? "yes" : "no");
    printf("%s is valid: %s\n", test3, isValidCIdentifier(test3) ? "yes" : "no");

    return 0;
}