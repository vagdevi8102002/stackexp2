#include <iostream>
#include <stack>

struct Node {
    int data;
    Node* next;
};

void pushStack(std::stack<int>& stack, Node* list) {
    while (list != nullptr) {
        stack.push(list->data);
        list = list->next;
    }
}

Node* add(Node* list1, Node* list2) {
    std::stack<int> stack1;
    std::stack<int> stack2;
    pushStack(stack1, list1);
    pushStack(stack2, list2);

    Node* result = nullptr;
    int carry = 0;
    while (!stack1.empty() || !stack2.empty() || carry != 0) {
        int sum = carry;
        if (!stack1.empty()) {
            sum += stack1.top();
            stack1.pop();
        }
        if (!stack2.empty()) {
            sum += stack2.top();
            stack2.pop();
        }
        carry = sum / 10;
        sum = sum % 10;
        Node* newNode = new Node{sum, result};
        result = newNode;
    }
    return result;
}

void printList(Node* list) {
    while (list != nullptr) {
        std::cout << list->data << " ";
        list = list->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* list1 = new Node{7, new Node{1, new Node{5, nullptr}}};
    Node* list2 = new Node{5, new Node{9, new Node{2, nullptr}}};
    Node* result = add(list1, list2);
    std::cout << "List 1: ";
    printList(list1);
    std::cout << "List 2: ";
    printList(list2);
    std::cout << "Result: ";
    printList(result);
    return 0;
}

