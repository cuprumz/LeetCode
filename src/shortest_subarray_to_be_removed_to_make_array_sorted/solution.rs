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
        let n = arr.len();
        let mut j = n - 1;
        let mut ans;
        while j > 0 && arr[j] >= arr[j - 1] {
            j -= 1;
        }
        if j == 0 {
            return 0;
        } else {
            ans = j;
            for i in 0..n {
                if i > 0 && arr[i - 1] > arr[i] {
                    break;
                } else {}
                while j < n && arr[i] > arr[j] {
                    j += 1;
                }
                ans = if ans < j - i -1 {
                    ans
                } else {
                    j - i -1
                }
            }
        }

        ans as i32
    }
}
