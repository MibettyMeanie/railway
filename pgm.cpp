#include<iostream>
#include<fstream>
using namespace std;


class Details{

	string name;
	int age;
	char gender;
	string berth_pref;
public:
	Details *next;
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
	Details passenger[100];
	fstream file_obj;	
public:
	Railway(){
		count=0;
	}
	void book(){
		int n;
		cout<<"Enter the number of tickets you want to book - ";
		cin>>n;
		cin.get();
		for(int i=0;i<n;i++){
			cout<<"Enter details of Passenger "<<i+1<<endl;
			passenger[i+count].get_details();
		}
		count+=n;
	}

	void print(){

		for(int i=0;i<count;i++){
			cout<<"Details of Passenger "<<i+1<<endl;
			cout<<endl;
			passenger[i].show_details();	
		}
	}

	void read_file(){
		fstream file_obj;
	 	file_obj.open("Railway_sys.txt",ios::binary|ios::in);
	 	if(!file_obj.is_open()){
	 		cout<<"File not found"<<endl;
	 		}else{
	 		while(!file_obj.eof()){
				if(file_obj.read((char*) & passenger[count], sizeof(passenger[count]))){
					count++;
				}else{
					break;
				}
			
			}
			file_obj.close();
		}
	}

	void save_file(){

		file_obj.open("Railway_sys.txt",ios::binary|ios::out|ios::trunc);
		for(int i=0;i<count;i++){
			file_obj.write((char*) & passenger[i], sizeof(passenger[i]));
		}
		file_obj.close();


	}
};
int main(){

	int n;
	Railway R;
	R.read_file();
	do{

		cout<<"Enter 1 to book ticket"<<endl;
		cout<<"Enter 2 to show all booked tickets"<<endl;
		cout<<"Enter 3 to exit"<<endl;
		cout<<"Enter your option: ";
		cin>>n;
		switch(n){

			case 1: 
				R.book();
				break;

			case 2:
				
				R.print();				
				break;

			case 3:
				R.save_file();
				return 0;

		}

	}while(1);
	
}
