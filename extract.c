/*
  extract.c
  Copyright (C) 2019 Dongsoo S. Kim
 */
#include <ctype.h>
#include <string.h>
#include "extlib.h"

char *extract(char *s, char *ch)
{
  char *saved, *t;
  saved = t = s;
  while (*s) {
    if (!strchr(ch, *s))	/* copy un-matched characters */
      *t++ = *s;
    s++;
  }
  *t++ = '\0';
  return saved; 
}

