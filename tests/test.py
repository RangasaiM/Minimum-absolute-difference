from solutions.solution import Solution
import sys

def run_test_cases():
    solution_instance = solution.Solution()
    test_cases = [
        ([4,2,1,3], [[1,2],[2,3],[3,4]]),
        ([1,3,6,10,15], [[1,3]]),
        ([3,8,-10,23,19,-4,-14,27], [[-14,-10],[19,23],[23,27]])
    ]
    for i, (arr, expected) in enumerate(test_cases):
        result = solution_instance.minimumAbsDifference(arr)
        if result != expected:
            print(f"Test case {i+1} failed: Input {arr}, Expected {expected}, Got {result}")
            sys.exit(1)
    print("All test cases passed!")

if __name__ == "__main__":
    run_test_cases()