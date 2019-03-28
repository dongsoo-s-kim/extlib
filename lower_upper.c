#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "extlib.h"

char *lower(char *s)//function prototype for converting to lowercase
{
  int i;

  for(i=0;s[i]!='\0';i++)
    {
      if(s[i]< 'Z' && s[i]> 'A')//condition that runs if the input is uppercase
	{
	  s[i] = s[i] + 'a' - 'A';//the statement to if condition where it converts upper to lowercase

	}
    }
  return s;//returns the converted string back
}

char *upper(char *s)
{
  int i;
  //char *res;

  for(i=0;s[i]!='\0';i++)
    {
      if(s[i]<'z' && s[i]>'a')//the condition is met when the input is lowercase 
	{
	  s[i] = s[i] - 'a' + 'A';//the statement that converts lower to uppercase
	}
      
      
    }
  return s;//returns the converted string back
}


int main()
{
  char str[] = "StRiNgS";

  char *res, *result;

  res = lower(str);
  printf("The lowercase string is %s\n", res);
  fflush(stdout);

  result = upper(str);
  printf("The uppercase string is %s\n", result);
  fflush(stdout);

  return 0;
}



  
