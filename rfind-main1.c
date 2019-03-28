#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int rfind(char[], char);
int endswith(char[], char);
int main() {
  
    char e[] = "Missisipi";
    printf("Last i position in %s is %d\n", e, rfind(e, 'i'));
    if (endswith(e, 'i')) printf("%s ends with i\n", e);
	return 0;
}

int rfind(char s[], char ch) {
    int i, k = -1; // means ch is not present.
    for (i = 0; s[i] != 0; i++) {

        if (s[i] == ch) k = i; // sets to if its k till last char
    }
    return k;
}