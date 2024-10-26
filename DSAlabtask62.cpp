#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
	Node* prv;
	Node(int data){
		this->data=data;
		this->next=NULL;
		this->prv =NULL;
	}
};
Node* head=NULL;
void AddAB(int data){
	Node* newNode= new Node(data);
	if(head==NULL){
		head=newNode;
		newNode->next=	newNode;
		newNode->prv = 	newNode;
	}
	Node* last= head->prv;
	head->prv = newNode;
	newNode->next= head;
	head=newNode;
	last->next = newNode;
	newNode->prv = last;
}
void AddAE(int data){
	Node* newNode= new Node(data);
	if(head==NULL){
		head=newNode;
		newNode->next=head;
		newNode->prv = head;
	}
	Node* last = head->prv;
	last->next= newNode;
	newNode->prv = last;
	newNode->next = head;
	head->prv= newNode;
}
void AddAM(int data,int p){
	if(p==0){
		AddAB(data);
		return;
	}
	Node* temp=head;
	Node* newNode = new Node(data);
	for(int i=0;i<p-1;i++){
		temp = temp->next;
		if(temp==head){
			cout<<"POsition out of bounds"<<endl;
			return;
		}
	}
	newNode->next= temp->next;
	newNode->prv = temp;
	temp->next->prv = newNode;
	temp->next= newNode;

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
cout<<"***********Double circular linklist*************\n";
cout<<"**MENU**\n";
cout<<"**press 1 if You want to add a node at Begining** \n";
cout<<"**press 2 if You want to add a node at End** \n";
cout<<"**press 3 if You want to add a node at Specific index** \n";
cout<<"**press 4 if You want to display linklist** \n";
cout<<"**press 5 if You want to Stop your program** \n";
while(1){

cout<<"**Enter you choice**\n";
cin>>ch;
if(ch==1){
	cout<<"Enter value you want to add At Begining of linklist\n";
	cin>>data;
	AddAB(data);
}
else if(ch==2){
	cout<<"Enter value you want to add At End of linklist\n";
	cin>>data;
	AddAE(data);	
}
else if(ch==3){

	cout<<"Enter value you want to add At Specific index of linklist\n";
	cin>>data;
		cout<<"Enter position  At which you want to add data\n";
	cin>>p;
		AddAM(data,p);
}


else if(ch==4){
	cout<<"Dsiplaying updated details\n";
display();
}
else{
	return 0;
}
}

	return 0;
}

