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
