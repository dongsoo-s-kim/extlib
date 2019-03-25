/*
  ltrim.c
  Copyright (C) 2019 Dongsoo S. Kim
 */
#include <string.h>
#include <ctype.h>
#include "extlib.h"

char *ltrim(char *buf)
{
  char *cp; 
  cp = buf; 
  while (isspace(*cp))	// find the first non-space character
    cp++;
  return strcpy(buf, cp); 
}

