#include "forecast_str.h"
using namespace std;
int main(){
	trie test;
	test.init();
	test.insert("test");
	test.insert("string");
	cout<<test.last("t")<<endl<<test.last("str")<<endl;
	cout<<test.have("str");
	return 0;
}
