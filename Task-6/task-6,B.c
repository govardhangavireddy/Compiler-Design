// VU21CSEN0100450 - Sai Govardhan Naidu Gavireddy
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct Production
{
    char lhs[10];
    char rhs[100];
};

struct CFG
{
    char Terminals[100];
    char NonTerminals[100];
    char Start_Symbol;
};

int main(void)
{
    struct Production productions[5];
    struct CFG cfg;
    int n;
    printf("Enter the number of productions: ");
    scanf("%d", &n);

    if (n == 0)
    {
        printf("Enter number greater then one productions entered");
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

    cfg.Start_Symbol = productions[0].lhs[0];
    strcat(cfg.NonTerminals, &productions[0].lhs[0]);

    for (int i = 1; i < n; i++)
    {
        if(strchr(cfg.NonTerminals,productions[i].lhs[0]) == NULL){
            strcat(cfg.NonTerminals, ",");
            strcat(cfg.NonTerminals, &productions[i].lhs[0]);
        }
        else{
            continue;
        }
    }

    for(int i=0;i<strlen(productions[0].rhs);i++){
        if(isupper(productions[0].rhs[i])){
            continue;
        }
        else{
            cfg.Terminals[strlen(cfg.Terminals)] = productions[0].rhs[i];
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < strlen(productions[i].rhs); j++)
        {
            if (isupper(productions[i].rhs[j]))
            {
                if (strchr(cfg.NonTerminals, productions[i].rhs[j]) == NULL)
                {
                    cfg.NonTerminals[strlen(cfg.NonTerminals)] = ',';
                    cfg.NonTerminals[strlen(cfg.NonTerminals)] = productions[i].rhs[j];
                }
                else
                {
                    continue;;
                }
            }
            else
            {
                if (strchr(cfg.Terminals, productions[i].rhs[j]) == NULL)
                {
                    if(strlen(cfg.Terminals)==0){
                        cfg.Terminals[strlen(cfg.Terminals)] = productions[i].rhs[j];
                    }
                    else{
                        cfg.Terminals[strlen(cfg.Terminals)] = ',';
                        cfg.Terminals[strlen(cfg.Terminals)] = productions[i].rhs[j];
                    }
                }
                else
                {
                    continue;
                }
            }
        }
    }

    printf("\nStart Symbol : %c\n", cfg.Start_Symbol);
    printf("Terminals : %s\n", cfg.Terminals);
    printf("Non Terminals : %s\n", cfg.NonTerminals);
    printf("The productions are : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%s -> %s\n", productions[i].lhs, productions[i].rhs);
    }
}

