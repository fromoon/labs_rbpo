#include <iostream>
#include <new>

template <typename T>
class StackBasedOnBidirectionalLinkedList {
private:
    template <typename T>
    class Node {
    public:
        T info;
        Node* next;
        Node* prev;
        Node(T info = T(), Node* next = nullptr, Node* prev = nullptr) {
            this->info = info;
            this->next = next;
            this->prev = prev;
        }
    };

    Node<T>* maxi;
    int size;

public:

    int GetSize() const {
        return size;
    };
    bool Push(const T& element);
    bool Pop(T& element);
    bool Peek(T& element) const;
    void clear();
    StackBasedOnBidirectionalLinkedList();
    StackBasedOnBidirectionalLinkedList(const StackBasedOnBidirectionalLinkedList<T>& other);
    StackBasedOnBidirectionalLinkedList(StackBasedOnBidirectionalLinkedList<T>&& other);
    StackBasedOnBidirectionalLinkedList(std::initializer_list<T> ilist);
    ~StackBasedOnBidirectionalLinkedList();
    StackBasedOnBidirectionalLinkedList<T>& operator=(const StackBasedOnBidirectionalLinkedList<T>& other);
    StackBasedOnBidirectionalLinkedList<T>& operator=(StackBasedOnBidirectionalLinkedList<T>&& other);
    StackBasedOnBidirectionalLinkedList<T>& operator=(std::initializer_list<T> ilist);
};

template<typename T>
StackBasedOnBidirectionalLinkedList<T>::StackBasedOnBidirectionalLinkedList()
{
    size = 0;
    maxi = nullptr;
}

template<typename T>
StackBasedOnBidirectionalLinkedList<T>::~StackBasedOnBidirectionalLinkedList() {
    clear();
}

template <typename T>
StackBasedOnBidirectionalLinkedList<T>::StackBasedOnBidirectionalLinkedList(const StackBasedOnBidirectionalLinkedList<T>& other) : maxi(nullptr), size(0) {
    *this = other;
}

template <typename T>
StackBasedOnBidirectionalLinkedList<T>::StackBasedOnBidirectionalLinkedList(StackBasedOnBidirectionalLinkedList<T>&& other) : maxi(nullptr), size(0) {
    *this = std::move(other);
}

template <typename T>
StackBasedOnBidirectionalLinkedList<T>::StackBasedOnBidirectionalLinkedList(std::initializer_list<T> ilist) : maxi(nullptr), size(0) {
    *this = ilist;
}

template <typename T>
StackBasedOnBidirectionalLinkedList<T>& StackBasedOnBidirectionalLinkedList<T>::operator=(StackBasedOnBidirectionalLinkedList<T>&& other) {
    if (this != &other) {
        clear();
        maxi = other.maxi;
        size = other.size;
        other.maxi = nullptr;
        other.size = 0;
    }

    return *this;
}

template <typename T>
StackBasedOnBidirectionalLinkedList<T>& StackBasedOnBidirectionalLinkedList<T>::operator=(const StackBasedOnBidirectionalLinkedList<T>& other) {
    if (this != &other) {
        clear();
        if (other.maxi != nullptr) {
            Node<T>* currentOther = other.maxi->next;
            do {
                if (!Push(currentOther->info)) {
                    clear();
                    throw std::bad_alloc();
                }
                currentOther = currentOther->next;
            } while (currentOther != other.maxi->next);
        }
    }

    return *this;
}



template <typename T>
StackBasedOnBidirectionalLinkedList<T>& StackBasedOnBidirectionalLinkedList<T>::operator=(std::initializer_list<T> ilist) {
    clear();
    for (const T& item : ilist) {
        Push(item);
    }
    return *this;
}

template<typename T>
bool StackBasedOnBidirectionalLinkedList<T>::Push(const T& element) {
    Node<T>* newNode = new(std::nothrow) Node<T>(element);
    if (newNode == nullptr) {
        return false;
    }
    if (size > 0) {
        newNode->next = newNode;

    }

    maxi = newNode;
    size++;
    return true;
}

template<typename T>
bool StackBasedOnBidirectionalLinkedList<T>::Pop(T& element) {
    if (maxi == nullptr) {
        return false;
    }
    element = maxi->info;
    Node<T>* toDelete = maxi;

    if (size == 1) {
        maxi->prev = nullptr;
    }
    else {
        maxi = toDelete->next;
    }
    delete toDelete;
    --size;
    return true;
}

template<typename T>
bool StackBasedOnBidirectionalLinkedList<T>::Peek(T& element) const {
    if (maxi == nullptr) {
        return false;
    }
    element = maxi->info;
    return true;
}

template<typename T>
void StackBasedOnBidirectionalLinkedList<T>::clear() {
    Node<T>* nextNode;
    while (size > 0) {
        nextNode = maxi->next;
        delete maxi;
        maxi = nextNode;
        --size;
    }
    maxi = nullptr;
    maxi = nullptr;
}


int main() {
    return 0;
}