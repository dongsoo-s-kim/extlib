/*
  atoc.c
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

double complex atoc(char *str)
{
  double x, y;
  char *a;
  char buffer[MAX];
  strcpy(buffer, str);

  a = extract(buffer, " \t\v\n");

  if (strchr(IMAG_CHARS, *a))
    return I;
  
  x = strtod(a, &a);
  if (*a == '\0')		/* contains a real part alone */
    return x;
  
  if (strchr(IMAG_CHARS, *a))	/* if it is one of {j,J,i,I}, */
    return x * I;		/* it contains an imaginary part alone */

  if (strchr(IMAG_CHARS, *(a+1))) {
    switch (*a) {
    case '+':
      y = 1;
      break;
    case '-':
      y = -1;
      break;
    default:
      y = 0;
      fprintf(stderr, "atoc() error for [%s]\n", str);
    }
    a++;
  }
  else {
    y = strtod(a, &a);		/* Now, it contains both real and imaginary parts */
  }
  
  if (strchr(IMAG_CHARS, *a))	/* if it is none of {j,J,i,I}, it is an error  */
    return x + y * I;
  
  fprintf(stderr, "atoc() error for [%s]\n", str);
  /* it contains two real parts, error!!!  */
  return 0; 
}

#ifdef __MAIN__
char *s[] = {
  "0", "1", "+1", "-1", "j", "+j", "-j", "1j", "+1j", "-1j", "0j", "1+j", "1-1j", 
  "+3+4j",
  "-3+4j",
  "-3 + 4 i",
  "- 3.00 - 4.00 I",
  "- 3+4 J", 
  "3.00",
  "-4.00 j",
  "3.00",
  "-4.00 j",
  ".4E-3+3.5E+3j",
  "3E3",
  "3E+3",
  "3E-3", 
  ".3",
  "3.",
  "3.3"
};

int main()
{
  for (int i=0; i<sizeof(s)/sizeof(s[0]); i++) {
    double complex x;
    x = atoc(s[i]);
    printf("%2d: %-16s => (%f,%f)\n", i, s[i], creal(x), cimag(x));
  }
}
#endif
