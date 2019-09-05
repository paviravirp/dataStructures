#include <iostream>
using namespace std;
struct node
{
    int value;
    struct node *next;
    struct node *prev;
};

class DoublyLinkedList
{
private:
    node *head;

public:
    DoublyLinkedList()
    {
        head = NULL;
    }

    void addNode(int num)
    {
        node *newNode = new node();
        newNode->value = num;
        newNode->next = NULL;
        newNode->prev = NULL;
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            node *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            newNode->prev = current;
            current->next = newNode;
        }
    }

    void addInSortedOrder(int num)
    {
        node *temp = new node();
        temp->next = NULL;
        temp->prev = NULL;
        temp->value = num;
        if (head == NULL)
        {
            head = temp;
        }
        if (head->value > num)
        {
            head->prev = temp;
            temp->next = head;
            head = temp;
        }
        else
        {
            node *current = head;
            while (current->value < num)
            {
                current = current->next;
            }
            temp->next = current;
            temp->prev = current->prev;
            current->prev->next = temp;
            current->prev = temp;
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
        cout << "List : ";
        while (current->next != NULL)
        {
            cout << current->value << " ----> ";
            current = current->next;
        }
        cout << current->value << "\n";
    }

    void printListReverse()
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }
        cout << "Reverse of List : ";
        node *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        cout << current->value;
        while (current->prev != NULL)
        {
            current = current->prev;
            cout << " <---- " << current->value;
        }
        cout << "\n";
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
            head->prev = NULL;
            free(current);
            return;
        }
        while (current->next != NULL && current->value != num)
        {
            current = current->next;
        }
        if (current->value == num)
        {
            if (current->next != NULL)
            {
                current->next->prev = current->prev;
                current->prev->next = current->next;
            }
            else
            {
                current->prev->next = NULL;
            }
            free(current);
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
            current = temp;
        }
        free(head);
    }
};

int main()
{
    DoublyLinkedList numbers;
    cout << "Length of the list: " << numbers.listLength() << "\n";
    numbers.addNode(1);
    numbers.addNode(2);
    numbers.addNode(4);
    numbers.printList();
    numbers.addInSortedOrder(3);
    numbers.addInSortedOrder(0);
    numbers.printList();
    cout << "Length of the list: " << numbers.listLength() << "\n";
    numbers.printListReverse();
    numbers.deleteNodeN(3);
    numbers.printList();
    numbers.deleteNodeN(0);
    numbers.printList();
    numbers.deleteNodeN(4);
    numbers.printList();
    numbers.printListReverse();
    numbers.deleteList();
    numbers.printList();
}