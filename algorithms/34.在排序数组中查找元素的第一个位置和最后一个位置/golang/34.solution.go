package main

import "fmt"

// 最坏时间复杂度O(n)
/*
func searchRange(nums []int, target int) []int {
	left, right := 0, len(nums)-1
	ans1, ans2 := -1, -1
	for left <= right {
		mid := left + (right-left)/2
		if nums[mid] == target {
			ans1 = mid
			for mid >= left && nums[mid] == target {
				ans1 = mid
				mid--
			}
			break
		} else if nums[mid] < target {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}

	for left <= right {
		mid := left + (right-left)/2
		if nums[mid] == target {
			ans2 = mid
			for mid <= right && nums[mid] == target {
				ans2 = mid
				mid++
			}
			break
		} else if nums[mid] < target {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}
	return []int{ans1, ans2}
}
*/

func searchRange(nums []int, target int) []int {
	left := binarySearch(nums, target, true)
	right := binarySearch(nums, target, false) - 1
	if left <= right && right < len(nums) && nums[left] == target && nums[right] == target {
		return []int{left, right}
	}
	return []int{-1, -1}
}

func binarySearch(nums []int, target int, flag bool) int {
	left, right := 0, len(nums)-1
	ans := len(nums)
	for left <= right {
		mid := left + (right-left)/2
		if (nums[mid] > target) || (flag && nums[mid] >= target) {
			ans = mid
			right = mid - 1
		} else {
			left = mid + 1
		}
	}
	return ans
}

func main() {

	nums := []int{5, 7, 7, 8, 8, 10}
	target := 8
	/*
		nums := []int{}
		target := 0
	*/
	ans := searchRange(nums, target)
	fmt.Println(ans)
}
