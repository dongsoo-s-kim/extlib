/*
   extlib.h
   Copyright (C) 2019 Dongsoo S. Kim
 */
#ifndef EXTLIB_H
#define EXTLIB_H
#include <stdbool.h>
#include <complex.h>
#define I_SYMBOL "j"
#define IMAG_CHARS  "iIjJ"

double complex atoc(char *str); 
char *ctoa_r(char *buffer, double complex x, char *format); 
char *ctoa(double complex x, char *format);

char *extract(char *s, char *ch);	/* eliminate characters in 'ch' from 's' */
char *compact(char *s); 		/* squeeze consecutive spaces to a space */
int  count(char *s, char *ch);		/* return the characters of ch in s */
char **split(char *s, char *del);	/* to split s by any of del */
char *ltrim(char *s);		     	/* to remove leading spaces */
char *rtrim(char *s);		     	/* to remove ending spaces */
void slist_free(char **slist);		
int  slist_count(char **slist); 

bool startswith(char *s, char *pat);	/* check if s starts with pat */
bool endswidth(char *s, char *pat);	/* check if s ends with pat */
char *repeat(char *s, int n);		/* repeat s n times */
char *lower(char *s);		     /* to convert all characters to lower case */
char *upper(char *s);		     /* to convert all characters to upper case */
char *capitalize(char *s);	     /* to convert each word to capitalized */
char *reverse(char *s);		     /* to reverse the string s */
char *trim(char *s);		     /* to remove leading and ending spaces */
char *join(char **slist, char *ch);  /* to insert ch between each characters */
char *rfind(char *s, char *pat);     /* to find the last pat in s */
char *replace(char *s, char *old, char *new); /* to replace old string with new string */

#define foreach_slist(x, xlist)  for (x=xlist; *x; x++)

#endif
