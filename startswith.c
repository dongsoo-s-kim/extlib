/*
   startswith.c
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "extlib.h"

bool startswith(char *s, char *pat)
{
    //while pattern doesn't equal 0
    while(*pat)
    {
	//check to see if pat matches source
	if(*s != *pat)
	    return false; //if mismatch return false
	//then move to next letter in string
	pat++;
	s++;
    }
    return true;
}

#ifdef __MAIN__
int main()
{
    char a[] = "HelloWorld";
    char b[] = "Hello";
    char c[] = "World";
    if(startswith(b, a))
	printf("%s begins with %s\n",b,a);
    else
        printf("%s doesn't begin with %s\n",b,a);

}
#endif 
