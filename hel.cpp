#include<iostream>
#include<fstream>
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

int main(){
	int n;
	Details P[3];
	Details D[3];
	fstream obj1;
	fstream obj2;

	do{

		cout<<"Enter 1 to book ticket"<<endl;
		cout<<"Enter 2 to show all booked tickets"<<endl;
		cout<<"Enter 3 to exit"<<endl;
		cout<<"Enter your option: ";
		cin>>n;
		switch(n){

			case 1: 
				
				obj1.open("File.txt",ios::out|ios::app);
				
				cin.get();
				for(int i=0;i<3;i++){
					cout<<"Enter details of Passenger "<<endl;
					P[i].get_details();
				}
				obj1.write((char*)&P,sizeof(P));
				obj1.close();
				break;

			case 2:
				
				
				obj2.open("File.txt",ios::in);
				obj2.read((char *) &D,sizeof(D));
				for(int i=0;i<3;i++){
					cout<<"Details of Passenger "<<i+1<<endl;
					D[i].show_details();
				}
				obj2.close();
				break;

			case 3:
				
				return 0;

		}

	}while(1);

}