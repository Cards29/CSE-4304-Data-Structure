#include <iostream>

using namespace std;

typedef struct node {
    int data;
    node* next;
    node(int value) : data(value), next(nullptr) {}
}node;
class linked_list
{
    node* head;
    node* tail;
public:
    linked_list() :head(nullptr), tail(nullptr) {}

    void Insert_front(int key) {
        node* new_node = new node(key);
        if (head == NULL) {
            head = new_node;
            tail = new_node;
        }
        else {
            new_node->next = head;
            head = new_node;
        }
    }
    void Insert_back(int key) {
        node* new_node = new node(key);
        if (head == NULL) {
            head = new_node;
            tail = new_node;
        }
        else {
            tail->next = new_node;
            tail = new_node;
        }
    }
    void Insert_after_node(int key, int v) {
        node* i = head;
        while (i != NULL && i->data != v) i = i->next;

        if (i == NULL) cerr << "Value not found" << endl;
        else {
            node* new_node = new node(key);
            new_node->next = i->next;
            i->next = new_node;
            if (i == tail) {
                tail = new_node;
            }
        }
    }
    void Update_node(int key, int v) {
        node* i = head;
        while (i != NULL && i->data != v) i = i->next;
        if (i == NULL) cerr << "Value not found" << endl;
        else i->data = key;
    }
    void Remove_head() {
        if (head == nullptr) {
            cerr << "Underflow" << endl;
            return;
        }
        node* temp = head;
        if (tail == head) tail = nullptr;
        head = head->next;
        delete temp;
    }
    void Remove_element(int key) {
        if (head == nullptr) {
            cerr << "Value not found" << endl;
            return;
        }
        if (head->data == key) {
            if (tail == head) tail = nullptr;
            node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        node* i = head;
        node* previous_node;
        while (i != nullptr && i->data != key) {
            previous_node = i;
            i = i->next;
        }
        if (i == NULL) cerr << "Value not found" << endl;
        else {
            if (tail == i) tail = previous_node;
            previous_node->next = i->next;
            delete i;
        }
    }
    void Remove_end() {
        if (head == nullptr) {
            cerr << "Underflow" << endl;
            return;
        }
        if (head == tail) {
            node* temp = head;
            head = nullptr;
            tail = nullptr;
            delete temp;;
            return;
        }
        node* i = head;
        node* previous_node = nullptr;
        while (i->next != nullptr) {
            previous_node = i;
            i = i->next;
        }
        tail = previous_node;
        previous_node->next = nullptr;
        delete i;
    }
    void print_list() {
        cout << "Head=";
        if (head == NULL) cout << "Null";
        else cout << head->data;
        cout << ", Tail=";
        if (tail == NULL) cout << "Null";
        else cout << tail->data;
        cout << ", ";
        //<< head->data << ", Tail=" << tail->data << ", ";
        node* i;
        for (i = head; i != NULL;i = i->next) {
            if (i->next != NULL) cout << i->data << ' ';
            else cout << i->data;
        }
        if (head == NULL) cerr << "Empty";
        cout << endl;
    }
    ~linked_list() {
        for (node* i = head; i != NULL;) {
            node* temp;
            temp = i;
            i = i->next;
            delete temp;
        }
        cout << "linked list was destroyed" << endl;
    }
};
int main() {
    int n;
    linked_list list;
    while (true) {
        cout <<
            "Press 1 to insert at front\n" <<
            "Press 2 to insert at back\n" <<
            "Press 3 to insert after a node\n" <<
            "Press 4 to update a node\n" <<
            "Press 5 to remove the first node\n" <<
            "Press 6 to remove a node\n" <<
            "Press 7 to remove the last node\n" <<
            "Press 8 to exit." << endl;
        cin >> n;
        if (n == 8) break;
        switch (n)
        {
        case 1:
            int x; cin >> x;
            list.Insert_front(x);
            list.print_list();
            break;
        case 2:
            int y; cin >> y;
            list.Insert_back(y);
            list.print_list();
            break;
        case 3:
            int z, v; cin >> z >> v;
            list.Insert_after_node(z, v);
            list.print_list();
            break;
        case 4:
            int p, v1; cin >> p >> v1;
            list.Update_node(p, v1);
            list.print_list();
            break;
        case 5:
            list.Remove_head();
            list.print_list();
            break;
        case 6:
            int q; cin >> q;
            list.Remove_element(q);
            list.print_list();
            break;
        case 7:
            list.Remove_end();
            list.print_list();
        default:
            break;
        }

    }
    return 0;
}