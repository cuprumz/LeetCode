fn main() {
    let a = b"AGGTAB";
    let b = b"GXTXAYB";

    let (length, subsequence) = Solution::longest_common_subsequence(a, b);

    println!("Length of LCS: {}", length);
    println!("a LCS: {:?}", subsequence);

    let subsequence: String = subsequence.iter().map(|&byte| byte as char).collect();
    println!("a LCS: {:?}", subsequence);
}

struct Solution;

impl Solution {
    pub fn longest_common_subsequence(a: &[u8], b: &[u8]) -> (usize, Vec<u8>) {
        let m = a.len();
        let n = b.len();

        let mut matrix = vec![vec![0; n + 1]; m + 1];

        for i in 1..=m {
            for j in 1..=n {
                if a[i - 1] == b[j - 1] {
                    matrix[i][j] = matrix[i - 1][j - 1] + 1;
                } else {
                    matrix[i][j] = matrix[i - 1][j].max(matrix[i][j - 1]);
                }
            }
        }
        
        for row in &matrix {
            for &ele in row {
                print!("{} ", ele);
            }
            println!();
        }

        let length = matrix[m][n];
        let mut subsequence = Vec::with_capacity(length);

        let mut i = m;
        let mut j = n;

        while i > 0 && j > 0 {
            if a[i - 1] == b[j - 1] {
                subsequence.push(a[i - 1]);
                i -= 1;
                j -= 1;
            } else if matrix[i - 1][j] > matrix[i][j - 1] {
                i -= 1;
            } else {
                j -= 1;
            }
        }

        subsequence.reverse();

        (matrix[m][n], subsequence)
    }
}
