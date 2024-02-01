// VU21CSEN0100450 - Sai Govardhan Naidu
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
  return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
  char sentence[100];
  char *words[100], *word;
  int i = 0;
  printf("Enter a sentence : ");
  scanf("[^\n]%s", sentence);

  word = strtok(sentence, " ");
  while (word != NULL) {
    words[i++] = word;
    word = strtok(NULL, " ");
  }
  
  qsort(words, i, sizeof(char *), compare);

  for (int j = 0; j < i; j++) {
    printf("%s\n", words[j]);
  }
  return 0;
}
