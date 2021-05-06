fn main() {
    let v = vec![2, 2, 1];
    println!("single number is {}.", Solution::single_number(v));
    let v = vec![4, 1, 2, 1, 2];
    println!("single number is {}.", Solution::single_number(v));
}

struct Solution;

impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        let mut res = 0;
        for num in nums.iter() {
            print!("{}, ", num);
            res ^= num;
        }
        res
    }
}
