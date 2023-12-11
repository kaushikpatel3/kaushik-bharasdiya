#include <iostream>
using namespace std;

class Queue
{
    int queue[10];
    int front=-1;
    int rear=-1;
    int n=10;

    public:
    void enqueue();
    void dequeue();
    bool is_full();
    bool is_empty();
    void inqueue();
    void display();

};

void Queue::enqueue()
{
    if(is_full())
    {
        cout<<"Queue is full"<<endl;
    }
    else
    {
        int num;
        cout<<"Enter number to be entered: ";
        cin>>num;
        
        if(front==-1 && rear==-1)
        {
            rear++;
            front++;
            queue[rear] = num;
        }
        else if (rear==n-1)
        {
            rear=0;
        }
        else
        {
            rear++;
            queue[rear] = num;
        }
    }
    cout<<"Front: "<<front<<" Rear: "<<rear<<endl;
}

void Queue::dequeue()
{
    if(is_empty())
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        if(front==rear)
        {
            cout<<"Deleted element: "<<queue[front]<<endl;
            queue[front]=0;
            front=-1;
            rear=-1;
        }
        else
        {
            queue[front]=0;
            front++;
        }
    }
    cout<<"Front: "<<front<<" Rear: "<<rear<<endl;
}

bool Queue::is_full()
{
    if(front==((rear+1)%n))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Queue::is_empty()
{
    if(front==-1 && rear==-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Queue::display()
{
    cout<<"Queue is: ";
    for(int i=0;i<n;i++)
        {
            cout<<queue[i]<<" ";
        }
    cout<<"\n";
}

void Queue::inqueue()
{
    for(int i=0;i<n;i++)
        {
            queue[i]=0;
        }
}

int main()
{
    int choice=0;
    Queue queue;
    queue.inqueue();
    
    while(choice!=3)
        {
            cout<<" 1. Adding Element\n";
            cout<<" 2.Removing Element\n";
            cout<<" 3.Quiting The Task"<<endl;
            cout<<"Enter your choice: ";
            cin>>choice;

            switch(choice)
                {
                    case 1:
                        queue.enqueue();
                        queue.display();
                    break;

                    case 2:
                        queue.dequeue();
                        queue.display();
                    break;

                    case 3:
                        cout<<"Exiting application"<<endl;
                        choice=3;
                    break;
                    
                    default:
                        cout<<"Enter valid choice!!"<<endl;
                    break;
                }
        }
        return 0;
}