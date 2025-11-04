#include <stdio.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize)
{
    if(strsSize == 0)
        return "";

    int len = strlen(strs[0]);

    for (int i = 0; i < len; i++)
    {
        for (int j = 1; j< strsSize; j++)
        {
            if(strs[j][i] != strs[0][i])
            {
                strs[0][i] = '\0'; // truncate
                return strs[0];
            }
        }
    }
    return strs[0];
}

int main() 
{
    char s1[] = "technique";
    char s2[] = "technician";

    char* strs[] = { s1, s2 };

    int strsSize = sizeof(strs) / sizeof(strs[0]);
    char* result = longestCommonPrefix(strs, strsSize);
    printf("lcp: %s\n", result);
    return 0;


}


// https://coderivers.org/blog/c-longest-common-prefix/
// and leetcode