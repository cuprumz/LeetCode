fn main() {
    let v = vec![2, 3, 1, 1, 4];

    println!("can jump: {}", Solution::can_jump(v));
}



struct Solution;

impl Solution {
    pub fn can_jump(nums: Vec<usize>) -> bool {
        let mut reach: usize = 0;
        let len: usize = nums.len();
        let mut index: usize = 0;
        while index < len && index <= reach {
            reach = if (index + nums[index]) > reach {
                index + nums[index]
            } else {
                reach
            };
            index += 1;
        }
        reach > len
    }
}