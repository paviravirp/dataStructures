#include <iostream>
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
            current = temp;
        }
        free(head);
    }
};

int main()
{
    SinglyLinkedList numbers;
    cout << "Length of the list: " << numbers.listLength() << "\n";
    numbers.addNode(1);
    numbers.addNode(2);
    numbers.addNode(4);
    numbers.printList();
    numbers.addInSortedOrder(3);
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