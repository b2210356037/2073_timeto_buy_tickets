#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int res = 0;
        for (int i = 0; i < k; i++) {
            res += min(tickets[i], tickets[k]);
        }
        for (int i = k + 1; i < tickets.size(); i++) {
            res += min(tickets[i], tickets[k] - 1);
            //-1 because we want to return exact moment k is 0, if we dont add -1,
            //it will simulate as if we keep going even the kth element is 0
        }
        res += tickets[k];
        return res;
    }
};


int main() {
    Solution s;
    vector<int> v{84,49,5,24,70,77,87,8};
    int k = 3;
    cout << s.timeRequiredToBuy(v, k);
    return 0;
}
