fn main() {
    let arr = vec![1,2,3,10,4,2,3,5];
    print_res(arr);

    let arr = vec![5,4,3,2,1];
    print_res(arr);

    let arr = vec![4,5,4,3,2,1];
    print_res(arr);

    let arr = vec![5,4,6,2,1];
    print_res(arr);

    let arr = vec![4,5,4,6,2,1];
    print_res(arr);

    let arr = vec![1,2,3];
    print_res(arr);

    let arr = vec![1,2,3,2];
    print_res(arr);

    let arr = vec![3,2,1,6];
    print_res(arr);

    let arr = vec![2,2,2,1,1,1];
    print_res(arr);
}

fn print_res(res: Vec<i32>) {
    println!("Input: arr = {:?}", res);
    println!("Output: {}", Solution::find_length_of_shortest_subarray(res));
}

struct Solution;

impl Solution {
    pub fn find_length_of_shortest_subarray(arr: Vec<i32>) -> i32 {
        let (mut left, mut right) = (0, arr.len() - 1);
        let (start, end) = (0, arr.len() - 1);

        for i in 1..arr.len() {
            if arr[i] < arr[i - 1] {
                left = i - 1;
                break;
            }
            left = end;
        }

        for j in (0..arr.len() - 1).rev() {
            if arr[j] > arr[j + 1] {
                right = j + 1;
                break;
            }
            right = start;
        }

        println!("left: {}, right: {}", left, right);

        if left == start && right == end {
            return end as i32;
        } else if left == end && right == start {
            return start as i32;
        } else if right == end {
            return (right - left) as i32;
        } else if left == start {
            return right as i32;
        } else {
            let mut m_left = left;
            while arr[right] < arr[m_left] && m_left > start {
                m_left = m_left - 1;
            }

            let mut m_right = right;
            while arr[left] > arr[m_right] && m_right < end {
                m_right = m_right + 1;
            }

            let ans1 = (right - m_left) as i32;
            let ans2 = (m_right - left) as i32;
            println!("ans1: {}, ans2: {}", ans1, ans2);
            println!("m_left: {}, m_right: {}", m_left, m_right);

            if ans1 < ans2 {
                ans1
            } else {
                ans2
            }
        }
    }
}
