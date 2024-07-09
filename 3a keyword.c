#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to check if a string is a C keyword
int isKeyword(char *str) {
    // List of C keywords
    const char *keywords[] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do", "double", 
        "else", "enum", "extern", "float", "for", "goto", "if", "inline", "int", 
        "long", "register", "restrict", "return", "short", "signed", "sizeof", 
        "static", "struct", "switch", "typedef", "union", "unsigned", "void", 
        "volatile", "while", "_Alignas", "_Alignof", "_Atomic", "_Bool", "_Complex", 
        "_Generic", "_Imaginary", "_Noreturn", "_Static_assert", "_Thread_local"
    };
    int n = sizeof(keywords) / sizeof(keywords[0]);
    int i;
    for ( i = 0; i < n; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    printf("Name: Shreejal Dhungana \nSection: A ");
    printf("Program to identify valid identifiers\t\t\t\t\n");
    char a[10], ch;
    do {
        int flag = 1, i = 1;
        printf("\nEnter an identifier: ");
        scanf("%s", a);

        if (isKeyword(a)) {
            flag = 2; // Set flag to 2 if the string is a keyword
        } else if (isalpha(a[0]) || a[0] == '_') {
            flag = 1;
        } else {
            flag = 0;
        }

        while (a[i] != '\0' && flag == 1) {
            if (!isdigit(a[i]) && !isalpha(a[i]) && a[i] != '_') {
                flag = 0;
                break;
            }
            i++;
        }

        if (flag == 1) {
            printf("Valid identifier");
        } else if (flag == 2) {
            printf("Not a valid identifier: it is a keyword");
        } else {
            printf("Not a valid identifier");
        }

        printf("\nDo you want to check another string (y/n)?: ");
        while (getchar() != '\n'); // Clear input buffer
        ch = getchar();
    } while (ch == 'y');
    return 0;
}

