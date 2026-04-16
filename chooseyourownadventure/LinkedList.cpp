// LinkedList.cpp
#include "LinkedList.h"

Node::Node(Room room) : room(room), next(nullptr) {}

LinkedList::LinkedList() : head(nullptr) {}

void LinkedList::addRoom(const Room& room) {
    auto newNode = make_shared<Node>(room);
    if (!head) {
        head = newNode;
    } else {
        auto current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void LinkedList::displayRooms() {
    auto current = head;
    while (current) {
        cout << current->room.toString() << endl;
        current = current->next;
    }
}

shared_ptr<Node> LinkedList::getHead() const {
    return head;
}
