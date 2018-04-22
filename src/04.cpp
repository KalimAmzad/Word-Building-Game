#include <iostream>
using namespace std;
int main()
{
    int i,j,k,n,sum=0,mul=1,p;
    cin>>n;
    j=1;
    for(i=1;i<=n;i++)
    {
        for(k=1;k<=i;k++)
        {
            if(k>1)
            {
                mul=1;
                for(int p=1;p<=k;p++)
                {
                    mul*=j;
                    j++;

                }
                sum+=mul;
               /// cout<<sum<<endl;
            }

            else{
                sum+=j;
                j++;
              ///  cout<<sum<<endl;
            }



        }
    }
    cout<<sum<<endl;
    return 0;
}
