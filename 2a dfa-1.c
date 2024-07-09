// Program to accept the binary number ending with 11
#include<stdio.h>
#define max 100

int main(){
    char str[max], state= 'A', ch;
    printf("Name: Shreejal Dhungana \nSection: A ");
    printf("Program to accept the binary number ending with 11, Alphabet(0,1)\t\t\t\t");
    do{
        printf("\nEnter the string to be checked: ");
        scanf("%s", str);
        int i;
        int invalid = 0; 
        for (i = 0; str[i] != '\0'; i++){
        	if (str[i] != '0' && str[i] != '1') {
                invalid = 1;  // Set invalid flag if non 'a' or 'b' character is found
                break;
            }
            switch (state){
                case 'A':
                    if(str[i] == '1'){
                        state ='B';
                    } 
                    else if(str[i] == '0'){
                        state = 'A';
                    }
                    break;

                case 'B':
                    if(str[i] == '1'){
                        state ='C';
                    }
                    else if(str[i] == '0'){
                        state = 'A';
                    }
                    break;

                case 'C':
                    if(str[i] == '1'){
                        state = 'C';
                    }
                    else if(str[i] == '0'){
                        state = 'A';
                    }
                    break;
                
                default:
                    break;
            }
        }
        if (invalid) {
            printf("Given string %s is not accepted. Only '0' and '1' are allowed.\n", str);
        }
        else if (state == 'C'){
            printf("Given string %s is accepted.", str);
        }
        else{
            printf("Given string %s is not accepted.", str);
        }
        printf("\nDo you want to check another string(y/n)?: ");
        while (getchar() != '\n'); // Clear input buffer
        ch = getchar();

        if(ch=='y'){
            state='A';
        }
    } while (ch=='y');
    return 0;
}
