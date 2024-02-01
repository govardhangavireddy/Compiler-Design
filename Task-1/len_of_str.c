// VU21CSEN0100450 - Sai Govardhan Naidu
#include <stdio.h>

int main(void) {
  char str[20];
  int len = 0;
  printf("Enter a String : ");
  scanf("%[^&\n]s", str);

  int i = 0;
  while (str[i] != '\0') {
    len++;
    i++;
  }
  printf("length of string is %d", len);
}