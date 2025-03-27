#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Trie.h"
using namespace std;

void testTrie(vector<string> &actions, vector<string> &value)
{
    Trie trie;
    unordered_map<string, int> dir = {{"Trie", 1}, {"insert", 2}, {"search", 3}, {"startsWith", 4}};
    for (int i = 0; i < actions.size(); ++i)
    {
        string word = actions[i];
        int key = dir[word];
        switch (key)
        {
        case 1:
            trie.root = new TrieNode();
            break;
        case 2:
            trie.insert(value[i]);
            cout << "Insert " << value[i] << endl;
            break;
        case 3:
            cout << "Search " << value[i] << trie.search(value[i]) << endl;
            break;
        case 4:
            cout << "StarsWith " << value[i] << trie.startsWith(value[i]) << endl;
            break;
        default:
            break;
        }
    }
}

int main()
{
    vector<string> actions = {"Trie", "insert", "search", "search", "startsWith", "insert", "search"};
    vector<string> value = {"", "apple", "apple", "app", "app", "app", "app"};
    testTrie(actions, value);
    return 0;
}