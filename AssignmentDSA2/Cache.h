#ifndef CACHE_H
#define CACHE_H

#include "main.h"

class Node {
public:
    Elem* obj;
    Node* left;
    Node* right;
//    Node* next;
    int height;
};


class Cache {
private:
		int p;
        int front;
        int rear;
        int capacity;
        Elem** arr;
        Node* root;
	public:
		Cache(int s) {
            front = rear = -1;
            capacity = s;
            arr = new Elem*[s];
            root = NULL;
            p = 0;
		}
        ~Cache();
		Data* read(int addr);
		Elem* put(int addr, Data* cont);
		Elem* write(int addr, Data* cont);
		void print();
		void preOrder();
		void inOrder();
        void DeleteCache(Node* node);
        void enQueue(Elem* in);
        void deQueue();
        void printQ();
        int get();
        Elem* pop();
};
//Cache* Q = new Cache(15);
#endif