double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    double medianValue = 0;
    int medIdx = 0;
    int i;
    int nums1Idx = 0,nums2Idx = 0;
    int midElement = 0,preMidElement;
    int num1Finished = 0,num2Finished = 0;
    medIdx = (nums1Size + nums2Size)/2;
    for(i = 0;i <= medIdx;i++)
    {
        // printf("%d %d -- ",nums1Idx,nums2Idx);
        preMidElement = midElement;
        if(nums1Size > 0 && nums2Size > 0) 
        {
            if((nums1[nums1Idx] <= nums2[nums2Idx] && num1Finished != 1) || num2Finished == 1)
            {
                midElement = nums1[nums1Idx];
                if(nums1Idx < nums1Size-1)
                {
                    nums1Idx++;
                }
                else
                {
                    num1Finished = 1;
                }
            }
            else if((nums2[nums2Idx] <= nums1[nums1Idx] && num2Finished != 1) || num1Finished == 1)
            {
                midElement = nums2[nums2Idx];
                if(nums2Idx < nums2Size-1)
                {
                    nums2Idx++;
                }
                else
                {
                    num2Finished = 1;
                }
            }
        }
        /*array 1 is empty*/
        else if(nums1Size <= 0)
        {
            midElement = nums2[nums2Idx];
            nums2Idx++;
        }
        /*array 2 is empty*/
        else
        {
            midElement = nums1[nums1Idx];
            nums1Idx++;
        }
        // printf("%d %d ",nums1Idx,nums2Idx);
        // printf("%d\n",midElement);
    }
    /*even*/
    if((nums1Size + nums2Size) % 2  == 0)
    {
        medianValue = (midElement + preMidElement) / 2.0;
    }
    /*odd*/
    else
    {
        medianValue = (double)midElement;
    }
    return medianValue;
}