class WordDictionary {
public:
    struct TrieNode {
        char c = '0';
        bool endOfWord = 0;
        unordered_map<char, TrieNode*> next;
    };

    vector<TrieNode*> tries;

    void insertToTrie(TrieNode* node, char* c) {
        char curr = *c; 
        if (curr == '\0') {
            node->endOfWord = 1;
            return;
        }
        
        auto itr = node->next.find(curr);
        if (itr == node->next.end()) {
            // belum ada
            node->next[curr] = new TrieNode(*(c + 1));
        } 

        itr = node->next.find(curr);
        insertToTrie(itr->second, c + 1);
    }

    WordDictionary() {
        tries.clear(); 
        tries.resize(128, NULL);
    }
    
    void addWord(string word) {
        if (tries[word[0]] == NULL) {
            tries[word[0]] = new TrieNode(word[0]);
        }

        insertToTrie(tries[word[0]], &word[1]);
    }

    bool ada = 0;
    void searchInTrie(TrieNode* node, char* c) {
        if (ada) {
            return;
        }

        if (node == NULL) {
            return;
        }

        char curr = *c;

        if (curr == '\0') {
            // jika di ujung
            if (node->endOfWord) {
                ada = 1;
            }

            return;
        }

        if (curr == '.') {
            //cek semua
            for (pair<char, TrieNode*> nodes : node->next) {
                if (nodes.second != NULL) {
                    searchInTrie(nodes.second, c + 1);
                }

                if (ada) {
                    break;
                }
            }
        } else {
            auto itr = node->next.find(curr);
            if (itr == node->next.end()) {
                return;
            }

            itr = node->next.find(curr);
            if (itr->second != NULL) {
                searchInTrie(itr->second, c + 1);
            }
        }
    }

    bool search(string word) {
        ada = 0;
        if (word[0] == '.') {
            for (TrieNode* nodes : tries) {
                searchInTrie(nodes, &word[1]);
                if (ada) {
                    break;
                }
            }
        } else {
            searchInTrie(tries[word[0]], &word[1]);
        }

        return ada;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */