#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N,i,j,k,B,maxR,maxC,nextC,startC,j_index,k_index,allot,avail=0;
    int arr[20][20];
    maxR=0,maxC=0;
    cout<<"Enter the no of blocks(<10)"<<endl;
    cin>>B;
    int inp[B][2];
    cout<<"Enter the seats"<<endl;
    for(i=0;i<B;i++)
    {
        cin>>inp[i][0]>>inp[i][1];
        maxC+=inp[i][0]; //to get max column
        if(inp[i][1]>maxR)maxR=inp[i][1]; //to get max row
        avail+= inp[i][0]*inp[i][1];
    }
    cout<<"Enter no of passenger"<<endl;
    cin>>N;
    if(N>avail)
    {
        cout<<"No of passenger more than available seat"<<endl;
        return 0;
    }
//    cout<<"maxC "<<maxC<<endl;
//    cout<<"maxR "<<maxR<<endl;
    for(i=0;i<maxR;i++)
    {
        for(j=0;j<maxC;j++)
        {
            arr[i][j]= 0;
        }
    }
    //allotin a=-1/w=-2/c=-3
    nextC=0,startC=0;
    for(i=0;i<B;i++)
    {
        if(i==0)
        {
            for(j=0;j<inp[i][1];j++)
            {
                arr[j][0]=-2;
            }

            startC = 0;
        }
        else
        {
            startC += inp[i-1][1];
        }

        if(i==B-1)
        {
            for(j=0;j<inp[i][1];j++)
            {
                arr[j][maxC-1]=-2;
            }
        }

        //allot aisle
        for(k=0;k<2;k++)
        {
            for(j=0;j<inp[i][1];j++)
            {
                if(arr[j][nextC] != -2)
                {
                    arr[j][nextC] = -1;
                }
            }
            nextC+=inp[i][0]-1;
        }
        nextC-=inp[i][0]-1;
        nextC++;

        //allot center
//        cout<<"startC "<<startC<<endl;
        for(j=0;j<inp[i][1];j++)
        {
            for(k=0;k<inp[i][0];k++)
            {
                j_index = j;
                k_index = k + startC;
                if(arr[j_index][k_index] != -2 && arr[j_index][k_index] != -1)
                {
                    arr[j_index][k_index]= -3;
                }
            }
        }

    }
    for(i=1;i<=N;i++)
    {
        //loop for aisle
        for(j=0;j<maxR;j++)
        {
            allot = 0;
            for(k=0;k<maxC;k++)
            {
                if(arr[j][k]== -1)
                {
                    arr[j][k]= i;
                    allot =1;
                    break;
                }
            }
            if(allot)break;
        }
        if(allot)continue;
        //loop for window

        for(j=0;j<maxR;j++)
        {
            if(arr[j][0]== -2)
            {
                arr[j][0]= i;
                allot =1;
                break;
            }
            if(arr[j][maxC-1]== -2)
            {
                arr[j][maxC-1]= i;
                allot =1;
                break;
            }
        }
        if(allot)continue;

        //loop for center
        for(j=0;j<maxR;j++)
        {
            allot = 0;
            for(k=0;k<maxC;k++)
            {
                if(arr[j][k]== -3)
                {
                    arr[j][k]= i;
                    allot =1;
                    break;
                }
            }
            if(allot)break;
        }
    }


    for(i=0;i<maxR;i++)
    {
        for(j=0;j<maxC;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<" "<<endl;
    }

    return 0;
}
