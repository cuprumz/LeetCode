package main

import "fmt"

func main() {
    nums := []int{3,-1,-5,2,5,-9}
    fmt.Println(maxStrength(nums))

    fmt.Println(maxStrength([]int{-4,5,-4}))
    
    fmt.Println(maxStrength([]int{-4,-5,-4}))
    
    fmt.Println(maxStrength([]int{0,-1}))
    fmt.Println(maxStrength([]int{-1,-1}))

    fmt.Println(maxStrength([]int{0}))

    fmt.Println(maxStrength([]int{-9}))

}

func maxStrength(nums []int) int64 {
}
