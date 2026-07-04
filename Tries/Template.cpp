#include <bits/stdc++.h>
using namespace std;

struct TrieNode{
    bool isEndOfWord;
    unordered_map<char,TrieNode*> children;

    TrieNode(){
        isEndOfWord = false;
    }
};

class StringTrie{
private:
    TrieNode* root;
    void clear(TrieNode* curr){
        if (!curr) return;

        for (auto& pair : curr->children){
            clear(pair.second);
        }

        delete curr;
    }

public:
    StringTrie(){
        root = new TrieNode();
    }

    ~StringTrie(){
        clear(root);
    }

    void insert(const string& word){
        TrieNode* curr = root;

        for (char ch : word){
            if (curr->children.find(ch) == curr->children.end()){
                curr->children[ch] = new TrieNode();
            }
            curr = curr->children[ch];
        }

        curr->isEndOfWord = true;
    }

    bool search(const string& word){
        TrieNode* curr = root;
        for (char ch : word){
            if (curr->children.find(ch) == curr->children.end()){
                return false;
            }
            curr = curr->children[ch];
        }
        return curr->isEndOfWord;
    }

    bool StartsWith(const string& prefix){
        TrieNode* curr = root;
        for (char ch : prefix){
            if (curr->children.find(ch) == curr->children.end()){
                return false;
            }
            curr = curr->children[ch];
        }
        return true;
    }
};

int main() {
    StringTrie trie;

    cout << "========= Testing String Trie =========" << endl;

    // 1. Test Insertion
    cout << "\n[Step 1] Inserting words: 'apple', 'app', 'apricot', 'banana'..." << endl;
    trie.insert("apple");
    trie.insert("app");
    trie.insert("apricot");
    trie.insert("banana");

    // 2. Test Word Search
    cout << "\n[Step 2] Searching for words:" << endl;
    cout << "Search 'apple': " << (trie.search("apple") ? "FOUND" : "NOT FOUND") << " (Expected: FOUND)" << endl;
    cout << "Search 'app': " << (trie.search("app") ? "FOUND" : "NOT FOUND") << " (Expected: FOUND)" << endl;
    cout << "Search 'apr': " << (trie.search("apr") ? "FOUND" : "NOT FOUND") << " (Expected: NOT FOUND)" << endl;
    cout << "Search 'orange': " << (trie.search("orange") ? "FOUND" : "NOT FOUND") << " (Expected: NOT FOUND)" << endl;

    // 3. Test Prefix Search (StartsWith)
    cout << "\n[Step 3] Searching for prefixes:" << endl;
    cout << "Starts with 'apr': " << (trie.StartsWith("apr") ? "YES" : "NO") << " (Expected: YES)" << endl;
    cout << "Starts with 'ban': " << (trie.StartsWith("ban") ? "YES" : "NO") << " (Expected: YES)" << endl;
    cout << "Starts with 'cat': " << (trie.StartsWith("cat") ? "YES" : "NO") << " (Expected: NO)" << endl;

    cout << "\n========= All Tests Completed Successfully =========" << endl;
    return 0;
}
