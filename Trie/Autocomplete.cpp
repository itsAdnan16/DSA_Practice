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
void store_suggestion(TrieNode * current,string &prefix,vector<string>&temp){
    //now we will give the current a choice from a to z
    if(current->isTerminal){
        temp.push_back(prefix);
    }
    for(char ch ='a';ch<='z';ch++){
        int index = ch - 'a';
        if(current->children[index]!=NULL){
            prefix.push_back(ch);
            TrieNode * next_node = current->children[index];
            store_suggestion(next_node,prefix,temp);
            prefix.pop_back();
        }
    }
}
vector<vector<string>>getSuggestions(TrieNode * root,string word){
    vector<vector<string>>output;
    string prefix;
    TrieNode * prev = root;
    for(int i=0;i<word.length();i++){
        char ch = word[i];
        int index = ch - 'a';
        if(prev->children[index]){
            TrieNode * current = prev->children[index];
            prefix.push_back(ch);
            vector<string>temp;
            store_suggestion(current,prefix,temp);
            output.push_back(temp);
            prev = current;
        }
        else{
            break;
        }
    }

}
int main() {
	vector<string> v;
	v.push_back("love");
	v.push_back("lover");
	v.push_back("loving");
	v.push_back("last");
	v.push_back("lost");
	v.push_back("lane");
	v.push_back("lord");

	string input = "lovi";

	TrieNode* root = new TrieNode('-');
	for(int i=0; i<v.size(); i++) {
		insert_word(root, v[i]);
	}

	vector<vector<string> > ans  = getSuggestions(root, input);

	cout << "Printing the answer: " << endl;

	for(int i=0; i<ans.size(); i++) {

		for(int j=0; j<ans[i].size(); j++) {
			cout << ans[i][j]<<", ";
		}
		cout << endl;
	}

  return 0;
}