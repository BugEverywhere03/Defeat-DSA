#include <string>
#include <iostream>
using namespace std;

class TrieNode
{
public:
    // Trường word này biểu thị nút này có phải là nút cuối của từ
    bool word;
    // Mảng chứa tất cả ký tự tiếp theo của một TrieNode
    TrieNode *children[26];

    // Khởi tạo giá trị của trường word = false và các node con đều bằng NULL
    TrieNode()
    {
        this->word = false;
        for (int i = 0; i < 26; ++i)
        {
            children[i] = nullptr;
        }
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }
    void insert(std::string word)
    {
        TrieNode *temp = root;
        for (int i = 0; i < word.size(); ++i)
        {
            // Kiểm tra xem ký tự này năm ở vị trí nào
            int indexWord = word[i] - 'a';
            if (!temp->children[indexWord])
            {
                temp->children[indexWord] = new TrieNode();
            }
            temp = temp->children[indexWord];
        }
        temp->word = true;
    }
    bool search(std::string word)
    {
        TrieNode *temp = this->root;
        for (int i = 0; i < word.size(); ++i)
        {
            int indexWord = word[i] - 'a';
            if (!temp->children[indexWord])
                return false;
            temp = temp->children[indexWord];
        }
        return temp->word;
    }
    bool startsWith(std::string prefix)
    {
        TrieNode *temp = this->root;
        for (int i = 0; i < prefix.length(); ++i)
        {
            int indexWord = prefix[i] - 'a';
            if (!temp->children[indexWord])
                return false;
            temp = temp->children[indexWord];
        }
        return true;
    }
};