#include <stdlib.h>
#include <limits.h>

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int **minimumAbsDifference(int *arr, int arrSize, int *returnSize, int **returnColumnSizes)
{
    qsort(arr, arrSize, sizeof(int), cmp);

    int diff = INT_MAX;
    int count = 0;
    for (int i = 0; i < arrSize - 1; i++)
    {
        int temp = arr[i + 1] - arr[i];
        if (temp < diff)
        {
            diff = temp;
            count = 1;
        }
        else if (temp == diff)
            count++;
    }

    int **ans = malloc(sizeof(int *) * count);
    *returnColumnSizes = malloc(sizeof(int *) * count);

    int x = 0;
    for (int i = 0; i < arrSize - 1; i++)
    {
        if (diff == arr[i + 1] - arr[i])
        {
            (*returnColumnSizes)[x] = 2;
            ans[x] = malloc(sizeof(int) * 2);
            ans[x][0] = arr[i];
            ans[x++][1] = arr[i + 1];
        }
    }
    *returnSize = count;
    return ans;
}