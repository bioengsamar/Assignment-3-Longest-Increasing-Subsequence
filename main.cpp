#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//function to find LIS
void LIS(int arr[],int n ,int lis[])
{
      lis[0]=1; //base case
      for(int i=1;i<n;i++) //start from the second array element
     {
          lis[i]=1; //lis[] = {1, 1, 1, 1,….} (initially).

          for(int j=0;j<i;j++) //do for each element in subarray `arr[0…i-1]`
          {
              if(arr[i]>arr[j])
              {
                  lis[i]=max(lis[i],lis[j]+1); //assign lis[i] with (lis[j]+1) if (lis[j]+1) is greater than lis[i]
              }
          }
      }
}


//function to print Longest Increasing Subsequence
void find_lis(int Table[], int Sequence[], int n ){
    int increment = 0;
    int size_subSequence=0;
    int maxlength = 0;
	int maxindex = 0;
	maxindex = distance(Table, max_element(Table, Table + n)); // to get index of max length in table[] = lis[]
	maxlength = Table[maxindex]; //get max length
    size_subSequence = maxlength;
    int subSequence[size_subSequence];

	//find the sequence
	for (int i = maxindex; i >= 0; i--)
	{
		maxlength = Table[i];

		if (maxlength == Table[maxindex] - increment)
		{
			maxlength = i;
			subSequence[Table[maxlength]-1] = Sequence[maxlength];
			increment++;
		}
	}

	cout << "\nThe longest subsequence\n";

	//print the subsequence
	for (int j = 0; j < size_subSequence; j++)
	{
		cout << subSequence[j] << " ";
	}

	cout << endl;

}

int main() {
  int ans_maxlength=0;
  int arr[]={ 3, 2, 6, 4, 5, 1 };
  int n=sizeof(arr)/sizeof(arr[0]);
  int lis[n];
  LIS(arr,n, lis);
  ans_maxlength=*max_element(lis,lis+n);
  cout<<"Longest increasing subsequence is:"<<" ";
  cout<<ans_maxlength<<endl;
  find_lis(lis, arr, n);

  return 0;}
