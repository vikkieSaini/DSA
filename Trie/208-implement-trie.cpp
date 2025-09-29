
struct TrieNode {
    bool isEnd;                 // marks end of word
    TrieNode* a[26];            // children
    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) a[i] = nullptr;
    }
};

class Trie {
public:

    TrieNode* trie;

    Trie() {
        trie = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* tmp = trie;
        for(int i = 0;i<word.length(); i++){
            int value = 0;
            if(word[i] >= 'A')
                value = word[i] - 'A';
            else
                value = word[i] - 'a';
            tmp->a[value] = new TrieNode();
            tmp = tmp->a[value];
        }
        tmp->isEnd = true;ss
    }
    
    bool search(string word) {
        TrieNode* tmp = trie;
        bool res = true;
        for(int i = 0;i<word.length(); i++){
            int value = 0;
            if(word[i] >= 'A')
                value = word[i] - 'A';
            else
                value = word[i] - 'a';
            if(!tmp->a[value])
                return false;
            tmp = tmp->a[value];
        }
        return tmp->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* tmp = trie;
        bool res = true;
        for(int i = 0;i<prefix.length(); i++){
            int value = 0;
            if(prefix[i] >= 'A')
                value = prefix[i] - 'A';
            else
                value = prefix[i] - 'a';
            if(!tmp->a[value])
                return false;
            tmp = tmp->a[value];
        }
        return res;
    }
};