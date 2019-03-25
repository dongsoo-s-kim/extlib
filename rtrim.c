/*
  rtrim.c
  Copyright (C) 2019 Dongsoo S. Kim
 */
#include <string.h>
#include <ctype.h>
#include "extlib.h"

char *rtrim(char *buf)
{
  char *cp = buf + strlen(buf); 
  for (cp = buf+strlen(buf)-1; buf <= cp && isspace(*cp); cp--) 
    *cp = '\0'; 
  return buf; 
}

