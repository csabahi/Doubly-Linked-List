#include "sequential-list.h"

SequentialList::SequentialList(unsigned int cap) {
    capacity_ = cap;
    data_ = new DataType [cap];
    size_ = 0;
}


SequentialList::~SequentialList() {
    delete [] data_;
    data_ = nullptr;
}

unsigned int SequentialList::size() const {
    return size_;
}

unsigned int SequentialList::capacity() const {
    return capacity_;
}

bool SequentialList::empty() const {
    return (size_ == 0);
}

bool SequentialList::full() const {
    return (size_ == capacity_);
}

SequentialList::DataType SequentialList::select(unsigned int index) const {
    if(index < size_){
       return data_[index];
    }

    return data_[size_-1];
}

unsigned int SequentialList::search(DataType val) const {

    for (unsigned int i = 0; i < size_; i++){
        if (data_[i] == val)
            return i;
    }
    return size_;
}

void SequentialList::print() const {
    for (unsigned int i = 0; i < size_; i++)
    {
        std::cout << data_[i] << std::endl;
    }
}

bool SequentialList::insert(DataType val, unsigned int index) {

    if ( size_ == capacity_ || index > size_)
    {
        return false;
    }

    for (unsigned int i = size_; i > index; i--){
        data_[i] = data_[i-1];
    }

    data_[index] = val;
    size_++;
    return true;
}


bool SequentialList::insert_front(DataType val) {

    if ( size_ == capacity_ ){
        return false;
    }

    if (size_==0){
        data_[0] = val;
        size_++;
        return true;
    }

    for (unsigned int i = size_; i > 0; i--){
        data_[i] = data_[i-1];
    }

    data_[0] = val;
    size_++;
    return true;
}


bool SequentialList::insert_back(DataType val) {
    if (size_ == capacity_) {
        return false;
    }

    data_[size_] = val;
    size_++;
    return true;
}

bool SequentialList::remove(unsigned int index) {

    if ( index > size_ || size_ == 0){
        return false;
    }

    data_[index] = 0;
    for (unsigned int i = index; i < size_; i++){
        data_[i] = data_[i+1];
    }
    size_--;
    return true;
}


bool SequentialList::remove_front(){

    if ( size_ == 0){
        return false;
    }

    data_[0] = 0;

    for (unsigned int i = 0; i < size_; i++){
        data_[i] = data_[i+1];
    }
    size_--;
    return true;
}

bool SequentialList::remove_back() {

    if (size_ == 0){
        return false;
    }

    data_[size_-1] = NULL;
    size_--;
    return true;
}


bool SequentialList::replace(unsigned int index, DataType val) {
    if (index > size_-1){
        return false;
    }

    data_[index] = val;
    return true;
}
