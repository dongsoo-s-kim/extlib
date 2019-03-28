
// Capitilize
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "extlib.h"
#include <ctype.h>

int Cap()
{
char str[100]={0};	
int i;
printf("Enter a string: ");
 gets(str);//reads str input with spaces
 
for(i=0; str[i]!='\0'; i++) 
  {
    if(i==0)
      {
	if((str[i]>='a' && str[i]<='z'))
	  str[i]=str[i]-32; // subtract 32 to make sure its capital
	continue;
      }
    if(str[i]==' ')
      {
	++i;
	if(str[i]>='a' && str[i]<='z')
	  {
	    str[i]=str[i]-32;
	    continue;
	  }
      }
    else
      {
	if(str[i]>='A' && str[i]<='Z')
	  str[i]=str[i]+32;
      }
  }
 printf("Capitalize string is: %s\n",str);
 return 0;
}


