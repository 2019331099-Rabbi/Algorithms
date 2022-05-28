#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
You are given some words. Add them in dictionary.

Then you are given some words letter. Prints those words from the dictionary
that has been started by the given words.

*/

struct node
{
    bool ending;
    node *next[sz];

    node()
    {
        ending = false;
        for (int i = 0; i < sz; i++) next[i] = NULL;
    }
};

struct TRIE
{
    node *root;
    TRIE();

    void insertTrie(string s);
    bool searchTrie(string s);
    void suggestion(string s);
    void deleteTrie();

    //Utils
    void printWord(string s, node *tmp);
    void deleteNode(node *);
};

TRIE::TRIE()
{
    root = new node();
}

void TRIE::insertTrie(string s)
{
    node *tmp = root;
    int len = s.size(), x;

    for (int i = 0; i < len; i++) {
        x = s[i] - 'a';
        if (tmp->next[x] == NULL) tmp->next[x] = new node();
        tmp = tmp->next[x];
    }
    tmp->ending = true;
}

bool TRIE::searchTrie(string s)
{
    node *tmp = root;
    int len = s.size(), x;

    for (int i = 0; i < len; i++) {
        x = s[i] - 'a';
        if (tmp->next[x] == NULL) return false;
        tmp = tmp->next[x];
    }
    return tmp->ending;
}

void TRIE::printWord(string s, node *tmp)
{
    if (tmp->ending) cout << s << endl;
    for (int i = 0; i < sz; i++) {
        if (tmp->next[i] == NULL) continue;
        else printWord(s + (char)('a' + i), tmp->next[i]);
    }
}

void TRIE::suggestion(string s)
{
    node *tmp = root;
    int len = s.size(), x;

    for (int i = 0; i < len; i++) {
        x = s[i] - 'a';
        if (tmp->next[x] == NULL) return;
        else tmp = tmp->next[x];
    }
    printWord(s, tmp);
}

void TRIE::deleteNode(node *tmp)
{
    for (int i=0; i<26; i++) {
        if (tmp->next[i]!=NULL) deleteNode(tmp->next[i]);
    }
    delete tmp;
}

void TRIE::deleteTrie()
{
    deleteNode(root);
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    TRIE *tr = new TRIE();
    string s;
    int n, q;

    cin >> n;
    while (n--) {
        cin >> s;
        tr->insertTrie(s);
    }

    cin >> n;
    while (n--) {
        cin >> s;
        cout << s << " does" << (tr->searchTrie(s)?"":"not") << " exist" << endl;
    }

    cin >> n;
    while (n--) {
        cin >> s;
        cout << "-----------" << endl;
        cout << "Words that start by " << s << endl;
        tr->suggestion(s);
        cout << "-----------" << endl;
    }
    tr->deleteTrie();
    return 0;
}
/**
17
abcdaabcdefa
ababcadacc
aaa
aa
aab
aabccc
aabc
aab
abcdaabcde
wow
this
that
those
this
is
absolutely
vogue

1
this

2
a
th
 */