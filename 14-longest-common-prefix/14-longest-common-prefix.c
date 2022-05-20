char * longestCommonPrefix(char ** strs, int strsSize){
    int i = 0,j = 0;
    int bFinished = 0;
    if(strsSize > 1)
    {
        while(strs[0][i] != '\0' && bFinished == 0)
        {
            for(j = 0;j < strsSize-1;j++)
            {
                /*current digit dont match on the next string*/
                if(strs[j][i] != strs[j+1][i])
                {
                    strs[0][i] = '\0';
                    bFinished = 1;
                    break;
                }
                /*current digit matches two strings then go check next two strings*/
                else
                {
                    /*pass*/
                }
            }
            i++;
        }
    }
    return strs[0];
}