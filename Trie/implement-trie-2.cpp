#include <bits/stdc++.h> 

struct TrieNode {
    bool isEnd;
    TrieNode* child[26];
    int count = 0;
    int counter = 0;
    
    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) child[i] = nullptr;
    }
};

class Trie{

    public:

    TrieNode* head = NULL;

    Trie() {
        head = new TrieNode();
    }

    void insert(string &word){
        TrieNode* tmp = head;
        for(int i = 0;i<word.length();i++){

            if(word[i] <= 'Z'){
                if(tmp->child[word[i]-'A'] == nullptr){
                    TrieNode* node = new TrieNode();
                    tmp->child[word[i]-'A'] = node;
                }
                tmp->child[word[i]-'A']->counter++;
                tmp = tmp->child[word[i]-'A'];
            }else if(word[i] >= 'a'){
                if(tmp->child[word[i] - 'a'] == nullptr){
                    TrieNode* node = new TrieNode();
                    tmp->child[word[i]-'a'] = node;
                }
                tmp->child[word[i]-'a']->counter++;
                tmp = tmp->child[word[i]-'a'];
            }
        }
        tmp->isEnd = true;
        tmp->count++;
    }

    int countWordsEqualTo(string &word){
        TrieNode* tmp = head;
        if(tmp == nullptr){
            cout<<"first";
            return false;
        }
        for(int i = 0;i<word.length();i++){
            if(word[i] <= 'Z'){
                if(tmp->child[word[i]-'A'] == nullptr){
                    return false;
                }
                tmp = tmp->child[word[i]-'A'];
            }else if(word[i] >= 'a'){
                if(tmp->child[word[i]-'a'] == nullptr)
                    return false;
                tmp = tmp->child[word[i]-'a'];
            }
        }
        return tmp->isEnd ? tmp->count : 0;
    }

    int countWordsStartingWith(string &word){
        TrieNode* tmp = head;
        if(tmp == nullptr){
            cout<<"first";
            return false;
        }
        for(int i = 0;i<word.length();i++){
            if(word[i] <= 'Z'){
                if(tmp->child[word[i]-'A'] == nullptr){
                    return false;
                }
                tmp = tmp->child[word[i]-'A'];
            }else if(word[i] >= 'a'){
                if(tmp->child[word[i]-'a'] == nullptr)
                    return false;
                tmp = tmp->child[word[i]-'a'];
            }
        }
        return tmp->counter;
    }

    void erase(string &word){
        TrieNode* tmp = head;
        for(int i = 0;i<word.length();i++){

            if(word[i] <= 'Z'){
                if(tmp->child[word[i]-'A'] == nullptr){
                    TrieNode* node = new TrieNode();
                    tmp->child[word[i]-'A'] = node;
                }
                tmp->child[word[i]-'A']->counter--;
                tmp = tmp->child[word[i]-'A'];
            }else if(word[i] >= 'a'){
                if(tmp->child[word[i] - 'a'] == nullptr){
                    TrieNode* node = new TrieNode();
                    tmp->child[word[i]-'a'] = node;
                }
                tmp->child[word[i]-'a']->counter--;
                tmp = tmp->child[word[i]-'a'];
            }
        }
        if(tmp->count == 0)
            return;
        if(tmp->count == 1) tmp->isEnd = false;
        tmp->count--;
    }
};
