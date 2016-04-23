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
