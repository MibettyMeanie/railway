#include<iostream>
using namespace std;


class Details{
public:
	string name;
	int age;
	char gender;
	string berth_pref;

	void get_details(Details&Passen){
		cout<<"Enter name - ";
		getline(cin,Passen.name);
		cout<<"Enter Age - ";
		cin>>Passen.age;
		cout<<"Enter gender(M/F) - ";
		cin>>Passen.gender;
		cout<<"Enter berth preference(Lower/Middle/Upper) - ";
		cin.get();
		getline(cin,Passen.berth_pref);
		cout<<endl;

	}

	void show_details(Details&Passen){
		cout<<"Name: "<<Passen.name<<" "<<endl;
		cout<<"Age: "<<Passen.age<<" "<<endl;
		cout<<"Gender: "<<Passen.gender<<" "<<endl;
		cout<<"Berth preference: "<<Passen.berth_pref<<endl;
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
			Passen[i].get_details(Passen[i]);
		}
		count+=n;
	}

	void print(){

		for(int i=0;i<count+1;i++){
			cout<<"Details of Passenger "<<i+1<<endl;
			cout<<endl;
			Passen[i].show_details(Passen[i]);	
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
