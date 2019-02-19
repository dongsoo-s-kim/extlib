/*
 * count.c
 * author: Stephen Kim (dongsoo.s.kim@gmail.com)
 */
#include <stdio.h>
#include <string.h>
#include "extlib.h"

/* 
   count()
   to count the number of characters of 'ch' in 's'. 
   for example, 
      count("hello world!", "l") returns 3, because 's' contain 3 'l'
      count("hello world!", "lo") return 5, because 's' contain 5 'l' or 'o'
 */
int count(char *s, char *ch)
{
  int cnt = 0; 
  while (*s) {
    if (strchr(ch, *s))
      cnt++;
    s++;
  }
  return cnt; 
}


#ifdef __MAIN__
int main()
{
  char *s[] = {
    "Hello. World", 
    "Four score and seven years ago our fathers brought forth on this continent, a  new nation, conceived in Liberty, and dedicated to the proposition that all men  are created equal."
  };

  for (int i=0; i < sizeof(s)/sizeof(s[0]); i++) {
    printf("%d\t%d\t%d\n", i, count(s[i], "l"), count(s[i], "lo")); 
  }
}
#endif
