// #include <bits/stdc++.h>
// using namespace std;

// #define md 1000000007
// #define PB push_back

// class Solution {
// public:
//     int count = 0;
//     vector<vector<string>> partition(string s){
//             vector<vector<string>> ans;
//             helper(s, 0);
//             cout << count;
//             return ans;
//     }

//     void helper(string& s, int index, vector<string>& ansz`){
//         // recursive call, break the first string off and check the rest
//         if(index == s.size()){
//             ans.push_back("");
//         }
//         int end = index;
//         while(isPalindrome(s, index, end) && end < s.size()){

//             helper(s, end + 1, ans);
//             end++;
//         }
        
//     }

// bool isPalindrome(string& s, int start, int end){
//     while(start < end){
//         if(s[start] != s[end]){
//             return false;
//         }
//         start++;
//         end--;
//     }
//     return true;
// }
// };

// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     Solution().partition("AA");

// }

