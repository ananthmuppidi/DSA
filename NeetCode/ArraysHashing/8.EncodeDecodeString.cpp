#include <bits/stdc++.h>
using namespace std;

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded = "";
        for(auto str : strs){
            int size = str.size();
            string temp = to_string(size) + "#" + str;
            encoded.append(temp);
        }

        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        int size = s.size();
        int i = 0;
        while(i < size - 1){
            int tempSize = 0;
            string tempSizeStr = "";
            while(s[i] != '#'){
                tempSizeStr.append(string(1,s[i]));
                i++;
            }
            i++;
            tempSize = stoi(tempSizeStr);
            string tempString = "";
            for(int j = i; j < i +  tempSize; j++){
                tempString.append(string(1, s[j]));
            }
            i += tempSize;
            ans.push_back(tempString);
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));


int main(){
    Codec coder;
    vector<string> inp = {"Neet", "Code"};
    string encoded = coder.encode(inp);

    vector<string> out = coder.decode(encoded);
    for(auto i : out){
        cout <<  i << " ";
    }
    cout << endl;
    return 0;
}