// Providing Operations on the BST (Binary Search Tree)
//  - Author: Tomash Mikulevich
//  - Created with: Visual Studio Code 1.54.0 | g++.exe (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0 | GNU gdb (GDB) 8.1
//  - Last edited: 17.03.2021

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>  

using namespace std;

int MAX_NODES = 20;     // Max number of nodes

struct node {
    int value;
    node* right;
    node* left;
};

// Menu function
void menu(node*& r);

// Functions to create a tree with unique values
void newTreeInit(node*& r);
void createTree(node*& r, int x);
int randValue();

// Functions to remove the node and its children
void deleteNodeInit(node*& r);
void searchNode(node*& r, int x);
void deleteNode(node*& r);

// Tree height calculation and console printing functions
void getHeightInit(node* r);
void getHeight(node* r, int& h, int& temp);


// Menu
void menu(node*& r) {
    int option2;

    do {
        cout << "--------------------------" << endl;
        cout << "Avaliable options: " << endl;
        cout << " 1 - Remove node \n"
             << " 2 - Determine the height of the tree and print in 2D \n"
             << " 0 - Exit" << endl;
        cout << "Your choice: "; cin >> option2;
        cout << "--------------------------" << endl;

        switch (option2) {
        case 1:
            deleteNodeInit(r);
            break;

        case 2:
            getHeightInit(r);
            break;

        default:
            cout << "!Exit!" << endl;
            option2 = 0;
        }
    } while (option2);
}


// Creating a tree (initialization)
void newTreeInit(node*& r) {
    int y;

    for (int i = 0; i < MAX_NODES; i++) {
        y = randValue();
        createTree(r, y);
    }
}

// Creating nodes
void createTree(node*& r, int x) {
    if (r == NULL) {
        node* fresh = new node;

        fresh->value = x;
        fresh->right = NULL;
        fresh->left = NULL;

        r = fresh;
    }
    else if (x > r->value)
        createTree(r->right, x);
    else if (x < r->value)
        createTree(r->left, x);
    else {
        x = randValue();
        createTree(r, x);
    }
}

// Generating a pseudo-random number in the range [10, 99]
int randValue() {
    return (rand() % 90 + 10);
}


// Removing the node (initialization)
void deleteNodeInit(node*& r) {
    int number;

    cout << "Enter the value of the node you want to delete: ";
    cin >> number;

    if (r != NULL)
        searchNode(r, number);
    else
        cout << "The tree is empty!" << endl;
}

// Search for a node with a given value
void searchNode(node*& r, int x) {
    if (r->value == x)
        deleteNode(r);
    else if (x < r->value && r->left != NULL) {
        if (r->left->value == x) {
            deleteNode(r->left);
            r->left = NULL;
        }
        else
            searchNode(r->left, x);
    }
    else if (x > r->value && r->right != NULL) {
        if (r->right->value == x) {
            deleteNode(r->right);
            r->right = NULL;
        }
        else
            searchNode(r->right, x);
    }
    else
        cout << "There is no such value!" << endl;
}

// Remove node children
void deleteNode(node*& r) {
    if (r->left != NULL)
        deleteNode(r->left);
    else if (r->right != NULL)
        deleteNode(r->right);

    delete r;
    r = NULL;
}


// Height calculating (initialization)
void getHeightInit(node* r) {
    int h = 0, temp = 0;

    if (r != NULL)
        getHeight(r, h, temp);
    else
        cout << "The tree is empty!";

    cout << "\n Height: " << temp << endl;
}

// Tree height calculation and console printing
void getHeight(node* r, int& h, int& temp) {
    cout << r->value;

    if (r->right != NULL) {
        h++;
        cout << "---";
        getHeight(r->right, h, temp);
    }

    if (r->left != NULL) {
        h++;
        cout << endl;
        cout << setw(5 * h - 3) << "|" << endl;
        cout << setw(5 * h) << "---";
        getHeight(r->left, h, temp);
    }
    else {
        if (h > temp)
            temp = h;
    }

    h--;
}


// Main function
int main() {
    srand(time(NULL));

    node* root = NULL;
    int option1;

    cout << "--------------------------" << endl;
    cout << "Start: " << endl;
    cout << " 1 - Create BST \n"
         << " 0 - Exit" << endl;
    cout << "Your choice: "; cin >> option1;

    switch (option1) {
    case 1:
        newTreeInit(root);
        break;

    default:
        cout << "!Exit!" << endl;
        return 1;
    }

    menu(root);

    return 0;
}