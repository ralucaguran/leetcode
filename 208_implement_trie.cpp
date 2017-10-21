#include <array>
#include <string>
#include <assert.h>

using namespace std;

class TrieNode {
    private:
        std::array<TrieNode*,26> _links;
        bool _isWord;

    public:
        TrieNode():_isWord(false) {
            _links.fill(nullptr);
        }

        bool isWord() const {
            return _isWord;
        }

        void setWord() {
            _isWord = true;
        }

        TrieNode* operator[](char ch) const {
            return _links[ch-'a'];
        }

        TrieNode* getLink(char ch) const {
            return _links[ch-'a'];
        }

        void setLink(char ch, TrieNode* node) {
            _links[ch-'a'] = node;
        }
};

class Trie {
    private:
        TrieNode* _root;

    public:
        /** Initialize your data structure here. */
        Trie() {
            _root = new TrieNode();
        }

        /** Inserts a word into the trie. */
        void insert(string word) {
            if (word.empty()) {
                return;
            }

            auto node = _root;
            for (auto ch:word) {
                TrieNode* link = node->getLink(ch);
                if (link == nullptr) {
                    node->setLink(ch, new TrieNode());
                }
                node = node->getLink(ch);
            }
            node->setWord();
        }

        TrieNode* searchStr(const std::string& str) {
            auto node = _root;
            for (auto ch:str) {
                TrieNode* next = node->getLink(ch);
                if (next == nullptr) {
                    return nullptr;
                }
                node = next;
            }
            return node;
        }

        /** Returns if the word is in the trie. */
        bool search(string word) {
            auto lastNode = searchStr(word);
            return lastNode != nullptr && lastNode->isWord();
        }

        /** Returns if there is any word in the trie that starts with the given prefix. */
        bool startsWith(string prefix) {
            auto lastNode = searchStr(prefix); 
            return lastNode != nullptr;
        }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

int main() {
    Trie trie = Trie();
    trie.insert("bus");
    assert(trie.search("bus") == true);
    assert(trie.search("bu") == false);
    assert(trie.startsWith("bu") == true);
    assert(trie.search("busy") == false);
    assert(trie.search("wohnung") == false);
    trie.insert("wohnung");
    assert(trie.search("wohnung") == true);
    assert(trie.search("wohnzimmer") == false);
    trie.insert("wohnzimmer");
    trie.insert("wohngemainshaft");
    assert(trie.search("wohnzimmer") == true);
    assert(trie.search("wohngemainshaft") == true);
}

