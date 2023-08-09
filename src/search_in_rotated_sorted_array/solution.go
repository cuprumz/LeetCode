package main

import "fmt"

func main() {
	nums := []int{4, 5, 6, 7, 0, 1, 2}

	fmt.Println(nums)
	for i := 0; i < 9; i++ {
		fmt.Println(i, " in ", search(nums, i))
	}
}

func search(nums []int, target int) int {
    left, right:=0, len(nums)-1

    for left <= right {
        pivot := (left+right)/2
        if nums[pivot]==target {
            return pivot
        }
        if (right-left<3){
            if nums[left]==target {
                return left
            }
            if nums[right]==target {
                return right
            }
        }
        
        if nums[left]<nums[pivot] {
            if nums[left]<=target&&target<=nums[pivot] {
                right=pivot-1
            } else {
                left=pivot+1
            }
        } else {
            if nums[pivot]<=target&&target<=nums[right] {
                left=pivot+1
            } else {
                right=pivot-1
            }
        }

    }
                
	return -1
}
