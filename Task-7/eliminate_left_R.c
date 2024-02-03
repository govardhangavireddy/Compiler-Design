// VU21CSEN0100450 - Sai Govardhan Naidu Gavireddy

#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct Production
{
    char lhs[10];
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
        scanf("%s", productions[i].lhs);
        while (1)
        {
            if (isupper(productions[i].lhs[0]))
            {
                break;
            }
            else
            {
                printf("Enter upper case letter for LHS \n");
                printf("Enter lhs of Production %d : ", (i + 1));
                scanf("%s", productions[i].lhs);
            }
        }
        printf("Enter rhs of Production : ");
        scanf("%s", productions[i].rhs);
    }

    printf("The productions are : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%s -> %s\n", productions[i].lhs, productions[i].rhs);
    }

    struct Production new_productions[10] = {0};
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        if (productions[i].lhs[0] == productions[i].rhs[0])
        {
            strcat(new_productions[k].lhs, productions[i].lhs);
            char str[10] = {0};
            for (int j = 1; j < strlen(productions[i].rhs); j++)
            {
                if (productions[i].rhs[j] == '/')
                {
                    strcat(new_productions[k].rhs, &productions[i].rhs[j + 1]);
                    new_productions[k].rhs[strlen(new_productions[k].rhs)] = productions[i].lhs[0];
                    strcat(new_productions[k].rhs, "'");
                    k++;
                    break;
                }
                else
                {
                    str[strlen(str)] = productions[i].rhs[j];
                }
            }
            strcat(new_productions[k].lhs, productions[i].lhs);
            strcat(new_productions[k].lhs, "'");
            strcat(new_productions[k].rhs, str);
            strcat(new_productions[k].rhs, new_productions[k].lhs);
            strcat(new_productions[k].rhs, "/null");
            k++;
        }
        else
        {
            new_productions[k] = productions[i];
            k++;
        }
    }
    printf("\nProductions after removing left recursion\n");
    for (int i = 0; i < k; i++)
    {
        printf("%s -> %s\n", new_productions[i].lhs, new_productions[i].rhs);
    }
}