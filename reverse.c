#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "extlib.h"

int main()
{
  char x[100], y[100];//sets the spaces stored in the arrays
  int begin, end;//declaring variables
  int cntr = 0;

  printf("Enter the worded string: \n");//asking the user to input a string
  fflush(stdout);
  scanf("%s", &x);

  while(x[cntr] != '\0')
    {
      cntr++;//counts the length of the string entered
    }
  end = cntr -1;//the "-1" removes the null character at the end of the string

  for(begin = 0;begin<cntr;begin++)
     {
       y[begin] = x[end];//this is a sort type statement that replaces the beginning letter to the end space one at a time
       end--;
     }
  x[begin]='\0';//the beginning space in the array is given the null character

  printf("The reverse output of the string is: %s\n",y);
  fflush(stdout);
  return 0;
}
