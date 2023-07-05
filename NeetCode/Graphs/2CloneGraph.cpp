#include <bits/stdc++.h>
using namespace std;

#define md 1000000007
#define PB push_back

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    void dfs(Node* node, vector<bool>& vis, vector<Node*>& lookup){
        if(vis[node->val]) return;
        vis[node->val] = true;

        // copy logic

        Node* curr; 
        if(lookup[node->val] != NULL) curr = lookup[node->val];
        else {
            curr = new Node(node->val);
            lookup[curr->val] = curr;
        }
        vector<Node*> currList;
        for(auto &i : node->neighbors){
            Node* temp;
            if(lookup[i->val] != NULL) temp = lookup[i->val];
            else {
                temp = new Node(i->val);
                lookup[temp->val] = temp;
            }
            currList.push_back(temp);
        }
        curr->neighbors = currList;

        // dfs on neighbors
        for(auto &i : node->neighbors){
            dfs(i, vis, lookup);
        }
    }

    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return NULL;
        }
        vector<bool> vis(101, false);
        vector<Node*> lookup(101, NULL);
        vis[node->val] = true;
        // copy logic
        Node* curr = new Node(node->val);
        lookup[curr->val] = curr;
        vector<Node*> currList;
        for(auto &i : node->neighbors){
            Node* temp = new Node(i->val);
            currList.push_back(temp);
            lookup[temp->val] = temp;
        }
        curr->neighbors = currList;
        lookup[curr->val] = curr;

        // dfs on neighbors
        for(auto &i : node->neighbors){
            dfs(i, vis, lookup);
        }
        return curr;
    }
};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
