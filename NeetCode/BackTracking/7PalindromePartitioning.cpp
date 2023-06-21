#include <bits/stdc++.h>
using namespace std;

#define md 1000000007
#define PB push_back

bool helper(string s, int index){
    int start = index; 
    int end = 0;


}

bool isPalindrome(string s, int start, int end){
    while(start < end){
        cout << s[start] << " " << s[end] << endl;
        if(s[start] != s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

}

