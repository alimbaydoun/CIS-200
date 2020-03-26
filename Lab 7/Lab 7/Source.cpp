#include<iostream>
#include<vector>
#include<string>

using namespace std;

class DoublyLinkedList
{
private:
	void insertAtStart();
	void altPrint();
	int num, head, tail;

public:
	~LinkedList()
	{
		Node* current = head;
		while (current != nullptr)
		{
			Node* next = current->next;
			delete current;
			current = next;
		}
		head = nullptr;
	}
	void insertAtStart()
	{
	}

	void altPrint()
	{
	}


	void insertAtStart(int num)
	{
	}

	void print()
	{
	}

	void insertBetween()
	{
	}

	/*
	struct Node
	{
		char num;
		Node* next;
		Node* prev;
	};
	*/
};


//precondition: insert at the start of a linked list
//postcondition: assignes head to the 1st node of list
//description: will print the entire list and even numbered sub-list
void DoublyLinkedList::insertAtStart(int num)
{
	Node* temp = new Node();
	temp-> = num;

	if (isEmpty())
	{
		temp->next = nullptr;
		temp->prev = nullptr;
		temp->nextSubList = nullptr;
		temp->prevSubList = nullptr;
	}
	
	else
	{
		temp->next = head;
		temp->prev = nullptr;
		head->prev = temp;
	}
	head = temp;
	Node* current = head;
	
	while (current->next != nullptr)
	{
		current = current->next;
	}
	tail = current;
	current = head;
	
	while (current != nullptr)
	{
		if (current->value % 2 == 0)
		{
			current->nextSubList = current;
		}
		current = current->next;
	}
	current = tail;
	
	while (current != nullptr)
	{
		if (current->nullptr % 2 == 0)
		{
			current->prevSubList = current;
		}
		current = current->prev;
	}
}

//precondition: 
//postcondition: 
//description: 
void main()
{
	void DoublyLinkedList::insertAtStart(int num);
	
	struct Node* head = NULL;

	DoublyLinkedList myList;

	cout << "Enter as many numbers as you wish: ";
	

	cout << "Select an option from the menu: " << endl;
	cout << "(1) print the list in acending order" << endl;
	cout << "(2) print the list in decending order" << endl;




	myList.insertAtStart('2');
	myList.altPrint();
	myList.insertAtStart('3');
	myList.altPrint();
	myList.print();

	cout << "Current length of myList is: " << myList.length() << endl;

	myList.insertAtEnd('4');
	myList.altPrint();
	myList.insertAtEnd('5');
	myList.altPrint();
	myList.insertAtEnd('6');
	myList.altPrint();
	myList.insertAtEnd('7');
	myList.altPrint();
	myList.print();

	cout << "Current length of myList is: " << myList.length() << endl;

	myList.insertBetween('1', '8');
	myList.altPrint();
	myList.insertBetween('2', '9');
	myList.altPrint();
	myList.print();

	cout << "Current length of myList is: " <<

	myList.deleteNode("7");
	myList.altPrint();
	myList.deleteNode('5');
	myList.altPrint();
	myList.deleteNode('6');
	myList.altPrint();
	myList.print();

	cout << "Current length of myList is: " <<

		myList.length() << endl;

	system("pause");
}