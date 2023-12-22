#include<stdio.h>
#include <stdint.h>
int main(void)
{
  uint32_t fact_result_ptr; 

  asm volatile("fact %0, %1\n":"=r"(fact_result_ptr):"i"(254):); 

  printf("fact: %i\n", fact_result_ptr);

  return 0;
}
