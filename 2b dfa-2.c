#include <stdio.h>
#define MAX 100

int main() {
    char str[MAX], state = 'A', ch;
    printf("\t\t\t\t\tName: Shreejal Dhungana \n\t\t\t\t\tSection: A \n");
    printf("\t\tProgram to accept the string which contains aba as substring, Alphabet(a,b)\t\t\t\t\n");
    int invalid = 0;
    do {
        printf("Enter the string to be checked: ");
        scanf("%s", str);
	    int i;
        for (i = 0; str[i] != '\0'; i++) {
        	if (str[i] != 'a' && str[i] != 'b') {
        		
                invalid = 1;  // Set invalid flag if non 'a' or 'b' character is found
                break;
            }
            switch (state) {
                case 'A':
                    if (str[i] == 'a') {
                        state = 'B';
                    } else if (str[i] == 'b') {
                        state = 'A';
                    }
                    break;

                case 'B':
                    if (str[i] == 'a') {
                        state = 'B';
                    } else if (str[i] == 'b') {
                        state = 'C';
                    }
                    break;

                case 'C':
                    if (str[i] == 'a') {
                        state = 'D';
                    } else if (str[i] == 'b') {
                        state = 'A';
                    }
                    break;

                case 'D':
                    if (str[i] == 'a') {
                        state = 'D';
                    } else if (str[i] == 'b') {
                        state = 'D';
                    }
                    break;

                default:
                    break;
            }
        }
		if (invalid) {
            printf("Given string %s is not accepted. Only 'a' and 'b' are allowed.\n", str);
        }
        else if (state == 'D') {
            printf("Given string %s is accepted.\n", str);
        } else {
            printf("Given string %s is not accepted.\n", str);
        }

        printf("\nDo you want to check another string(y/n)?: ");
        scanf(" %c", &ch);
        printf("\n");
        if (ch == 'y') {
            state = 'A';
        }
    } while (ch == 'y');

    return 0;
}
