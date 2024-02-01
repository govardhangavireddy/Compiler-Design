#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct Production
{
    char lhs;
    char rhs[100];
};
int main(void)
{
    struct Production productions[5];
    int n;
    printf("Enter the number of productions: ");
    scanf("%d", &n);
    if (n == 0)
    {
        printf("No productions entered");
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        printf("Enter lhs of Production %d : ", (i + 1));
        scanf("%s", &productions[i].lhs);
        while (1)
        {
            if (isupper(productions[i].lhs))
            {
                break;
            }
            else
            {
                printf("Enter upper case letter for LHS \n");
                printf("Enter lhs of Production %d : ", (i + 1));
                scanf("%s", &productions[i].lhs);
            }
        }
        printf("Enter rhs of Production : ");
        scanf("%s", productions[i].rhs);
    }
    printf("The productions are : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%c -> %s\n", productions[i].lhs, productions[i].rhs);
    }

    struct Production new_production[5];
    int k = 0, flag = 0;
    new_production[0] = productions[0];
    k++;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (productions[i].lhs == new_production[j].lhs)
            {
                char RHS[100];
                strcpy(RHS, productions[i].rhs);
                strcat(new_production[j].rhs, "/");
                strcat(new_production[j].rhs, RHS);
                flag = 1;
                break;
            }
            else
            {
                flag = 0;
            }
        }
        if (flag == 0)
        {
            new_production[k] = productions[i];
            k++;
        }
    }
    printf("The Simplified productions are : \n");
    for (int i = 0; i < k; i++)
    {
        printf("%c -> %s\n", new_production[i].lhs, new_production[i].rhs);
    }
}