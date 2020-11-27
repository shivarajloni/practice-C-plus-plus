// Given a set of integers Determine whether or not this set can be divided into two subsets such that 
// the sum of elements in each subset is equal.

#include<iostream>
using namespace std;
 
bool subset_sum(int a[],int n, int sum)
{
    bool dp[n+1][sum+1];
 
    //dp[i][j]=whethere there is a subset of sum j in subarray a[0....i-1]
 
    int i,j;
 
    for(i=0;i<=n;i++)
        dp[i][0]=true;
 
    for(j=1;j<=sum;j++)
        dp[0][j]=false;
 
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=sum;j++)
        {
            //if using i-1 elements, there is a subset of desired sum
            if(dp[i-1][j]==true)
                dp[i][j]=true;
             else
            {
                if(a[i-1]>j)
                    dp[i][j]=false;
                 else
                    dp[i][j]=dp[i-1][j-a[i-1]];
            }
        }
    }
     return dp[n][sum];
}
 
 
int main()
{
    int i;
    int n;
    int sum=0;
 
    cout<<"Enter the number of elements in the set"<<endl;
    cin>>n;
    int a[n];
 
    cout<<"Enter the values"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
 
    //if sum of elements of set is odd, there is no way this set can be divided into two subsets of equal sum
    if(sum%2==1)
    {
        cout<<"Balanced partioning not possible"<<endl;
        return 0;
    }
     bool result=subset_sum(a,n,sum/2);
 
    if(result==true)
        cout<<"Balanced partitioning possible";
 
    else
        cout<<"Balanced partioning not possible"<<endl;
 
    cout<<endl; 
    return 0;
}