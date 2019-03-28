/* Lab08
   Author:
   trim(s) removes begining and trailing spaces of the given string s.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "extlib.h"

char *left_trim(char *buf)
{
  char *dest, *cp; 
  dest = cp = buf; 
  while (isspace(*cp))	// find the first non-space character
    cp++;
  while (*cp)			// shift all remaining to left
      *dest++ = *cp++;  
  *dest = '\0';
  return buf;
}

char *right_trim(char *buf)
{
  char *cp; 
  cp = buf; 
  while (*cp)	// Find end of the string
      cp++;  
  while (buf <= --cp && isspace(*cp))	// trim right
    *cp = '\0'; 
  return buf;
}

char *trim(char *buf)
{
  right_trim (buf);
  left_trim (buf);
  return buf;
}

#ifdef __MAIN__
#define MAX 		256
char *data[] = {
  "Now we are engaged in a great civil war, testing whether that",
  "     nation, or any nation so conceived and so dedicated,",
  "  can long endure. We are met on a great battle-field    ", 
  "   of    that    war.     We    have    come to   ",
  "		dedicate a portion of that field, ",
  "   as a final resting place for those who here gave their", 
  "   lives that that nation might live. It is altogether", 
  "  fitting and proper that we should do this.   ",
  "  ",
  "",
};
int main()
{
  char buffer[MAX]; 
  for (int i=0; i<sizeof(data)/sizeof(data[0]); i++) {
    strcpy(buffer, data[i]); 
    printf("S0 [%s]\n", buffer);
    trim(buffer); 
    printf("S1 [%s]\n", buffer);
    printf("\n");
    fflush(stdout); 
  }
}
#endif


