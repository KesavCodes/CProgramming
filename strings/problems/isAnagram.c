#include <stdio.h>
#include <stdbool.h>

bool isAnagram(char *str1, char *str2)
{
    int H[26] = {0};
    for(int i=0;str1[i]!='\0';i++) H[str1[i]-97]++;
    for(int i=0;str2[i]!='\0';i++){
        if(H[str2[i]-97]-1<0) return false;
        H[str2[i]-97]--;
    }
    return true;
}

int main()
{
    printf("%s\n", isAnagram("decimal", "medical") ? "True" : "False");
    printf("%s\n", isAnagram("tenet", "tenet") ? "True" : "False");
    printf("%s\n", isAnagram("batman", "superman") ? "True" : "False");

    return 0;
}