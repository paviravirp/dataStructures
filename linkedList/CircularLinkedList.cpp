#include <iostream>
using namespace std;
struct node
{
    int value;
    struct node *next;
};

class CircularLinkedList
{
private:
    node *head;

public:
    CircularLinkedList()
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
            temp->next = head;
            return;
        }
        node *current = head;
        do
        {
            current = current->next;
        } while (current->next != head);

        current->next = temp;
        temp->next = head;
    }

    void addInSortedOrder(int num)
    {
        node *temp = new node();
        temp->value = num;
        temp->next = NULL;
        if (head == NULL)
        {
            temp->next = head;
            head = temp;
            return;
        }
        node *current = head;
        do
        {
            current = current->next;
        } while(current->value > num && current->next != head);
        temp->next = current->next;
        current->next = temp;
        if (head->value > num)
        {
            head = temp;
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
        cout << current->value;
        do {
            current = current->next;
            cout << " ----> " << current->value;
        } while(current->next != head);
        cout << "\n";
    }

    int listLength()
    {
        node *current = head;
        int count = 0;
        if(head == NULL) {
            return count;
        }
        do
        {
            count++;
            current = current->next;
        } while (current != head);
        return count;
    }

    void deleteNodeN(int num) {
        node *current = head;
        do {
            current = current->next;
        } while(current->next->value != num && current->next != head);
        if(current->next->value == num) {
            node *temp = current->next->next;
            if(current->next == head)
                head = temp;
            free(current->next);
            current->next = temp;
        }
    }

    void deleteList()
    {
        node *current = head;
        node *temp;
        do
        {
            temp = current->next;
            free(current);
            current = temp;
        } while (current != head);
        head->next = head;
        head = NULL;
    }
};

int main()
{
    CircularLinkedList numbers;
    cout << "Length of the list: " << numbers.listLength() << "\n";
    numbers.addNode(1);
    numbers.addNode(2);
    numbers.addNode(4);
    numbers.printList();
    numbers.addInSortedOrder(3);
    numbers.printList();
    numbers.addInSortedOrder(0);
    numbers.printList();
    cout << "Length of the list: " << numbers.listLength() << "\n";
    numbers.deleteNodeN(3);
    numbers.printList();
    numbers.deleteNodeN(0);
    numbers.printList();
    numbers.deleteNodeN(4);
    numbers.printList();
    numbers.deleteList();
    numbers.printList();
}