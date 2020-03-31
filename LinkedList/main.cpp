#include <iostream>

struct Node {
    int data;
    Node *next;
};

struct LinkedList {
    Node* head;
};

void print_linked_list(LinkedList *ll) {
    Node* tmp = ll->head;
    while(tmp != NULL) {
        std::cout << tmp->data << " ";
        tmp=tmp->next;
    }
    std::cout << std::endl;
}

Node* make_node(int data) {
    Node * node = new Node();
    node->data = data;
    node->next = NULL;
    return node;
}

LinkedList* make_list(int data) {
    LinkedList* ll = new LinkedList();
    ll->head =make_node(data);
    return ll;
}

//new node before head
void insert_at_beginning(LinkedList *ll, Node *node) {
    node->next = ll->head;
    ll->head = node;
}

//inserts new node at last
void insert_at_last(LinkedList *ll, Node *node) {
    if(ll->head == NULL) {
        ll->head = node;
        node->next = NULL;
        return;
    }
    Node *tmp = ll->head;
    while(tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = node;
    return;
}

//function to insert a node after node n
void insert_node_after(Node *n, Node * a) {
    n->next = a->next;
    a->next = n;
}

void delete_node(LinkedList *ll, Node *node) {
    if(ll->head == NULL) {
        return;
    }
    Node *tmp = ll->head;
    if(ll->head == node) {
        //removing head;
        ll->head = ll->head->next;
        delete tmp;
    }
    else {
        while(tmp != NULL) {
            if(tmp->next == node) {
                tmp->next = tmp->next->next;
                delete tmp;
                break;
            }
            tmp = tmp->next;
        }
    }
}

int main() {
    LinkedList *ll = make_list(10);

    Node *a, *b, *c;
    a=make_node(20);
    b=make_node(30);
    c=make_node(40);
    ll->head->next = a;
    a->next=b;
    b->next=c;

    print_linked_list(ll);

    Node *z;
    z = make_node(0);
    insert_at_beginning(ll, z);
    z = make_node(-10);
    insert_at_beginning(ll, z);

    z = make_node(100);
    insert_at_last(ll, z);

    z = make_node(30);
    insert_node_after(z, a);
    z = make_node(40);
    insert_node_after(z, a->next);
    z = make_node(500);
    insert_node_after(z, a->next->next);

    print_linked_list(ll);

    delete_node(ll, ll->head);
    delete_node(ll, z);
    print_linked_list(ll);

}