#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

/*

思路：如果n不是快乐数，那么在变化过程中，一定会出现重复，反之是快乐数。

*/
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        s.insert(n);
        while (n != 1) {
            int temp = n, sum = 0;
            while (temp > 0) {
                sum += ((temp % 10) * (temp % 10));
                temp /= 10; 
            }
            if (s.count(sum)) return false;
            s.insert(sum);
            n = sum;
        }
        return true;
    }
};
int main() {
    /*
        1 f
        2 -> 4 -> 16 -> 37 -> 9+49=58 -> 25+64=89 -> 64+81=145 -> 1+16+25=17+25=42 -> 16+4=20 -> 4f
        3 -> 9 -> 81 -> 65 -> 36+25=71 -> 50 -> 25 -> 9 f
        4 -> 16 -> 
    */
    int n = 19;
    //int n = 2;
    Solution sol;
    bool ans = sol.isHappy(n); 
    cout << ans << endl; 
    return 0; 
}