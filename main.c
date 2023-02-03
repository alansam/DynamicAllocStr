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

typedef struct n2s n2s;
struct n2s {
  int    nr;
  char * nstr;
  size_t nstr_sz;
};

char * number_to_string(int number) {
  char * str = malloc(BIGGULP);
  if (str == NULL) {
    fprintf(stderr, "%s : %d : allocation failed\n", __FILE__, __LINE__);
    exit(EXIT_FAILURE);
  }
  sprintf(str, "%d", number);
  return str;
}

static
n2s sample[] = {
  { .nr = 123, },
  { .nr = INT_MAX, },
  { .nr = INT_MIN, },
};
size_t n2s_sz = sizeof sample / sizeof *sample;

int main(int argc, char const * argv[]) {
  for (size_t s_ = 0ul; s_ < n2s_sz; ++s_) {
    sample[s_].nstr = number_to_string(sample[s_].nr);
    sample[s_].nstr_sz = strlen(sample[s_].nstr);

    printf("%p %4zu\n",
           sample[s_].nstr,
           sample[s_].nstr_sz);
    sample[s_].nstr = realloc(sample[s_].nstr,
                              sample[s_].nstr_sz);
    printf("%p %4zu\n",
           sample[s_].nstr,
           sample[s_].nstr_sz);
    printf("+%15d\n", sample[s_].nr);
    printf(">%15s\n", sample[s_].nstr);
    free(sample[s_].nstr);
    putchar('\n');
  }

// #define LET_IT_LEAK
#ifdef LET_IT_LEAK
  printf("%s\n", number_to_string(123));
#else
  char * kp = NULL;
  printf("~%15s\n", (kp = number_to_string(123)));
  free(kp);
#endif

  return EXIT_SUCCESS;
}
