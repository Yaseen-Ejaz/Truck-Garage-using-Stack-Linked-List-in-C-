#include <iostream>             //yaseen ejaz ahmed   B20F0283CS014
using namespace std;

class node
{
	private:
	int data;
	node* next;
	node *head=NULL;
	node *ptr;
	
	public:
	void Enter_Garage(int truck_ID)
	{
		node* temp=new node();
		temp->data=truck_ID;
		temp->next=NULL;
		
		if(head==NULL)
		{
			head=temp;
			ptr=head;
		}
		
		else
		{
			ptr->next=temp;
			ptr=ptr->next;	
		}
	}
	
	void Show_Trucks()
	{
		ptr=head;
		
		while(ptr->next!=NULL)
		{
			cout<<"\t"<<ptr->data;
			ptr=ptr->next;
		}
		
		cout<<"\t"<<ptr->data;
	}
	
	bool On_Road(int ID)
	{
		ptr=head;
		
		while(ptr->next!=NULL)
		{
			
			if(ptr->data==ID)
			return true;
			ptr=ptr->next;
		}
		
		if(ptr->data==ID)
		return true;
		
		return false;
	}
	
	int Exit_Garage()
	{
		int ID;
		cout<<"\nEnter the ID of the truck : ";
		cin>>ID;
		
		if(On_Road(ID))
		{
			ptr=head;
		
		    while(ptr->next->next!=NULL)
		    {
			ptr=ptr->next;
		    }
		
		    node* temp=ptr->next;
		
		    if(temp->data==ID)
		{
			delete temp;
		    ptr->next=NULL;	
		}
		
		    else cout<<"\nTruck "<<ID<<" is not near the door\n\n";
		}
		
		else return 0;
	}

};

int main()
{
	node n;
	int opt,truck_ID;
	cout<<"\t\t\t\tTRUCK GARAGE";
	do
	{
		cout<<"\n\n---------------------------------------\n\nWould you like to\n1. Enter Truck\n2. Exit Truck\n3. Exit\n";
		cin>>opt;
		
		if(opt==1)
		{
			cout<<"\nEnter the Truck ID : ";
			cin>>truck_ID;
			
			n.Enter_Garage(truck_ID);
			cout<<endl<<endl;
			n.Show_Trucks();	
		}
		
		else if(opt==2)
		{
			n.Exit_Garage();
			n.Show_Trucks();
		}
	}
	while(opt!=3);
}
