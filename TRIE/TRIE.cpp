#include <bits/stdc++.h>
#define sz 100
#define endl '\n'
using namespace std;

/**
You are given some words, Add them in dictionary using TRIE.
Then you are given some query. In each query check the given word is present in the
dictionary or not.
*/

struct node
{
    bool ending;
    node *next[26];
    node()
    {
        ending=false;
        for (int i=0; i<26; i++) next[i]=NULL;
    }
};

struct TRIE
{
    node *root;
    TRIE();
    void insert_trie(string);
    bool search_trie(string);
    void delete_trie();

    ///Utility function
    void delete_node(node *);
};

TRIE::TRIE()
{
    root=new node();
}

void TRIE::insert_trie(string s)
{
    node *tmp=root;
    int i, len=s.size(), x;
    for (i=0; i<len; i++) {
        x=s[i]-'a';
        if (tmp->next[x]==NULL) tmp->next[x]=new node();
        tmp=tmp->next[x];
    }
    tmp->ending=true;
}

bool TRIE::search_trie(string s)
{
    int i, x, len=s.size();
    node *tmp=root;
    for (i=0; i<len; i++) {
        x=s[i]-'a';
        if (tmp->next[x]==NULL) return false;
        tmp=tmp->next[x];
    }
    return tmp->ending;
}

void TRIE::delete_node(node *tmp)
{
    for (int i=0; i<26; i++) {
        if (tmp->next[i]!=NULL) delete_node(tmp->next[i]);
    }
    delete tmp;
}

void TRIE::delete_trie()
{
    delete_node(root);
}

int main()
{
    TRIE *tr=new TRIE();
    int n;
    string s;
    cin >> n;
    while (n--) {
        cin >> s;
        tr->insert_trie(s);
    }
    cin >> n;
    while (n--) {
        cin >> s;
        cout << s << " does" << (tr->search_trie(s)?"":"not") << " exist" << endl;
    }
    tr->delete_trie();
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
10
these
is
i
absolute
abcdaabcd
vog
abcdaabcdefa
aaaa
aabc
aabcc
*/
