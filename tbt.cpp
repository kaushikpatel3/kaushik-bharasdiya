#include<iostream>
using namespace std;

class node {
public:
    int data;
    int lth, rth;
    node* right, *left;
};

class thread {
public:
    node* dummy;
    node* New, *root, *temp;

    thread() {
        root = NULL;
    }

    void create() {
        New = new node;
        New->left = NULL;
        New->right = NULL;
        New->lth = 0;
        New->rth = 0;
        cout << "\nEnter the element: ";
        cin >> New->data;
        if (root == NULL) {
            root = New;
            dummy = new node;
            dummy->left = root;
            dummy->data = -9999; 
            root->left = dummy;
            root->right = dummy;
        } else {
            insert(root, New);
        }
    }

    void insert(node* root, node* New) {
        if (New->data < root->data) {
            if (root->lth == 0) {
                New->left = root->left;
                New->right = root;
                root->left = New;
                root->lth = 1;
            } else {
                insert(root->left, New);
            }
        } else if (New->data > root->data) {
            if (root->rth == 0) {
                New->right = root->right;
                New->left = root;
                root->rth = 1;
                root->right = New;
            } else {
                insert(root->right, New);
            }
        }
    }

    void display() {
        if (root == NULL)
            cout << "Tree is not created\n";
        else {
            cout << "\nInorder traversal :";
            inorder(root);
            cout << "\nPreorder traversal :";
            preorder(root);
            cout << endl;
        }
    }

    void inorder(node* root) {
        node* temp = root;
        while (temp->lth == 1) {
            temp = temp->left;
        }
        while (temp != dummy) {
            cout << " " << temp->data;
            if (temp->rth == 1) {
                temp = temp->right;
                while (temp->lth == 1) {
                    temp = temp->left;
                }
            } else {
                temp = temp->right;
            }
        }
    }

    void preorder(node* root) {
        node* temp = root;
        while (temp != dummy) {
            cout << " " << temp->data;
            if (temp->lth == 1) {
                temp = temp->left;
            } else if (temp->rth == 1) {
                temp = temp->right;
            } else {
                while (temp->rth == 0) {
                    temp = temp->right;
                    if (temp == dummy) {
                        return;
                    }
                }
                temp = temp->right;
            }
        }
    }
};

int main() {
    int choice;
    char ans = 'N';
    thread th;
    do {
        cout << "------- THREADED BINARY TREE ------- \n";
        cout << "1.Create\n2.Display\n";
        cin >> choice;
        switch (choice) {
        case 1:
            do {
                th.create();
                cout << "Want to enter more elements? (Y/N): ";
                cin >> ans;
            } while (ans == 'Y' || ans == 'y');
            break;
        case 2:
            th.display();
            break;
        }
        cout << "Want to continue? (Y/N): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
    return 0;
}
