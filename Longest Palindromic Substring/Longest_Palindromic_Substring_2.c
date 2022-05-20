#include<stdio.h>
#include<stdlib.h>
/**
 * @brief function to return the longest Palindromic Substring
 * @details
 *          1 - iterate string
 *          2 - check n-1,n,n+1  or n,n+1 to determine start and stop of Palindromic Substring if found
 *          3 - if found --> iterate with (next--, end --) till u find the max Palindromic, check if end-start > longest Palindromic sub string
 *          4 - next char will be last valid end
 * @param s input string
 * @return char* pointer to output string
 */

char * longestPalindrome(char * s){
    int startIdx = 0,endIdx = 0;
    int tempStartIdx = 0,tempEndIdx = 0;
    int maxStartIdx = 0,maxEndIdx = 0;
    int maxLength = 0;
    int bIsPalindromic = 0;
    int i;
    char * retString;
    while(s[startIdx] != '\0')
    {
        printf("current char:%c %d|",s[startIdx],startIdx);
        if( (startIdx-1 >= 0) && (s[startIdx + 1] != '\0') && (s[startIdx] == s[startIdx + 1]) && (s[startIdx] == s[startIdx - 1]) )
        {
            bIsPalindromic = 1;
            tempStartIdx = startIdx-1;
            tempEndIdx = startIdx+1;
            while (bIsPalindromic == 1)
            {
                printf("same char: %d %d|",tempStartIdx,tempEndIdx);
                if( (tempStartIdx-1 >= 0) && (s[tempStartIdx] == s[tempStartIdx-1]))
                {
                    tempStartIdx--;
                }
                else if ((s[tempEndIdx+1] != '\0') && (s[tempEndIdx] == s[tempEndIdx+1]))
                {
                    tempEndIdx++;
                }
                else
                {
                    break;
                }
            }
            
        }
        else if((s[startIdx + 1] != '\0') && (s[startIdx] == s[startIdx + 1]))
        {
            bIsPalindromic = 1;
            endIdx = startIdx + 1;
            tempStartIdx = startIdx;
            tempEndIdx = endIdx;

        }
        else if((s[startIdx + 1] != '\0') && (s[startIdx + 2] != '\0') && (s[startIdx] == s[startIdx + 2]))
        {
            bIsPalindromic = 1;
            endIdx = startIdx + 2;
            tempStartIdx = startIdx;
            tempEndIdx = endIdx;
        }
        else
        {
            bIsPalindromic = 0;
        }

        while(bIsPalindromic == 1)
        {
            printf("check:%d %d|",tempStartIdx,tempEndIdx);
            if(((tempStartIdx-1) < 0) || (s[tempEndIdx+1] == '\0') || (s[tempStartIdx-1] != s[tempEndIdx+1]))
            {
                printf("new Palindromic|");
                bIsPalindromic = 0;
                if(tempEndIdx - tempStartIdx > maxLength)
                {
                    maxLength = tempEndIdx - tempStartIdx;
                    maxStartIdx = tempStartIdx;
                    maxEndIdx = tempEndIdx;
                }
                startIdx = tempEndIdx-1;
                break;

            }
            tempStartIdx--;
            tempEndIdx++;
        }
        startIdx++;
        printf("\n");
    }
    /*generate max string*/
    retString = (char *)malloc((maxLength + 2) * sizeof(char));
    for(i = 0;i <= maxLength;i++)
    {
        retString[i] = s[maxStartIdx];
        maxStartIdx++;
    }
    retString[i] = '\0';
    return retString;
}

int main()
{
    char * string = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    printf("input string : %s\n",string);
    printf("output string : %s",longestPalindrome(string));
    return 0;
}