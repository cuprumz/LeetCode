fn main() {
    let v = vec![7, 1, 5, 3, 6, 4];
    println!("output: {}.", Solution::max_profit(v));
    let v = vec![7, 6, 4, 3, 1];
    println!("output: {}.", Solution::max_profit(v));
}

struct Solution;

impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut min = i32::MAX;
        let mut profit = 0;

        for num in prices.iter() {
            if *num < min {
                min = *num;
            } else if (*num - min) > profit {
                profit = *num - min;
            }
        }

        profit
    }
}
