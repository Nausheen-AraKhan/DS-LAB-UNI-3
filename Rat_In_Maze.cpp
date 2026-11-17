#include<iostream>
using namespace std;
int maze[10][10];
int stRow[100],stCol[100];
int top=-1;
void push(int r,int c)
{
    top++;
    stRow[top]=r;
    stCol[top]=c;
}
void pop(int r,int c)
{
    r=stRow[top];
    c=stCol[top];
    top--;
}
int path(int m,int n)
{
    int row=1,col=1;
    maze[row][col]=1;
    while(row!=m || col!=n)
    {
        if(col<n && maze[row][col+1]==0)
        {
            push(row,col);
            col++;
            maze[row][col]=1;
        }
        else if(row<m && maze[row+1][col]==0)
        {
            push(row,col);
            row++;
            maze[row][col]=1;
        }
        else if(col>1 && maze[row][col-1]==0)
        {
            push(row,col);
            col--;
            maze[row][col]=1;
        }
        else if(row>1 && maze[row-1][col]==0)
        {
            push(row,col);
            row--;
            maze[row][col]=1;
        }
        else if(top==-1)
        {
            return 0;
        }
        else{
            pop(row,col);
        }
    }
    cout<<"\nPath Found!\n";
    cout<<"Destination: ("<<row<<","<<col<<")";
    cout<<"\nRat's Path:\n";
    for(int i=0;i<=top;i++)
    {
        cout<<"("<<stRow[i]<<","<<stCol[i]<<")->";
    }
    cout<<"("<<row<<","<<col<<")";
    return 1;
}
int main()
{
    int m,n;
    cout<<"Enter rows and columns:"<<endl;
    cin>>m>>n;
    cout<<"Enter maze (0=open, 1=blocked):"<<endl;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>maze[i][j];
        }
    }
    if(path(m,n)==0)
    {
        cout<<"\nNo Path Existes!\n";
    }
    return 0;
}
