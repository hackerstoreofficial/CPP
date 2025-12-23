#include <iostream>
using namespace std;
int main()
{
    
    int a[50][50],b[50][50],c[50][50],i,j,m,n,o,p,l=1,r;
    cout<<"Enter case:\n";
    cin>>r;
    switch(r)
    {
        //MULTIPLICATION
        case 1:
            cout<<"\nEnter the order of matrix a (must be m*n): "<<endl;
            cin>>m;
            cout<<"* \n";
            cin>>n;
            cout<<"Enter the order of matrix b (must be o*p): "<<endl;
            cin>>o;
            cout<<"* \n";
            cin>>p;
            if (n==o)
            {
                cout<<"Multiplication possible "<<endl;
            }
            else
            {
                cout<<"Multiplication not possible ";
                l=0;
            }
        
            if(l)
            {
                cout<<"\n\nEnter the elements of matrix 1: "<<endl;
                for (i=1;i<=m;i++)
                {
                    for (j=1;j<=n;j++)
                        cin>>a[i][j];
                }
                cout<<"Elements of matrix 1 are: ";
                for (i=1;i<=m;i++)
                {
                    cout<<endl;
                    for (j=1;j<=n;j++)
                        cout<<a[i][j]<<" ";
                }
                cout<<"\nEnter the elements of matrix 2: "<<endl;
                for (i=1;i<=o;i++)
                {
                    for (j=1;j<=p;j++)
                        cin>>b[i][j];
                }
                cout<<"Elements of matrix 2 are: ";
                for (i=1;i<=o;i++)
                {
                    cout<<endl;
                    for (j=1;j<=p;j++)
                        cout<<b[i][j]<<" ";
                }
                cout<<"\n\n\nMultiplication:\nc=aXb=";
                for (i=1;i<=m;i++)
                {
                    for (j=1;j<=p;j++)
                    {
                        c[i][j]=0;
                        for (int k=1;k<=n;k++)
                        {
                            c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
                        }
                    }
                }
                for (i=1;i<=m;i++)
                {
                    cout<<endl;
                    for (j=1;j<=p;j++)
                        cout<<c[i][j]<<" ";
                }
            }
            break;
        // default case
        default:
            cout<<"Wrong choice";
    }
    return 0;
}