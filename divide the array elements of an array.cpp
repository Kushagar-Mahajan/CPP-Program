//how to divide the elements of array in two parts on the basis of even and odd index
#include<iostream> 
using namespace std;
main()
    {
 
        long int ARR[10], OAR[10], EAR[10];
        int i, j = 0, k = 0, n;
 
        cout<<"Enter the size of array AR n"<<endl;
        cin>>n;
 
        printf("Enter the elements of the array n");
        for (i = 0; i < n; i++)
        {
            cin>>ARR[i];
            fflush(stdin);
        }
 
        /*  Copy odd and even elements into their respective arrays */
 
        for (i = 0; i < n; i++)
        {
            if (ARR[i] % 2 == 0)
            {
                EAR[j] = ARR[i];
                j++;
            }
            else
            {
                OAR[k] = ARR[i];
                k++;
            }
        }
 
        cout<<"The elements of OAR are n"<<endl;
        for (i = 0; i < k; i++)
        {
            cout<<OAR[i]<<endl;
        }
 
        cout<<"The elements of EAR are n"<<endl;
        for (i = 0; i < j; i++)
        {
            cout<<EAR[i]<<endl;
        }
}
