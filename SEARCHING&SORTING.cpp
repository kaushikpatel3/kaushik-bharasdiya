#include<iostream>
#include<string>
using namespace std;

struct student
{
int rollno ,i ,j ,n;
string name;
float sgpa;
};

class studentinfo
{
struct student s[20] , temp;

public:
int i,n , j ,c ;
float target;
string key;
string object;
void getdata();
void putdata();
void display();
void quicksort(int , int);
void insertion();
void lsearch(float);
void bsearch(string);
};

void studentinfo :: getdata()
{
cout<<"Enter The Number Of Student: ";
cin>>n;

for(i=0;i<n;i++)
{
cout<<"enter Roll no. :";
cin>>s[i].rollno;
cout<<"Enter name :";
cin>>s[i].name;
cout<<"Enter SGPA :";
cin>>s[i].sgpa;
}

cout<<endl;
}

void studentinfo :: display()
{
for(i=0;i<n;i++)
{
cout<<s[i].rollno<<"\t";
cout<<s[i].name<<"\t";
cout<<s[i].sgpa<<endl;
}

cout<<endl;
}

void studentinfo :: putdata()


{
for(i=0;i<n-1;i++)
{
for(j=0;j<n-1-i;j++)
{
if (s[j].rollno > s[j+1].rollno)
{
temp=s[j];
s[j]=s[j+1];
s[j+1]=temp;
}

}
}
cout<<"The Sorted List According To Roll No. Is "<<endl;
for(i=0;i<n;i++)
{
cout<<s[i].rollno<<"\t";
cout<<s[i].name<<"\t";
cout<<s[i].sgpa<<endl;
}
cout<<endl;
}


void studentinfo :: insertion()

{
struct student key;
for (i = 1; i < n; i++)
 {
        key = s[i];
        j = i - 1;
         while (j >= 0 && s[j].name > key.name) {
            s[j + 1] = s[j];
            j = j - 1;
        }
        s[j + 1]= key;
    }
   

cout<<"The Sorted List According To Name Is : \n";
for(i=0; i<n; i++)
{
        cout<<s[i].rollno<<"\t";
		cout<<s[i].name<<"\t";
		cout<<s[i].sgpa<<endl;
		}
    cout<<endl;
}

void studentinfo :: quicksort(int Start, int End)
{
    int i,j ,pivot;
    struct student temp;
    if(Start < End)
    {
        pivot = Start;
        i = Start;
        j = End;
        while(i < j)
        {
            while((s[i].sgpa >= s[pivot].sgpa) && (i < End))
            {
                i++;
            }
            while(s[j].sgpa < s[pivot].sgpa)
            {
                j--;
            }
            if(i < j)
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
        temp = s[pivot];
        s[pivot] = s[j];
        s[j] = temp;
        quicksort(Start , j-1);
        quicksort(j+1 , End);
    }
}

void studentinfo :: lsearch(float key)
{
	int i, c=0;
	for (i = 0; i < n; i++)
	{
		if (s[i].sgpa == key)
		{
			cout << "Element is Present \n";
            cout<<s[i].rollno<<"\t";
            cout<<s[i].name<<"\t";
            cout<<s[i].sgpa<<"\n";
			c=1;
		}
	}

	if (c == 0)
	{
		cout<<"Element is absent \n";
	}
}

void studentinfo :: bsearch(string key)
{
int Start = 0, End = n - 1;
int mid;
int c=0;
while (Start < End)
{
	mid = Start + (End - Start) / 2;
	if (s[mid].name == key)
	{
		c=1;
		break;
	}
	else if (s[Start].name == key)
	{
		mid = Start;
		c=1;
		break;
	}
	else if (s[End].name == key)
	{
		mid = End;
		c=1;
		break;
	}
	else if (s[mid].name > key)
	{
		End = mid - 1;
	}
	else if (s[mid].name < key)
	{
		Start = mid + 1;
	}
}
if (c == 1)
    {
        cout << "Element is Present \n";
        cout << "\n";
        cout<<s[mid].rollno<<"\t";
        cout<<s[mid].name<<"\t";
        cout<<s[mid].sgpa<<"\n"; 
    }
    else
    {
        cout << "Element is absent \n";
    }
}

int main ()
{
string key2;
float key1;
studentinfo abc;
abc.getdata();
abc.display();

int c;
while(true)
{
cout << "\nMenu:\n";
cout << "1. Sort students by Roll No (Bubble Sort)\n";
cout << "2. Sort students alphabetically by Name (Insertion Sort)\n";
cout << "3. Find top 10 toppers by SGPA (Quick Sort)\n";
cout << "4. Search students by SGPA(Linear Search)\n";
cout << "5. Search student by Name (Binary Search)\n";
cout << "6. Exit\n";
cout << "Enter your choice: ";
cin>>c;

switch (c)
{
case 1:
abc.putdata();
break;
case 2:
abc.insertion();
break;
case 3:
abc.quicksort(0, abc.n- 1);
abc.display();
break;
case 4:
cout<<"Enter The SGPA To Be Found: \n";
cin>>key1;
abc.lsearch(key1);
break;
case 5:
cout << "Enter Name To Be Found: \n";
cin >> key2;
abc.bsearch(key2);
break;
case 6:
cout << "Exiting the application..... \n";
return 0;
default:
cout<<"invalid choice ";
break;
}
}
return 0;
}
