//Phone directory program usnig linked list and file handling

#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
fstream myfile;

struct clients{
	                 
	string name;        //part of the node
	string number;
	string cnic;
	clients*link;
	
	clients(){
		link= NULL;
	}
};

class directory{
	 
	 clients *start,*cur,*temp;   //pointer to handle the linklist
	 public:
	 	directory(){  
	 	
	 		start = NULL;
		 }
		 create_file(string n,string num, string cn){     //function to craete nodes
		 	
		 	if(start==NULL){          // craete the 1st node
		 		
		 		start= new clients;
		 		start->link = NULL;
		 		start->name = n;
		 		start->number = num;
		 		start->cnic = cn;
		 		
		 		myfile.open("directory.txt",ios::out | ios::app);
		 		  myfile<<"Name_:_"<<start->name<<"__|__CNIC:_"<<start->cnic<<"_|_Phone Number_:_"<<start->number<<endl;
		 		  myfile.close();
		 		  
		 	    
			 }
			 
			 else{     //to craet new node
			 	
			 	cur = start;
			 	while(cur->link!=NULL){
			 		
			 		cur = cur->link;
				 }
				 
				temp= new clients;
				temp->name =n;
				temp->number =num;
				temp->cnic =cn; 
				temp->link =NULL;
				
				cur->link = temp;
				
				myfile.open("directory.txt",ios::out | ios::app);
		 		  myfile<<"Name_:_"<<temp->name<<"__|__CNIC:_"<<temp->cnic<<"_|_Phone Number_:_"<<temp->number<<endl;
		 		  myfile.close();
				
			 }
		 }
		 
		 void terminating_file(string n){
		 	
		 	cur= start;
		 	if(start->name==n){
		 		temp= start;
		 		start= start->link;
		 		delete temp;
		 		
			 }
			 else{
			 	
			 	while(cur->name!=n){
			 		
			 		if(cur->link==NULL){
			 			
			 			 cout<<"Any case of"<<n<<" does not exist"<<endl;
			 			 return;
					 }
					 temp= cur;
					 cur=cur->link;
					 
				 }
			 }
			 
			 
		 }
		 
		 void print_now(){         //print data of the linklist
		 	
		 	cur=start;
		 	int c;
		 	cout<<"Person #"<<" --->Name  \tNmuber \tCNIC"<<endl;
		 	
		 	for(c=1;cur->link!=-NULL;c++){
		 		
		 		cout<<"Person "<<c<<" -->"<<cur->name<<"\t"<<cur->number<<"\t"<<cur->cnic<<endl;
		 		cur=cur->link;
			 }
			 
			 cout<<"Person "<<c<<" -->"<<cur->name<<"\t"<<cur->number<<"\t"<<cur->cnic<<endl;
		 }
		 
		 void search(string n){
		 	
		 	cur= start;
		 	 while(cur!=NULL){
		 	 	if(cur->name==n){
		 	 		
		 	 		char mod;
		 	 		cout<<"\n\t___________DATA FOUND_________\n\n";
		 	 		cout<<"Name : "<<cur->name<<endl;
		 	 		cout<<"CNIC : "<<cur->cnic<<endl;
		 	 		cout<<"Phone # : "<<cur->number<<endl;
		 	 		cout<<"\nDo you want to modify Phone Number (y/n) : ";
		 	 		cin>>mod;
		 	 		
		 	 		if(mod=='y'||mod=='Y'){
		 	 			
		 	 			cout<<"Enter New Phone Number ";
		 	 			cin>>cur->number;
		 	 			cout<<"\n\t________Data Updated________"<<endl;
					  }
					  
					  break;
				  }
				  
				  cur= cur->link;
			  }
			  
			  if(cur==NULL)
			  cout<<"\n\t__________DATA NOT FOUND__________\n\n";
		 }
		 
		 void print(){
		 	
		 	string s;    //below function reads the data from the file
		 	myfile.open("directory.txt",ios::in);
		 	while(!myfile.eof())
		 	{
		 		myfile>>s;
		 		cout<<s<<endl;
			 }
			 
			 myfile.close();
		 }
		 
		 
		 
};

int main(){
	
	directory l1;
	int nooffiles,i,p,ch;
	string n,nm,cnc;
	
	cout<<"\n\t======================================================================\n\n";
	cout<<"\t\t\t PHONE DIRECTORY SYSTEM\n";
	cout<<"\n\t======================================================================\n\n";
	
	cout<<"\n\t======================================================================\n\n";
	cout<<"\n\t1- SAVE NUMBERS\n";
	cout<<"\n\t2- CAN SEARCH AND UPDATE THE NUMBER\n";
	cout<<"\n\t3- WHEN A NUMBER IS OFF,,, YOU CAN DELETE IT FROM YOUR DIRECTORY\n";
	cout<<"\n\t4- CAN SEE ALL THE LIST ANY TIME\n";
	
	cout<<"\n\t======================================================================\n\n";
	cout<<"\n\t========================================SAVE NUMBERS==========================\n"<<endl;
	
	cout<<"\thow many numbers you want to save"<<endl;    //no. of files
	cin>>nooffiles;
	
	for(i=1;i<nooffiles;i++){      // createor save data of each number ...function call pass data....
		
		cout<<"\n\tEnter Name \t";
		cin>>n;
		
		cout<<"\n\tEnter Phone Nmuber\t";
		cin>>nm;
		
		cout<<"\n\tEnter CNIC\t";
		cin>>cnc;
		
		l1.create_file(n,nm,cnc);
		
	}
	      system("CLS");
	do{
		
		cout<<"\n\nWhat You want to do with your case now"<<endl;
		cout<<"\n1- Save new PHONE NUMBER\n";
		cout<<"2- Delete any NUMBER"<<endl;
		cout<<"3- Search and Modify"<<endl;
		cout<<"4- See ALL List"<<endl;
		cout<<"5- Exit\n"<<endl;
		
		cin>>ch;
		      system("CLS");
		switch(ch)
		{
			case 1:
				cout<<"\n\t========================================SAVE NEW NUMBERS==========================\n\n";
				cout<<"Enter DAta to insert new person's data"<<endl;
				
				cout<<"\nEnter Name \t";
				cin>>n;
				
				cout<<"\nEnter Phone Number \t";
				cin>>nm;
				
				cout<<"\nEnter CNIC \t";
				cin>>cnc;
				
				l1.create_file(n,nm,cnc);
				cout<<"Number of"<<n<<" has been saved in your phone directory "<<endl;
				break;
				
			case 2:
				
			     cout<<"\n\t=========================================DELETE NUMBER===============================\n\n";
				 cout<<"\nEnter name of person whose number you want to delete\n"<<endl;
				 cin>>n;
				 
				 l1.terminating_file(n);
				 cout<<"\nNumber of"<<n<<" has been removed from your list"<<endl;
				 break;
				     
			case 3:
			     
				 cout<<"\n\t=========================================SEARCH AND UPDATE NUMBER=============================\n\n";
				 cout<<"Enter NAME of Person to search it from list\t";
				 cin>>n;
				 
				 l1.search(n);
				 break;
				 
			case 4:
			     
				 cout<<"\n\t====================================PRINTING ALL LIST=====================================\n\n";
				 
				 l1.print();
				 break;
			
			case 5:
			     
				 cout<<"\n\t=========================================LIST OF Numbers added now==================================\n\n";
				 l1.print_now();
				 break;
				 
			default:
				cout<<"\t-------------Invalid---------"<<endl;
				 		 
					 	
			  }      
	}
	
	while(ch!=5);
	cout<<"\nTHANKS"<<endl;
	getch();
	
	 
}









































