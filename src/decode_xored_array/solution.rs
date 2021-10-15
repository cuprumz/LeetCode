fn main() {
    let v = vec![1,2,3];
    println!("encode: {:?}", v);
    println!("decode: {:?}", Solution::decode(v, 1));
}

struct Solution;

impl Solution {
    pub fn decode(encoded: Vec<i32>, first: i32) -> Vec<i32> {
        println!("first is {}", first);
        let mut res: Vec<i32> = Vec::new();
        res.push(first);
        for (count, val) in encoded.iter().enumerate() {
            // println!("{}:{}", count, val);
            res.push(*val^&res[count]);
        }
    
        res
    }
}
