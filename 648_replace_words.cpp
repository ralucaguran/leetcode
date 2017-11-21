#include <array>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <assert.h>

using namespace std;


class TrieNode {
    private:
        std::array<TrieNode*,26> _children;
        bool _isWord;

    public:
        TrieNode():_isWord(false) {
            _children.fill(nullptr);
        }

        bool isWord() const {
            return _isWord;
        }

        void setWord() {
            _isWord = true;
        }

        TrieNode* operator[](char ch) const {
            return _children[ch-'a'];
        }

        TrieNode* getChild(char ch) const {
            return _children[ch-'a'];
        }

        void setChild(char ch, TrieNode* node) {
            _children[ch-'a'] = node;
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

        TrieNode* getRoot() {
            return _root;
        }

        /** Inserts a word into the trie. */
        void insert(string word) {
            if (word.empty()) {
                return;
            }

            auto node = _root;
            for (auto ch:word) {
                //TrieNode* next = node->getChild(ch);
                TrieNode* next = (*node)[ch];
                if (next == nullptr) {
                    next = new TrieNode();
                    node->setChild(ch, next);
                }
                node = next;
            }
            node->setWord();
        }

        TrieNode* searchPrefix(const std::string& prefix) {
            auto node = _root;
            for (auto ch:prefix) {
                //TrieNode* next = node->getChild(ch);
                TrieNode* next = (*node)[ch];
                if (next == nullptr) {
                    return nullptr;
                }
                node = next;
            }
            return node;
        }

        /** Returns if the word is in the trie. */
        bool search(string word) {
            auto lastNode = searchPrefix(word);
            return lastNode != nullptr && lastNode->isWord();
        }

        /** Returns if there is any word in the trie that starts with the given prefix. */
        bool startsWith(string prefix) {
            auto lastNode = searchPrefix(prefix); 
            return lastNode != nullptr;
        }
};

class Solution {
    public:
        string replaceWords(vector<string>& dict, string sentence) {
            // insert words in dictionary into a trie data struct
            Trie dictTrie;
            for (std::string& word:dict) {
                dictTrie.insert(word);
            }

            // split sentence into words and replace words with prefixes stored in trie
            std::istringstream iss(sentence);
            std::string word;
            std::string resultSentence;
            while (iss >> word) {
                std::string prefix = "";
                TrieNode* trieNode = dictTrie.getRoot();
                for (char ch:word) {
                    trieNode = trieNode->getChild(ch);
                    if (trieNode == nullptr) {
                        break;
                    }
                    prefix += ch;
                    if (trieNode->isWord()) {
                        word = prefix;
                        break;
                    }
                }
                resultSentence += word + ' ';
            }

            resultSentence.pop_back();
            return resultSentence;
        }
};


int main() {
    Solution sol;
    std::vector<std::string> dict{"cat", "bat", "rat", "batt"};
    std::string sentence = "the cattle was rattled by the battery";
    assert("the cat was rat by the bat" == sol.replaceWords(dict, sentence));
    return 0;
}

