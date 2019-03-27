/*
  ctoa.c
  Copyright (C) 2019 Dongsoo S. Kim
 */
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "extlib.h"
#define SPACE      " "
#define PLUS   "+"
#define MINUS  "-"
#define MAX 80
#define SPACED(x)	SPACE x SPACE

char *ctoa_r(char *buffer, double complex x, char *format)
{
  if (format == NULL)
    format = "%f";
  *buffer = '\0';

  if (creal(x) != 0.0)
    sprintf(buffer, format, creal(x));
  
  if (cimag(x) != 0.0) {
    if (creal(x) == 0.0) {
      if (cimag(x) != 1.0)
	strcat(buffer, cimag(x)>0.0 ? PLUS : MINUS);
    }
    else 
      strcat(buffer, cimag(x)>0.0 ? SPACED(PLUS) : SPACED(MINUS));

    if (fabs(cimag(x)) == 1.0)
      strcat(buffer, I_SYMBOL);
    else {
	sprintf(buffer+strlen(buffer), format, fabs(cimag(x)));
	strcat(buffer, SPACE I_SYMBOL);
    }
  }
  if (*buffer == '\0')
    strcpy(buffer, "0");
  
  return buffer; 
}

char *ctoa(double complex x, char *format)
{
  static char buffer[MAX];
  return ctoa_r(buffer, x, format);
}
  
#ifdef __MAIN__
double complex s[] = {
  0, 1, +1, -1, I, -I, 0I, 1+I, 1-1I, 
  +3+4I,
  -3+4I,
  - 3.00 - 4.00I,
  - 3+4I, 
  3.00,
  -4.00I,
  3.00,
  -4.00*I,
  .4E-3+3.5E+3I,
  3E3,
  3E+3,
  3E-3, 
  .3,
  3.,
  3.3
};

int main()
{
  for (int i=0; i<sizeof(s)/sizeof(s[0]); i++) {
    printf("%2d: (%f,%f) => %s\n", i, creal(s[i]), cimag(s[i]), ctoa(s[i], NULL));
  }
}
#endif
