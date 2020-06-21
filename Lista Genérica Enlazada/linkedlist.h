
template <class L>
class LinkedList
{
	int size;
	Node<L> *head;
	
	public:
		
		class LLIterador
		{
			Node<L> *iter;
			LinkedList<L> lista;
			int pos;
	
			public:
		
				LLIterador(LinkedList<L> lista);
				LLIterador(Node<L> *n);
				LLIterador(LinkedList<L> lista, int posicion);
				bool hasNext();
				Node<L>* Next();
				LLIterador* first();
		        		
				LLIterador& operator = (Node<L> *ptr);
				L operator *();
		
				void operator ++ (int)
				{
					iter = iter->getNext();
				}
		
				friend ostream& operator << (ostream &o,const LLIterador &lli)
				{
					o << lli.iter->getElem() ;
    				return o;
				}
		
		};
	
	
	public:

		LinkedList();
		LinkedList(const LinkedList &copia);

		void insertAtHead(const Node<L> &n);
		void insertAtTail(const Node<L> &n);
		void insertPos(const Node<L> &n, int pos);
		void removeHead();
		void removeTail();
		void removePos(const int pos);
		void print();
		LLIterador begin();
		LLIterador end();
		
		Node<L> *getHead();
		~LinkedList();
		
					
};



















template <class L>
LinkedList<L>::LLIterador::LLIterador(LinkedList<L> lista)
{
	iter = lista.getHead();
}

template <class L>
LinkedList<L>::LLIterador::LLIterador(Node<L> *n)
{
	iter = n;
}


template <class L>
LinkedList<L>::LLIterador::LLIterador(LinkedList<L> lista, int posicion)
{
	iter = lista.getHead();
	if (posicion != 0) 
	{
		while (iter != NULL && posicion)
		{
			iter = iter->getNext();
			posicion--;
		}
	}
}


template <class L>
bool LinkedList<L>::LLIterador::hasNext()
{
	if (iter->getNext() != NULL)		 
	{
		return true;
	}
	return false;
}

template <class L>
Node<L>* LinkedList<L>::LLIterador::Next()
{
	return iter->getNext();
}




template <class L>
typename LinkedList<L>::LLIterador* LinkedList<L>::LLIterador::first()
{
	iter = lista.getHead();
}


template <class L>
typename LinkedList<L>::LLIterador& LinkedList<L>::LLIterador::operator = (Node<L> *ptr)
{
	iter = ptr;
}

template <class L>
L LinkedList<L>::LLIterador::operator *()
{
	return iter->getElem();
}












//Constructor por defecto
template <class L>
LinkedList<L>::LinkedList()
{
	head = NULL;
	size = 0;
}

//Constructor copia
template <class L>
LinkedList<L>::LinkedList(const LinkedList &copia)
{
	size = copia.size;
	head  = copia.head;
}


//Eliminar el "head" del arreglo:
template <class L>
void LinkedList<L>::removeHead()
{
	Node<L> *temp = head;
    head = head->getNext();
    delete temp;
    return;
}


//Eliminar el último nodo del arreglo:
template <class L>
void LinkedList<L>::removeTail()
{
	Node<L> *puntero = head;
	Node<L> *temp = puntero;
	while(puntero->getNext()!=NULL)
	{
		temp = puntero;
		puntero = puntero->getNext();
	}
	    
	delete puntero;
	temp->setNext(NULL);
}

//Eliminar un nodo de cualquier posición del arreglo:
template <class L>
void LinkedList<L>::removePos(const int pos)
{
	int posicion = pos;
	
	if(posicion == 0 )
    {
        Node<L> *temp = head;
        head = head->getNext();
        delete temp;
        return;//Para no ejecutar los demás pasos
    }
    
    Node<L> *puntero = head;
    while(puntero->getNext()!=NULL && --posicion)
       	puntero = puntero->getNext();
		
    if(puntero->getNext()==NULL)  return;
	    
    Node<L> *temp = puntero->getNext();
    puntero->setNext(puntero->getNext()->getNext());
	delete temp;
	
    size--;

}

template <class L>
void LinkedList<L>::print()
{
	//Se itera sobre todos los elementos y se imprimen sus datos miembro
	Node<L> *puntero = head;
	int k = 1;
	while(puntero)
    {
    	cout<< "Elemento "<< k<< ": "<< puntero->getElem()<<endl;
        puntero = puntero->getNext();
        k++;
    }
}

//Insertar un nodo en la posición adecuada (para que esté ordenado)

template <class L>
void LinkedList<L>::insertAtHead(const Node<L> &n)
{
	Node<L> *new_node = new Node<L>(n);
	Node<L> *puntero = head;
	if (size == 0) 
	{
		head = new_node;
		size++;
		return;
	}
	
	new_node->setNext(head);
	head = new_node;
	
	size++;
}

template <class L>
void LinkedList<L>::insertAtTail(const Node<L> &n)
{
	Node<L> *new_node = new Node<L>(n);
	Node<L> *puntero = head;
	if (size == 0) 
	{
		head = new_node;
		size++;
		return;
	}
		
	while (puntero->getNext() != NULL)
	{
		puntero = puntero->getNext();
    }
    puntero->setNext(new_node);
		
	size++;	
}

template <class L>
void LinkedList<L>::insertPos(const Node<L> &n, int pos)
{
	Node<L> *new_node = new Node<L>(n);
	
	if(pos==0)
    {
        new_node->setNext(head);
        head = new_node;
        return;
    }
    pos--;
    
    Node<L> *puntero = head;
    while(puntero != NULL && --pos)
    {
        puntero = puntero->getNext();
    }
    
    if(puntero == NULL)
    return;//La posición más grande que la longitud de la lista
    new_node->setNext(puntero->getNext());
    puntero->setNext(new_node);
	
	size++;
}


template <class L>
typename LinkedList<L>::LLIterador LinkedList<L>::begin()
{
	LLIterador ite(head); 
	return ite;
}


template <class L>
typename LinkedList<L>::LLIterador LinkedList<L>::end()
{
	LLIterador ite(head);
		
	if (size != 0) 
	{
		while ( LinkedList::LLIterador::iter != NULL)
		{
			ite = ite->Next();
		}
	}
	 
	return ite;
}


template <class L>
Node<L>* LinkedList<L>::getHead()
{
	return head;
}

//Destructor
template <class L>
LinkedList<L>::~LinkedList()
{
	Node<L> *puntero = head;
	Node<L> *siguiente2 = NULL;
	
	//Se libera la memoria asignada con new
	while(puntero != NULL)
    {
        siguiente2 = puntero->getNext();
        delete puntero;
        puntero = siguiente2;
    }
}






















