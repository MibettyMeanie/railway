#include<iostream>
using namespace std;



class railway{

	int count;

	struct details{
		string name;
		int age;
		char gender;
		string berth_pref;
	}Passen[100];

	
public:
	railway(){
		count=-1;
	}
	void get_details(int n){
		cin.get();
		for(int i=count+1;i<n+count+1;i++){
			cout<<"Enter details of Passenger "<<i+1<<endl;
			cout<<endl;
			cout<<"Enter name - ";
			getline(cin,Passen[i].name);
			cout<<"Enter Age - ";
			cin>>Passen[i].age;
			cout<<"Enter gender(M/F) - ";
			cin>>Passen[i].gender;
			cout<<"Enter berth preference(Lower/Middle/Upper) - ";
			cin.get();
			getline(cin,Passen[i].berth_pref);
			cout<<endl;
			
		}
		count+=n;
	}

	void show_details(){

		for(int i=0;i<count+1;i++){
			cout<<"Details of Passenger "<<i+1<<endl;
			cout<<endl;
			cout<<"Name: "<<Passen[i].name<<" "<<endl;
			cout<<"Age: "<<Passen[i].age<<" "<<endl;
			cout<<"Gender: "<<Passen[i].gender<<" "<<endl;
			cout<<"Berth preference: "<<Passen[i].berth_pref<<endl;
			cout<<endl;

		}
	}

	



};


int main(){

	int n;
	railway R;
	cout<<"Enter the no: of tickets - ";
	cin>>n;
	cout<<endl;
	R.get_details(n);
	R.show_details();
	return 0;


}
