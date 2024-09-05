#include <vector>
#include <iostream>
using namespace std;

class TrieNode {
public:
    char data; 
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char d) {
        this->data = d;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isTerminal = false;
    }
};
void insert_word(TrieNode * root,string word){
      //base case which is very important
      if(word.length() == 0){
        root->isTerminal = true;
        return;
      }
      char ch = word[0];
      int index = ch - 'a';
      TrieNode * child;
      if(root->children[index]!=NULL){
        child = root->children[index];
      }
      else{
        child = new TrieNode(ch);
        root->children[index] = child;
      }
      insert_word(child,word.substr(1));
       
}
void Remove(TrieNode * root,string word){
    if(word.length()==0){
        root->isTerminal = false;
        return;
    }
    char ch = word[0];
    int index = ch - 'a';
    TrieNode * child;
    if(root->children[index]!=NULL){
        child = root->children[index];
    }
    else{
        cout<<"The word is not present";
        return;
    }
    Remove(child,word.substr(1));

}
bool search_word(TrieNode * root,string word){
    if(word.length() == 0){
        return root->isTerminal;
    }
    char ch = word[0];
    int index = ch - 'a';
    TrieNode * child ;
    if(root->children[index]!=NULL){
        child = root->children[index];
    }
    else{
        return false;
    }
    search_word(child,word.substr(1));
}
int main(){
    TrieNode * root = new TrieNode('-');
    insert_word(root,"code");
    insert_word(root,"codehelp");
    insert_word(root,"coding");
    Remove(root,"code");



    
}

