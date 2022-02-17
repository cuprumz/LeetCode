fn main() {
    println!("{}", 3.14 as i32);

    let matrix1 = vec![vec![1,2,3], vec![4,5,6], vec![7,8,9]];
    println!("before smoother {:?}", matrix1);
    println!("after  smoother {:?}", Solution::image_smoother(matrix1));

    let matrix1 = vec![vec![1,1,1], vec![1,0,1], vec![1,1,1]];
    println!("before smoother {:?}", matrix1);
    println!("after  smoother {:?}", Solution::image_smoother(matrix1));

    let matrix1 = vec![vec![100,200,100], vec![200,50,200], vec![100,200,100]];
    println!("before smoother {:?}", matrix1);
    println!("after  smoother {:?}", Solution::image_smoother(matrix1));
}

struct Solution;

impl Solution {
    pub fn image_smoother(img: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let m = img.len();
        let n = img[0].len();
        let mut res = vec![vec![0; n]; m];
        for (i, row) in img.iter().enumerate() {
            for (j, _) in row.iter().enumerate() {
                if (i == 0 && j == 0) {
                    res[i][j] = ((img[i][j] + img[i][j+1] + img[i+1][j] + img[i+1][j+1]) as f64 / 4.0) as i32;
                }
                else if (i == 0 && j == n - 1) {
                    res[i][j] = ((img[i][j] + img[i][j-1] + img[i+1][j] + img[i+1][j-1]) as f64 / 4.0) as i32;
                }
                else if (i == m - 1 && j == 0) {
                    res[i][j] = ((img[i][j] +img[i][j+1] +img[i-1][j] +img[i-1][j+1]) as f64 / 4.0) as i32;
                }
                else if  (i == m - 1 && j == n - 1) {
                    res[i][j] = ((img[i][j] + img[i][j-1] + img[i-1][j] + img[i-1][j-1]) as f64 / 4.0) as i32;
                } else if (i == 0 && (j != 0 && j != n - 1)) {
                    res[i][j] = ((img[i][j] + img[i][j-1] + img[i][j+1] + img[i+1][j] + img[i+1][j-1] + img[i+1][j+1]) as f64 / 6.0) as i32;
                }
                else if (i == m - 1 && (j != 0 && j != n - 1)) {
                    res[i][j] = ((img[i][j] + img[i][j-1] + img[i][j+1] + img[i-1][j] + img[i-1][j-1] + img[i-1][j+1]) as f64 / 6.0) as i32;
                }
                else if  (j == 0 && (i != 0 && i != m - 1)) {
                    res[i][j] = ((img[i][j] + img[i][j+1] + img[i-1][j] + img[i-1][j+1] + img[i+1][j] + img[i+1][j+1]) as f64 / 6.0) as i32;
                }
                else if (j == n - 1 && (i != 0 && i != m - 1)) {
                    res[i][j] = ((img[i][j] + img[i][j-1] + img[i+1][j] + img[i+1][j-1] + img[i-1][j] + img[i-1][j-1]) as f64 / 6.0) as i32;
                } else {
                    res[i][j] = ((img[i][j] + img[i][j-1] + img[i][j+1] + img[i-1][j] + img[i-1][j-1] + img[i-1][j+1] + img[i+1][j] + img[i+1][j-1] + img[i+1][j+1]) as f64 / 9.0) as i32;
                }
            }
        }
        res
    }
}
