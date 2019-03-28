#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include "extlib.h"


char *replace(char *s, char *old, char *new)

{
	char *res;
	int oldWrd = strlen(old);//storing the word in a string
	int newWrd = strlen(new);//storing the length of the word
	int i, count = 0;

	for (i = 0; old[i] != '\0'; i++)//loop counts the letters in the word
	{

		count++;

	}
     
	res = (char *)malloc(sizeof(i + count * (newWrd - oldWrd) + 1));//allocates memory in the result to accomodate the data type of the new replaced word
	i = 0;
	while (*s)
	{
		res[i] = '\0';
		if (strstr(s, old) == s)
		{
		  strcpy(&res[i], new);//copys the result of the new replaced word to the new result string
			i += newWrd;
			s += oldWrd;
		}
		else
		  res[i++] = *s++;//stores the length of the string into the new one
	}

	return res;//returns the resulting new word back into the output
}



int main()
{
	char str[] = "xxxIamxxx";
	char c[] = "xxx";
	char d[] = "Boy";

	char *res = NULL;

	// oldW string 
	printf("Old string: %s\n", str);
	fflush(stdout);

	res = replace(str, c, d);
	printf("New String: %s\n", res);
	fflush(stdout);

	free(res);

	//system("pause");
	return 0;

}
