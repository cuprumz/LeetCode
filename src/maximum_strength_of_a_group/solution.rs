fn main() {
    println!("{}", Solution::max_strength(vec![1,2,3]));
    println!("{}", Solution::max_strength(vec![0,-1]));
    println!("{}", Solution::max_strength(vec![0,-1, 1]));
    println!("{}", Solution::max_strength(vec![0,0]));
    println!("{}", Solution::max_strength(vec![-4,-5,-4]));
    println!("{}", Solution::max_strength(vec![-4,-5,4,5]));
    println!("{}", Solution::max_strength(vec![3,-1,-5,2,5,-9]));
    println!("{}", Solution::max_strength(vec![0,3,-1,-5,2,5,-9]));
    println!("{}", Solution::max_strength(vec![6,-3,-4,8,4,7,6,4,7,7,-3,-6,9]));
}

struct Solution {}

impl Solution {
    pub fn max_strength(nums: Vec<i32>) -> i64 {
        println!("{:?}", nums);

        let mut cnt0 = 0;
        let mut cntN = 0;
        let mut sum: Option<i64> = None;
        let mut min = None;

        for num in &nums {
            if *num == 0 {
                cnt0 += 1;
                continue;
            }

            if *num<0 {
                cntN+=1;
                if min.is_none()||*num>min.unwrap() {
                    min = Some(*num);
                }
            }

            match sum {
                Some(val) => sum = Some(val**num as i64),
                None => sum = Some(*num as i64),
            }
        }

        println!("min: {:?}", min);

        if sum.is_some() && sum.unwrap() < 0 && min.is_some() 
          && !(cnt0+cntN==nums.len() && cntN==1){
            match sum {
                Some(val) => {
                    if val/min.unwrap() as i64 > val {
                        sum = Some(val/min.unwrap() as i64)
                    }
                },
                None => {}
            }
        }

        if sum.is_some() && sum.unwrap() < 0 && cnt0>0 {
            sum=Some(0);
        }


        sum.unwrap_or(0) as i64
    }
}
