// VU21CSEN0100450 - Sai Govardhan Naidu
#include <stdbool.h>
#include <stdio.h>

bool isValidIdentifier(char *str)
{
  if (!(str[0] == '_' || (str[0] >= 'a' && str[0] <= 'z') ||
        (str[0] >= 'A' && str[0] <= 'Z')))
  {
    return false;
  }
  for (int i = 1; str[i] != '\0'; i++)
  {
    if (str[i] == '[')
    {
      if (str[i + 1] == ']')
      {
        printf("Identifier is an Array");
        return true;
      }
      else
      {
        return false;
      }
    }
    else if (str[i] == '(')
    {
      if (str[i + 1] == ')')
      {
        printf("Identifier is a Function");
        return true;
      }
      else
      {
        return false;
      }
    }
    else if (str[i] == '{')
    {
      if (str[i + 1] == '}')
      {
        printf("Identifier is a Structure");
        return true;
      }
      else
      {
        return false;
      }
    }
    if (!((str[i] >= 'a' && str[i] <= 'z') ||
          (str[i] >= 'A' && str[i] <= 'Z') ||
          (str[i] >= '0' && str[i] <= '9') || str[i] == '_'))
    {
      return false;
    }
  }
  printf("Identifier is a Variable");
  return true;
}

int main(void)
{
  char str[100];
  printf("Enter a identiifer : ");
  scanf("%[^\n]s", str);
  bool result = isValidIdentifier(str);
  if (result == true)
  {
    printf("");
  }
  else
  {
    printf("Its not a valid Identifier");
  }
}