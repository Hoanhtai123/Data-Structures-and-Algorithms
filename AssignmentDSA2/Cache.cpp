#include "main.h"
#include "Cache.h"


Elem* Cache::pop(){
    return arr[front];
}
int Cache::get() {
    Elem* addr_t = arr[front];

    return addr_t->addr;
}
void Cache::enQueue(Elem* in)
{
    if ((front == 0 && rear == capacity - 1) ||
        (rear == (front - 1) % (capacity - 1)))
    {
        //printf("\nQueue is Full");
        return;
    }

    else if (front == -1) /* Insert First Element */
    {
        front = rear = 0;
        arr[rear] = in;
    }

    else if (rear == capacity - 1 && front != 0)
    {
        rear = 0;
        arr[rear] = in;
    }

    else
    {
        rear++;
        arr[rear] = in;
    }
}
void Cache::printQ() {

    int f = front, r = rear;
    if (front == -1) {
        return;
    }
    if (f <= r) {
        while (f <= r) {
            arr[f]->print();
            f++;
        }
    }
    else {
        while (f <= capacity - 1) {
            arr[f]->print();
            f++;
        }
        f = 0;
        while (f <= r) {
            arr[f]->print();
            f++;
        }
    }
}
void Cache::deQueue() {

    if (front == -1) {
        return;
    }
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else {
        if (front == capacity - 1)
            front = 0;
        else
            front = front + 1;
    }
}
void Cache::DeleteCache(Node* node) {
    if (node) {
        DeleteCache(node->left);
        DeleteCache(node->right);
        delete node->obj;
        delete node;
    }
}
Cache::~Cache() {
    delete[] arr;
    DeleteCache(root);
}
Node* newNode(Elem* data_0)
{
    Node* node = new Node();
    node->obj = data_0;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return(node);

}
int height(Node* N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

Node* rightRotate(Node* y)
{
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}
Node* leftRotate(Node* x)
{
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}
int getBalance(Node* N)
{
    if (N == NULL)
    {
        return 0;
    }
    return height(N->left) - height(N->right);
}

Node* insertNode(Node* node, Elem*& key)
{
    if (node == NULL)
    {
        //b->enQueue(key);
        return(newNode(key));
    }

    if (key->addr < node->obj->addr)
    {
        node->left = insertNode(node->left, key);
    }
    else if (key->addr > node->obj->addr)
    {
        node->right = insertNode(node->right, key);
    }
    else 
    {
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);


    if (balance > 1 && key->addr < node->left->obj->addr)
    {
        return rightRotate(node);
    }

    if (balance < -1 && key->addr > node->right->obj->addr)
    {
        return leftRotate(node);
    }

    if (balance > 1 && key->addr > node->left->obj->addr)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key->addr < node->right->obj->addr)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node* minValueNode(Node* node)
{
    Node* current = node;

    while (current->left != NULL) {

        current = current->left;
    }

    return current;
}

Node* deleteNode(Node* root, int key)
{
 
    if (root == NULL)
    {
        return root;
    }

    if (key < root->obj->addr)
    {
        root->left = deleteNode(root->left, key);
    }

    else if (key > root->obj->addr)
    {
        root->right = deleteNode(root->right, key);
    }

    else
    {
        if ((root->left == NULL) || (root->right == NULL))
        {
            Node* temp = root->left ?
                root->left :
                root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else 
            {
                *root = *temp;
            } 
            free(temp);
        }
        else
        {
            Node* temp = minValueNode(root->right);
            root->obj = temp->obj;
            root->right = deleteNode(root->right, temp->obj->addr);
        }
    }

    if (root == NULL)
    {
        return root;
    }
    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root); 
    if (balance > 1 && getBalance(root->left) >= 0)
    {
        return rightRotate(root);
    }
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
    {
        return leftRotate(root);
    }
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Data* read_AVL(Node* root, int addr) {
    while (root != NULL) {
        if (addr == root->obj->addr) {
            return root->obj->data;
        }
        else if (addr < root->obj->addr) {
            return read_AVL(root->left, addr);
        }
        else if (addr > root->obj->addr) {
            return read_AVL(root->right, addr);
        }
    }
    return NULL;
}
bool write_AVL(Node* root, int addr, Data* cont) {
    while (root != NULL) {
        if (addr == root->obj->addr) {
            //free(root->obj->data);
            root->obj->data = cont;
            root->obj->sync = false;
            return true;
        }
        else if (addr < root->obj->addr) {
            return write_AVL(root->left, addr, cont);
        }
        else if (addr > root->obj->addr) {
            return write_AVL(root->right, addr, cont);
        }
    }
    return false;
}

void printpreOrder(Node* root) {
    if (root == NULL)
        return;
    root->obj->print();
    printpreOrder(root->left);
    printpreOrder(root->right);
}
void printInorder(struct Node* root) {
    if (root == NULL)
    {
        return;
    }
    printInorder(root->left);
    root->obj->print();
    printInorder(root->right);
}
Data* Cache::read(int addr) {
    return read_AVL(root, addr);
}
Elem* Cache::put(int addr, Data* cont) {
	Node* temp = root;
	if (p < MAXSIZE) {
		Elem* nNode = new Elem(addr, cont, true);
		root = insertNode(root, nNode);
        this->enQueue(nNode);
		p++;
		return NULL;
	}
	else {
		root = temp;
		Elem* rm = this->pop();
		root = deleteNode(root, this->get());
		this->deQueue();
		Elem* nNode = new Elem(addr, cont, true);
		root = insertNode(root, nNode);
        this->enQueue(nNode);
		return rm;
	}
}
Elem* Cache::write(int addr, Data* cont) {

		Node* temp = root;
		if (write_AVL(root, addr, cont)) {
			return NULL;
		}
		if (p < MAXSIZE) {
			Elem* nNode = new Elem(addr, cont, false);
			root = insertNode(root, nNode);
            this->enQueue(nNode);
			p++;
			//delete temp;
			return NULL;
		}
		else {
			root = temp;
			Elem* rm = this->pop();
			
			root = deleteNode(root, this->get());
            this->deQueue();
			Elem* nNode = new Elem(addr, cont, false);
			root = insertNode(root, nNode);
            this->enQueue(nNode);
			return rm;
		}
}
void Cache::print() {
	this->printQ();
}
void Cache::preOrder() {
	printpreOrder(root);
}
void Cache::inOrder() {
	printInorder(root);
}
