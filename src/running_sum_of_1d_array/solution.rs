fn main() {

    println!("{:?}", Solution::running_sum(vec![1,2,3,4]));
    println!("{:?}", Solution::running_sum(vec![1,1,1,1,1]));
    println!("{:?}", Solution::running_sum(vec![3,1,2,10,1]));

}

struct Solution;

impl Solution {
    pub fn running_sum(nums: Vec<i32>) -> Vec<i32> {
        let mut v : Vec<i32> = vec![0; nums.len() + 1];
        for (index, val) in nums.iter().enumerate() {
            v[index + 1] = nums[index] + v[index]
        }
        v.remove(0);
        v
    }
}
