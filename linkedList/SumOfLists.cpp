#include <iostream>
#include <stdlib.h>
using namespace std;
struct node
{
    int value;
    struct node *next;
};

class SumOfLists {
    private:
        node *head1, *head2;
    public:
        SumOfLists() {
            head1 = NULL, head2 = NULL;
        }
        void addNodeToList1(int num)
        {
            node *temp = new node();
            temp->value = num;
            temp->next = NULL;
            if (head1 == NULL)
            {
                head1 = temp;
            }
            else
            {
                node *current = head1;
                while (current->next != NULL)
                {
                    current = current->next;
                }
                current->next = temp;
            }
        }

        void addNodeToList2(int num)
        {
            node *temp = new node();
            temp->value = num;
            temp->next = NULL;
            if (head2 == NULL)
            {
                head2 = temp;
            }
            else
            {
                node *current = head2;
                while (current->next != NULL)
                {
                    current = current->next;
                }
                current->next = temp;
            }
        }

        void findSum() {
            node *current = head1;
            int list1Length = 1, list2Length = 1;
            int diff = 0;
            while(current->next != NULL)
                list1Length++;
            current = head2;
            while(current->next != NULL)
                list2Length++;
            if(list1Length <list2Length) {
                current = head2;
                head2 = head1;
                head1 = current;
                diff = list2Length - list1Length;
            } else {
                diff = list1Length - list2Length;
            }
            current = head1;
            while(diff-- > 0) {
                current = current->next;
            }

            int *carry = 0;
            node *result = NULL;
            addNumbersOfLists(current, head2, carry, result);
            if(list1Length < list2Length)
                diff = list2Length - list1Length;
            else
                diff = list1Length - list2Length;
            if(current != head1) {
                addRemainingList(head1, current, carry, result);
            }

            while(result->next != NULL) {
                cout << result->value << "---->";
            }
            cout << result->value;
        }

        node* addRemainingList(node *list1, node* current, int *carry, node* result) {
            if(current == head1)
                return NULL;
            result = new node();
            result->next = addRemainingList(head1->next, current, carry, result);
            int sum = list1->value + *carry;
            *carry = sum / 10;
            result->value = sum % 10;
            return result;
        }

        node* addNumbersOfLists(node *list1, node *list2, int *carry, node *result) {
            if(list1  = NULL)
                return NULL;
            result = new node();
            result->next = addNumbersOfLists(list1->next, list2->next, carry, result);
            int sum = list1->value + list2->value + *carry;
            result->value = (sum) % 10;
            *carry = (sum) / 10;
            return result;
        }
        
        void printLists() {
            node *current = head1;
            while(current->next != NULL) {
                cout << current->value << "---->";
                current = current -> next;
            }
            cout << current->value;

            current = head2;
            while(current->next != NULL) {
                cout << current->value << "---->";
                current = current -> next;
            }
            cout << current->value;
        }
};

int main() {
    SumOfLists s;
    s.addNodeToList1(5);
    s.addNodeToList1(6);
    s.addNodeToList1(3);
    s.addNodeToList2(8);
    s.addNodeToList2(4);
    s.addNodeToList2(2);
    s.printLists();
    s.findSum();
}