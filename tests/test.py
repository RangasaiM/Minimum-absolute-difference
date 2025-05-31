import sys
import os
from typing import List

# Add root folder to Python path for importing solutions
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

from solutions.solution import Solution


def run_test(arr: List[int], expected: List[List[int]], test_num: int):
    sol = Solution()
    result = sol.minimumAbsDifference(arr)

    # Normalize for comparison (sort outer list and inner lists)
    result_sorted = sorted([sorted(pair) for pair in result])
    expected_sorted = sorted([sorted(pair) for pair in expected])

    print(f"Test Case {test_num}:")
    if result_sorted == expected_sorted:
        print(f"  PASSED [Ok] (Output: {result})")
        return False
    else:
        print(f"  FAILED [X]")
        print(f"    Input:    {arr}")
        print(f"    Expected: {expected_sorted}")
        print(f"    Got:      {result_sorted}")
        return True


if __name__ == "__main__":
    test_cases = [
        # Format: (arr, expected_output)
        ([4, 2, 1, 3], [[1, 2], [2, 3], [3, 4]]),
        ([1, 3, 6, 10, 15], [[1, 3]]),
        ([3, 8, -10, 23, 19, -4, -14, 27], [[-14, -10], [19, 23], [23, 27]]),
        ([1, 2], [[1, 2]]),
        ([1, 1000000], [[1, 1000000]]),
        ([-10, -5, 0, 5, 10], [[-10, -5], [-5, 0], [0, 5], [5, 10]]),
        ([10, 9, 8, 7, 6, 5], [[5, 6], [6, 7], [7, 8], [8, 9], [9, 10]]),
        ([1, 3, 5, 7], [[1, 3], [3, 5], [5, 7]]),
        ([-100000, 0, 100000], [[-100000, 0], [0, 100000]]),
        ([1, 1, 1, 1], [[1, 1], [1, 1], [1, 1]]),
    ]

    failed_any = False
    for i, (arr, expected) in enumerate(test_cases, 1):
        if run_test(arr, expected, i):
            failed_any = True

    if failed_any:
        print("\n[FAIL] Some test cases failed.")
        sys.exit(1)
    else:
        print("\n[OK] All test cases passed.")
        sys.exit(0)
