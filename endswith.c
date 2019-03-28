/*
   endswith.c
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "extlib.h"

bool endswith(char *s, char *pat)
{
    int i,j;
    //getting size of two strings
    int s_size = strlen(s);
    int pat_size = strlen(pat);
    //starting at the end of each string loop
    //until there is a mismatch or until the pat
    //is fully checked
    for(i=pat_size-1, j=s_size-1; i>=0; i--, j--)
    {
	if(s[j] != pat[i])
	    return false;
    }
    return true;
}

#ifdef __MAIN__
int main()
{
    char a[] = "HelloWorld";
    char b[] = "Hello";
    char c[] = "World";
    if(endswith(a, a))
	printf("%s ends with %s\n",a,a);
    else
        printf("%s doesn't end with %s\n",a,a);

}
#endif 
