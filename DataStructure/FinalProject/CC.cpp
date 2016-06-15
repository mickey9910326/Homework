#include<iostream>
#include <stdlib.h>
#include<vector>

using namespace std;

int cx[]={-1,0,1,0};  //�W,�k,�U,��
int cy[]={0,1,0,-1};

void dfs(const vector<vector<int> > &grid,long long sum,int x,int y,vector<vector<bool> > &visited,long long &ans){
    int m=grid.size();
    int n=grid[0].size();

    if(x==m-1 && y==n-1 && sum<ans)
		ans=sum;

    for(int i=0;i<4;i++){
        bool flag=false;
        int nx=x+cx[i];

        int ny=y+cy[i];

        if(ny==-1 || ny==n || nx==-1 || nx==m)
       		continue;

        if(visited[nx][ny] || grid[nx][ny]==1)
			continue;

        visited[nx][ny]=true;

        dfs(grid,sum+1,nx,ny,visited,ans);

        visited[nx][ny]=false;
    }
}


int main(){
    int val;
    int row_num,col_num;
    while(cout<<"�п��J�H�C�P�H���G ",cin>>row_num>>col_num){
        if(row_num>0 && col_num>0){
            vector<vector<int> > grid(row_num,vector<int>(col_num));
            vector<vector<bool> > visited(row_num,vector<bool>(col_num,false));
            for(int i=0;i<row_num;i++){
            	cout<<"�п��J�� "<<i+1<<" �C�� "<<col_num<<" �ӼƦr�G (���J�Ʀr�����΢�)�@";
                for(int j=0;j<col_num;j++){
					cin>>val;
                    if(val==1 || val==0)
                        grid[i][j]=val;
                    else
                        return 0;
                }
            }

            long long shortest=row_num*col_num;
            long long sum=0;

            visited[0][0]=true;
            dfs(grid,grid[0][0],0,0,visited,shortest);

            cout<<endl<<"�̵u���|�B�Ƭ��G "<<shortest<<endl<<endl;
        }
        else cout<<"�п��J���Ӥj�󢯪��Ʀr "<<endl;
    }
    return 0;
}
