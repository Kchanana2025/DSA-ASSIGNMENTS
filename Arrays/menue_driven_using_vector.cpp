// IN THIS QUESTION IF SIZE OF ARRAY REACHES 30 WE CANT INSERT MORE ELEMENTS AND IN ORDER TO INSERT MORE ELEMENTS
//  WE NEED TO REDECLARE ARRAY OF LARGER SIZE AND COPY ELEMENT OF EXISTING ARRAY INTO NEW ARRAY SAME GOES WITH
//  DYANMIC ARRAY AS WELL,SO WE USE VECTOR.VECTOR IS LIKE DYANMIC ARRAY ONLY BUT IT HAS FUNCTIONALITY OF INCREASING
//   SIZE ON ITS OWN WHEN MORE ELEMENTS ARE ADDED TO IT.bUT I WILL DO QUESTIONS TWO TIMES USING BOTH DYANMIC ARRAY AND STL
//) Develop a Menu driven program to demonstrate the following operations of Arrays
//  1.CREATE
//  2.DISPLAY
//  3.INSERT
//  4.DELETE
//  5.SEARCH
//  6.EXIT
// file names should not have space in them in vs code
#include <vector>
#include <iostream>
using namespace std;
int delete_num(vector<int> &vec) // vectors ko hmesha by reference pass kro taki main mein bhi reflect ho changes
{
    // vec.erase(vec.begin() + index at which you want deletion);
    int i;
    int j;
    if (vec.size() == 0)
    {
        cout << "ELEMENT CANT BE DELETED";
    }
    cout << "ENTER THE INDEX AT WHICH YOU WISH TO DELETE THE ELEMENT";
    cin >> j;
    vec.erase(vec.begin() + j);
}

void create(vector<int> &vec)
{
    int n;
    int element;
    cout << "ENTER THE SIZE OF ARRAY";
    cin >> n;
    cout << "ENTER THE ELEMENTS OF ARRAY";
    for (int i = 0; i < n; i++)
    {
        cin >> element;
        vec.push_back(element);
    }
}
void display(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++) // vec.size() kitne elements bhare hue hai vector mein wo wala size btata hai/wo ye nai btata ki kitne aa skte hain wo toh capacity batata hai aur capacity bhi sirf ussi samay ke lie kitne aa skte hain elements wo batta hai/max_size tell total kitne elements aa skte hain refer cplusplus.com
    {
        cout << vec[i];
    }
}
int insert(vector<int> &vec)

{
    int j, val;
    cout << "ENTER THE POSITION AT WHICH YOU WANT TO INSERT ELEMENT";
    cin >> j;
    cout << "ENTER THE VALUE OF ELEMENT TO BE INSERTED";
    cin >> val;
    // vec.begin(); Returns an iterator pointing to the first element in the vector.
    vector<int>::iterator iter = vec.begin(); // iter is a iterator/pointer that will point towards first element
    vec.insert(iter + j, val);
    display(vec); // optional (htane se koi frk ni padhega normal function hi call hua hai)
}
void search(vector<int> &vec)
{
    int m, i;
    int flag = 0;
    cout << "Enter element you wish to search";
    cin >> m;
    for (i = 0; i < vec.size(); i++) // vec.size() gives size of vector
    {
        if (vec[i] == m)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        cout << "Element is presnt at " << i << " th "
             << "index";
    else
        cout << "element not present";
}

int main()
{
    // vector<int> vec1(4, 16); vector of size 4 with all values 16 craeted
    vector<int> vec;
    int a;
    int n;
    char ch;
    do
    {

        cout << "1.CREATE" << endl;
        cout << "2.DISPLAY" << endl;
        cout << "3.INSERT" << endl;
        cout << "4.DELETE" << endl;
        cout << "5.SEARCH" << endl;
        cout << "6.EXIT" << endl;
        cout << "ENTER YOUR CHOICE" << endl;
        cin >> a;
        switch (a)
        {
        case 1:
            create(vec);
            break;
        case 2:
            display(vec);
            break;

        case 3:
            insert(vec);
            break;
        case 4:
            delete_num(vec);
            break;
        case 5:
            search(vec);
            break;
        case 6:
            exit(0);
        default:

            cout << "wrong choice entered";
        }
        cout << endl;
        cout << "do you wish to continue" << endl;
        cin >> ch;
        cout << endl;
    } while (ch != 'n'); // while ke baad semicolon aata hai
    return 0;
}