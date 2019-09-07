#include<iostream>
using namespace std;


class Details{

	string name;
	int age;
	char gender;
	string berth_pref;
public:
	void get_details(){
		cout<<"Enter name - ";
		getline(cin,name);
		cout<<"Enter Age - ";
		cin>>age;
		cout<<"Enter gender(M/F) - ";
		cin>>gender;
		cout<<"Enter berth preference(Lower/Middle/Upper) - ";
		cin.get();
		getline(cin,berth_pref);
		cout<<endl;

	}

	void show_details(){
		cout<<"Name: "<<name<<" "<<endl;
		cout<<"Age: "<<age<<" "<<endl;
		cout<<"Gender: "<<gender<<" "<<endl;
		cout<<"Berth preference: "<<berth_pref<<endl;
		cout<<endl;

	}

};

class Railway{
	int count;
	Details Passen[100];	
public:
	Railway(){
		count=-1;
	}
	void book(int n){
		
		for(int i=count+1;i<n+count+1;i++){
			cout<<"Enter details of Passenger "<<i+1<<endl;
			Passen[i].get_details();
		}
		count+=n;
	}

	void print(){

		for(int i=0;i<count+1;i++){
			cout<<"Details of Passenger "<<i+1<<endl;
			cout<<endl;
			Passen[i].show_details();	
		}
	}
};


int main(){

	int n;
	Railway R;
	cout<<"Enter the no: of tickets - ";
	cin>>n;
	cin.get();
	cout<<endl;
	R.book(n);
	R.print();
	return 0;


}
