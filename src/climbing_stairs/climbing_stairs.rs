fn main() {
    for num in (1..46) {
        println!("n={}: There are {} ways to climb to the top.",num, Solution::climb_stairs(num));
    }
}

struct Solution;

impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        let (mut f0, mut f1, mut f2) = (1, 1, 0);

        for _ in (2..n+1) {
            f2 = f0 + f1;
            f0 = f1;
            f1 = f2;
        }

        f1
    }
}
