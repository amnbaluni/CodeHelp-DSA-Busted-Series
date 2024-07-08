https://www.naukri.com/code360/problems/implement-a-phone-directory_1062666

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
        int index = word[0] - 'a';
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

   void printSuggestions(TrieNode* curr, vector<string> &temp, string prefix){
       //base case
       if(curr->isTerminal){
           temp.push_back(prefix);
       }

       for(char ch = 'a'; ch<='z'; ch++){
         TrieNode* next = curr->children[ch-'a'];
         if(next!=NULL){
             prefix.push_back(ch);
             printSuggestions(next, temp,prefix);
             prefix.pop_back();
         }  
       }
   }

   vector<vector<string> > getSuggestions(string str){
       TrieNode* prev = root;
       vector<vector<string> > output;
       string prefix = "";
       for(int i=0; str.length(); i++){
          char lastCh = str[i];
          prefix.push_back(lastCh);
          //check for last ch
          TrieNode* curr = prev->children[lastCh-'a'];

          if(curr==NULL){
              break;
          }

          //found
          vector<string> temp;
          printSuggestions(curr, temp, prefix);
          output.push_back(temp);
          temp.clear();
          prev = curr;
       }
       return output;
   }
};
vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{ 
   //creation of Trie 
   Trie *t = new Trie();  

   //insert all contacts in Trie
   for(int i=0; i<contactList.size();i++){
       string str = contactList[i];
       t->insertWord(str);
   }

   //return ans
   return t->getSuggestions(queryStr);
}
