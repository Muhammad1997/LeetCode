#define INT_MAX_COMP (214748364)        /*MAX positive int is 2147483647*/
#define INT_MIN_COMP (-214748364)       /*MAX negative int is -2147483648*/

int reverse(int x){
    int reversedNum = 0;
    while(x != 0)
    {
        /*check if the next iteration will overflow !!*/
        if(reversedNum >= INT_MAX_COMP || reversedNum <= INT_MIN_COMP)
        {
            /*num will be less than max positive int*/
            if(reversedNum == INT_MAX_COMP && (x%10) < 7)
            {
                /*continue*/
            }
            /*num will be less than max negative int*/
            else if(reversedNum == INT_MIN_COMP && (x%10) < 8)
            {
                /*continue*/
            }
            /*num will overflow*/
            else
            {
                reversedNum = 0;
                break;
            }
        }
        reversedNum = (reversedNum*10) + (x%10);
        x /= 10;
    }
    return (int)reversedNum;
}