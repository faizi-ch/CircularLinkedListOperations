#include <stdlib.h>
#include <conio.h>
#include <iostream>
using namespace std;

void MainMenu();
void CreateNode();
void SearchNode();
void ModifyNode();
void DisplayLinkedList();
void DeleteNode();
void ReverseList();


struct node
{
	int data;
	node *link;
}; node *first = NULL, *last = NULL, *newNode, *current, *neXt, *temp, *pre;

void main()
{

	bool check = false;

	newNode = new node;
	cout << "Enter data: ";
	cin >> newNode->data;
	newNode->link = newNode;
	last = newNode;

	while (1)
	{
		system("CLS");
		DisplayLinkedList();

		cout << "\nWanna add more [y/n]: ";
		char ch = _getch();
		if (ch == 'y' || ch == 'Y')
			CreateNode();

		else if (ch == 'n' || ch == 'N')
		{
			check = true;
			break;
		}

		else
			cout << "\aWRONG ENTRY!!!";
		
	}
	if (check)
	{
		//DisplayLinkedList();
		MainMenu();
	}
	cout << endl;
	system("pause");
}
void MainMenu()
{
	system("CLS");
	cout << "\n\n1. Create Nodes in the list\n2. Search in the list\n3. Modify data in a node in the list\n4. Delete node in the list\n5. Reverse the list\n6. Exit\n\nEnter your choice:\n";
	char ch = _getch();
	switch (ch)
	{
	case '1':
	{
		CreateNode();
		break;
	}
	case '2':
	{
		SearchNode();
		break;
	}
	case  '3':
	{
		ModifyNode();
		break;
	}
	case  '4':
	{
		DeleteNode();
		break;
	}
	case  '5':
	{
		ReverseList();
		break;
	}
	case '6':
		exit(0);
		break;
	default:
		cout << "\aWRONG ENTRY!!!";
	}

}
void CreateNode()
{
	system("CLS");
	cout << "\n\n1. Create Node at the start of the list\n2. Create Node at the middle of the list\n3. Create Node at the end of the list\n\nEnter your choice:\n";
	char ch = _getch();
	if (ch == '1')
	{
		newNode = new node;
		cout << "\nEnter data: \n";
		cin >> newNode->data;
		if (last == NULL)
		{
			first = newNode;
			last = newNode;
		
		}
		else
		{
			newNode->link = last->link;
			last->link = newNode;
		}

	}
	else if (ch == '2')
	{
		cout << "Current list:\n";
		DisplayLinkedList();

		cout << "\nAfter which integer you wanna insert data? ";
		int n;
		cin >> n;

		bool check = false;
		current = last->link;
		while (current != last)
		{
			current = current->link;
			if (n == current->data)
			{
				check = true;
				break;
			}

		}
		//temp = current;
		//current = current->link;
		if (check)
		{
			newNode = new node;
			cout << "\nEnter data: \n";
			cin >> newNode->data;
			newNode->link = current->link;
			current->link = newNode;
		}
		else
			cout << "\n\a" << n << " is not in the list!";
		if (last == NULL)
		{
			last = newNode;
		}
	}
	else if (ch == '3')
	{
		newNode = new node;
		cout << "Enter data: \n";
		cin >> newNode->data;
		newNode->link = last->link;

		if (last == NULL)
		{
			first = newNode;
			last = newNode;
		}
		//else
		/*{
		last->link = newNode;
		last = newNode;
		}*/

		last->link = newNode;
		last = newNode;
	}
	else
		cout << "\aWRONG ENTRY!!!";

}
void SearchNode()
{
system("CLS");
cout << "Enter node data which you wanna search: ";
int n;
cin >> n;

bool check = false;
int count = 0;
current = last->link;
while (current != last)
{
count++;
if (n == current->data || n == last->data)
{
check = true;
break;
}
current = current->link;
}
//temp = current;
//current = current->link;
if (check)
{
cout << n << " is found in node " << count << ".";
}
else
cout << "\n\a" << n << " is not in the list!";

cout << "\n\nDo you wanna search more? [y/n]: ";
char c = _getch();
if (c == 'y' || c == 'Y')
{
SearchNode();
}
else
MainMenu();
}
void ModifyNode()
{
system("CLS");
DisplayLinkedList();
cout << "\nWhich node data you wanna modify: ";
int n;
cin >> n;

bool check = false;
current = first;
while (current != NULL)
{
if (n == current->data)
{
check = true;
break;
}
current = current->link;
}

if (check)
{
cout << "Enter new data: ";
int nn;
cin >> nn;
current->data = nn;

cout << "\nData has been successfully modified!";

cout << "\nAfter modification:\n";
DisplayLinkedList();
}
else
cout << "\n\a" << n << " is not in the list!";

cout << "\n\nDo you wanna modify more? [y/n]: ";
char c = _getch();
if (c == 'y' || c == 'Y')
{
ModifyNode();
}
else
MainMenu();
}
void DisplayLinkedList()
{
	current = last->link;
	
	/*while (current != last)
	{
		cout << current->data << " ";
		current = current->link;
	}
	cout << last->data << " ";*/

	do 
	{
		cout << current->data << " ";
		current = current->link;
	} while (current != last->link);
}
void DeleteNode()
{
system("CLS");
DisplayLinkedList();
cout << "\nWhich node data you wanna delete: ";
int n;
cin >> n;

bool check = false;
current = last->link;

do 
{
	if (n == current->data)
	{
		check = true;
		break;
	}
	current = current->link;
} while (current != last->link);

if (check)
{
if (n == last->link->data)
{
temp = last->link;
last->link = last->link->link;
delete temp;
}
else if (n == last->data)
{
current = last->link;
do 
{
	pre = current;
	current = current->link;
} while (current != last);

pre->link = last->link;

temp = last;
last = pre;
delete temp;
}
else
{
bool c = false;

current = last->link;
do 
{
	if (n==current->data)
	{
		c = true;
		break;
	}
	pre = current;
	current = current->link;
} while (current != last);

if (c)
{
	temp = pre->link;
	pre->link = current->link;
	delete temp;
}
else
	cout << "\a\n" << n << " is not in the list!\n";

}

cout << "\nAfter deletion:\n";
DisplayLinkedList();
}
else
cout << "\a\n" << n << " is not in the list!\n";

cout << "\n\nDo you wanna delete more? [y/n]: ";
char c = _getch();
if (c == 'y' || c == 'Y')
{
DeleteNode();
}
else
MainMenu();

}
void ReverseList()
{
system("CLS");
DisplayLinkedList();

cout << "\nDo you wanna reverse this list? [y/n]";
char c = _getch();
if (c == 'y' || c == 'Y')
{
pre = current = neXt = last->link;

do 
{
	pre = current;
	current = neXt;
	neXt = current->link;
	current->link = pre;
} while (neXt!=last->link);

/*
while (neXt != NULL)
{
pre = current;
current = neXt;
neXt = current->link;
current->link = pre;
}*/
last->link = current;
//first = current;

cout << "\n\nReversed list:" << endl;
DisplayLinkedList();

cout << "\n\nPress any key to go back to Main Menu...";
if (_getch())
{
MainMenu();
}
}
else
MainMenu();
}


