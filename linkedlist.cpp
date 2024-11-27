
#include <iostream>
#include "Linkedlist.hpp"
#include <string>

//Smart pointers allow for automatic, exception safe, object management https://en.cppreference.com/w/cpp/memory#Smart_pointers

//To implement a method or constructor from a header file we just need to do
//template on the top if created using it
//Classname<T>::Method/constructor(params){}. The <T> is for the template Types you use in the header files
template <typename T> 
Linkedlist<T>::Linkedlist() {
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;
};

template <typename T>
Linkedlist<T>::Linkedlist(Node<T>* node) {
    this->size = 1;
    this->head = node;
    this->tail = node;
}

template <typename T>
int Linkedlist<T>::getSize() {
    return this->size;
};

template <typename T>
Node<T>* Linkedlist<T>::getHead() {
    return this->head;
};

template <typename T>
Node<T>* Linkedlist<T>::getTail() {
    return this->tail;
};

template <typename T>
void Linkedlist<T>::add(T value){
    Node<T>* pNewNode = new Node<T>;
    pNewNode->value = value;
    pNewNode->next = nullptr;

    if(this->head == nullptr) {
        this->head = pNewNode;
        this->tail = pNewNode;
    }
    else {
        this->tail->next = pNewNode;
        this->tail = pNewNode;
    }
    this->size++;
};

template <typename T>
void Linkedlist<T>::remove(T value) {
    if(this->head == nullptr) {
        std::cout << "Can't remove any values: list is empty\n";
        return;
    }
    Node<T>* current = this->head;
    Node<T>* previous = nullptr;

    while(current != nullptr) {
        if(current->value == value ) {
            if(current == this->head && this->head->next == nullptr) {
                this->head = nullptr;
                this->tail = nullptr;
            }
            else if(current == this->head){
                this->head = current->next;
            }
            else if(current == this->tail){
                this->tail = previous;
            }
            else {
                previous->next = current->next;
            }

            //std::is_pointer<T>::value checks if the value is a pointer variable 
            //we need to use if constexpr because std::is_pointer<T> is saved as a constexpr bool
            //constexpr bool is_pointer_v = is_pointer<T>::value;
            //constexpr means that the const expression is run on compile time instead of run time.
            //This can save time
            //Explanation for constexpr: https://www.youtube.com/watch?v=KBny6MZJR64 AND https://www.youtube.com/watch?v=r2ZxhpSk8EA
            if constexpr(std::is_pointer<T>::value) {
                delete[] current -> value;
            }
            //This is to delete the node itself
            delete current;
            this->size--;
            std::cout << "Value: " << value << " has been removed from the list\n";
            return;
        }
        previous = current;
        current = current->next;
    }

    std::cout << "Value: " << value << " has been not been found from the list\n";

};

//To return if something is null, we need to return a pointer of the object itself instead of the actual object
//That way we can use nullptr.
template <typename T>
T* Linkedlist<T>::peek() {
    if(this->head != nullptr){
        return &this->head->value;
    }
    else {
        std::cout << "There is no value in the list yet\n";
        return nullptr;
    }
};

template <typename T>
void Linkedlist<T>::deleteAll() {
    Node<T>* current = this->head;


    while(current != nullptr) {
        Node<T>* temp = current;
        current = current->next;

        //std::is_pointer<T>::value checks if the value is a pointer variable 
        //we need to use if constexpr because std::is_pointer<T> is saved as a constexpr bool
        //constexpr bool is_pointer_v = is_pointer<T>::value;
        //constexpr means that the const expression is run on compile time instead of run time.
        //This can save time
        //Explanation for constexpr: https://www.youtube.com/watch?v=KBny6MZJR64 AND https://www.youtube.com/watch?v=r2ZxhpSk8EA
        if constexpr (std::is_pointer<T>::value) {
            delete[] temp -> value;
        }
        else{

        }

        delete temp;
        
        this->size--;
    }

    std::cout << "DELETE DONE\n";
    this->head = nullptr;
    this->tail = nullptr;
}


int main() {

    /*
    Example how to use this linked list with a char* data type
    Linkedlist<char*> list;

    for(int i = 1; i <= 1000; i++) {
        std::string str = std::to_string(i);
        char* x = new char[str.length()+1];
        for(int j = 0; j < str.length(); j++) {
            x[j] = str[j];
        }
        x[str.length()] = '\0';
        list.add(x);
    }

    Node<char*>* current = list.getHead();
    
    while(current != nullptr) {
        std::cout << (current -> value) << '\n' ;
        current = current -> next;
    }

    std::cout << *list.peek() << '\n';
    std::cout << "Size of list:\t" << list.getSize() << '\n'; 
    list.deleteAll();
    std::cout << "Head:\t" << list.getHead() -> value << '\n'; 
    std::cout << "Size of list:\t" << list.getSize() << '\n'; 
    if(list.getHead() != nullptr){
        std::cout << list.getHead() -> value << '\n';
    }
    else {
        std::cout << "Head is " << nullptr << '\n';
    }
    
    */
    
    /*
    
    
    
    */
    Linkedlist<int*> list;
    for(int i = 1; i <= 1000; i++) {
        int* x = new int(i);
        list.add(x);
    }

    Node<int*>* current = list.getHead();
    while(current != nullptr) {
        std::cout << (current -> value) << '\n' ;
        current = current -> next;
    }

    //std::cout << *list.peek() << '\n';
    std::cout << "Size of list:\t" << list.getSize() << '\n'; 
    list.deleteAll();
    std::cout << "Size of list:\t" << list.getSize() << '\n'; 
    if(list.getHead() != nullptr){
        std::cout << list.getHead() -> value << '\n';
    }
    else {
        std::cout << "Head is " << nullptr << '\n';
    }
    return 0;

}
