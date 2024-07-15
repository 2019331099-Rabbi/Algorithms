#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 1001
#define inf 1e9 + 9
#define mod 100000000
#define RUN_FAST 
using namespace std;

// int row[] = {0, 0, -1, 1, -1, 1, -1, 1};
// int col[] = {1, -1, 0, 0, -1, 1, 1, -1};

class TrieNode {
public:
    bool ending;
    unordered_map <char, TrieNode*> next;

    TrieNode() {
        ending = false;
    }
};

class Trie {
public:

    TrieNode *root;

    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *tmp = root;
        for (auto ch: word) {
            if (tmp->next.find(ch) == tmp->next.end()) tmp->next[ch] = new TrieNode();
            tmp = tmp->next[ch];
        }
        tmp->ending = true;
    }
    
    bool search(string word) {
        TrieNode *tmp = root;
        for (auto ch: word) {
            if (tmp->next.find(ch) == tmp->next.end()) return false;
            tmp = tmp->next[ch];
        }
        return tmp->ending;
    }
    
    bool startsWith(string prefix) {
        TrieNode *tmp = root;
        for (auto ch: prefix) {
            if (tmp->next.find(ch) == tmp->next.end()) return false;
            tmp = tmp->next[ch];
        }
        return true;
    }
};

int main() 
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    Trie *trie = new Trie();

    trie->insert("apple");
    cout << trie->search("apple") << endl;
    cout << trie->search("app") << endl;
    cout << trie->startsWith("app") << endl;
    trie->insert("app");
    cout << trie->search("app") << endl;
}