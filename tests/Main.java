package tests;

import solutions.Solution;
import java.util.*;

public class Main {
    private static boolean anyTestFailed = false;

    private static void runTest(int[] input, List<List<Integer>> expected, int testNum) {
        Solution sol = new Solution();
        List<List<Integer>> result = sol.minimumAbsDifference(input);

        Collections.sort(result, (a, b) -> a.get(0) - b.get(0));
        Collections.sort(expected, (a, b) -> a.get(0) - b.get(0));

        boolean passed = result.equals(expected);

        System.out.println("Test Case " + testNum + ": " + (passed ? "PASSED ✅" : "FAILED ❌"));

        if (!passed) {
            System.out.println("  Input: " + Arrays.toString(input));
            System.out.println("  Expected: " + expected);
            System.out.println("  Output:   " + result);
            anyTestFailed = true;
        }
    }

    public static void main(String[] args) {
        List<Object[]> testCases = new ArrayList<>();

        testCases.add(new Object[] { new int[] { 4, 2, 1, 3 },
                Arrays.asList(Arrays.asList(1, 2), Arrays.asList(2, 3), Arrays.asList(3, 4)) });
        testCases.add(new Object[] { new int[] { 1, 3, 6, 10, 15 }, Arrays.asList(Arrays.asList(1, 3)) });
        testCases.add(new Object[] { new int[] { 3, 8, -10, 23, 19, -4, -14, 27 },
                Arrays.asList(Arrays.asList(-14, -10), Arrays.asList(19, 23), Arrays.asList(23, 27)) });
        testCases.add(new Object[] { new int[] { 1, 2 }, Arrays.asList(Arrays.asList(1, 2)) });
        testCases.add(new Object[] { new int[] { 1, 1000000 }, Arrays.asList(Arrays.asList(1, 1000000)) });
        testCases.add(new Object[] { new int[] { -10, -5, 0, 5, 10 }, Arrays.asList(Arrays.asList(-10, -5),
                Arrays.asList(-5, 0), Arrays.asList(0, 5), Arrays.asList(5, 10)) });
        testCases.add(new Object[] { new int[] { 10, 9, 8, 7, 6, 5 }, Arrays.asList(Arrays.asList(5, 6),
                Arrays.asList(6, 7), Arrays.asList(7, 8), Arrays.asList(8, 9), Arrays.asList(9, 10)) });
        testCases.add(new Object[] { new int[] { 1, 3, 5, 7 },
                Arrays.asList(Arrays.asList(1, 3), Arrays.asList(3, 5), Arrays.asList(5, 7)) });
        testCases.add(new Object[] { new int[] { -100000, 0, 100000 },
                Arrays.asList(Arrays.asList(-100000, 0), Arrays.asList(0, 100000)) });
        testCases.add(new Object[] { new int[] { 1, 1, 1, 1 },
                Arrays.asList(Arrays.asList(1, 1), Arrays.asList(1, 1), Arrays.asList(1, 1)) });

        for (int i = 0; i < testCases.size(); i++) {
            int[] input = (int[]) testCases.get(i)[0];
            @SuppressWarnings("unchecked")
            List<List<Integer>> expected = (List<List<Integer>>) testCases.get(i)[1];
            runTest(input, expected, i + 1);
        }

        if (anyTestFailed) {
            System.out.println("\n❌ Some test cases failed.");
            System.exit(1);
        } else {
            System.out.println("\n✅ All test cases passed.");
            System.exit(0);
        }
    }
}
