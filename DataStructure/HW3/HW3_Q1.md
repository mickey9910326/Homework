## HW3_Q1,Q2

##### The Question

Q1. Give a recursive algorithm to generate all melement subsets of {1,...,n}.
Hint : This is to find all combinations out of n C(n,m).  
Ex : C(4,1) = 4; C(4,2) = 6; C(4,3) = 4  

Q2. Give an implementation of Q1 in C++, and give the filename : HW3_1_ID.cpp  
Input (cin) : n, m, with 0 < m < n <= 24  
Ex : 4 2  
Output (cout) : C(n,m)  
Ex: 6  

##### My Answer

``` c++

#include <iostream>
using namespace std;

int nC(int m, int n) {
    if(n == 0)
        return m;
    else
        return gcd(n, m % n);
}
int main(){
    int m,n;
    cout << "C(m,n)" <<endl;
    cout << "Please input m: ";
    cin  >> m;
    cout << "Please input n: ";
    cin  >> n;
    cout << "C(" << m << "," << n << ")= " << nC(m,n);
    return 0;
}

```
