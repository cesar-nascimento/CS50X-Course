#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Check out the exercice at: https://cs50.harvard.edu/x/2020/psets/2/substitution/ */

int main(int argc, char *argv[])
{

  /* Validate quantity of system args */
  if (argc != 2)
  {
    printf("Usage: ./substitution key\n");
    return 1;
  }

  /* Validate key */
  unsigned int key_size;
  key_size = strlen(argv[1]);
  if (key_size != 26)
  {
    printf("Key must contain 26 characters.");
    return 1;
  }

  /* Loop over the key */
  char *key = argv[1];
  for (int i = 1; i != key_size; i++)
  {
    char current;
    char *remainder;

    current = key[0];
    remainder = ++key;

    /* If of the characters is not an alphabetic character: exit. */
    if ((current < 'A' || current > 'Z') && (current < 'a' || current > 'z'))
    {
      printf("%c is not a valid character.", current);
      return 1;
    }

    for (int j = 0; j != (key_size - i); j++)
    {
      if ((current | 32) == (remainder[j] | 32))
      {
        printf("%c is repeated, each letter should only appear once\n", current);
        printf("%c == %c\n", current, remainder[j]);
        return 1;
      }
    }
  }

  printf("plaintext:  ");

  /* Receives an input string of unknow size and assing it to an array */
  int size = 64;
  int current_size = size;
  char *string = malloc(size);
  int c = EOF;
  int i = 0;

  while ((c = getchar()) != '\n' && c != EOF)
  {
    string[i++] = (char)c;

    if (i == current_size)
    {
      current_size = i + size;
      string = realloc(string, current_size);
    }
  }
  string[i] = '\0';

  /* construct the lookup table */
  char alphabet[128];

  for (size_t i = 65, j = 0; i <= 90; i++)
  {
    alphabet[i] = (argv[1][j] & 95);
    alphabet[(i + 32)] = argv[1][j] | 32;
    j++;
  }

  for (size_t i = 0; i <= current_size; i++)
  {
    if ((string[i] >= 'A' && string[i] <= 'Z') || (string[i] >= 'a' & string[i] <= 'z'))
    {
      string[i] = alphabet[(int)string[i]];
    }
  }
  
  printf("ciphertext: %s\n", string);

  return 0;
}
