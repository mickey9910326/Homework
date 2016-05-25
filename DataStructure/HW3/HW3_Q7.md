## HW3_Q7,Q8

##### The Question

Q7. Give a recursive algorithm to output all  permutations of 1, …, n in lexicographical order.  
Q8. Given an implementation in C++ of Q7 (this is handwriting homework)  
Input : n with 0 < n <= 10  

##### My Answer

``` c++

#include <iostream>
#include <algorithm>
using namespace std;
int *ptr_a,N;

void print_list(){
    for (int i=0; i<N; ++i) cout << ptr_a[i]<<",";
    cout << '\n';
}

bool next_permutation(){
    for (int i=N-1; i>0; i--)
        if (ptr_a[i-1] < ptr_a[i]){
            int j = N-1;
            while (ptr_a[i-1] >= ptr_a[j])
                j--;
            swap(ptr_a[i-1], ptr_a[j]);
            reverse(ptr_a+i, ptr_a+N);
            return true;
        }
    return false;
}

void permutations(){
    do print_list(); while (next_permutation());
}

int main(int argc, char const *argv[]){
    cout << "plz input the N : ";
    cin  >> N;
    while (N<=0) {
        std::cout << "wrong input, input a number again : ";
        cin  >> N;
    }
    int a[N];
    for (int i = 0; i < N; i++) {
        a[i] = i+1;
    }
    ptr_a=a;
    permutations();
    return 0;
}

```