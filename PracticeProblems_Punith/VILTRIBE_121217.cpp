//https://www.codechef.com/viewsolution/16556352
#include <iostream>
#include <string>

using namespace std;
class SM{
	private:
		int a, b, dota, dotb, i, len;
		string test;
	public:
		SM(string t){
			a = b = dota = dotb = i = 0;
			test = t;
			len = t.length();
		}
		void State0();
		void StateA();
		void StateB();
		void Print(){
			cout << a << " " << b << endl;
		}
};
void SM::State0(){
	while(test[i] == '.' && i < len){
		++i;
	}
	if(i == len)
		return;
	if(test[i] == 'A')
		StateA();
	else
		StateB();
}
void SM::StateA(){
	++a;
	++i;
	while(test[i] == '.' && i < len){
		++dota;
		++i;
	}
	if(i == len)
		return;
	if(test[i] == 'A'){
		a += dota;
		dota = 0;
		StateA();
	}
	if(test[i] == 'B'){
		dota = 0;
		StateB();
	}			
}


void SM::StateB(){
	++b;
	++i;
	while(test[i] == '.' && i < len){
		++dotb;
		++i;
	}
	if(i == len)
		return;
	if(test[i] == 'B'){
		b += dotb;
		dotb = 0;
		StateB();
	}
	if(test[i] == 'A'){
		dotb = 0;
		StateA();
	}			
}

int main(){
	string test;
	int t;
	cin >> t;
	getline(cin,test);
	while(t--){
		getline(cin, test);
		SM obj(test);
		obj.State0();
		obj.Print();
	}
	return 0;
}
