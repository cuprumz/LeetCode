fn main() {
    for i in (0..1001) {
        if (!Solution::is_same_after_reversals(i)) {
            println!("{}", i);
        }
    }
}

struct Solution;

impl Solution {
    pub fn is_same_after_reversals(num: i32) -> bool {
        if (0 == num) {
            return true;
        }
        !(num % 10 == 0)
    }
}
