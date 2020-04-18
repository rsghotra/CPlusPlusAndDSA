#include <iostream>

struct Node {
    int data;
    Node *next;
};

struct CircularLL {
    Node *last;
};

Node* make_node(int data) {
    Node* node = new Node();
    node->data = data;
    node->next = NULL;
    return node;
}

//initializing a circular linked list.
CircularLL* init_circular_linked_list(int key) {
    Node *node = make_node(key);
    //now making it a circular node;
    node->next = node;
    //node is ready --> blessing with last pointer to make it circular linked list.
    CircularLL *c = new CircularLL();
    c->last = node;
    return c;
}

void insert_after(Node *n, Node *a) {
    n->next = a->next;
    a->next = n;
}

void insert_at_last(CircularLL *cll, Node *n) {
    n->next = cll->last->next;
    cll->last->next = n;
    cll->last = n;
}

void print_cll(CircularLL *cll) {
    //print of circular is tricky too. We have to first traverse on step more 
    //but print the last node first.
    Node *temp = cll->last;
    std::cout << temp->data << std::endl;
    temp = temp->next;
    while(temp != cll->last) {
        std::cout << temp->data << std::endl;
        temp=temp->next;
    }
    std::cout << std::endl;
}

void delete_node(CircularLL *cll, Node *n) {
    //interesting delete in circulat linked list.
    /*
        - First we traverse up to node-1. This is universal to every delete operation.
        - Once we are are n-1th node. We have two use cases
            - If node to be deleted is the last node
                - if node is the only node in the list
                - else standard list
            - else node is middle node, standard delection applies
    */
   Node *temp = cll->last;
   while(temp->next != n) {
       temp = temp->next;
   }
   if(temp->next == cll->last) {
    //means last node
    //if it the only node in the list
    if(temp->next == temp) {
        cll->last = NULL;
    } else {
        temp->next = cll->last->next;
        cll->last = temp;
    }
   } else {
       //standard middle deletion
       temp->next = temp->next->next;
   }
   delete n;
}

int main() {
    CircularLL *cll = init_circular_linked_list(10);
    Node *a, *b, *c;
    a = make_node(20);
    b = make_node(30);
    c = make_node(40);
    cll->last->next = a;
    a->next = b;
    b->next = c;
    c->next = cll->last;
    print_cll(cll);
    Node *z = make_node(50);
    insert_after(z, c);
    z = make_node(25);
    insert_after(z, a);
    z = make_node(100);
    insert_at_last(cll, z);
    print_cll(cll);
    delete_node(cll, cll->last);
    delete_node(cll, b);
    print_cll(cll);
    return 0;
}
