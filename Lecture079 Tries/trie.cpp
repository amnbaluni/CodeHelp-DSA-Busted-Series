
#include <iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    
    TrieNode(char ch){
        data = ch;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;
    
    Trie(){
        root = new TrieNode('\0');
    }
    
    void insertUtils(TrieNode* root, string word){
        //base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }
        
        //Assuming words will be in caps
        int index = word[0] - 'A';
        TrieNode* child;
        
        //if character is present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            //absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        
        //recursion
        insertUtils(child, word.substr(1));
    }
    
    void insertWord(string word){
        insertUtils(root, word);
    }

   bool searchUtil(TrieNode* root, string word){
    //base case
    if(word.length()==0){
        return root->isTerminal;
    }
    
    int index = word[0]-'A';
    TrieNode* child;
    
    //if present
    if(root->children[index]!=NULL){
        child = root->children[index];
    }
    //if absent
    else{
        return false;
    }
    return searchUtil(child, word.substr(1));
}
    
    void search(string word){
        return searchUtil(root, word);
    }
    
    
    
    
};
int main() {
    Trie *t = new Trie();
    
    t->insertWord("Aman");
    cout<<"present or not"<<t->searchWord("aman")<<endl;
    
    return 0;
}
