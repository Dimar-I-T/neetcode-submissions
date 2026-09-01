class PrefixTree {
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
            node->next[curr] = new TrieNode(curr);
            node->next[curr]->next.reserve(128);
        } 

        itr = node->next.find(curr);
        insertToTrie(itr->second, c + 1);
    }

    bool searchInTrie(TrieNode* node, char* c) {
        char curr = *c;
        if (curr == '\0') {
            if (node->endOfWord) {
                return 1;
            } else {
                return 0;
            }
        } 

        auto itr = node->next.find(curr);
        if (itr == node->next.end()) {
            // tidak ada
            return 0;
        }

        itr = node->next.find(curr);
        return searchInTrie(itr->second, c + 1);
    }

    bool startsWithInTrie(TrieNode* node, char* c) {
        char curr = *c;
        if (curr == '\0') {
            return 1;
        }

        auto itr = node->next.find(curr);
        if (itr == node->next.end()) {
            // tidak ada
            return 0;
        }

        itr = node->next.find(curr);
        return startsWithInTrie(itr->second, c + 1);
    }

    PrefixTree() {
        tries.clear(); 
        tries.resize(128, NULL);
    }
    
    void insert(string word) {
        if (tries[word[0]] == NULL) {
            tries[word[0]] = new TrieNode(word[0]);
        }

        insertToTrie(tries[word[0]], &word[1]);
    }
    
    bool search(string word) {
        if (tries[word[0]] == NULL) {
            return 0;
        }

        return searchInTrie(tries[word[0]], &word[1]);
    }
    
    bool startsWith(string prefix) {
        if (tries[prefix[0]] == NULL) {
            return 0;
        }

        return startsWithInTrie(tries[prefix[0]], &prefix[1]);
    }
};