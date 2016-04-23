#include <iostream>
using namespace std;

int nC( int n, int k ){
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
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
