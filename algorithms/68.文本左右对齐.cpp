#include <iostream>
#include <vector>
using namespace std;

/*

思路：1.用left和right进行分组，确定每一行单词范围。每次从left开始，尽量多放单词，
     直到加下一个单词会超出maxWidth（注意计算的时候把每个单词间至少1个空格加上）。
     2.处理一行时，如果是最后一行或者这一行只有一个单词，则单词之间只用一个空格，末尾补空格到maxWidth。
     否则（中间行），要把空格尽量均匀分配到单词之间，左边多余。
*/
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> ans;
        int left = 0, right, lineLen;
        while (left < n) {
            right = left;
            lineLen = 0;
            string line = "";
            while (right < n && lineLen + words[right].size() + right - left <= maxWidth) {
                lineLen += words[right].size();
                right ++;
            }
            if (right == n || right - left == 1) {
                line = words[left];
                for (int i = left + 1; i < right; i ++)
                    line += " " + words[i];
                line += string(maxWidth - line.size(), ' ');
            } else {
                int totalSpaces = maxWidth - lineLen;//需要插入的空格总数
                int slots = right - left - 1;//单词之间所需的空隙数
                int avgSpace = totalSpaces / slots;//每个空隙至少分配多少个空格
                int extra = totalSpaces % slots;//计算多出来的空格数（从左往右分配）
                for (int i = left; i < right; i ++) {
                    line += words[i];
                    if (i < right - 1) {
                        int spaces = avgSpace + (i - left < extra ? 1 : 0);
                        line += string(spaces, ' ');
                    }
                }
            }
            ans.push_back(line);
            left = right;
        }
        return ans;
    }
};

int main() {
    vector<string> words = {
        "This", "is", "an", "example", "of", "text", "justification."
    };
    int maxWidth = 16;
    Solution sol;
    vector<string> ans = sol.fullJustify(words, maxWidth);
    for (auto item: ans) cout << item << endl;
    return 0; 
}