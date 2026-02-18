#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Codec {
public:
    // 时间复杂度O(n)，空间复杂度O(n)
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string msg = "";
        int size = strs.size();
        for (string s : strs) {
            msg += (to_string(s.size()) + "#" + s);
        }
        return msg;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> strs;
        if (s.empty())
            return strs;
        int start = 0, size = s.size();
        while (start < size) {
            int pos = s.find("#", start);
            int len = stoi(s.substr(start, pos - start));
            strs.push_back(s.substr(pos+1, len));
            start = pos + len + 1;
        }
        
        return strs;
    }
};

void showOutput(vector<string> strs) {
    for (string s : strs)
        cout << s << " ";
    cout << endl;
}

int main() {
    Codec c;
    vector<string> strs = {"Hello","World"};
    string s = c.encode(strs);
    vector<string> output = c.decode(s);
    showOutput(output);
}