#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
	Node(int data){
		this->data=data;
		this->next=NULL;
	}
};
Node* head=NULL;
void AddAB(int data){
	Node* newNode= new Node(data);
	if(head==NULL){
		head= newNode;
		head->next=head;
	}
	else{
		Node* temp=head;
		while(temp->next!=head){
			temp= temp->next;
		}
		newNode->next=head;
		head=newNode;
		temp->next=head;
	}
}


void deleteAB(){
	if(head==NULL){
		cout<<"Empty list"<<endl;
		return;
	}
	Node* temp=head;
	while(temp->next!=head){
		temp=temp->next;
	}
	if(head->next==head){
		delete head;
		head=NULL;
		return;
	}
	else{
		Node* todelete = head;
		head=head->next;
		temp->next= head;
		delete todelete;	
	}
}
void DeleteAE(){
	if(head==NULL){
		cout<<"Empty list"<<endl;
		return;
	}
	Node* temp=head;
	Node* prv = NULL;
	while(temp->next!=head){
		prv = temp;
		temp = temp->next;
	}
	if(temp==head){
		delete head;
		head=NULL;
	return;
	}
		prv->next=head;
		delete temp;
	
}
void deleteATM(int p){
	if(p==0){
		deleteAB();
		return;
	}
	Node* temp=head;
	for(int i=0;i<p-1;i++){
		temp= temp->next;
		if(temp->next==head){
			cout<<"Position out of bounds"<<endl;
			return;
		}
	}
	Node* del= temp->next;
	temp->next= del->next;
	delete del;
}
void display(){
	if(head==NULL){
		cout<<"List is empty"<<endl;
		return;
	}
	Node* temp=head;
	do{
		cout<<temp->data<<" ->";
		temp= temp->next;
	}
	while(temp!=head);
	cout<<"HEAD\n";
}
int main()
{
int ch;
	int data;
	int p;
cout<<"***********Single circular linklist*************\n";
cout<<"**MENU**\n";
cout<<"**press 1 if You want to add a node at Begining** \n";
cout<<"**press 2 if You want to delete a node at Begining** \n";
cout<<"**press 3 if You want to delete a node at End** \n";
cout<<"**press 4 if You want to delete a node at Specific index** \n";
cout<<"**press 5 if You want to display linklist** \n";
cout<<"**press 6 if You want to Stop your program** \n";
while(1){

cout<<"**Enter you choice**\n";
cin>>ch;
if(ch==1){
	cout<<"Enter value you want to add At Begining of linklist\n";
	cin>>data;
	AddAB(data);
}

else if(ch==2){
	cout<<"Delete  value from begining of linklist\n";
	 deleteAB();	
}

else if(ch==3){
	cout<<"Delete  value from End of linklist\n";
	DeleteAE();	
}
else if(ch==4){

		cout<<"Enter position  at  you want to delete data \n";
	cin>>p;
	deleteATM(p);
}
else if(ch==5){
	cout<<"Dsiplaying updated details\n";
   display();
}
else{
	return 0;
}


}



	return 0;
}
