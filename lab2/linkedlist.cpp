#include "linkedlist.h"


//implementations for the member functions of LinkedList class

/*
 * default constructor for the list ADT
 */
LinkedList::LinkedList() {
    head = nullptr;

}


/*
 * destructor for the list. When this is called all dynamic data will be
 * released
 */
LinkedList::~LinkedList() {
    // we have to change this loop we need to avoid while loops
    node *curr = head;
    while (curr) {
        head = head->next;
        delete curr;
        curr = head;
    }
    head = nullptr;
}

/*
 * override the stream << operator to have it print all the data in our list.
 */
ostream &operator<<(ostream &out, const LinkedList &list) {
    LinkedList::node *curr;

    for (curr = list.head; curr; curr = curr->next) {
        out << *(curr->data) << endl;
    }

    return out;
}

/*
 * Add a new character to the linked list by traversing to the end of list
 * adding the newly created node to the end of the list.
 * INPUT: char ch - a character to add
 * OUTPUT: none
 * */
void LinkedList::add(char ch) {
    node *newNode = new node(ch);
    node *curr = head;

    // list is empty? add the new node.
    if (!head) {
        head = newNode;
    }
    // list isn't empty, add it to the end.
    else {

        // move the head pointer to the end of the list
        while (curr->next) {
            curr = curr->next;
        }

        // append the new node to the end of the list.
        curr->next = newNode;
    }


}


bool LinkedList::find(char ch) {
    bool found = false;
    node *curr = head;

    // loop through our list while curr isn't null AND its data != ch
    while (curr && *curr->data != ch) {
        curr = curr->next;
    }

    if (curr) {
        found = true;
    }
    return found;
}


bool LinkedList::del(char ch) {

    node *curr = head;
    node *prev = nullptr;
    bool found = false;

    // empty list? return false.
    if (!head) {
        return found;
    } else {
        while (curr && *curr->data != ch) {
            prev = curr;
            curr = curr->next;
        }

        // if curr is null then we reached the end of the list without a match
        if (!curr) {
            return found;
        }

        if (curr == head) {
            head = head->next;
            found = true;
            delete curr;
        } else {
            prev->next = curr->next;
            found = true;
            delete curr;
        }
    }

    return found;

}

