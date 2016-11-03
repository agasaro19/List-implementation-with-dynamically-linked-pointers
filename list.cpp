#include<iostream>
#include<map>
#include"List.h"

using namespace std;

List::List(){
	capacity = length;
	length =0;
	front = NULL;	
	back = NULL;
}

List::List(int size){
	capacity = size;
	length =0;
	front = NULL;		
	back = NULL;	
}

List::~List()
{
	//delete nodes from back
	Node *temp1 = back; 
	while(temp1 != 0)
	{
		Node *temp2 = temp1;
		temp1 = temp1->GetBlink();
		delete temp2;
	}
	front = NULL;
	back = NULL;
}

int List::Insert(int payload)
{
	//check for full
	if(length == capacity)
	{
		cout << "Error. Full list"<<endl;
		return -1;
	}

	// create a new node and set its payload
	Node *current = new Node();
	current->SetPayload(payload);
	
	//list empty
	//both front an back point to node
	//front's and back's flinks and blinks = NULL
	if(length == 0)
	{
		current->SetBlink(NULL);
		current->SetFlink(NULL);
		front = back = current;
		length ++;
		return 1;
	}

	//if it is not empty
	else 
	{
		//if we push data that is less than front, it always becomes front
		//PUSH AT FRONT
		if(current->GetPayload() < front->GetPayload())
		{
			//set temporary reference node
			Node *temp_front = front;
				
			front = current;
			temp_front->SetBlink(front);
			current->SetFlink(temp_front); //front instead of current?
			current->SetBlink(NULL);				//front instead of current?
			length++;
			return 1;
		}

		//if the data to be pushed is > than back, just push at back
		//PUSH AT BACK
		if(current->GetPayload() > back->GetPayload())
		{
			Node *temp_back = back;
			back = current;
			temp_back->SetFlink(back);
			current->SetBlink(temp_back);
			current->SetFlink(NULL);
			length++;
			return 1;
		}

			//while the data to be pushed >= front && front < last data on list 
			//PUSH at MIDDLE
			//reference_node < back is to reinforce check
			Node *reference_node = front; 
			while(current->GetPayload() >= reference_node->GetPayload() && reference_node->GetPayload() < back->GetPayload())
			{
				
				//first check for duplicates
				if(current->GetPayload() == reference_node->GetPayload())
				{
					cout<< payload << " already exist on list" << endl;
					return -1;
				}
				
				//check if data that follows reference data (temp_front) right away is > data to be pushed 
				//i.e. looking for a stop node before which the data should be inserted
				//if the above statement is true; insert the data to be pushed right before our reference data
				Node *flink_from_referenceNode = reference_node->GetFlink();
				if(current->GetPayload() < flink_from_referenceNode->GetPayload())
				{
				
					reference_node->SetFlink(current);
					current->SetBlink(reference_node);
					current->SetFlink(flink_from_referenceNode);
					flink_from_referenceNode->SetBlink(current);
					length ++;
					return 1;

				}

				else
				{
					reference_node = reference_node->GetFlink();
				}

			}//end loop
	}
	return 0;
}//end insert

//remove assumes that list is sorted already (should be)
int List::Remove(int payload)
{
	// check for empty
	if(length == 0)
	{
		cout<<"empty list, nothing to be removed" << endl;
		return -1;
	}

	
	//create nodes
	Node *current = new Node;
	current->SetPayload(payload);
	Node *reference_node = new Node();

	//if there is only 1 element on list
	if(length == 1)
	{
		current=front=back;
		delete current;
		front = back = NULL;
		length --;
		return 1;
	}

	//check if data belongs to list
	if(current->GetPayload() < front->GetPayload() || current->GetPayload() > back->GetPayload())
	{
		cout<<payload<< " doesn't belong"<< endl;
		return 1;
	}

	//else check if the element should be removed from front, middle or back
	else
	{
				
		//REMOVE AT FRONT
		if(current->GetPayload() == front->GetPayload())
		{
			reference_node = front;
			front = front->GetFlink();
			front->SetBlink(NULL);
			delete reference_node;
			length--;
			return 1;
		}

		//REMOVE AT BACK
		else if(current->GetPayload() == back->GetPayload())
		{
			reference_node = back;
			back = back->GetBlink();
			back->SetFlink(NULL);
			delete reference_node;
			length--;
			return 1;
		}
		
		//REMOVE AT THE MIDDLE
		else
		{
			reference_node = front;
			//while reference node is not deleted and that its payload is less than data to be removed
			//need to check if reference_node exists to catch any error
			while(reference_node->GetPayload() < current->GetPayload())
			{
				reference_node = reference_node->GetFlink();
				if(reference_node->GetPayload() == current->GetPayload())
				{
					Node * temp = reference_node->GetFlink();
					temp->SetBlink(reference_node->GetBlink());
					(reference_node->GetBlink())->SetFlink(temp);
					reference_node->SetBlink(NULL);
					reference_node->SetFlink(NULL);
					delete reference_node;
					length--;
					return 1;
				}
				
			}
		}
				
	}
	return 0;
}//end remove

void List::Print(){
	// check for empty
	if(length == 0)
	{
		cout<<"empty list, nothing to print" << endl;
		return;
	}

	else
	{
		cout<<"straigthforward print:"<<endl;
	// walk list and print
	// start at front and use flinks
	Node *reference_node = front;
	while(reference_node != 0)
	{
		cout << reference_node->GetPayload() << "  ";
		reference_node = reference_node->GetFlink();
	}
	cout<<endl;
	}
	return;
	
}


void List::ReversePrint(){
	// check for empty
	if(length ==0)
	{
		cout<<"empty list" << endl;
		return;
	}

	else
	{
		cout<<"backwards print: "<<endl;
	// walk list and print
	// start at back and use blinks
	Node *reference_node = back;
	while(reference_node != 0)
	{
		cout << reference_node->GetPayload() << "  ";
		reference_node = reference_node->GetBlink();
	}
	cout<<endl;
	}
	return;
}