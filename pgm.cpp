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

	int n,x;
	Details D[100];
	fstream file_obj,to_write;
	file_obj.open("Railway_sys.rtf",ios::binary|ios::in);
	int counter=-1;
	while(!file_obj.eof()){

		file_obj.read((char*)&D[counter], sizeof(D[counter])); 
		counter++;

	}


	do{

		cout<<"Enter 1 to book ticket"<<endl;
		cout<<"Enter 2 to show all booked tickets"<<endl;
		cout<<"Enter 3 to exit"<<endl;
		cout<<"Enter your option: ";
		cin>>n;
		switch(n){

			case 1: 
				cout<<"Enter the number of tickets you want to book - ";
				cin>>x;
				cin.get();
				for(int i=counter;i<x+counter;i++){
					cout<<"Enter details of Passenger "<<endl;
					D[i].get_details();
				}
				counter+=x;
				break;

			case 2:
				for(int i=0;i<counter;i++){
					cout<<"Details of Passenger "<<i+1<<endl;
					D[i].show_details();
				}
				break;

			case 3:

				to_write.open("Railway_sys.rtf",ios::binary|ios::out|ios::app);
				for(int i=0;i<counter;i++){
					Details P= D[counter];
					to_write.write((char*)&P, sizeof(P));

				}
				char y= 'p';
				to_write>>y;
				to_write.close();
				file_obj.close();
				return 0;

		}

	}while(1);
	
}
