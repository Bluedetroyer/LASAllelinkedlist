#ifndef SLIST_H
#define SLIST_H

#include <string>
class Airport
{
public:
    char    code[5];
    double   longitude;
    double   latitude;

};

class node {
  public:
    Airport* data;
    node *next;
    node(Airport* value) {
      data = value;
      next = nullptr;
    }
};

class linkedList {
  private:
    node *head;
  public:
    linkedList() {
      head = nullptr;
    }

    ~linkedList() {
      while (head != nullptr) {
        node *current = head;
        while (current->next != nullptr) {
          current = current->next;
        }
        delete current;
      }
    }

    void add(Airport* value) {
      node **current = &head;

      while (*current != nullptr) {

        current = &(*current)->next;
      }
      *current = new node(value);

    }

    void clear() {

      head = nullptr;
    }

    bool equals(linkedList list) {
      node *current1 = head;
      node *current2 = list.head;
      while (current1 != nullptr) {
        if (current2 == nullptr) {
          return false;
        }

        if (current1->data != current2->data) {
          return false;
        }
        current1 = current1->next;
        current2 = current2->next;
      }
      if (current1 == nullptr && current2 != nullptr) {
        return false;
      }
      return true;
    }

    Airport* get(int index) {
      node *current = head;
      for (int i = 0; i < index; i++) {
        current = (*current).next;
      }
      return current->data;
    }

    void insert(int index, Airport* value) {
      node **current = &head;

      for (int i = 0; i < index; i++) {

        current = &(*current)->next;
      }

      node* temp = *current;
      *current = new node(value);
      (**current).next = temp;
    }

    void exchg(int index1, int index2) {
      Airport* temp = get(index1);
      node *current = head;
      for (int i = 0; i < index1; i++) {
        current = current->next;
      }
      current->data = get(index2);
      current = head;
      for (int i = 0; i < index2; i++) {
        current = current->next;
      }
      current->data = temp;
    }

    bool isEmpty() {
      if (head == nullptr) {
        return true;
      }
      return false;
    }

    void set(int index, Airport* value) {
      node *current = head;
      for (int i = 0; i < index; i++) {
        current = current->next;
      }
      current->data = value;
    }

    void remove(int index) {
      node **current = &head;
      for (int i = 0; i < index; i++) {
        current = &(*current)->next;
      }
      node **prvPtr = current;
      current = &(*current)->next;
      *prvPtr = *current;
    }

    void swap(int index1, int index2) {
      node **current = &head;
      for (int i = 0; i < index1; i++) {
        current = &(*current)->next;
      }
      node **prvPtr = current;
      node **inx1Ptr = &(*current)->next;

      current = &head;
      for (int i = 0; i < index2; i++) {
        current = &(*current)->next;
      }
      node **prvPtr2 = current;
      node **inx2Ptr = &(*current)->next;

      node *temp = *prvPtr;
      *prvPtr = *prvPtr2;
      *prvPtr2 = temp;

      temp = *inx1Ptr;
      *inx1Ptr = *inx2Ptr;
      *inx2Ptr = temp;
    }

    int size() {
      int length = 0;
      node *current = head;
      while (current != nullptr) {
        current = (*current).next;
        length++;
      }
      return length;
    }

    linkedList subList(int start, int length) {
      linkedList newList = linkedList();
      node *current = head;
      for (int i = 0; i < start; i++) {
        current = (*current).next;
      }
      for (int i = 0; i < length; i++) {
        newList.add(current->data);
        newList.add(get(i+start));
        if (i != length-1) {
          current = (*current).next;
        }

      }
      return newList;
    }

    string toString() {
    }
};

#endif