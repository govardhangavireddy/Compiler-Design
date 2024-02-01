// VU21CSEN0100450 - Sai Govardhan Naidu
#include <stdio.h>

int main(void) {
  char str[100];
  int no_vowels = 0, no_words = 1;
  printf("Enter a sentence : ");
  scanf("%[^\n]s", str);
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' ||
        str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' ||
        str[i] == 'O' || str[i] == 'U') {
      no_vowels++;
    }
    if (str[i] == ' ') {
      no_words++;
    }
  }
  printf("No of words : %d\n", no_words);
  printf("No of vowels : %d\n", no_vowels);
  return 0;
}