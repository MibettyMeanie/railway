#include<iostream>
#include<fstream>
using namespace std;

static int cnf_count=0;
static int rac_count=0;
static int wl_count=0;

class Details{

	
	char gender;
	
	
		
public:
	Details(){
		consider='N';
	}
	string berth_pref;
	int done;
	int age;
	string berth_alloted;
	string name;
	char consider;
	char type;
	Details *next;
	int pnr;
	string status;
	void get_details(int pnr=0){

		cout<<"Enter name - ";
		getline(cin,name);
		cout<<"Enter Age - ";
		cin>>age;
		cout<<"Enter gender(M/F) - ";
		cin>>gender;
		if(gender=='F'){
			cout<<"Do you have any child (age less than 5) with you? (Y/N)"<<endl;
			cin>>this->consider;
		}
		cout<<"Enter berth preference(LB/MB/UB/SUB) - ";
		cin.get();
		getline(cin,berth_pref);
		cout<<endl;
		this->pnr=pnr;
		if(cnf_count<14){
			this->status="CNF";
			cnf_count++;
		}else if(rac_count<4){
			this->status="RAC";
			rac_count++;
		}else if(wl_count<2){
			this->status="WL";
			wl_count++;
		}
	}

	void show_details(){
		
		cout<<"Name: "<<name<<" "<<endl;
		cout<<"Age: "<<age<<" "<<endl;
		cout<<"Gender: "<<gender<<" "<<endl;
		cout<<"Berth preference: "<<berth_pref<<endl;
		cout<<"PNR no: "<<pnr<<endl;
		cout<<"Status "<<status<<endl;
		cout<<endl;	

	}

};

class Railway{

	int count;
	int pnr;
	Details *front ;
	Details *rear ;
	fstream file_obj;	
public:
	Railway(){
		front=NULL;
		rear=NULL;
		count=0;
		pnr=0;
	}

	void book(){
		int n;
		char ch;
		cout<<"Enter the number of tickets you want to book - ";
		cin>>n;
		cin.get();
		for(int i=0;i<n;i++){
			if(count<20){
				cout<<"Enter details of Passenger "<<i+1<<endl;
				cout<<"Are you an adult or a child(A/C)"<<endl;
				cin>>ch;
				cin.get();
				Details *temp= new Details();
				if(ch=='A'){
					pnr++;
					count++;
					temp->get_details(pnr);
					temp->type='A';
					cout<<"Your PNR is "<<temp->pnr<<endl;
					cout<<"Status: "<<temp->status<<endl;
				}else{
					temp->type='C';
					temp->get_details();
				}
				cout<<endl;
				if(front==NULL&&rear==NULL){
					front = rear= temp;
				}else{
					rear->next=temp;
					rear=temp;
				}
			}else{
				cout<<"NO TICKETS AVAILABLE"<<endl;
			}
			
		}
	}

	void print(){
		Details *temp=front;
		if(front==NULL&&rear==NULL){
			cout<<"No tickets to show"<<endl;
			cout<<endl;
		}
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
						if((temp->pnr)>pnr){
							pnr= temp->pnr;
						}
						if(temp->status=="CNF"){
							cnf_count++;
						}else if(temp->status=="RAC"){
							rac_count++;
						}else if(temp->status=="WL"){
							wl_count++;
						}
					}else{
						break;
					}
	 			}
	 			Details *temp=new Details();
				if(file_obj.read((char*) temp, sizeof(*temp))){	
					rear->next=temp;
					rear=temp;	
					count++;
					if((temp->pnr)>pnr){
						pnr= temp->pnr;
					}
					if(temp->status=="CNF"){
						cnf_count++;
					}else if(temp->status=="RAC"){
						rac_count++;
					}else if(temp->status=="WL"){
						wl_count++;
					}
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

	int cancel(){
		int x;
		cout<<"Enter your PNR no"<<endl;
		cin>>x;
		if(x>0){
			Details *temp=front;
			if(temp->pnr==x){
				front=temp->next;
				string temp_status= temp->status;
				delete temp;
				cout<<"Ticket successfully cancelled"<<endl;
				count--;
				reassign(temp_status);
				cout<<endl;
				return 0;
			}
			while(temp->next!=NULL){
				if((temp->next)->pnr==x){
					Details *temp2= temp->next;
					temp->next= temp2->next;
					string temp_status= temp2->status;
					if(temp2==rear){
						rear= temp;
					}
					delete temp2;
					cout<<"Ticket successfully cancelled"<<endl;
					count--;
					reassign(temp_status);
					cout<<endl;
					return 0;
				}
				temp=temp->next;
			}
			cout<<"INVALID PNR"<<endl;
			cout<<endl;
			return 0;
		}else{
			cout<<"INVALID PNR"<<endl;
			cout<<endl;
			return 0;
		}	
	}

	void reassign(string status){
		if(status=="CNF"){
			if(rac_count>0){
				Details *temp=front;
				while(temp!=NULL){
					if(temp->status=="RAC"){
						temp->status="CNF";
						rac_count--;
						break;
					}
					temp=temp->next;
				}
				if(wl_count>0){
					Details *temp=front;
					while(temp!=NULL){
						if(temp->status=="WL"){
							temp->status="RAC";
							rac_count++;
							wl_count--;
							break;
						}
						temp=temp->next;
					}
				}
			}else{
				cnf_count--;
			}
		}else if(status=="RAC"){
			if(wl_count>0){
				Details *temp=front;
				while(temp!=NULL){
					if(temp->status=="WL"){
						temp->status="RAC";
						wl_count--;
						break;
					}
					temp=temp->next;
				}
			}else{
				rac_count--;
			}
		}else if(status=="WL"){
			wl_count--;
		}
	}

	void prep_chart(){
		Details *temp=front;
		int lb=4;
		int mb=4;
		int ub=4;
		int sub=2;
		while(temp!=NULL){
			if(temp->status=="CNF"){
				if((temp->age>60&&lb>0)||(temp->consider=='Y'&&lb>0)){
					temp->berth_alloted="Lower Berth";
					temp->done=1;
					lb--;
				}
			temp=temp->next;
			}
		}
		while(temp!=NULL){
			if(temp->status=="CNF"&&temp->done!=1){
				if(temp->berth_pref=="LB"&&lb>0){
					temp->berth_alloted="Lower Berth";
					lb--;
					temp->done=1;
				}else if(temp->berth_pref=="MB"&&mb>0){
					temp->berth_alloted="Middle Berth";
					mb--;
					temp->done=1;
				}else if(temp->berth_pref=="UB"&&ub>0){
					temp->berth_alloted="Upper Berth";
					ub--;
					temp->done=1;
				}else if(temp->berth_pref=="SUB"&&sub>0){
					temp->berth_alloted="Side Upper Berth";
					sub--;
					temp->done=1;
				}
			}else if(temp->status=="RAC"){
				temp->berth_alloted="Side Lower Berth";
			}else if(temp->status=="WL"){
				temp->berth_alloted="NA";
			}
		}
		while(temp!=NULL){
			if(temp->status=="CNF"&&temp->done!=1){
				if(lb!=0){
					temp->berth_alloted="Lower Berth";
					lb--;
				}else if(mb!=0){
					temp->berth_alloted="Middle Berth";
					mb--;
				}else if(ub!=0){
					temp->berth_alloted="Upper Berth";
					ub--;
				}else if(sub!=0){
					temp->berth_alloted="Side Upper Berth";
					sub--;
				}
			}else if(temp->type=='C'){
				temp->berth_alloted="NA";
			}
		}
		Details *temp2=front;
		while(temp2!=NULL){
			cout<<temp2->name<<": "<<temp2->berth_alloted<<endl;
			temp2=temp2->next;
		}	
	}
};
int main(){

	int n;
	Railway R;
	R.read_file();
	do{

		cout<<"Enter 1 to book ticket"<<endl;
		cout<<"Enter 2 to cancel ticket"<<endl;
		cout<<"Enter 3 to show all booked tickets"<<endl;
		cout<<"Enter 4 to see tentative chart"<<endl;
		cout<<"Enter 5 to exit"<<endl;
		cout<<"Enter your option: ";
		cin>>n;
		cout<<endl;
		switch(n){

			case 1: 
				R.book();
				break;

			case 2:
				R.cancel();
				break;

			case 3:
				R.print();				
				break;

			case 4:
				R.prep_chart();				
				break;

			case 5:
				R.save_file();
				return 0;

		}

	}while(1);
	
}
