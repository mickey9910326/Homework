#include <iostream>
using namespace std;

int N=5;
int solution[N];    // 用來存放一組可能的答案
bool filled[N];     // 紀錄各個位置是否填過數字，填過為true

void backtrack(int n)
{
    // it's a solution
    if (n == N)
    {
        for (int i=0; i<N; i++)
            cout << solution[i] << ' ';
        cout << endl;

        return;
    }

    for (int i=0; i<N; i++)     // 試著將數字 n 填入各個位置
        if (!filled[i])
        {
            filled[i] = true;   // 紀錄填過的位置

            solution[i] = n;    // 將數字 n 填入第 i 格
            backtrack(n+1);     // 繼續枚舉下一個數字

            filled[i] = false;  // 回收位置
        }
}

void enumerate_permutations()
{
    for (int i=0; i<N; i++) // initialization
        filled[i] = false;

    backtrack(0);   // 印出數字1到N的所有排列。
}
int int main(int argc, char const *argv[]) {
    enumerate_permutations();
    return 0;
}
