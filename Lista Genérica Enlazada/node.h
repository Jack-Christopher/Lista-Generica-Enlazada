using namespace std;

template <class N>
class Node
{
	N elem;
	Node *next;
		
	public:
			
		Node();
		Node(N elem);
		N getElem() const;
		void setElem(const N elemento);
		Node *getNext() const;
		void setNext(Node *n);
		
};

template <class N>
Node<N>::Node()
{
	elem = NULL;
	next = NULL;
}


template <class N>
Node<N>::Node(N elemento)
{
	elem = elemento;
	next = NULL;
}

template <class N>
N Node<N>::getElem() const
{
	return elem;
}

template <class N>
void Node<N>::setElem(const N elemento) 
{
	elem = elemento;
}

template <class N>
Node<N>* Node<N>::getNext() const
{
	return next;
}

template <class N>
void Node<N>::setNext(Node *n)
{
	next = n;
}

