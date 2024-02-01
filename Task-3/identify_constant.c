// VU21CSEN0100450 - Sai Govardhan Naidu Gavireddy
#include <ctype.h>
#include <stdio.h>

void classifyConstant(char constant[]) {
  int hasDecimal = 0;
  int isReal = 0;

  int i;
  for (i = 0; constant[i] != '\0'; i++) {
    if (!isdigit(constant[i])) {
      if (constant[i] == '.' && !hasDecimal) {
        hasDecimal = 1;
      } else {
        printf("Invalid character in constant\n");
        return;
      }
    }
  }

  if (hasDecimal) {
    printf("%s is a Real Number\n", constant);
  } else {
    printf("%s is an Integer\n", constant);
  }
}

int main() {
  char constant[100];

  printf("Enter a constant: ");
  scanf("%s", constant);

  if (isdigit(constant[0])) {
    classifyConstant(constant);
  } else {
    printf("Invalid constant\n");
    return 1;
  }
  return 0;
}
