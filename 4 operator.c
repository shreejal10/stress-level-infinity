#include <stdio.h>

int count_operators(const char *expression)
{
    int count = 0, i;
    for ( i = 0; expression[i] != '\0'; i++)
    {
        switch (expression[i])
        {
        case '+':
        case '-':
        case '*':
        case '/':
            count++;
            break;
        default:
            break;
        }
    }
    return count;
}

int main()
{
	printf("Name: Shreejal Dhungana \nSection: A ");
    printf("Program to count number of operators\t\t\t\t\n");
    char expression[100], ch;
    do{
    printf("\nEnter an expression: ");
    scanf("%s", expression);
    int count = count_operators(expression);
    printf("The number of operators in the expression is %d\n", count);
    printf("\nDo you want to check another expression (y/n)?: ");
        while (getchar() != '\n'); // Clear input buffer
        ch = getchar();
	}while(ch=='y');
    return 0;
}
