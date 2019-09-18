#include <iostream>
#include <stdlib.h>
using namespace std;
struct node
{
    int value;
    struct node *next;
};

class SinglyLinkedList
{
private:
    node *head;

public:
    SinglyLinkedList()
    {
        head = NULL;
    }

    void addNode(int num)
    {
        node *temp = new node();
        temp->value = num;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            node *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = temp;
        }
    }

    void addInSortedOrder(int num)
    {
        node *temp = new node();
        temp->value = num;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
        }
        if (head->value > num)
        {
            temp->next = head;
            head = temp;
        }
        else
        {
            node *current = head;
            while (current->next->value < num)
            {
                current = current->next;
            }
            temp->next = current->next;
            current->next = temp;
        }
    }

    void printList()
    {
        node *current = head;
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }
        cout << "the list : ";
        while (current->next != NULL)
        {
            cout << current->value << " ----> ";
            current = current->next;
        }
        cout << current->value << "\n";
    }

    int listLength()
    {
        node *current = head;
        int count = 0;
        while (current != NULL)
        {
            count++;
            current = current->next;
        }
        return count;
    }

    void deleteNodeN(int num)
    {
        node *current = head;
        if (head->value == num)
        {
            head = current->next;
        }
        else
        {
            while (current->next != NULL && current->next->value != num)
            {
                current = current->next;
            }
            if (current->next->value == num)
            {
                node *temp = current->next->next;
                free(current->next);
                current->next = NULL;
                current->next = temp;
            }
        }
    }

    void deleteList()
    {
        node *current = head;
        node *temp;
        while (current != NULL)
        {
            temp = current->next;
            free(current);
            current = NULL;
            current = temp;
        }
        free(head);
        head = NULL;
    }

    void modularNodeLastFromBeginning(int k) {
        int i = 1;
        node *modularNode = NULL;
        for(node *temp = head; temp != NULL; temp = temp->next) {
            if(i%k == 0) {
                modularNode = temp;
            }
            i++;
        }
        cout << "Last Modular node from the beginning: " << modularNode->value << "\n";
    }

    void modularNodeFromEnd(int k) {
        int i = 0;
        node *modularNode = head;
        node *fastPtr = head;
        while(i < k) {
            fastPtr = fastPtr->next;
            i++;
        }
       while(fastPtr != NULL) {
            modularNode = modularNode->next;
            fastPtr = fastPtr->next;
        }
        
        cout << "First Modular node from the end: " << modularNode->value << "\n";
    }

    void fractionalNode(int k) {
        node *slowPtr = head;
        node *fastPtr = head;
        int i = 1;
        while(fastPtr != NULL) {
            if(i % k == 0)
                slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
            i++;
        }
        cout << k << "th Fractional node :" << slowPtr->value << "\n";
    }

    void evenBeforeOdd() {
        node *odd = NULL;
        node *even = NULL;
        node *current = head;
        node *end = head;
        while(end->next != NULL) {
            end = end->next;
        }
        node *temp = end;
        while(current != end && current->value % 2 != 0) {
            temp->next = current;
            current = current->next;
            temp->next->next = NULL;
            temp = temp->next;
        }

        if(current->value % 2 == 0) {
            head = current;
            node *prev = current;
            while(current != end) {
                if(current->value % 2 == 0) {
                    prev = current;
                    current = current->next;
                }
                else {
                    temp->next = current;
                    prev->next = current->next;
                    current->next = NULL;
                    current = prev->next;
                    temp = temp->next;
                }
            }
        }
    }
};

int main()
{
    SinglyLinkedList numbers;
    cout << "Length of the list: " << numbers.listLength() << "\n";
    numbers.addNode(1);
    numbers.addNode(2);
    numbers.addNode(4);
    numbers.addNode(5);
    numbers.addNode(6);
    numbers.addNode(7);
    numbers.addNode(8);
    numbers.addNode(9);
    numbers.addNode(10);
    numbers.addNode(11);
    numbers.addNode(12);
    numbers.printList();
    numbers.addInSortedOrder(3);
    numbers.addInSortedOrder(0);
    numbers.printList();
    cout << "Length of the list: " << numbers.listLength() << "\n";
    numbers.modularNodeLastFromBeginning(3);
    numbers.modularNodeFromEnd(3);
    numbers.fractionalNode(2);
    numbers.fractionalNode(3);
    numbers.evenBeforeOdd();
    numbers.printList();
    numbers.deleteNodeN(3);
    numbers.printList();
    numbers.deleteNodeN(0);
    numbers.printList();
    numbers.deleteNodeN(4);
    numbers.printList();
    numbers.deleteList();
    numbers.printList();
}