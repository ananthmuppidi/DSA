#include <bits/stdc++.h>
using namespace std;

#define md 1000000007
#define PB push_back

class Solution {
public:
    int maxArea(vector<int>& height) {
        int s = 0, e = height.size() - 1;
        int maxContent = 0;
        while(s < e){
            int content = (e - s) * min(height[s], height[e]);
            maxContent = max(maxContent, content);
            if(height[s] > height[e]) e--;
            else s++;
 
        }
        return maxContent;
    }
};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<int> arr = {1,8,6,2,5,4,8,3,7};
    cout << Solution().maxArea(arr) << endl;
}
