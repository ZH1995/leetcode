package main

import "fmt"

// 暴力遍历居然也能过！！！
/*
func searchMatrix(matrix [][]int, target int) bool {
	row := len(matrix)
	col := len(matrix[0])
	for i := range row {
		if matrix[i][0] > target {
			return false
		}
		for j := range col {
			if matrix[i][j] <= target && matrix[i][j] == target {
				return true
			}
		}
	}
	return false
}
*/

func searchMatrix(matrix [][]int, target int) bool {
	row, col := len(matrix), len(matrix[0])
	left, right := 0, row*col-1
	for left <= right {
		mid := left + (right-left)/2
		if matrix[mid/col][mid%col] == target {
			return true
		} else if matrix[mid/col][mid%col] < target {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}
	return false
}

func main() {
	/*
		matrix := [][]int{
			{1, 3, 5, 7},
			{10, 11, 16, 20},
			{23, 30, 34, 60},
		}
		target := 13
	*/

	matrix := [][]int{
		{1, 1},
	}
	target := 2
	ans := searchMatrix(matrix, target)
	fmt.Println(ans)
}
