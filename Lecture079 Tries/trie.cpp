
#include <iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];   //A to Z has 26 characters
    bool isTerminal;    //to check whether a node is terminal or not
    
    TrieNode(char ch){
        data = ch;
        for(int i=0; i<26; i++){
            children[i] = NULL;     //at start all childern are pointing to NULL
        }
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;
    
    Trie(){
        root = new TrieNode('\0');    //to avoid segmentation fault
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
        insertUtils(child, word.substr(1));   //first char ko chor kr aage wala word pass krdo
    }

    /** Inserts a word into the trie. */
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
    /** Returns if the word is in the trie. */
    void search(string word){
        return searchUtil(root, word);
    }
 
     bool removeUtil(TrieNode* root, string word) {
        // base case
        if (word.length() == 0) {
            if (root->isTerminal) {
                root->isTerminal = false;

                // Check if this node has any children
                for (int i = 0; i < 26; i++) {
                    if (root->children[i] != NULL) {
                        return false;  // Node is part of another word
                    }
                }

                return true;  // Node can be deleted
            }
            return false;  // Word not found
        }

        int index = word[0] - 'A';
        TrieNode* child = root->children[index];

        if (child == NULL) {
            return false;  // Word not found
        }

        bool shouldDeleteChild = removeUtil(child, word.substr(1));

        if (shouldDeleteChild) {
            delete child;
            root->children[index] = NULL;

            // Check if root has any other children
            for (int i = 0; i < 26; i++) {
                if (root->children[i] != NULL) {
                    return false;  // Node is part of another word
                }
            }

            return !root->isTerminal;  // Return true if the root can be deleted
        }

        return false;
    }

    void removeWord(string word) {
        removeUtil(root, word);
    }

    bool searchPrefix(TrieNode *root, string word) {
    // base case
    if (word.length() == 0) {
      return true;
    }

    int index = word[0] - 'a';
    TrieNode *child;

    // if present
    if (root->children[index] != NULL) {
      child = root->children[index];
    }
    // if absent
    else {
      return false;
    }
    return searchPrefix(child, word.substr(1));
  }
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return searchPrefix(root, prefix);
    }
};
int main() {
    Trie *t = new Trie();
    
    t->insertWord("Aman");
    cout<<"present or not"<<t->searchWord("aman")<<endl;
    
    return 0;
}
