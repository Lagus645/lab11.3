#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next_ptr;
};
struct stack {
    Node* head;
    int size;
    void setNode(Node*& temp, int data, Node* next_ptr) {
        temp = new Node;
        temp->next_ptr = next_ptr;
        temp->data = data;
        return;
    }
    void setstack(stack& mystack) {
        mystack.head = nullptr;
        mystack.size = 0;
        return;
    }
    void Push(stack& mystack, int data) {
        Node* new_node;
        setNode(new_node, data, mystack.head);
        mystack.head = new_node;
        mystack.size++;
        return;
    }
    void pop(stack& mystack) {
        if (mystack.head != nullptr) {
            Node* delete_element = mystack.head;
            mystack.head = mystack.head->next_ptr;
            delete delete_element;
            mystack.size--;
        }
        return;
    }
    void clearstack(stack& mystack) {
        while (mystack.head != NULL) {
            pop(mystack);
        }
    }
    void show(stack& mystack) {
        Node* temp = mystack.head;
        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next_ptr;
        }
        return;
    }

};
int main() {
    stack st;
    st.setstack(st);
    stack* ptr = &st;
    st.Push(st, 15);
    st.Push(st, 5);
    st.Push(st, 8);
    st.Push(st, 7);
    st.Push(st, 12);
    st.Push(st, 48);
    st.Push(st, 97);
    int num = 4;
    int k;
    cin >> k;
    if (k > num) cout << "ошибка";
    int* arr = new int[st.size];
    for (int i = 1; i < num - k; i++) {
        arr[i - 1] = st.head->data;
        st.pop(st);
    }
    for (int i = 0; i < k; i++) {
        st.pop(st);
    }
    for (int i = num - k - 1; i >= 1; i--) {
        st.Push(st, arr[i - 1]);
    }
    Node* n = ptr->head;
    while (n != nullptr) {
        cout << n->data << ' ';
        n = n->next_ptr;
    }
    cout << endl;
    int size = st.size;
    for (int i = 0; i < size; i++) {
        arr[i] = ptr->head->data;
        st.pop(st);
    }
    int temp;
    for (int i = 0; i < k; i++) {
        cin >> temp;
        st.Push(st, temp);
    }
    for (int i = 0; i < size; i++) {
        st.Push(st, arr[size - i - 1]);
    }
    n = ptr->head;
    while (n != nullptr) {
        cout << n->data << ' ';
        n = n->next_ptr;
    }
    system("pause");
}