#include <iostream>
#include <cstring>
using namespace std;
class tnode 
{
    public:
    char data;
    tnode* left;
    tnode* right;
};

class snode 
{
    public:
    tnode* val;
    snode* next;
};

class stack 
{
    public:
    snode* top = nullptr;

    void push(tnode* root) 
    {
        snode* temp = new snode;
        temp->val = root;
        temp->next = top;
        top = temp;
    }

    tnode* pop() 
    {
        tnode* tmp = nullptr;
        if (top != nullptr) 
        {
            tmp = top->val;
            snode* temp = top;
            top = top->next;
            delete temp;
        }
        return tmp;
    }
};

class exp_tree 
{
    public:
    tnode* root = nullptr;
    string postfix, prefix;
    stack s;

    void creat_post() 
    {
        cout << "Enter expression: ";
        cin >> postfix;
        for (int i = 0; i < postfix.length(); i++) 
        {
            tnode* root = new tnode;
            root->data = postfix[i];
            root->left = root->right = nullptr;

            if (postfix[i]>='a'&&postfix[i]<='z'||postfix[i]>='A'&&postfix[i]<='Z')
            {
                s.push(root);
            }
            else if (postfix[i] == '/' || postfix[i] == '*' || postfix[i] == '+' || postfix[i] == '-') 
            {
                root->right = s.pop();
                root->left = s.pop();
                s.push(root);
            }
            else 
            {
                cout << "Invalid expression" << endl;
                return;
            }
        }
        root = s.pop(); // root of the created tree
    }
    
    void creat_pre() 
    {
        cout << "Enter prefix expression: ";
        cin >> prefix;
         // Start from the end of the prefix expression
        for (int i = prefix.length() - 1 ;i >= 0; i--) 
        {
            tnode* root = new tnode;
            root->data = prefix[i];
            root->left = root->right = nullptr;

            if (postfix[i]>='a'&&postfix[i]<='z'||postfix[i]>='A'&&postfix[i]<='Z')
            {
                s.push(root);
            }
            else if (prefix[i] == '/' || prefix[i] == '*' || prefix[i] == '+' || prefix[i] == '-') 
            {
                root->left = s.pop();
                root->right = s.pop();
                s.push(root);
            }
            else 
            {
                cout << "Invalid expression" << endl;
                return;
            }
        }
        root = s.pop(); // root of the created tree
    }

    void inorder_recursive(tnode* root) 
    {
        if (root != nullptr) 
        {
            inorder_recursive(root->left);
            cout << root->data;
            inorder_recursive(root->right);
        }
    }

    void preorder_recursive(tnode* root) 
    {
        if (root != nullptr) 
        {
            cout << root->data;
            preorder_recursive(root->left);
            preorder_recursive(root->right);
        }
    }

    void postorder_recursive(tnode* root) 
    {
        if (root != nullptr) 
        {
            postorder_recursive(root->left);
            postorder_recursive(root->right);
            cout << root->data;
        }
    }

    void inorder_nonrecursive(tnode* root) 
    {
        stack st;
        tnode* current = root;
        while (current != nullptr || st.top != nullptr) 
        {
            while (current != nullptr) 
            {
                st.push(current);
                current = current->left;
            }
            current = st.pop();
            cout << current->data;
            current = current->right;
        }
    }

    void preorder_nonrecursive(tnode* root) 
    {
        stack st;
        st.push(root);
        while (st.top != nullptr) 
        {
            tnode* current = st.pop();
            cout << current->data;
            if (current->right != nullptr)
                st.push(current->right);
            if (current->left != nullptr)
                st.push(current->left);
        }
    }

    void postorder_nonrecursive(tnode* root) 
    {
        stack st1, st2;
        st1.push(root);
        while (st1.top != nullptr) 
        {
            tnode* current = st1.pop();
            st2.push(current);
            if (current->left != nullptr)
                st1.push(current->left);
            if (current->right != nullptr)
                st1.push(current->right);
        }
        while (st2.top != nullptr) 
        {
            cout << st2.pop()->data;
        }
    }
};

int main()
{
    exp_tree tr;
    int ch,ch1,ch2,ans2,ans,ans1;
    
    do{
        cout<<"\n-------------------------------------------------------------------------------\n";
        cout<<"\n1.POSTFIX\n2.PREFIX\n3.EXIT\n";
        cout<<"Enter choice\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
                tr.creat_post();
                cout << "\n*****MENU*****";
                cout << "\n1.Recursive function for inorder\n2.Recursive function for preorder\n3.Recursive function for postorder\n4.Nonrecursive function for inorder\n5.Nonrecursive function for preorder\n6.Nonrecursive function for postorder";
                
                do {
                    cout << "\nENTER YOUR CHOICE:";
                    cin >> ch1;
                    switch (ch1)
                    {
                        case 1:
                            cout << "\n Inorder Exp with Recursive => ";
                            tr.inorder_recursive(tr.root);
                            break;
                        case 2:
                            cout << "\n Preorder Exp with Recursive => ";
                            tr.preorder_recursive(tr.root);
                            break;
                        case 3:
                            cout << "\n Postorder Exp with Recursive => ";
                            tr.postorder_recursive(tr.root);
                            break;
                        case 4:
                            cout << "\n Inorder Exp with Non_Recursive => ";
                            tr.inorder_nonrecursive(tr.root);
                            break;
                        case 5:
                            cout << "\n Preorder Exp with Non_Recursive => ";
                            tr.preorder_nonrecursive(tr.root);
                            break;
                        case 6:
                            cout << "\n Postorder Exp with Non_Recursive => ";
                            tr.postorder_nonrecursive(tr.root);
                            break;
                        default:
                            cout<<"Invalid choice\n";
                            break;
                    }
                    cout << "\nDo you want to continue: (1 for yes, 0 for no)\n ";
                    cin >> ans;
                } while (ans == 1);
                break;
            case 2 :
                tr.creat_pre();
                cout << "\n*****MENU*****";
                 cout << "\n1.Recursive function for inorder\n2.Recursive function for preorder\n3.Recursive function for postorder\n4.Nonrecursive function for inorder\n5.Nonrecursive function for preorder\n6.Nonrecursive function for postorder";
                
                do {
                    cout << "\nENTER YOUR CHOICE:";
                    cin >> ch2;
                    switch (ch2) 
                    {
                        case 1:
                            cout << "\n Inorder Exp with Recursive => ";
                            tr.inorder_recursive(tr.root);
                            break;
                        case 2:
                            cout << "\n Preorder Exp with Recursive => ";
                            tr.preorder_recursive(tr.root);
                            break;
                        case 3:
                            cout << "\n Postorder Exp with Recursive => ";
                            tr.postorder_recursive(tr.root);
                            break;
                        case 4:
                            cout << "\n Inorder Exp with Non_Recursive => ";
                            tr.inorder_nonrecursive(tr.root);
                            break;
                        case 5:
                            cout << "\n Preorder Exp with Non_Recursive => ";
                            tr.preorder_nonrecursive(tr.root);
                            break;
                        case 6:
                            cout << "\n Postorder Exp with Non_Recursive => ";
                            tr.postorder_nonrecursive(tr.root);
                            break;
                        default:
                            cout<<"Invalid choice\n";
                            break;
                    }
                    cout << "\nDo you want to continue : (1 for yes, 0 for no)\n ";
                    cin >> ans2;
                } while (ans2 == 1);
                break;
            default:
                cout<<"Invalid choice\n";
                break;
        }
        cout<<"WANT TO CONTINUE :(1 for yes, 0 for no)\n";
        cin>>ans;
    }while (ans==1);
}
