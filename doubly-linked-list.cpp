#include "doubly-linked-list.h"

DoublyLinkedList::Node::Node(DataType data) {
    value = data;
    next = nullptr;
    prev = nullptr;
}


DoublyLinkedList::DoublyLinkedList() {
    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
}


DoublyLinkedList::~DoublyLinkedList() {
    for (int i = 0; i < size_; i++) {
        Node *temp = head_;
        head_ = head_->next;
        delete temp;
        temp = nullptr;
    }
    delete head_;
    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
}
//
//    while (head_ != nullptr){
//        Node *temp = head_;
//        head_ = head_ -> next;
//        temp = nullptr;
//        delete temp;
//    }
//    head_ = nullptr;
//    delete head_;
//    size_= 0;
//}


unsigned int DoublyLinkedList::size() const {
    return size_;
}


unsigned int DoublyLinkedList::capacity() const {
    return CAPACITY;
}


bool DoublyLinkedList::empty() const {
    return (size_ == 0);
}


bool DoublyLinkedList::full() const {
    return (size_ == CAPACITY);
}


DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const {
    if (index > size_ ){
        return tail_->value;
    }

    Node* temp = getNode(index);

    return temp->value;
}


unsigned int DoublyLinkedList::search(DataType value) const {
    Node *temp = head_;

    unsigned int pos;

    while(temp->value != value && temp->next != NULL){
        pos ++;
        temp = temp->next;
    }

    if (temp->value != value){
        return size_;
    }

    return (pos++);
}


void DoublyLinkedList::print() const {
    if (head_ == nullptr){
        std::cout << size_ << std::endl;
        return;
    }

    Node *temp = head_;
//    std::cout<<temp->value;
    while (temp != nullptr){
        std::cout << temp->value << "->";
        temp = temp->next;
    }
    std::cout<<std::endl;
    return;
}


DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const {
    if (index == 0){
        return head_;
    }

    Node *current = head_;
    for (unsigned int i = 0; i < (index - 1); i++){
        current = current->next;
    }
    return current->next;
}


bool DoublyLinkedList::insert(DataType value, unsigned int index) {
    if (full() || index > size_){
        return false;
    }

    if(index==0){
        insert_front(value);
        return true;
    }

    if(index == size_){
        insert_back(value);
        return true;
    }


    Node *newNode = new Node(value);
    Node *after = getNode(index);
    Node *previous = after->prev;
    newNode->prev = previous;
    newNode->next = after;
    previous->next = newNode;
    after->prev = newNode;
    size_++;
    return true;
}


bool DoublyLinkedList::insert_front(DataType value) {
    if (full() ){
        return false;
    }

    Node *newNode = new Node(value);

    if (size_ == 0){
        head_ = newNode;
        tail_ = head_;
        size_ ++;
        return true;
    }


    newNode->next = head_;
    head_->prev = newNode;
    head_ = newNode;
    size_++;
    return true;

}


bool DoublyLinkedList::insert_back(DataType value) {
    if (full()){
        return false;
    }

    Node *newNode = new Node(value);

    if (size_ == 0){

        head_ = newNode;
        tail_ = newNode;
        size_ ++;
        return true;
    }

    newNode->prev = tail_;
    tail_->next = newNode;
    tail_ = newNode;
    size_++;
    return true;

}


bool DoublyLinkedList::remove(unsigned int index) {
    if (index > size_ || size_ == 0 ){//|| index < 0){ // index of element to remove is invalid
        return false;
    }

    if (index == 0){
        remove_front();
        return true;
    }

    if (index == size_-1){
//        std::cout<<head_->next->next->value<<std::endl;
//        std::cout<<tail_->value <<std::endl;
        remove_back();
        return true;
    }

    Node *removeNode = getNode(index);
    Node *previous = removeNode->prev;
    Node *after = removeNode->next;

    after->prev =previous;
    previous->next = after;

    removeNode = nullptr;
    delete removeNode;
    size_--;
    return true;
}


bool DoublyLinkedList::remove_front() {
    if (empty()) {
        return false;
    }

    if (size_ == 1){
        head_ = nullptr;
        tail_ = nullptr;
        size_ = 0;
        return true;
    }

    Node *temp = head_;
    head_ = head_->next;
    delete temp;
    temp = nullptr;
    size_--;
    return true;

}

bool DoublyLinkedList::remove_back() {
    if (empty()){
        return false;
    }

    if (size_==1){
        delete head_;
        head_ = nullptr;
        tail_ = nullptr;
        size_ = 0;
        return true;
    }

    Node *temp = tail_;
    tail_ = tail_->prev;
    tail_ -> next = nullptr;
    delete temp;
    temp = nullptr;
    size_--;
    return true;
}


bool DoublyLinkedList::replace(unsigned int index, DataType value) {
    if (index >= size_ || empty()){
        return false;
    }

    Node *curr = getNode(index);
    curr->value = value;
    return true;
}
