#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    // 解法一：时间复杂度O(nlogn)，空间复杂度O(n)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (int x : nums) {
            hash[x] ++;
        }
        vector<pair<int, int>> vp;
        for (auto it : hash) {
            vp.push_back(pair<int, int> (it.first, it.second));
        }
        sort(vp.begin(), vp.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            return a.second > b.second;
        });
        vector<int> ret;
        int size = vp.size();
        for (int i = 0; i < k; i ++)
            ret.push_back(vp[i].first);
        return ret;
    }

    /* 解法二：时间复杂度O(nlogk)，空间复杂度O(n)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (int x : nums) {
            hash[x] ++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto& [num, freq] : hash) {
            pq.push({freq, num});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> ret;
        while (!pq.empty()) {
            ret.push_back(pq.top().second);
            pq.pop();
        }
        return ret;
    }
    */
};

void showVector(vector<int>& nums) {
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    Solution s;
    vector<int> output = s.topKFrequent(nums, k);
    showVector(output);
}