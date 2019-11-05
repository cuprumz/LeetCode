import java.util.*;

public class TwoSum {

    public static int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int reserve = target - nums[i];
            if (map.containsKey(reserve)) {
                int index = map.get(reserve);
                return i < index ?
                        new int[]{i, index}
                        : new int[]{index, i};
            } else {
                map.put(nums[i], i);
            }
        }
        return new int[]{-1, -1};
    }

    public static void main(String[] args) {
        int[] nums = {2, 7, 11, 15};
        int target = 9;

        int[] ret = twoSum(nums, target);

        System.out.println(ret[0]);
        System.out.println(ret[1]);
    }
}