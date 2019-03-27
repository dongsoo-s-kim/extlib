//Repeat Function 
//Lab 08

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "extlib.h"

char * repeat(char *s, int n){

  int counter = 0;
  char *holder = s;
  char *buff = malloc(sizeof(char)*50);
  for(int i=0; i<n; i++) //Loop n times
  {
	  //copy string to buffer each time
	  while(*holder)
	  {
	    buff[counter++] = *holder;
	    holder = holder + 1; 
	  }  
	holder = s;
  }
  buff[counter] = '\0';
  return buff;
}


#ifdef __MAIN__
int main()
{
  char b[] = {"Hello"};
  char *a;
  int n;
  printf("ENTER A INTEGER VALUE: ");
  fflush(NULL);
  scanf("%d", &n); //Get n value

  printf("String is: %s\n", b);
  a = repeat(b, n); //Call function
  printf("%s",a);
  fflush(NULL);

}
#endif 
