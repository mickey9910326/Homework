## HW3_Q5,Q6

##### The Question

Q5. Give a recursive algorithm to solve the equation ax+by = c where a, b, c are given and x, y are unknown integers.  
Q6. Given an implementation in C++ of Q5 (this is handwriting homework)  
Input : a, b, c are random integer  
Output :  x, y with 0 < x < y <= 30000  

##### My Answer

``` c++

#include <iostream>
using namespace std;
int a,b,c;

int find_first_x() {
    for (int i = 0; i < b; i++)
        if ( (c-i*a)%b==0 )
            return i;
    cout << "x:" << x << ",y:" << y << endl;
    return -1;
}

void next_x(int x) {
    x+=b;
    y = (c-x*a)/b;
    if ( x<=y && y<=30000 ) {
        cout << "x:" << x << ",y:" << y << endl;
        next_x(x);
    }
    else{
        return;
    }
}

int main(int argc, char const *argv[]){
    cout << "plz input the a : ";
    cin  >> a;
    cout << "plz input the b : ";
    cin  >> b;
    cout << "plz input the c : ";
    cin  >> c;
    while (N<=0) {
        std::cout << "wrong input, input a number again : ";
        cout << "plz input the a : ";
        cin  >> a;
        cout << "plz input the b : ";
        cin  >> b;
        cout << "plz input the c : ";
        cin  >> c;
    }
    x = find_first_x();
    next_x(x);

    return 0;
}

```
