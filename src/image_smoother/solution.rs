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
        // println!("m={}, n={}", m, n);
        if m == n && m == 1 {
            return img;
        }

        let mut smooth = vec![vec![0; n]; m];
        let mut pad_img = vec![vec![0; n + 2]; m + 2];

        for (i, row) in img.iter().enumerate() {
            for (j, &v) in row.iter().enumerate() {
                pad_img[i + 1][j + 1] = v;
            }
        }
        // println!("pad_img {:?}", pad_img);

        
        for i in 0..m {
            for j in 0..n {
                //figure out the count
                let mut count = 0;

                if (i == 0 && j ==0)
                || (i == 0 && j == n - 1)
                || (i == m - 1 && j == 0)
                || (i == m - 1 && j == n - 1) {
                    if m == 1 || n == 1 {
                        count = 2;
                    } else {
                        count = 4;
                    }
                } else if (i == 0 && j != 0 && j != n - 1)
                || (i == m - 1 && j != 0 && j != n - 1)
                || (j == 0 && i != 0 && i != m - 1)
                || (j == n - 1 && i != 0 && i != m - 1) {
                    if m == 1 || n == 1{
                        count = 3;
                    } else {
                        count = 6;
                    }
                } else {
                    count = 9;
                }

                let mut total = 0;
                for k in i..i+3 {
                    for l in j..j+3 {
                        total = total + pad_img[k][l];
                    }
                }

                smooth[i][j] = total / count;
            }
        }
        
        smooth
    }
}
