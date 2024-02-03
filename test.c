#include <stdio.h>
#include <string.h>

int main(){
    // printf("Hello world\'\n");
    char str[10];
    scanf("%s",str);

    // int len = strlen(str);
    // printf("%d",len);
    char str2[10];
    strcat(str2,&str[2]);
    printf("%s",str2);
    // str[strlen(str)] = '\'';
    // printf("%s",str);
    // char str1[10];
    // printf("%s",str1);
}