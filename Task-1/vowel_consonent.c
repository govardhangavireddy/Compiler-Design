// VU21CSEN0100450 - Sai Govardhan Naidu
#include <stdio.h>

int main(void) {
  char c;
  printf("Enter input : ");
  scanf("%c", &c);
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' ||
      c == 'E' || c == 'I' || c == 'O' || c == 'U') {
    printf("Its a vowel\n");
  } else {
    printf("Its a consonant\n");
  }
}