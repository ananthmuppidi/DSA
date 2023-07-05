#include <bits/stdc++.h>
using namespace std;

#define md 1000000007
#define PB push_back

class Solution {
public:
    vector<string> generateParenthesis(int n) {

        vector<string> ans;
        deque<string> dq;

        
        if(n == 1) {
            ans.push_back("()");
            return ans;
        }
        dq.push_back("()");

        int currentSize = 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < currentSize; j++){
                if(j == 0){
                    string popped = dq.front();
                    dq.pop_front();
                    dq.push_back("()" + popped);
                    dq.push_back("(" + popped + ")");
                } else {
                    string popped = dq.front();
                    dq.pop_front();
                    dq.push_back("()" + popped);
                    dq.push_back("(" + popped + ")");
                    dq.push_back(popped + "()");
                }
            }
            currentSize = dq.size();
        }

        for(auto i : dq){
            ans.push_back(i);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    auto ans = Solution().generateParenthesis(3);
    sort(ans.begin(), ans.end());
    for(auto &i : ans){
        cout << i << " ";
    }
    cout << endl;
    
}
