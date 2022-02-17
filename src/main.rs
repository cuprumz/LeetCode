fn main() {
    let matrix1 = vec![vec![1]];
    println!("before smoother {:?}", matrix1);
    println!("after  smoother {:?}", Solution::image_smoother(matrix1));

    let matrix1 = vec![vec![1, 2, 3]];
    println!("before smoother {:?}", matrix1);
    println!("after  smoother {:?}", Solution::image_smoother(matrix1));

    let matrix1 = vec![vec![1], vec![2], vec![3]];
    println!("before smoother {:?}", matrix1);
    println!("after  smoother {:?}", Solution::image_smoother(matrix1));

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
        let (m, n) = (img.len(), img[0].len());
        println!("m={}, n={}", m, n);
        if m == n && m == 1 {
            return img;
        }
        img
    }
}
