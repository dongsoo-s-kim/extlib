/*
  split.c
  Copyright (C) 2019 Dongsoo S. Kim
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "extlib.h"

char **split(char *s, char *del)
{
  int cnt = count(s, del) + 2;	/* the last one contains NULL */
  char **list = (char **) malloc(cnt * sizeof(char *));
  char *buffer = strdup(s);
  char **lp;
  
  lp = list;
  *lp++ = buffer;
  while (*buffer) {
    if (strchr(del, *buffer)) {
      *buffer = '\0';
      *lp++ = buffer+1;
    }
    buffer++; 
  }
  *lp = NULL;
  return list; 
}

#ifdef __MAIN__

char *data[] = {
  "abc;def",
  ";;abdc;"
};


int main()
{
  char **alist;
  char **a;
  int  acount;
  
  for (int i=0; i<sizeof(data)/sizeof(data[0]); i++) {
    alist = split(data[i], ";");
    acount = slist_count(alist); 
    printf("%s\n", data[i]);
    printf("[%d]", acount);
    int k = 0; 
    foreach_slist(a, alist) {
      printf("%s%c", *a, ++k<acount ? ',' : '\n');
    }
    
    printf("\n");
    slist_free(alist);
  }
}

#endif
