#include<iostream>
#include"linked_list.h"

int main()
{
	List<int> l1;
	l1.push_back(18);
	l1.push_back(20);
	l1.push_back(15);
	l1.push_front(7);
	l1.insert(2,100);
	l1.push_back(22);
	l1.push_back(6);
	l1.push_back(30);
	l1.display();
	std::cout<<std::endl;
	l1.pop_front();
	l1.display();
	std::cout<<std::endl;
	l1.pop_back();
	l1.display();
	std::cout<<std::endl;
	l1.remove(4);
	l1.display();
        std::cout<<std::endl;
	List<int> l2(l1);
	l2.push_back(25);
	l2.push_front(25);
	l2.display();
	std::cout<<std::endl;
	l1.display();
	std::cout<<std::endl;
	l1 = l2;
	l1.display();
        std::cout<<std::endl;
	return 0;
}
