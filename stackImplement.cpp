#include <iostream>

typedef struct List {
    int data;
    struct List* next;
} Node;

class Stack {
    Node* node;
    Stack() {
        node = nullptr;
    }

    ~Stack() {
        free(node);
    }

    void Push(int data);
    int Pop();
};

void Stack::Push(int data) {
    node->data = data;
    node->next = nullptr;
}

int Stack::Pop() {
    Node* temp = node;
    node = node->next;
    free(temp);
}

int main(int argc, char** argv) {
    struct Stack* rootNode = nullptr;
}