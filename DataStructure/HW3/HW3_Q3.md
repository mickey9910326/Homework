## HW3_Q3,Q4

##### The Question

Q3. Give a recursive algorithm to find gcd(x,y) where x, y are integers  
Hint : gcd(0,x) = x; gcd(0,y) = y; gcd(x,y) = gcd(y,x)  
Hint : gcd(ay+b, y) = gcd (y,b) for a>0 and y > b
Hint: Euclidean algorithm  

Q4. Give an implementation of Q3 in C++, and give the filename : HW3_2_ID.cpp  
Input : x, y are random integers  
　　　Ex :12 8  
Output : gcd  
　　　Ex : 4  

##### My Answer

``` c++

#include <iostream>
using namespace std;

int GCD(int a,int b){
    if(b) while((a %= b) && (b %= a));
	return a + b;
}
int main(){
    int m,n;
    cout << "GCD(a,b)" <<endl;
    cout << "Please input a: ";
    cin  >> m;
    cout << "Please input b: ";
    cin  >> n;
    cout << "GCD(" << m << "," << n << ")= " << GCD(m,n);
    return 0;
}


```
