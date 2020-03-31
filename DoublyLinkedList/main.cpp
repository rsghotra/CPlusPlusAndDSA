#include <iostream>

struct Node {
    int data;
    Node *next;
    Node *prev;
};

struct LinkedList {
    Node *head;
};

Node* make_node(int n) {
    Node * node = new Node;
    node->data = n;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

LinkedList* make_list(int n) {
    LinkedList *ll = new LinkedList();
    ll->head = make_node(n);
    return ll;
}

void print_list(LinkedList *ll) {
    Node *tmp = ll->head;
    if(tmp == NULL) {
        return ;
    }
    while(tmp != NULL) {
        std::cout << tmp->data << " ";
        tmp = tmp->next;
    }
    std::cout << std::endl;
}

void insert_at_beginning(LinkedList *ll, Node *node) {
    node->next = ll->head;
    ll->head->prev = node;
    ll->head = node;
}

void insert_at_tail(LinkedList *ll, Node *node) {
    Node *tmp = ll->head;
    while(tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = node;
    node->prev = tmp;
}

void insert_after(Node *n, Node *a) {
    n->next = a->next;
    a->next->prev = n;
    n->prev = a;
    a->next = n;
}

void delete_node(LinkedList *ll, Node *node) {
    if(node->prev == NULL) {
        //removing a head
        node->next->prev = NULL;
        ll->head = node->next;
        node->next = NULL;
    } else {
        node->prev->next = node->next;
    }
    if(node->next != NULL) {
        node->next->prev = node->prev;
    }
    delete node;
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

    print_list(ll);

    Node *z;
    z = make_node(0);
    insert_at_beginning(ll, z);
    z = make_node(-10);
    insert_at_beginning(ll, z);
    z = make_node(100);
    insert_at_tail(ll, z);
    
    z = make_node(30);
    insert_after(z, a);
    z = make_node(40);
    insert_after(z, a->next);
    z = make_node(500);
    insert_after(z, a->next->next);

    print_list(ll);

    
    delete_node(ll, ll->head);
    delete_node(ll, z);
    print_list(ll);
}