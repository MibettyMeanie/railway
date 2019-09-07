#include<iostream>
#include<fstream>
using namespace std;

int main(){
	fstream obj;
	obj.open("Railway.rtf",ios::out);
	obj<<"Heloo";
	obj.close();
	return 0;

}