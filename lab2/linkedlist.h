#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include <ostream>
#include <iostream>
using namespace std;

class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void add(char ch);
	bool find(char ch);
	bool del(char ch);

	friend std::ostream& operator<<(std::ostream& out, const LinkedList& list);

private:
	struct node
    {
        char * data;
        node * next;

        node()
        {
            data = nullptr;
            next = nullptr;
        }

        node(char character)
        {
            data = new char(character);
            next = nullptr;
        }

        ~node()
        {
            if(data)
            {
                delete data;
            }

            data = nullptr;
            next = nullptr;
        }
    };

    node * head;
    node * tail;
};

#endif // _LINKED_LIST_
