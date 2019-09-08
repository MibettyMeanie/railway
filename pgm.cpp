#include<iostream>
#include<fstream>
using namespace std;


class Details{

	string name;
	int age;
	char gender;
	string berth_pref;
	int pnr;

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
		static int pnr=0;
		this->pnr=++pnr;

	}

	void show_details(){
		
		cout<<"Name: "<<name<<" "<<endl;
		cout<<"Age: "<<age<<" "<<endl;
		cout<<"Gender: "<<gender<<" "<<endl;
		cout<<"Berth preference: "<<berth_pref<<endl;
		cout<<"PNR no: "<<pnr<<endl;
		cout<<endl;	

	}

};

class Railway{

	int count;
	Details *front ;
	Details *rear ;
	fstream file_obj;	
public:
	Railway(){
		front=NULL;
		rear=NULL;
		count=0;
	}

	void book(){
		int n;
		cout<<"Enter the number of tickets you want to book - ";
		cin>>n;
		cin.get();
		for(int i=0;i<n;i++){
			count++;
			cout<<"Enter details of Passenger "<<i+1<<endl;
			Details *temp= new Details();
			temp->get_details();
			if(front==NULL&&rear==NULL){
				front = rear= temp;
			}else{
				rear->next=temp;
				rear=temp;
			}
		}
	}

	void print(){
		Details *temp=front;
		while(temp!=NULL){
			temp->show_details();
			temp=temp->next;
		}		
	}

	void read_file(){
		fstream file_obj;
	 	file_obj.open("Railway_sys.txt",ios::binary|ios::in);
	 	if(!file_obj.is_open()){
	 		cout<<"File not found"<<endl;
	 	}else{
	 		while(!file_obj.eof()){
	 			if(front==NULL&&rear==NULL){
	 				Details *temp=new Details();
	 				if(file_obj.read((char*) temp, sizeof(*temp))){
	 					front = rear = temp;
						count++;
					}else{
						break;
					}
	 			}
	 			Details *temp=new Details();
				if(file_obj.read((char*) temp, sizeof(*temp))){	
					rear->next=temp;
					rear=temp;	
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

		Details *temp=front;
		while(temp!=NULL){
			file_obj.write((char*) temp, sizeof(*temp));
			temp=temp->next;
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
