#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **minimumAbsDifference(int *arr, int arrSize, int *returnSize, int **returnColumnSizes);

int comparePairs(const void *a, const void *b)
{
    const int *pa = *(const int **)a;
    const int *pb = *(const int **)b;
    if (pa[0] != pb[0])
        return pa[0] - pb[0];
    return pa[1] - pb[1];
}

int arraysEqual(int **a, int sizeA, int *colSizesA,
                int **b, int sizeB, int *colSizesB)
{
    if (sizeA != sizeB)
        return 0;
    for (int i = 0; i < sizeA; i++)
    {
        if (colSizesA[i] != colSizesB[i])
            return 0;
        for (int j = 0; j < colSizesA[i]; j++)
        {
            if (a[i][j] != b[i][j])
                return 0;
        }
    }
    return 1;
}

void printPairs(int **pairs, int size, int *colSizes)
{
    printf("[");
    for (int i = 0; i < size; i++)
    {
        if (i > 0)
            printf(", ");
        printf("[%d,%d]", pairs[i][0], pairs[i][1]);
    }
    printf("]");
}

int runTest(int *arr, int arrSize,
            int **expected, int expectedSize, int *expectedColSizes,
            int testNum)
{
    printf("\n=== Test Case %d ===\n", testNum);
    printf("Input array: [");
    for (int i = 0; i < arrSize; i++)
    {
        if (i > 0)
            printf(", ");
        printf("%d", arr[i]);
    }
    printf("]\n");

    int returnSize = 0;
    int *returnColumnSizes = NULL;

    int **result = minimumAbsDifference(arr, arrSize, &returnSize, &returnColumnSizes);

    printf("Expected output: ");
    printPairs(expected, expectedSize, expectedColSizes);
    printf("\nActual output:   ");
    printPairs(result, returnSize, returnColumnSizes);
    printf("\n");

    // Deep copy of expected to avoid sorting stack-allocated memory
    int **expectedCopy = malloc(expectedSize * sizeof(int *));
    for (int i = 0; i < expectedSize; i++)
    {
        expectedCopy[i] = malloc(expectedColSizes[i] * sizeof(int));
        memcpy(expectedCopy[i], expected[i], expectedColSizes[i] * sizeof(int));
    }

    qsort(expectedCopy, expectedSize, sizeof(int *), comparePairs);
    qsort(result, returnSize, sizeof(int *), comparePairs);

    int passed = arraysEqual(result, returnSize, returnColumnSizes,
                             expectedCopy, expectedSize, expectedColSizes);

    if (passed)
    {
        printf("Test %d PASSED ✅\n", testNum);
    }
    else
    {
        printf("Test %d FAILED ❌\n", testNum);
    }

    for (int i = 0; i < returnSize; i++)
        free(result[i]);
    free(result);
    free(returnColumnSizes);

    for (int i = 0; i < expectedSize; i++)
        free(expectedCopy[i]);
    free(expectedCopy);

    return passed ? 0 : 1;
}

int main()
{
    printf("Starting Minimum Absolute Difference Test Suite...\n");
    printf("==============================================\n");

    int totalTests = 0;
    int failedTests = 0;

    // Test case 1
    {
        int arr[] = {4, 2, 1, 3};
        int *expected[] = {(int[]){1, 2}, (int[]){2, 3}, (int[]){3, 4}};
        int expectedColSizes[] = {2, 2, 2};
        failedTests += runTest(arr, 4, expected, 3, expectedColSizes, ++totalTests);
    }

    // Test case 2
    {
        int arr[] = {1, 3, 6, 10, 15};
        int *expected[] = {(int[]){1, 3}};
        int expectedColSizes[] = {2};
        failedTests += runTest(arr, 5, expected, 1, expectedColSizes, ++totalTests);
    }

    // Test case 3
    {
        int arr[] = {3, 8, -10, 23, 19, -4, -14, 27};
        int *expected[] = {(int[]){-14, -10}, (int[]){19, 23}, (int[]){23, 27}};
        int expectedColSizes[] = {2, 2, 2};
        failedTests += runTest(arr, 8, expected, 3, expectedColSizes, ++totalTests);
    }

    // Test case 4: duplicates
    {
        int arr[] = {1, 1, 3, 4, 5};
        int *expected[] = {(int[]){1, 1}};
        int expectedColSizes[] = {2};
        failedTests += runTest(arr, 5, expected, 1, expectedColSizes, ++totalTests);
    }

    // Test case 6: single element repeated multiple times
    {
        int arr[] = {5, 5, 5, 5};
        int *expected[] = {(int[]){5, 5}, (int[]){5, 5}, (int[]){5, 5}};
        int expectedColSizes[] = {2, 2, 2};
        failedTests += runTest(arr, 4, expected, 3, expectedColSizes, ++totalTests);
    }

    // Test case 7: sorted array with equal gaps
    {
        int arr[] = {2, 4, 6, 8, 10};
        int *expected[] = {(int[]){2, 4}, (int[]){4, 6}, (int[]){6, 8}, (int[]){8, 10}};
        int expectedColSizes[] = {2, 2, 2, 2};
        failedTests += runTest(arr, 5, expected, 4, expectedColSizes, ++totalTests);
    }

    // Test case 8: array with only two elements
    {
        int arr[] = {10, 3};
        int *expected[] = {(int[]){3, 10}};
        int expectedColSizes[] = {2};
        failedTests += runTest(arr, 2, expected, 1, expectedColSizes, ++totalTests);
    }

    // Test case 10: negative large values
    {
        int arr[] = {-100, -50, 0, 50, 100};
        int *expected[] = {(int[]){-100, -50}, (int[]){-50, 0}, (int[]){0, 50}, (int[]){50, 100}};
        int expectedColSizes[] = {2, 2, 2, 2};
        failedTests += runTest(arr, 5, expected, 4, expectedColSizes, ++totalTests);
    }

    // Test case 11: array with all elements same
    {
        int arr[] = {7, 7, 7, 7, 7};
        int *expected[] = {(int[]){7, 7}, (int[]){7, 7}, (int[]){7, 7}, (int[]){7, 7}};
        int expectedColSizes[] = {2, 2, 2, 2};
        failedTests += runTest(arr, 5, expected, 4, expectedColSizes, ++totalTests);
    }

    // Test case 12: minimal difference is 0 with duplicates in the middle
    {
        int arr[] = {1, 2, 2, 3, 4};
        int *expected[] = {(int[]){2, 2}};
        int expectedColSizes[] = {2};
        failedTests += runTest(arr, 5, expected, 1, expectedColSizes, ++totalTests);
    }

    printf("\nTest Summary:\n");
    printf("=============\n");
    printf("Total tests: %d\n", totalTests);
    printf("Passed:      %d\n", totalTests - failedTests);
    printf("Failed:      %d\n", failedTests);

    if (failedTests == 0)
    {
        printf("\n✅ All tests passed successfully!\n");
    }
    else
    {
        printf("\n❌ Some tests failed!\n");
    }

    return failedTests > 0 ? 1 : 0;
}
