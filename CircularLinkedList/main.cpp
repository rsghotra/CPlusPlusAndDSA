#include <iostream>

struct Node {
    int data;
    Node *next;
};

struct LinkedList {
    Node *last;
};

Node* make_node(int n) {
    Node* node = new Node();
    node->data = n;
    node->next = NULL;
    return node;
}

LinkedList* init_circular_linked_list(int n) {
    Node * node = make_node(10);
    node->next = node;
    LinkedList *ll = new LinkedList();
    ll->last = node;
    return ll;
}

void print_list(LinkedList *ll) {
    Node *temp = ll->last;
    std::cout << temp->data << " ";
    temp = temp->next;
    while(temp != ll->last) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << "\n";
}

void insert_at_last(LinkedList *ll, Node *node) {
    node->next = ll->last->next;
    ll->last->next = node;
    ll->last = node;
}

void insert_after(Node *n, Node *a) {
    n->next = a->next;
    a->next = n;
}

void delete_node(LinkedList *ll, Node *node) {
    Node *temp = ll->last;
    while(temp->next != node) {
        temp = temp->next;
    }
    //we just before the node which is to be deleted. It could be only node it self.
    //if we are removing last node.
    if(ll->last == node) {
        //if only one node
        if(node->next == node) {
            ll->last = NULL;
        } else {
            temp->next = ll->last->next;
            ll->last = temp;
        }
    } else {
        temp->next = node->next;
    }
    delete node;
}


int main() {
    LinkedList *ll = init_circular_linked_list(10);

    Node *a, *b, *c;
    a=make_node(20);
    b=make_node(30);
    c=make_node(40);
    ll->last->next = a;
    a->next = b;
    b->next = c;
    c->next = ll->last;
    print_list(ll);

    Node *z;
    z = make_node(50);
    insert_after(z, c);
    z = make_node(25);
    insert_after(z, a);
    z = make_node(100);
    insert_at_last(ll, z);

    print_list(ll);
    delete_node(ll, ll->last);
    delete_node(ll, b);
    print_list(ll);
    return 0;
}