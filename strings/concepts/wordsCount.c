#include <stdio.h>
int numberOfWords(char *A)
{
    int wCount = 0, i = 0;
    while (A[i] != '\0')
    {
        if ((A[i] != ' ' && A[i+1] == ' ') || (A[i] != ' ' && A[i+1] == '\0'))
            wCount += 1;
        i++;
    }
    return wCount; 
}

int main()
{
    char var1[] = "hello";
	char var2[] = " hello";
	char var3[] = " hello from the other side ";
	char var4[] = "This is good to hear that";
	char var5[] = "This is good to hear that ";
	char var6[] = "";
	char var7[] = " ";
	char var8[] = "    Hello World ";
	char var9[] = "    Hello World";
 
	printf("Number of words(var1): %d \n", numberOfWords(var1)); // 1
	printf("Number of words(var2): %d \n", numberOfWords(var2)); // 1
	printf("Number of words(var3): %d \n", numberOfWords(var3)); // 5
	printf("Number of words(var4): %d \n", numberOfWords(var4)); // 6
	printf("Number of words(var5): %d \n", numberOfWords(var5)); // 6
	printf("Number of words(var6): %d \n", numberOfWords(var6)); // 0
	printf("Number of words(var7): %d \n", numberOfWords(var7)); // 0
	printf("Number of words(var8): %d \n", numberOfWords(var8)); // 2
	printf("Number of words(var9): %d \n", numberOfWords(var9)); // 2
    return 0;
}