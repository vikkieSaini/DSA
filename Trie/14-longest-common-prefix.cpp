struct TrieNode {
    TrieNode* child[26];
    bool isEnd;
    int counter = 0;

    TrieNode() {
        isEnd = false;
        for(int i = 0;i<26;i++){
            child[i] = nullptr;
        }
    }
};

class Trie {

    TrieNode* head = NULL;
    string pref = "";
    public:

    Trie() {
        head = new TrieNode();
    }

    void insert(string &word){
        TrieNode* tmp = head;
        for(int i = 0;i<word.length();i++){
            // if(word[i] <= 'Z'){
            //     if(tmp->child[word[i]-'A'] == nullptr){
            //         TrieNode* node = new TrieNode();
            //         tmp->child[word[i]-'A'] = node;
            //     }
            //     tmp->child[word[i]-'A']->counter++;
            //     tmp = tmp->child[word[i]-'A'];
            // }else if(word[i] >= 'a'){
                if(tmp->child[word[i] - 'a'] == nullptr){
                    TrieNode* node = new TrieNode();
                    tmp->child[word[i]-'a'] = node;
                }
                tmp->child[word[i]-'a']->counter++;
                tmp = tmp->child[word[i]-'a'];
            //}
        }
        tmp->isEnd = true;
    }

    string prefix(int count){
        TrieNode* tmp = head;
        string pref = "";
        while(1){
            if(tmp->isEnd || !tmp)
                break;
            int i = 0;
            for(i = 0;i<26;i++){
                if(tmp->child[i] != nullptr && tmp->child[i]->counter == count){
                    pref += ('a' + i);
                    tmp = tmp->child[i];
                    break;
                }
            }
            if(i == 26)
                break;
        }
        return pref;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie* trie = new Trie();

        for(int i = 0;i<strs.size();i++){
            trie->insert(strs[i]);
        }

        return trie->prefix(strs.size());

    }
};