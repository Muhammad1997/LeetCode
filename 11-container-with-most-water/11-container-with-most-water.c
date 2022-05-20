int maxArea(int* height, int heightSize){
    int area = 0;
    int maxArea = 0;
    int minNum = 0;
    int leftIdx = 0, rightIdx = heightSize-1;
    while(rightIdx > leftIdx)
    {
        minNum = (height[leftIdx] >= height[rightIdx]) ? height[rightIdx] : height[leftIdx];
        area = minNum * (rightIdx - leftIdx);
        maxArea = (area > maxArea) ? area : maxArea;
        // printf("%d - %d : %d Vs. %d\n",height[leftIdx],height[rightIdx],area,maxArea);
        if(height[leftIdx] >= height[rightIdx])
        {
            rightIdx--;
        }
        else if(height[rightIdx] >= height[leftIdx])
        {
            leftIdx++;
        }
    }
    return maxArea;
}