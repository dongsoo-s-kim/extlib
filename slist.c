/*
   slist.c
   author: Dongsoo S. Kim (dskim@iupui.edu)
   slist (string list)
   1. slist is an array of character pointers, where the last pointer contains NULL 
      to indicate the end of strings.  
   2. all strings in the array is allocated in a contiguous memory spaces.  

 */
#include <stdlib.h>
#include "extlib.h"

void slist_free(char **s)
{
  free(*s);			/* it is the storage of actual characters */
  free(s); 			/* it is the array of pointers */
}

int slist_count(char **slist)
{
  int cnt = 0;
  char **s; 

  foreach_slist(s, slist)	/* increment until NULL */
    cnt++;
  
  return cnt;
}

