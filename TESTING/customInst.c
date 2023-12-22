#include <stdint.h>
#include <stdio.h>

int main(void)
{
  uint32_t num1 = 4, num2 = 5, gcd = 0;
  uint32_t n = 10, r = 2, comb = 0;
  uint32_t fact_result_ptr; 

  asm volatile("fact %0, %1\n":"=r"(fact_result_ptr):"i"(10):);
  asm volatile("gcd %0, %1,%2\n":"=r"(gcd):"r"(num1),"r"(num2):);
  asm volatile("comb %0, %1,%2\n":"=r"(comb):"r"(n),"r"(r):);

  printf("\nGCD of %d and %d is %i\n", num1, num2, gcd);
  printf("\nCombination of %dC%d is %i\n", n, r, comb);
  printf("\nFACT of 10 is %i\n", fact_result_ptr);

  return 0;
}
