#include<iostream>
#include<algorithm>
#include"list.h"

using namespace std;

int main()
{
	// Create a linked list to implement List class. Size Specified
	List slist(100);
	List unlimited;

	// integers to use for linked list payloads
	// 	they must be unique, will be 1-100
	int payloads[100];
	for (int i=0;i<100;i++)
		payloads[i] = i+1;

	// shuffle the values in the array to randomize
	//	they must be inserted randomly
    	random_shuffle(&payloads[0],&payloads[100]);

	// display shuffled payloads
	cout<< "data: " <<endl;
	for (int i=0;i<100;i++)
		cout<< payloads[i] << "  ";
	cout<<endl;

	// Loop inserting the payloads (array contents [0] to [99])
	for(int i =0; i<100; i++)
	{
		slist.Insert(payloads[i]);
	}

	
	// Print the contents of the list
	slist.Print();

	// Optionally print the contents of the list 
	// in reverse to test your blinks
	slist.ReversePrint();
	
	// Try to remove something that is not on list (ex. 200)
	slist.Remove(200);

	// Print the contents of the list
	slist.Print();

	// Remove the contents of the list in the reverse order they
	//	were created.  (array contents [99] to [0])
	for(int i = 0; i <= 99; i++)
	{
		int index = 99 - i;
		int remove = payloads[index];
		slist.Remove(remove);
		i = 99-index;
	}

	// Print the contents of the list
	slist.Print();

	//test unlimitted list
	for(int i =0; i<100; i++)
	{
		unlimited.Insert(payloads[i]);
	}

	unlimited.Insert(101); unlimited.Insert(102);
	unlimited.Print(); unlimited.ReversePrint();
	unlimited.Remove(200);

	// Try to insert something that is not unique (ex. 1 again)
	unlimited.Insert(1);

	return 0;
}
