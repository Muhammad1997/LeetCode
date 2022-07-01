#define UINT_MAX (2147483647UL)
int myAtoi(char * s){
    signed int retVar = 0;
    unsigned long int number = 0;
    int i = 0;
    signed char numSign = 1;
    unsigned numStarted = 0;
    while(s[i] != '\0')
    {
        /*get the number*/
        if((s[i] >= '0') && (s[i] <= '9'))
        {
            numStarted = 1;
            /*number * 10 -> add new decimal place, num - 48 because the asci representaion of '0' is 48 in decimal*/
            number = (number*10) + (s[i] - 48);
            /*check for overflow*/
            if ((numSign > 0) && (number > UINT_MAX))
            {
                break;
                
            }
            else if((numSign < 0) && (number > UINT_MAX+1))
            {
                break;
            }
        }
        else if(numStarted != 1)
        {
            /*ignore white space*/
            if(s[i] == ' ')
            {
                /**do nothing - ignore white space at start*/
            }
            /*check for negative sign*/
            else if (s[i] == '-')
            {
                numSign = -1;
                numStarted = 1;
            }
            /*check for positive sign*/
            else if(s[i] == '+')
            {
                numSign = 1;
                numStarted = 1;
            }
            else
            {
                break;
            }
        }
        /*no new numbers to parse*/
        else 
        {
            break;
        }
        i++;
    }
    /*put sign*/
    if ((numSign > 0) && (number > UINT_MAX))
    {
        retVar = UINT_MAX;
        
    }
    else if((numSign < 0) && (number > UINT_MAX+1))
    {
        retVar = -(UINT_MAX+1);
    }
    else
    {
        /*put the sign*/
        retVar = numSign * number;
    }
    return retVar;
}