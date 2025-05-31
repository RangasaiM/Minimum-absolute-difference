package tests;
import java.util.*;
import solutions.Solution;

public class Main {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] arr = {4,2,1,3};
        List<List<Integer>> res = s.minimumAbsDifference(arr);
        for (List<Integer> pair : res) {
            System.out.println(pair);
        }
    }
}
