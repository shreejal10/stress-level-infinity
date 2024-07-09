#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void add_symbol(char *, char);
void FIND_FIRST(char *, char);
void FIRST_SHOW();

int nt = 0, cr = 0, count = 0;
char FIRST[100][100];
char NT[100], G[100][100];

void main() {
    int i, j, fl, ch1;
    printf("Enter production rules of grammar in the form A->B (use '!' for epsilon)\n\n");
    fl = 1;
    while (1) {
        printf("\n1) Insert Production Rules\n2) Show Grammar\n3) Show FIRST Sets\n4) Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch1);
        switch (ch1) {
            case 1:
                printf("Enter rule %d of grammar: ", cr + 1);
                scanf("%s", G[cr++]);
                for (i = 0; i < nt && fl == 1; i++) {
                    if (NT[i] == G[cr - 1][0])
                        fl = 0;
                }
                if (fl == 1)
                    NT[nt++] = G[cr - 1][0];
                fl = 1;
                break;

            case 2:
                if (cr > 0) {
                    printf("\nGrammar");
                    printf("\nStarting symbol is: %c", G[0][0]);
                    printf("\nNon-terminal symbols are: ");
                    for (i = 0; i < nt; i++)
                        printf("%c  ", NT[i]);
                    printf("\nProduction rules: ");
                    for (i = 0; i < cr; i++)
                        printf("%s  ", G[i]);
                    printf("\n");
                } else {
                    printf("Enter at least one production rule!");
                }
                break;

            case 3:
                FIRST_SHOW();
                break;

            case 4:
                exit(0);
        }
    }
}

void FIRST_SHOW() {
    int i, j;
    char arr[100];
    for (i = 0; i < nt; i++) {
        arr[0] = '\0';
        FIND_FIRST(arr, NT[i]);
        for (j = 0; arr[j] != '\0'; j++) {
            FIRST[i][j] = arr[j];
        }
        FIRST[i][j] = '\0';
        count = 0;
    }
    printf("\nFIRST:\n\n");
    for (i = 0; i < nt; i++) {
        printf("FIRST(%c): { ", NT[i]);
        for (j = 0; FIRST[i][j + 1] != '\0'; j++)
            printf("%c, ", FIRST[i][j]);
        printf("%c }\n", FIRST[i][j]);
    }
}

void FIND_FIRST(char *arr, char ch) {
    int i, k;
    if (!isupper(ch))
        add_symbol(arr, ch);
    else {
        for (i = 0; i < cr; i++) {
            if (ch == G[i][0]) {
                if (G[i][3] == '!')
                    add_symbol(arr, G[i][3]);
                else {
                    for (k = 3; G[i][k] != '\0'; k++) {
                        FIND_FIRST(arr, G[i][k]);
                        if (!isupper(G[i][k]) || strchr(FIRST[G[i][k] - 'A'], '!') == NULL)
                            break;
                    }
                }
            }
        }
    }
}

void add_symbol(char *arr, char ch) {
    int i, flag = 0;
    for (i = 0; arr[i] != '\0'; i++) {
        if (ch == arr[i]) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        arr[count++] = ch;
        arr[count] = '\0';
    }
}
