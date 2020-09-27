#include <cs50.h>
#include <stdio.h>
/* problem set https://cs50.harvard.edu/x/2020/psets/1/mario/more/ */
int main(void)
{
  while (1)
  {
    int h;

    printf("Height: ");
    if (scanf("%d", &h) != 1)
    {
      continue;
    }
    if (h >= 1 && h <= 8)
    {
      int i;
      for (i = 1; i <= h; i++)
      {
        // Print string to screen.
        int spaces;
        for (spaces = 0; spaces < (h - i); spaces++)
        {
          printf(" ");
        }

        int left_side;
        for (left_side = 0; left_side != i; left_side++)
        {
          printf("#");
        }
        printf("  ");

        int right_side;
        for (right_side = 0; right_side != i; right_side++)
        {
          printf("#");
        }

        printf("\n");
      }
      return 0;
    }
  }
  return 0;
}
