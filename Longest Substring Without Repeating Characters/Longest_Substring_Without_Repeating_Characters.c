#include<stdio.h>
int lengthOfLongestSubstring(char * s){
    int retLongestSubString = 0;
    int maxLongStr = 0;
    int newStrStartIdx = 0;
    int i = 0,j = 0;
    while(s[i] != '\0')
    {
        printf("current char:%c ",s[i]);
        /*current Idx is one or more steps ahead new string start Idx*/
        if(newStrStartIdx < i)
        {
            maxLongStr = i - newStrStartIdx + 1;
            for(j = newStrStartIdx; j < i;j++)
            {
                printf(" | checked char:%c ",s[j]);
                /*we found a dublicated char so, make new string from this point*/
                if(s[i] == s[j])
                {
                    newStrStartIdx = j+1;
                    maxLongStr = 0;
                    printf("*");
                    break;
                }
            }
        }
        /*current Idx is the start Idx*/
        else
        {
            maxLongStr = 1;
        }
        /*new longer string*/
        if(maxLongStr > retLongestSubString)
        {
            retLongestSubString = maxLongStr;
        }
        /*increment Idx*/
        i++;
        printf("\n");
    }
    return retLongestSubString;
}

int main()
{
    char * string = "abcabca";
    printf("string : %s\n",string);
    printf("%d",lengthOfLongestSubstring(string));
    return 0;
}