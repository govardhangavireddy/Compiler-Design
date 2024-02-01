// VU21CSEN0100450 - Sai Govardhan Naidu
#include <stdio.h>
#include <string.h>

int main(void) {
  char str[100];
  int i = 0;
  printf("Enter Email : ");
  scanf("%s", str);
  if(str[0] == '\0' || strchr(str, '@') == NULL) {
    printf("Invalid email\n");
    return 0;
  }
  char *domain = strchr(str, '@') + 1;
  if(strcmp(domain, "gmail.com") == 0) {
    printf("Valid email\n");
  } else {
    printf("Invalid email\n");
  }
}
