#include<iostream>
#include <algorithm>	//for operator=()

template <typename T> 
struct Node
{
	T data;
	Node<T>* next;	
};

template <typename T>
class List
{
private:
	Node<T> *head, *tail;

public:
//constructors
	List();
	List(const List& obj);
	~List();


//operator=()
	List<T>& operator=(const List<T>& obj);


//member functions
	void push_back(T data);
	void push_front(T data);
	void display();
	void insert(int position, T data);
	void pop_front();
	void pop_back();
	void remove(int position);
};

template <typename T>
	List<T>::List() 
	{
		head = NULL;
		tail = NULL;	
	}

template <typename T>
	void List<T>::push_back(T number)
	{
		Node<T> *temp = new Node<T>();
		temp->data = number;
		temp->next = NULL;

		if(!head) 
		{
			head = temp;
			tail = temp;
			temp = NULL;
	//		return this;
		} else {
			tail->next = temp;
			tail = temp;
			temp = NULL;
	//		return this;
			}
	}

template<typename T>
	void List<T>::push_front(T number)
	{
		Node<T> *temp = new Node<T>();
		temp->data = number;
		temp->next = NULL;
		if(!head)
		{
			head = temp;
			tail = temp;
			temp = NULL;
		} else {
			temp->next = head;
			head = temp;
			temp = NULL;
			}
	}

template <typename T>
	void List<T>::display()
	{
		Node<T> *temp = new Node<T>();
		temp = head;
		while(temp!=NULL)
		{
			std::cout<<temp->data<<" ";
			temp = temp->next;
		}
	}

template<typename T>
	void List<T>::insert(int position, T data)
	{
		Node<T>* temp = new Node<T>;
		Node<T>* cur;
		Node<T>* pre;
		cur = head;
		for(int i=1; i<position; i++)
		{
			pre = cur;
			cur = cur->next;
		}
		temp->data = data;
		pre->next = temp;
		temp->next = cur;

	}

template<typename T>
	void List<T>::pop_front()
	{
		Node<T>* temp = head;
		delete head;
		head = temp->next;
	}

template<typename T>
	void List<T>::pop_back()
	{
		Node<T>* pre;
		Node<T>* cur = head;
		while(cur->next != NULL)
		{
			pre = cur;
			cur = cur->next;
		}
		tail = pre;
		pre->next = NULL;
		delete cur;
	}


template<typename T>
	void List<T>::remove(int position)
	{	
		Node<T>* pre;
		Node<T>* cur = head;
		for(int i=1; i<position; i++)
		{
			pre = cur;
			cur = cur->next;
		}
		pre->next = cur->next;
		delete cur;
	}

template<typename T>
	List<T>::~List()
	{
		Node<T>* temp = new Node<T>();
		Node<T>* current;
		temp = head;
		if(head)
		{
			while(temp != 0)
			{
				current = temp;
				delete temp;
				temp = current->next;
			}
		}
	}

template<typename T>
	List<T>::List(const List<T>& obj)
	{
		head = NULL;
		Node<T>* temp = obj.head;
		while(temp != NULL)
		{
			push_back(temp->data);
			temp = temp->next;
		}
	}

template<typename T>
	List<T>& List<T>::operator=(const List<T>& obj)
	{
		List<T> temp(obj);
		std::swap(temp.head, head);
		return *this;
	}
