/*
->  number_to_string takes integer as argument and convert it to string
    i need to return a dynamically allocated string 

->  since i have given large size(1024) in malloc i need to reallocate it to 
    size of string length.
    
-> for example:
    i passed 123 as argument to function. it should return "123" as string
    while returning string it should only take 4 byte 
    (including null character) and remaining 1020 block
    need to be freed

-> my own solution  is finding length of number like:
    while number > 0
        increase counter
        divide number by 10 untill its zero
   character pointer = malloc((sizeof(char) * counter)+1)
   copy string to pointer
   return pointer from function
   
   but if there is other possible way to reallocate memory after assigning 
   some data to it i could learn way to do it and i guess using sprintf makes it
   quick rather than using solution as i have mention in above pseudo code
   since long long integer may takes more time.

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define BIGGULP 1024

char * number_to_string(int number) {
  char * str = malloc(BIGGULP);
  if (str == NULL) {
    fprintf(stderr, "%s : %d : allocation failed\n", __FILE__, __LINE__);
    exit(EXIT_FAILURE);
  }
  sprintf(str, "%d", number);
  return str;
}

int main(void) {
  char * nstr = number_to_string(123);
  size_t nstr_sz = strlen(nstr);

  printf("%p %4zu\n", nstr, nstr_sz);
  nstr = realloc(nstr, nstr_sz + 1);
  printf("%15s\n", nstr);
  free(nstr);
  putchar('\n');

  nstr = number_to_string(INT_MAX);
  nstr_sz = strlen(nstr);

  printf("%p %4zu\n", nstr, nstr_sz);
  nstr = realloc(nstr, nstr_sz + 1);
  printf("%15s\n", nstr);
  free(nstr);
  putchar('\n');

  nstr = number_to_string(INT_MIN);
  nstr_sz = strlen(nstr);

  printf("%p %4zu\n", nstr, nstr_sz);
  nstr = realloc(nstr, nstr_sz + 1);
  printf("%15s\n", nstr);
  free(nstr);
  putchar('\n');

  nstr = number_to_string(INT_MIN);
  nstr_sz = strlen(nstr);

  printf("%p %4zu\n", nstr, nstr_sz);
  nstr = realloc(nstr, nstr_sz + 1);
  printf("%15s\n", nstr);
  free(nstr);
  putchar('\n');

  printf("%s\n", number_to_string(123));

  return EXIT_SUCCESS;
}
