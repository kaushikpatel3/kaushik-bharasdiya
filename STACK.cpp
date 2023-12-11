#include <iostream>
using namespace std;

class Node
{
    public:
    char data;
    Node *next;

    Node(char val) 
    {
        data = val;
        next = NULL;
    } 
};

class Stack
{
    private:
    Node *top;

    public:
    Stack() 
    {
        top = NULL ;
    }  

    bool isEmpty()
    {
        return top == NULL ;
    }

    void push (char x)
    {
        Node * temp = new Node(x);
        temp -> next = top;
        top = temp ;
    }

    char pop()
    {
        if (isEmpty())
        {
            cout << "Error: Stack is empty." << endl;
            exit(1);
        }
        Node * temp  = top;
        char x =  temp -> data;
        top = top -> next;
        delete (temp);
        return x;
    }

    char topData()
    {
        if (isEmpty())
        {
            cerr << "Error: Stack is empty." << endl;
            exit(1);
        }
        return top->data;
    }
};

class Expression
{
public:
    int precedence(char x);
    void reverse(char *a, char *b);
    int evaluate(int op1, int op2, char op);

     void infixToPostfix( char *infix, char *postfix);
     void infixToPrefix( char *infix, char *prefix);

    void evaluatePostfix( char *postfix);
    void evaluatePrefix( char *prefix);
};

int main()
{
    Expression exp;

    char infix[20], token, postfix[20], prefix[20];
    int choice, result;

    do
    {
        cout << "\n1. Infix to Postfix Conversion";
        cout << "\n2. Infix to Prefix Conversion";
        cout << "\n3. Evaluate Postfix Expression";
        cout << "\n4. Evaluate Prefix Expression";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
    {
        case 1:
            cout << "\nEnter Infix expression: ";
            cin >> infix;
            exp.infixToPostfix(infix, postfix);
            cout << "\nPostfix: " << postfix;
            break;

        case 2:
            cout << "\nEnter Infix expression: ";
            cin >> infix;
            exp.infixToPrefix(infix, prefix);
            cout << "\nPrefix expression is: " << prefix;
            break;

        case 3:
            exp.evaluatePostfix(postfix);
            break;

        case 4:
            exp.evaluatePrefix(prefix);
            break;
        

        default:
            cerr << " wrong choice " << endl;
     } 
    }
        while (choice != 5);
}

void Expression :: infixToPostfix(char *infix, char *postfix)
{
    Stack s;
    int i = 0, j = 0;
    char token, x;

    while (infix[i] != '\0')
    {
        token = infix[i];

        if (isalnum(token))
        {
            postfix[j] = token;
            j++;
        }
        else
        {
            if (token == '(')
                s.push(token);
            else if (token == ')')
            {
                while ((x = s.pop()) != '(')
                {
                    postfix[j] = x;
                    j++;
                }
            }
            else
            {
                while (!s.isEmpty() && precedence(token) <= precedence(s.topData()))
                {
                    postfix[j] = s.pop();
                    j++;
                }
                s.push(token);
            }
        }
        i++;
    }

    while (!s.isEmpty())
    {
        postfix[j] = s.pop();
        j++;
    }

    postfix[j] = '\0';
}

void Expression::reverse( char *a, char *b)
{
    int i = 0, j = 0;

    while (a[i] != '\0')
    {
        i++;
    }
    i--;

    while (i >= 0)
    {
        if (a[i] == '(')
            b[j] = ')';
        else if (a[i] == ')')
            b[j] = '(';
        else
            b[j] = a[i];
        i--;
        j++;
    }

    b[j] = '\0';
}

void Expression::infixToPrefix( char *infix, char *prefix)
{
    char prefix1[20], infix1[20];
    reverse(infix, infix1);
    infixToPostfix(infix1, prefix1);
    reverse(prefix1, prefix);
}

int Expression::precedence(char x)
{
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    if (x == '^')
        return 3;

    return 4;
}

int Expression::evaluate(int op1, int op2, char op)
{
    if (op == '+')
        return op1 + op2;
    if (op == '-')
        return op1 - op2;
    if (op == '*')
        return op1 * op2;
    if (op == '/')
        return op1 / op2;
    if (op == '%')
        return op1 % op2;
}

void Expression::evaluatePostfix( char *postfix)
{
    Stack s;
    int i, op1, op2, result;
    char token;
    int x;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        token = postfix[i];

        if (isalnum(token))
        {
            cout << "Enter the value for " << token << ": ";
            cin >> x;
            s.push(char(x));
        }
        else
        {
            op2 = s.pop();
            op1 = s.pop();
            result = evaluate(op1, op2, token);
            s.push(char(result));
        }
    }

    result = s.pop();
    cout << "Result = " << result;
}

void Expression::evaluatePrefix( char *prefix)
{
    Stack s;
    int  op1, op2, result;
    char token;
    int x;

    int i = 0;

    while (prefix[i] != '\0')
    {
        i++;
    }
    i--;

    while (i >= 0)
    {
        token = prefix[i];

        if (isalnum(token))
        {
            cout << "Enter the value for " << token << ": ";
            cin >> x;
            s.push(char(x));
        }
        else
        {
            op1 = s.pop();
            op2 = s.pop();
            result = evaluate(op1, op2, token);
            s.push(char(result));
        }
        i--;
    }

    result = s.pop();
    cout << "Result = " << result;
}
