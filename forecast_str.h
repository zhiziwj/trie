#include <bits/stdc++.h>
using namespace std;
struct ch_node{
    ch_node* last[26];
    bool is_end=false;
};
class trie{
	private:
		ch_node* root;
	public:
		void init(){
			root=new ch_node();
		}
		void insert(string word){
			ch_node* in=root;
			for(int i=0;i<word.size();i++){
				if(in->last[word[i]-'a']==nullptr){
					ch_node* temp=new ch_node();
					in->last[word[i]-'a']=temp;
				}
				in=in->last[word[i]-'a'];
			}
			in->is_end=true;
			return;
		}
		bool have(string word){
			ch_node* in=root;
			for(int i=0;i<word.size()&&in;i++){
				in=in->last[word[i]-'a'];
			}
			return (in->is_end&&in!=nullptr);
		}
		string last(string str){
			ch_node* in=root;
			for(int i=0;i<str.size();i++){
				if(in==nullptr){
					return "";//have not
				}
				bool flag=false;
				for(int i=0;i<26;i++){
					if(in->last[i]!=nullptr){
						in=in->last[i];
						flag=true;
						break;
					}
				}
				if(!flag){
					in=nullptr;
				}
			}
			string ans="";
			while(!in->is_end){
				for(int i=0;i<26;i++){
					if(in->last[i]!=nullptr){
						ans+='a'+i;
						in=in->last[i];
						break;
					}
				}
			}
			ans=str+ans;
			return ans;
		}
		void delete_tree(ch_node* node){
			if(node->is_end){
				delete node;
				return;
			}
			for(int i=0;i<26;i++){
				if(node->last[i]!=nullptr){
					delete_tree(node->last[i]);
				}
			}
			delete node;
		}
		~trie(){
			delete_tree(root);
		}
};
