/*
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
*/

char numToRoman(int * num)
{
    char retChar = 0;
    if(*num >= 1000)
    {
       retChar = 'M';
       *num = *num - 1000;
    }
    else if(*num == 900)
    {
       retChar = 'C';
       *num = 1000;
    }
    else if(*num >= 500)
    {
       retChar = 'D';
       *num = *num - 500;
    }
    else if(*num == 400)
    {
       retChar = 'C';
       *num = 500;
    }
    else if(*num >= 100)
    {
       retChar = 'C';
       *num = *num - 100;
    }
    else if(*num == 90)
    {
       retChar = 'X';
       *num = 100;
    }
    else if(*num >= 50)
    {
       retChar = 'L';
       *num = *num - 50;
    }
    else if(*num == 40)
    {
       retChar = 'X';
       *num = 50;
    }
    else if(*num >= 10)
    {
       retChar = 'X';
       *num = *num - 10;
    }
    else if(*num == 9)
    {
       retChar = 'I';
       *num = 10;
    }
    else if(*num >= 5)
    {
       retChar = 'V';
       *num = *num - 5;
    }
    else if(*num == 4)
    {
       retChar = 'I';
       *num = 5;
    }
    else if(*num >= 1)
    {
       retChar = 'I';
       *num = *num - 1;
    }
    return retChar;
}


char * intToRoman(int num){
    int i = 0;
    int currentNum = 0;
    int divider = 1000;
    char * retString  = (char *) malloc(sizeof(char)*30);
    while (num > 0)
    {
        currentNum = divider*(num/divider);
        num = num - currentNum;
        while(currentNum > 0)
        {
            *(retString+i) = numToRoman(&currentNum);
            i++;
            // retString  = (char *) realloc(retString,(i+1)*sizeof(char));
        }
        divider /= 10;
    }
    *(retString+i) = '\0';
    return retString;
}