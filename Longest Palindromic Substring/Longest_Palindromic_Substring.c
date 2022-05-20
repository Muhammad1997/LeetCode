#include<stdio.h>
#include<stdlib.h>


char * longestPalindrome(char * s){
    int startIdx = 0,endIdx = 0;
    int tempStartIdx = 0,tempEndIdx = 0;
    int maxStartIdx = 0,maxEndIdx = 0;
    int maxLength = 0;
    int i;
    char * retString;
    while(s[startIdx] != '\0')
    {
        printf("current char:%c|",s[startIdx]);
        endIdx = startIdx + 1;
        while (s[endIdx] != '\0')
        {
            /*found a dublicated char*/
            if(s[startIdx] == s[endIdx])
            {
                printf("found char at:%d|",endIdx);
                tempStartIdx = startIdx;
                tempEndIdx = endIdx;
                while (tempStartIdx < tempEndIdx)
                {
                    printf("temp st:%d,temp end:%d|",tempStartIdx,tempEndIdx);
                    /*not a paladromic string*/
                    if(s[tempStartIdx] != s[tempEndIdx])
                    {
                        break;
                    }
                    tempStartIdx++;
                    tempEndIdx--;
                    /*we found a paladromic string, check for the longest string*/
                    if(tempStartIdx >= tempEndIdx)
                    {
                        if((endIdx-startIdx) > maxLength)
                        {
                            maxLength = endIdx-startIdx;
                            printf("-->start found:%d,End found:%d",startIdx,endIdx);
                            maxStartIdx = startIdx;
                            maxEndIdx = endIdx;
                        }
                    }
                }
                
            }
            endIdx++;
        }
        
        startIdx++;
        printf("\n");
    }
    /*generate max string*/
    maxLength = maxEndIdx - maxStartIdx;
    retString = (char *)malloc((maxLength + 2) * sizeof(char));
    printf("length:%d\n",maxLength+2);
    for(i = 0;i <= maxLength;i++)
    {
        printf("%d\n",i);
        retString[i] = s[maxStartIdx];
        maxStartIdx++;
    }
    printf("%d\n",i);
    retString[i] = '\0';
    return retString;
}

int main()
{
    char * string = "aaa";
    printf("input string : %s\n",string);
    printf("output string : %s",longestPalindrome(string));
    return 0;
}