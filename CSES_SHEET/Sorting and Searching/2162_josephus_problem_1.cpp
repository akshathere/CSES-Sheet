#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <list>
using namespace std;
class LL{
    public:
    int data;
    LL* next;
    LL* prev;
    LL(int data){
        this->data=data;
        this->next=nullptr;
        this->prev=nullptr;
    }
};
LL* del(LL* node) {
    LL* nextNode = node->next;

    node->prev->next = node->next;
    node->next->prev = node->prev;

    delete node;

    return nextNode;
}
int main()
{
    int n;
    cin >> n;

    LL* head = new LL(1);
    LL* temp = head;

    for (int i = 2; i <= n; i++) {
        LL* node = new LL(i);
        temp->next = node;
        node->prev = temp;
        temp = node;
    }

    // make circular
    temp->next = head;
    head->prev = temp;

    LL* a = head;

    while (a->next != a) {   // only one node left
        a = a->next;         // move to node to delete
        cout<<a->data<<" ";      // delete and move next
        a = del(a);
    }

    cout << a->data << endl;
}