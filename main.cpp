#include <bits/stdc++.h>
using namespace std;

class TrieNode{
 public:
     char data;
     TrieNode**children;
     bool isTerminal;

   TrieNode(char data){
   this->data = data;
   children = new TrieNode*[26];
   for(int i=0;i<26;i++){
    children[i] = NULL;
   }
   isTerminal = false;
   }
     };

 class Trie{
 TrieNode* root;

  void insertWord(string word,TrieNode* branch){
  if(word.size()==0){
    branch->isTerminal = true;
    return;
  }

  int index = word[0]-'a';
  TrieNode* child;
  if(branch->children[index]!=NULL)
    child = branch->children[index];
  else{
    child = new TrieNode(word[0]);
    branch->children[index] = child;
  }
  insertWord(word.substr(1),child);
  }
  void deleteWord(string word,TrieNode* branch){
  if(word.size()==0){
    branch->isTerminal = false;
    return;}
    TrieNode* child;
    int index = word[0]-'a';
    if(branch->children[index]!=NULL)
        child = branch->children[index];
    else
        return;
    deleteWord(word.substr(1),child);

    if(child->isTerminal == false){
        for(int i=0;i<26;i++){
            if(child->children[i]!=NULL)
                return;
        }
        delete child;
        branch->children[index]= NULL;
    }
  }
  void searchWord(string startUtil,string start, TrieNode* branch){
      if(branch==NULL)
        return;
      if(startUtil.size()==0){
        for(int i=0;i<26;i++){
            TrieNode* child;
            if(branch->children[i]!=NULL){
                child = branch->children[i];
                if(child->isTerminal==true)
                    cout<<start+char('a'+i)<<endl;
                searchWord(startUtil,start+char('a'+i),child);
            }
        }
      }
      else{
         int index = startUtil[0]-'a';
        if(branch->children[index]!=NULL){
         TrieNode* child = branch->children[index];
         searchWord(startUtil.substr(1),start,child);
        }
      }
  }
  public:
     Trie(){
     root = new TrieNode('\0');
     }
  void searchWord(string start){
    searchWord(start,start,this->root);
  }
  void insertWord(string word){
   insertWord(word,this->root);
  }

 void deleteWord(string word){
   deleteWord(word,this->root);
 }

 };
int main()
{
Trie test;
test.insertWord("apple");
test.insertWord("america");
test.insertWord("atmost");
test.insertWord("atlantic");
test.insertWord("best");
test.insertWord("bamboo");
test.insertWord("benefit");
test.insertWord("bombay");
test.insertWord("chair");
test.insertWord("cat");
test.insertWord("cough");
test.insertWord("cease");
test.insertWord("deaf");
test.insertWord("determine");
test.insertWord("disturb");
test.insertWord("dormitory");
test.insertWord("easy");
test.insertWord("elephant");
test.insertWord("etecetra");
test.insertWord("elated");
test.insertWord("foul");
test.insertWord("fast");
test.insertWord("formula");
test.insertWord("famous");
test.insertWord("grapes");
test.insertWord("ghost");
test.insertWord("gallantary");
test.insertWord("get");
int select = 0;
string temp;
cout<<"Enter 0 to search, 1 to add ,2 to delete a word and -1 to exit"<<endl;
do{
  cin>>select;
  if(select==-1)
    break;
  else if(select==0){
    cout<<"Enter word"<<endl;
    cin>>temp;
    transform(temp.begin(),temp.end(),temp.begin(),::tolower);
    test.searchWord(temp);
  }
  else if(select==1){
    cout<<"Enter word"<<endl;
    cin>>temp;
    transform(temp.begin(),temp.end(),temp.begin(),::tolower);
    test.insertWord(temp);
  }
    else if(select==2){
        cout<<"Enter word"<<endl;
        cin>>temp;
        transform(temp.begin(),temp.end(),temp.begin(),::tolower);
        test.deleteWord(temp);
    }
    cout<<endl;
}while(select!=-1);
return 0;
}
