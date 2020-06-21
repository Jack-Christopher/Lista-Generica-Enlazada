#include <iostream>
#include "node.h"
#include "linkedlist.h"

using namespace std;

int main()
{
	//Se declara un objeto de clase LinkedList
	LinkedList<float> l1;
	
	//Se declaran cinco objetos de Node y
	// se inicializan con valores
	Node <float> n1 (25.235);
	Node <float> n2 (72.314);
	Node <float> n3 (16.352);
	Node <float> n4 (84.517);
	Node <float> n5 (725.28);
	Node <float> n6 (345.26);
	Node <float> n7 (45.58);
	Node <float> n8 (7.75);

	
	//Se insertan los elementos en l1
	l1.insertAtHead(n1);
	l1.insertAtHead(n2);
	l1.insertAtHead(n3);
	l1.insertAtHead(n4);
	l1.insertAtHead(n5);
	l1.insertAtHead(n6);
	l1.insertAtHead(n7);
	l1.insertAtHead(n8);

	cout<< "La lista de elementos es: "<<endl;
	l1.print();
	
	//Se elimina los elementos de los indices 4 y 2 (3 y 1 para el computador)
	l1.removePos(3);
	l1.removePos(1);
	cout<<"\nLos elementos numero 4 y 2 han sido eliminados "<<endl;
	cout<< "La nueva lista de elementos es: "<<endl;
	l1.print();	
	
	
	LinkedList<float>::LLIterador it(l1,2);
	cout<< it<<endl;
	it++;
	cout<< it<<endl;
	
	cout<<"Next test\n";
	
	it = l1.begin();
	cout<< it<<endl;
	it++;
	cout<< it<<endl;
	
	
		
	return 0;
}
