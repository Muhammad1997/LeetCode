#include <stdlib.h>
/**
 * @brief API used to return the number of possible unique paths that the robot can take to reach the bottom-right corner
 * @details 
 *          -1- iterate obstacleGrid
 *          -2- check current node not to be an obstacle
 *          -3- initialize first two nodes arr[0][1] and arr[1][0]
 *          -4- put the sum of up and left nodes paths into current node (if up or left nodes are obstacle or out of range assume to be 0)
 *          -5- return the grid[m-1][n-1] number(number of valid paths) 
 * @param obstacleGrid          pointer to 2D array of obstacles
 * @param obstacleGridSize      number of array rows
 * @param obstacleGridColSize   number of array columns 
 * @return int                  number of possible unique paths 
 */
int uniquePathsWithObstacles(int ** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    int row,col;
    int upNodeNumOfPaths = 0,leftNodeNumOfPaths = 0;
    int retNumOfPaths;
    const int numOfRows = obstacleGridSize,numOfCol = *obstacleGridColSize;
    int * numOfPathsArray = (int *) malloc(sizeof(int) * numOfRows * numOfCol);
    /*iterate obstacleGrid*/
    for(row = 0;row < numOfRows;row++)
    {
        for(col = 0;col < numOfCol;col++)
        {
            /*check current node not to be an obstacle*/
            if(obstacleGrid[row][col] != 1)
            {
                /*initialize arr[0][0] node*/
                if((row == 0) && (col == 0))
                {
                    numOfPathsArray [row * numOfCol + col]  = 1;
                }
                else
                {
                    /*check up node to be a valid path*/
                    if((row-1 >= 0) && (obstacleGrid[row-1][col] != 1))
                    {
                        upNodeNumOfPaths = numOfPathsArray [(row-1) * numOfCol + col];
                    }
                    else
                    {
                        upNodeNumOfPaths = 0;
                    }
                    /*check left node to be a valid path*/
                    if((col-1 >= 0) && (obstacleGrid[row][col-1] != 1))
                    {
                        leftNodeNumOfPaths = numOfPathsArray [row * numOfCol + (col-1)];
                    }
                    else
                    {
                        leftNodeNumOfPaths = 0;
                    }
                    /*put the sum of up and left nodes paths into current node (if up or left nodes are obstacle or out of range assume to be 0)*/
                    numOfPathsArray [row * numOfCol + col] = upNodeNumOfPaths + leftNodeNumOfPaths;
                }
            }
            else
            {
                /*do nothing current node is an obstacle*/
                numOfPathsArray [row * numOfCol + col] = 0;
            }
        }
    }
    retNumOfPaths = numOfPathsArray [numOfRows * numOfCol - 1];
    free(numOfPathsArray);
    return retNumOfPaths;
}