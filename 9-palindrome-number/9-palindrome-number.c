int getLeftDigit(int num,int num_len,int digit)
{
    int retVar = 0;
    int devisor = (int)pow(10,(num_len-digit));
    retVar = (int)num / devisor;
    retVar = retVar % 10;
    return retVar;
}

int getRightDigit(int num,int num_len,int digit)
{
    int retVar = 0;
    int devisor = (int)pow(10,(digit-1));
    retVar = (int)num / devisor;
    retVar = retVar % 10;
    return retVar;
}

bool isPalindrome(int x){
    bool bRet = true;
    int y = x;
    int numOfDigits = 0;
    int i;
    if(x >= 0)
    {
        do
        {
            numOfDigits++;
            y /= 10;
        }
        while(y != 0);
        y = x;
        for(i = 1;i <= numOfDigits/2;i++)
        {
            if(getLeftDigit(y,numOfDigits,i) != getRightDigit(y,numOfDigits,i))
            {
                bRet = false;
            }
            else
            {
                /*do nothing*/
            }
        }
    }
    else
    {
        bRet = false;
    }
    return bRet;
}