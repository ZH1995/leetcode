#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 时间复杂度O(n),空间复杂度O(1)
    int maxArea(vector<int>& height) {
        int size = height.size(), result = 0;
        if (size <= 0) return result;
        int left = 0, right = size - 1;
        while (left < right) {
            int minHeight = min(height[left], height[right]);
            result = max(result, minHeight * (right - left));
            if (height[left] < height[right]) left ++;
            else right --;
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << s.maxArea(height) << endl;
}