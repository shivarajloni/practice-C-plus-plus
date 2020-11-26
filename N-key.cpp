#include<iostream>
using namespace std;
 
int catalan_binary_trees(int n)
{
    //we are required to find out number of structurally different binary trees with n nodes
    int c[n+1];
 
    //c[i]=number of structurally different binary trees with i distinct nodes
    c[0]=1;
    c[1]=1;
    c[2]=2;
 
    int i,j;
 
    //now, using bottom up DP, we will implement the recursive formula of catalan number to find the required value
    for(i=3;i<=n;i++)
    {
        c[i]=0;
 
        for(j=0;j<i;j++)
        {
            c[i]+=c[j] * c[(i-1)-j];
        }
    }
 
    return c[n];
}
 
int main()
{
    int n;
 
    cout<<"Enter the number of distinct keys in the binary tree"<<endl;
    cin>>n;
 
    cout<<"Total number of structurally different binary trees that can be formed with "<<n<<" distinct keys are"<<endl;
    cout<<catalan_binary_trees(n);
 
    cout<<endl;
    return 0;
}