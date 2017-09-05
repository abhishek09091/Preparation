#include<bits/stdc++.h>
using namespace std;


/*
Author : Abhishek Tripathi
Date : 5 Sep 2017
Problem Statement : Program for array rotation

Algorithm 1st:

d - number of rotation
n - size of array


1) Create an empty array of size temp[d].
2) Initialize first d values of actual array into temp[d].
3) traverse the complete array and shift all elements d places towards left
4) Copy the elements of temp[d] array into last n-d position of original array.

Obeservation:
Time Complexity : O(n)
Space Complexity : O(d)


Algorithm 2nd: 

length - number of elements in the array
rotation - number of times we have to rotate the array

1) loop to rotate the elements for given number of times
2) temporary variable to store the first element at every iteration
3) loop to shift the elemenet one by one to left side
4) replace the temporary element with last element

Observation :
Time Complexity : O(n*d)
Space Complexity : O(1)



Algorithm 3rd:( Juggling Algorithm )

length -number of elements in the array
rotation - number of times we have to rotate the array

1) Find the GCD of (length,rotation)
2) Then iterate till GCD number of times
3) Store the first set ith element int the temp variable
4) Iterate till all the ith element of the sets will not changed
5) Change the temp element with last set ith element


Observation :
Time Complexity : O(n)
Space Complexity : o(1)

*/

int printArray(int *arr,int length)
{
	
	for(int i=0;i<length;i++)
	{
		printf("%d ",arr[i]);
	}
	
	printf("\n");
	return 0;
}



/* 


**********************************************************************FIRST ALGORITHM IMPLEMENTATION********************************************************************



int main()
{
	int length,rotation;
	//Enter the length of the array
	printf("Enter the length of the array \n");
	scanf("%d",&length);
	//Enter the rotation number
	printf("Enter the rotation number \n");
	scanf("%d",&rotation);
	//creating the two arrays one actual and another temporary to store first d elements
	int arr[length],temp[rotation];
	
	printf("Enter the %d elements in the array",length);
	for(int i=0;i<length;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	
	//printing the intial array
	printf("Initial Array before rotation \n");
	printArray(arr,length);
	
	
	//copy the elements into the temp array
	for(int i=0;i<rotation;i++)
	{
		temp[i]=arr[i];
	}
	
	//for to shift the elements d places;
	for(int i=0;i<length-rotation;i++)
	{
		arr[i]=arr[i+rotation];
	}
	
	
	for(int i=length-rotation,j=0;i<length;i++,j++)
	{
		arr[i]=temp[j];
	}
	
	//printing the array function
	printf("Result after performing rotation \n");
	printArray(arr,length);
	return 0;
}

*/



/*

**************************************************************************SECOND ALGORITHM IMPLEMENTATION****************************************************************
   


int leftRotationFunction(int arr[],int length)
{
	int temp=arr[0];
	
	//shifting the elements to left
	for(int i=0;i<length-1;i++)
	{
		arr[i]=arr[i+1];
	}
	
	arr[length-1]=temp;
	
	return 0;
}

int rotationFunction(int arr[],int length,int rotation)
{
	
	for(int i=0;i<rotation;i++)
	{
			leftRotationFunction(arr,length);
	}
	
	return 0;
}


int main()
{
	int length,rotation;
	
	//Enter the length of the array
	printf("Enter the length of the array \n");
	
	scanf("%d",&length);
	
	//Enter the rotation number
	printf("Enter the rotation number \n");
	
	scanf("%d",&rotation);
	
	//Array to store the elements in the array
	int arr[length];
	
	printf("Enter the %d elements in the array",length);
	
	for(int i=0;i<length;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	//printing the intial array
	printf("Initial Array before rotation \n");
	printArray(arr,length);
	
	rotationFunction(arr,length,rotation);
	
	//printing the array function
	printf("Result after performing rotation \n");
	printArray(arr,length);
	
	return 0;
}


*/


/*

****************************************************THIRD ALGORITHM IMPLEMENTATION  ( JUGGLING ALGORITHM )*********************************************************************

*/
int gcd(int first,int second)
{
	if(second==0)
		return first;
	else
		return gcd(second,first%second);
}

int rotateFunction(int arr[],int length,int rotation)
{
	int j,k,temp;
	for(int i=0;i<gcd(length,rotation);i++)
	{
		temp=arr[i];
		j=i;
		while(true)
		{
			k=j+rotation;
			if(k>=length)
				k=k-length;
			if(k==i)
				break;
			arr[j]=arr[k];
			j=k;
		}
		arr[j]=temp;
	}
	return 0;
}

int main()
{
	int length,rotation;
	
	//Enter the length of the array
	printf("Enter the length of the array \n");
	
	scanf("%d",&length);
	
	//Enter the rotation number
	printf("Enter the rotation number \n");
	
	scanf("%d",&rotation);
	
	//Array to store the elements in the array
	int arr[length];
	
	printf("Enter the %d elements in the array",length);
	
	for(int i=0;i<length;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	//printing the intial array
	printf("Initial Array before rotation \n");
	printArray(arr,length);
	
	//Calling Function to rotate the elements of the array
	rotateFunction(arr,length,rotation);
	
	//printing the array function
	printf("Result after performing rotation \n");
	printArray(arr,length);
	
	return 0;
}