#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum TokenType { IDENTIFIER, CONSTANT, KEYWORD, ERROR };

struct Token {
  enum TokenType type;
  char value[50];
};

int isKeyword(char *str) {
  char *keywords[] = {"int",   "if",     "else", "for",   "while",
                      "float", "double", "char", "return"};
  int numKeywords = sizeof(keywords) / sizeof(keywords[0]);

  for (int i = 0; i < numKeywords; ++i) {
    if (strcmp(str, keywords[i]) == 0) {
      return 1;
    }
  }
  return 0;
}
struct Token lexer(char *input) {
  struct Token token;
  int state = 0;
  int index = 0;

  while (input[index] != '\0') {
    char currentChar = input[index];

    switch (state) {
    case 0:
      if (isalpha(currentChar)) {
        state = 1;
        token.type = IDENTIFIER;
        token.value[0] = currentChar;
        token.value[1] = '\0';
      } else if (isdigit(currentChar)) {
        state = 2;
        token.type = CONSTANT;
        token.value[0] = currentChar;
        token.value[1] = '\0';
      } else if (isspace(currentChar)) {

      } else {
        state = 3;
        token.type = ERROR;
        token.value[0] = currentChar;
        token.value[1] = '\0';
      }
      break;
    case 1:
      if (isalnum(currentChar)) {
        strncat(token.value, &currentChar, 1);
      } else {
        state = 0;
        if (isKeyword(token.value)) {
          token.type = KEYWORD;
        }
        return token;
      }
      break;
    case 2:
      if (isdigit(currentChar)) {
        strncat(token.value, &currentChar, 1);
      } else {
        state = 0;
        return token;
      }
      break;
    case 3:
      strncat(token.value, &currentChar, 1);
      break;
    }

    index++;
  }
  if (state == 1 || state == 2) {
    return token;
  }
  token.type = ERROR;
  strcpy(token.value, "Unexpected end of input");
  return token;
}

int main() {
  char input[100];
  printf("Enter a line of code: ");
  fgets(input, sizeof(input), stdin);
  input[strcspn(input, "\n")] = '\0';
  struct Token token = lexer(input);
  printf("<%s, %s>\n",
         token.type == IDENTIFIER
             ? "identifier"
             : (token.type == CONSTANT ? "constant" : "keyword"),
         token.value);
  return 0;
}