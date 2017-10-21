#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
    public:
        vector<string> findRepeatedDnaSequences(string s) {
            unordered_map<string, unsigned> subSeqs;
            vector<string> repSubSeqs;
            unsigned maxSubSeqStartPos = s.length() >= 10 ? s.length()-10 : 0;
            for (unsigned i = 0; i <= maxSubSeqStartPos; i++) {
                string subSeq = s.substr(i, 10);
                ++subSeqs[subSeq];
                if (subSeqs[subSeq] == 2) {
                    repSubSeqs.push_back(subSeq);
                };
            }
            return repSubSeqs;
        }
};

int main() {
    Solution sol;
    //vector<string> repSeqs = sol.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    //vector<string> repSeqs = sol.findRepeatedDnaSequences("AAAAAAAAAAA");
    //vector<string> repSeqs = sol.findRepeatedDnaSequences("");
    vector<string> repSeqs = sol.findRepeatedDnaSequences("AAAAAAAAAAAA");
    for (auto seq:repSeqs) {
        cout << seq << endl;
    }
    return 0;
}

