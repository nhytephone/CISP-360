#include <iostream>

using namespace std;
int* function(int arr[],int size)
{
/*make array*/
int *out=new int[size],j=0;
/*store in reverse*/
for(int i=size-1;i>=0;i--)
{
out[j]=arr[i];
j++;
}
/*return pointer*/
return out;
}
int main()
{
/*initalize array*/
int arr[]={1,2,3,4,5,6,7,8,9,10};
/*call function*/
int* out=function(arr,10);

/*print original array*/
cout<<"The Contents of the original array are:"<<endl;
for(int i=0;i<10;i++)
{
cout<<arr[i]<<" ";
}

/*print copy arr*/
cout<<endl<<"The Contents of the copy are:"<<endl;
for(int i=0;i<10;i++)
{
cout<<out[i]<<" ";
}
cout<<endl<<endl<<"----------------------------------------";
return 0;
}
