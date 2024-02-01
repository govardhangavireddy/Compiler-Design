// VU21CSEN0100450 - Sai Govardhan Naidu

#include <stdio.h>

int main(void) {
  int n, i;
  printf("Enter a number: ");
  scanf("%d", &n);
  for (i = 2; i <= n; i++) {
    int count = 0;
    for (int j = 2; j < i; j++) {
      if (i % j == 0) {
        count++;
      }
    }
    if (count == 0) {
      printf("%d\n", i);
    }
  }
  return 0;
}