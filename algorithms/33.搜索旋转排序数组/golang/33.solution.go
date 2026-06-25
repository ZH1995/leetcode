package main

import "fmt"

// 时间复杂度O(n)
/*
func search(nums []int, target int) int {
	sliceLen := len(nums)
	firstIdx := len(nums)
	for i := range nums {
		if i+1 < sliceLen && nums[i+1] < nums[i] {
			firstIdx = i + 1
			break
		}
	}
	leftIdx := binarySearch(nums, target, 0, firstIdx-1)
	if leftIdx == -1 {
		return binarySearch(nums, target, firstIdx, len(nums)-1)
	} else {
		return leftIdx
	}
}

func binarySearch(nums []int, target, left, right int) int {
	ans := -1
	for left <= right {
		mid := left + (right-left)/2
		if nums[mid] == target {
			return mid
		} else if nums[mid] < target {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}
	return ans
}
*/

func search(nums []int, target int) int {
	left, right := 0, len(nums)-1
	for left <= right {
		mid := left + (right-left)/2
		if nums[mid] == target {
			return mid
		}
		if nums[left] <= nums[mid] {
			if nums[left] <= target && target < nums[mid] {
				right = mid - 1
			} else {
				left = mid + 1
			}
		} else {
			if nums[mid] < target && target <= nums[right] {
				left = mid + 1
			} else {
				right = mid - 1
			}
		}
	}
	return -1
}

func main() {

	nums := []int{4, 5, 6, 7, 0, 1, 2}
	target := 0

	/*
		nums := []int{1, 3}
		target := 0
	*/
	ans := search(nums, target)
	fmt.Println(ans)
}
