#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/* problem set https://cs50.harvard.edu/x/2020/psets/2/readability/ */
int main(void)
{
  while (1)
  {
    int size = 64;
    int current_size = size;

    char *array = malloc(size);

    printf("Text: ");

    int c = EOF;
    int i = 0;

    while ((c = getchar()) != '\n' && c != EOF)
    {
      array[i++] = (char)c;

      if (i == current_size)
      {
        current_size = i + size;
        array = realloc(array, current_size);
      }
    }
    array[i] = '\0';

    int words = 0;
    int letters = 0;
    int sentences = 0;

    char *pa;

    pa = array;

    while (1)
    {

      if (*pa == ' ')
      {
        words++;
      }
      else if (*pa == '\0')
      {
        words++;
        break;
      }
      else if (*pa == '.' || *pa == '!' || *pa == '?')
      {
        sentences++;
      }
      else if ((*pa >= 'A' && *pa <= 'Z') || (*pa >= 'a' && *pa <= 'z'))
      {
        letters++;
      }
      *pa++;
    }

    float index;
    float L;
    float S;
    int index_rounded;

    L = (float)letters / (float)words * 100;
    S = (float)sentences / (float)words * 100;

    index = roundf((0.0588 * L - 0.296 * S - 15.8));

    index_rounded = (int)index;

    if (index_rounded < 1)
    {
      printf("Before Grade 1\n");
      return 0;
    }
    else if (index_rounded >= 16)
    {
      printf("Grade 16+\n");
      return 0;
    }
    else
    {
      printf("Grade %d\n", index_rounded);
      return 0;
    }
    return 0;
  }
  return 0;
}
