// VU21CSEN0100450 - Sai Govardhan Naidu
#include <stdio.h>
#include <string.h>
int main(void) {
  char str[100];
  int i = 0;
  int No_word = 1;
  int no_char = 0;
  int no_white = 0;
  printf("Enter a string: ");
  scanf("%[^\n]s", str);
  if(strlen(str)==0){
    No_word = 0;
  }
  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] == ' ') {
      no_white++;
      No_word++;
    }
    if (str[i] != ' ') {
      no_char++;
    }
  }

  printf("Number of words: %d\n", No_word);
  printf("Number of characters: %d\n", no_char);
  printf("Number of whitespaces: %d\n", no_white);
}
