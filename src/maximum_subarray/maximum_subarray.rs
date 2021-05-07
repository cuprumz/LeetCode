fn main() {
    let v = vec![-2, 1, -3, 4, -1, 2, 1, -5, 4, 5];
    println!("sum of max sub array is {}.", Solution::max_sub_array(v))
}

struct Solution;

impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let mut ans = nums[0];
        let mut sum = nums[0];
        for num in nums.iter() {
            sum = max(sum + num, *num);
            if sum > ans {
                ans = sum;
            }
        }

        ans
    }
}

fn max(a: i32, b: i32) -> i32 {
    if a > b {
        return a;
    }
    b
}
