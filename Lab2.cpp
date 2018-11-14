#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <list>

using namespace std;



struct Node
{
	string driver;
	string position;
	string busnumb;
	Node *Next, *Prev;
};
template <class T>
class Autopark
{
	Node *Head, *Tail;
public:
	Autopark() :Head(NULL), Tail(NULL) {};
	~Autopark();
	void Show();
	void Showbusposition();
	void Add(string driver, string position, string busnumb);
};
template <class T>
Autopark <T>::~Autopark()
{
	while (Head)
	{
		Tail = Head->Next;
		delete Head;
		Head = Tail;
	}
}
template <class T>
void Autopark<T>::Add(string driver, string position, string busnumb)
{
	Node *temp = new Node;
	temp->Next = NULL;
	temp->driver = driver;
	temp->position = position;
	temp->busnumb = busnumb;

	if (Head != NULL)
	{
		temp->Prev = Tail;
		Tail->Next = temp;
		Tail = temp;
	}
	else //Если список пустой
	{
		temp->Prev = NULL;
		Head = Tail = temp;
	}
}
template <class T>
void Autopark<T>::Show()
{
	Node *temp = Tail;
	temp = Head;
	string k = "IN ROUTE";
	while (temp != NULL)
	{
		cout << "||||||||||||||||||||||||||||||||||||||" << endl;
		cout << "|" << temp->driver << " " << temp->position << " " << temp->busnumb << " " << endl;
		temp = temp->Next;
	}
	cout << "||||||||||||||||||||||||||||||||||||||" << endl;
	cout << "\n";
};
template<class T>
void Autopark<T>::Showbusposition()
{
	Node *temp = Tail;
	temp = Head;
	string k = "IN ROUTE";
	string n = "IN PARK";
	cout << "Drivers in route: " << endl;
	while (temp != NULL)
	{
		if (temp->position == k) {
			cout << temp->driver << " " << temp->busnumb << " " << endl;
			temp = temp->Next;
		}
		else {
			cout << "Drivers in park: " << endl;
			while (temp != NULL) {
				if (temp->position == n) {
					cout << temp->driver << " " << temp->busnumb << " " << endl;
					temp = temp->Next;
				}
			}
			cin.get();
		}
	}
	cout << "\n";
};


int main()
{
	system("CLS");
	Autopark<string> park;
	park.Add("Knysh D.A", "IN ROUTE", "E564MT");
	park.Add("Kozlov G.A", "IN ROUTE", "A765CT");
	park.Add("Samoylov N.D", "IN ROUTE", "A001AA");
	park.Add("Ugulava R.G", "IN PARK", "K887AT");
	park.Add("Mitrovic M.D", "IN PARK", "A807ET");
	park.Show();
	park.Showbusposition();
	system("PAUSE");
	return 0;
}