#include <iostream>

/*
    - Implementation of Stack using: Array and Linked List
    - Provides operations: Push, Pop, Top, IsEmpty, and Traversal
    - Applications of Stacks:
        - Backtracking Algorithms
        - Undo-Redo functionality
        - Parathnesis Closure Check
    - Note: Stack is both a Abstract Data Type and a Data Structure.
    - Data Structure: is something which provides efficient organization of data
    - Abstract Data Type: is a data type which provides the 'User' operations to interact with data
                            without knowing the implementation.
*/

/*
1. Array Implementation
    - First element is put starting from index 1
    - Declare array of reqired size+1
    - Pitfall:
        - Array should be of (required size + 1)
        - Top will begin at index 0 even though we will never put any element at index 1
        - Push: Increment TOP first and then PUSH at the index
        - POP:  Save element of top for return and then redude the top by 1.
*/
const int SIZE=10;
int stk[SIZE+1];
int top = 0;

int getTop() {
    return stk[top];
}

void push(int elem) {
    top = top + 1;
    if(top > SIZE) {
        std::cout << "Stack Overflow." << std::endl;
        return;
    }
    stk[top] = elem;
}

int pop() {
    if(top == 0) {
        std::cout << "Stack Underflow." << std::endl;
        return -1000;
    }
    int elem = stk[top];
    top -= 1;
    return elem;
}

void print_array_stack() {
    //notice for loop starts at 1
    for(int i=1;i<=SIZE;i++) {
        std::cout << stk[i] << " ";
    }
    std::cout << std::endl;
}

void stack_using_array_call() {
    //main wrapper call to array implementation.
    pop();
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    push(70);
    push(80);
    push(90);
    push(100);
    push(110);
    push(120);
    push(130);
    push(140);

    print_array_stack();
    return;
}

/*
1. LinkedList Implementation
    - Easy implementation than Array
    - No serious pitfalls
    - Couple of points:
        - Need to maintain both head and top pointer
        - In pop, because it is a singly linked list - we can not go back therefore, in order
            to move top to previous node - you will have to traverse from the head until top-1
*/

struct Node {
    Node *next;
    int data;
};

struct StackLL {
    Node *head;
    Node *top;
};
StackLL *stkLL = new StackLL();
Node* make_node(int data) {
    Node *node = new Node();
    node->data=data;
    node->next = NULL;
    return node;
}

void print_linked_list_stack() {
    Node *temp = stkLL->head;
    while(temp != NULL) {
        std::cout << temp->data << " ";
        temp=temp->next;
    }
    std::cout << std::endl;
}

bool isLLStackEmpty() {
    bool status;
    if(stkLL->head == NULL) status=true;
    else status = false;
    return status;
}

void push_LL_stack(int elem) {
    //creating node
    Node *node = make_node(elem);
    //if it is the first element
    if(isLLStackEmpty()) {
        stkLL->head = node;
        stkLL->top = node;
    } else {
        stkLL->top->next = node;
        stkLL->top = node;
    }
}

int pop_LL_stack() {
    //only one error underflow
    if(isLLStackEmpty()) {
        std::cout << "Underflow." << std::endl;
        return -1000;
    }
    int elem = stkLL->top->data;
    if(stkLL->head == stkLL->top) {
        delete stkLL->top;
        stkLL->head = NULL;
        stkLL->top = NULL;
    } else {
        //top removal require traversal until top-1;
        Node *temp = stkLL->head;
        while(temp->next != stkLL->top) {
            temp = temp->next;
        }
        temp->next = NULL;
        //free the memore block
        delete stkLL->top;
        stkLL->top = temp;
    }
    return elem;
}

void stack_using_linked_list() {
    pop_LL_stack();
    push_LL_stack(10);
    push_LL_stack(20);
    push_LL_stack(30);

    print_linked_list_stack();

    pop_LL_stack();
    print_linked_list_stack();
}

int main() {

    stack_using_linked_list();
    return 0;
}