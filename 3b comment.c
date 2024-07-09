#include <stdio.h>

int main()
{
    printf("Name: Shreejal Dhungana \nSection: A ");
    printf("Program to check valid comments\t\t\t\t\n");
    char com[30], ch;
    int i = 2, a = 0;

    do
    {
        printf("Enter comment: ");
        scanf("%s", com);
        if (com[0] == '/')
        {
            if (com[1] == '/')
                printf("It is a comment");
            else if (com[1] == '*')
            {
                for (i = 2; i <= 30; i++)
                {
                    if (com[i] == '*' && com[i + 1] == '/')
                    {
                        printf("It is a comment");
                        a = 1;
                        break;
                    }
                }
                if (a == 0)
                    printf("It is not a comment");
            }
            else
                printf("It is not a comment");
        }
        else
            printf("It is not a comment");

        printf("\nDo you want to check another string (y/n)?: ");
        while (getchar() != '\n')
            ;
        ch = getchar();
    } while (ch == 'y');
    return 0;
}
