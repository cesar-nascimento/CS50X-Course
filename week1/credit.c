#include <stdio.h>
/* problem set https://cs50.harvard.edu/x/2020/psets/1/credit/ */
int main(void)
{
  while (1)
  {
    unsigned long long int cc_number;
    int total_digits = 0;

    printf("Number: ");
    if (scanf("%llu", &cc_number) != 1)
    {
      continue;
    }
    int sum_product_second = 0;
    int sum_first = 0;
    int sum_total;
    unsigned long long int number = cc_number;

    while (number != 0)
    {
      int second;
      int first;

      first = number % 10;
      sum_first += first;
      second = ((int)(number % 100) / 10) * 2;
      while (second != 0)
      {
        sum_product_second += (second % 10);
        second /= 10;
      }

      number /= 10;
      total_digits++;
      if (number != 0)
      {
        total_digits++;
        number /= 10;
      }
    }

    sum_total = sum_first + sum_product_second;

    if (sum_total % 10 == 0)
    {
      int last_one;
      int last_two;

      if (total_digits == 13)
      {

        last_one = cc_number / 1000000000000;
        if (last_one == 4)
        {
          printf("VISA\n");
          return 0;
        }
        else
        {
          printf("INVALID\n");
          return 0;
        }
      }
      else if (total_digits == 15)
      {

        last_two = cc_number / 10000000000000;
        if (last_two == 34 || last_two == 37)
        {
          printf("AMEX\n");
          return 0;
        }
        else
        {
          printf("INVALID\n");
          return 0;
        }
      }
      else if (total_digits == 16)
      {
        last_one = cc_number / 1000000000000000;
        last_two = cc_number / 100000000000000;
        if (last_one == 4)
        {
          printf("VISA\n");
          return 0;
        }
        else if (last_two <= 55 && last_two >= 51)
        {
          printf("MASTERCARD\n");
          return 0;
        }
        else
        {
          printf("INVALID\n");
          return 0;
        }
      }
      else
      {
        printf("INVALID\n");
        return 0;
      }
    } else
    {
      printf("INVALID\n");
      return 0;
    }
    
  }
  return 0;
}
