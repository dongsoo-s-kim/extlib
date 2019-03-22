//Repeat Function 
//Lab 08

#include <stdio.h>
#include <string.h>
#include "extlib.h"

char *repeat(char *s, int n){

  for(int i=0; i<n; i++) //Loop n times and print string each time
	  printf("%s", s);

  return NULL;
}


#ifdef __MAIN__
int main()
{
  char b[] = {"Hello"};
  int n;
  printf("ENTER A INTEGER VALUE: ");
  fflush(NULL);
  scanf("%d", &n); //Get n value

  printf("String is: %s\n", b);
  repeat(b, n); //Call function
  fflush(NULL);
}
#endif 