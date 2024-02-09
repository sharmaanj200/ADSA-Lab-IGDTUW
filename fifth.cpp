/*
Program 5:
Bubble, insertion, selection,merge, quick sort
Plot graphs for time complexity of sorted, reverse sorted and random arrays for varying 10 different sizes of the array
*/

#include<bits/stdc++.h>
using namespace std;


//swap adjacent elements of the array if those are not passing the condition check.
void bubble_sort(int *arr, int n)
{
    int min;
    //number of times we compare
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(arr[j] > arr[j+1]) 
                swap(arr[j],arr[j+1]);
        }
    }
}


void insertion_sort(int *arr, int n)
{
    for(int i=1; i<n; i++)
    {
        int curr = arr[i];
        int prev = i-1;
        while(prev >= 0 and arr[prev] > curr)
        {
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
    }
}



void selection_sort(int *arr, int n)
{
    for(int i=0; i<n; i++)
    {
        int min = i;

        for(int j=i+1; j<n; j++)
        {
            if(arr[j] < arr[min]) min = j;
        }

        swap(arr[i], arr[min]);
    }
}



void merge(int *arr, int s, int e)
{

    int m = (s + e) / 2;   

    int len1 = m - s + 1;
    int len2 = e - m;

    int *first = new int[len1];
    int *second = new int[len2];

    int main_index = s;

    for(int i=0; i<len1; i++)
    {
        first[i] = arr[main_index++];
    }

    main_index = m + 1;

    for(int i=0; i<len2; i++)
    {
        second[i] = arr[main_index++];
    }

    int index1 = 0;
    int index2 = 0;
    main_index = s;

    while(index1 < len1 and index2 < len2)
    {
        if(first[index1] > second[index2]) 
            arr[main_index++] = second[index2++];

        else 
            arr[main_index++] = first[index1++];
    }

    while(index1 < len1)
    {
        arr[main_index++] = first[index1++];
    }

    while(index2 < len2)
    {
        arr[main_index++] = second[index2++];
    }

    delete []first;
    delete []second;
}


void mergeSort(int *arr, int s, int e)
{
    if(s >= e) 
    {
        return;
    }

    int m = (s + e) / 2;

    //sorting first half of the array.
    mergeSort(arr, s, m);

    //sorting the second half of the array.
    mergeSort(arr, m+1, e);

    //merge the two arrays.
    merge(arr, s, e);
}



int partition(int *arr, int s, int e)
{
    int pivot = arr[s];
    int count = 0;
    for(int i=s+1; i<=e; i++)
    {
        if(arr[i] <= pivot)
            count++;
    }

    int pivotIndex = s + count;

    swap(arr[s], arr[pivotIndex]);

    int left = s;
    int right = e;

    while(left < pivotIndex and right > pivotIndex)
    {
        while(arr[left] <= pivot) 
            left++;

        while(arr[right] > pivot) 
            right--;

        if( left < pivotIndex and right > pivotIndex )
        {
            swap(arr[left++], arr[right--]);
        }
    }

    return pivotIndex;
}


void quickSort(int *arr, int s, int e)
{
    if(s >= e)
        return;

    int p = partition(arr, s, e);

    //left side array
    quickSort(arr, s, p-1);

    //right side array
    quickSort(arr, p+1, e);
}



int main()
{
    int arr1[] = {9,9,2,5,1,8,2,9,3};
    int n = sizeof(arr1)/sizeof(int);
    cout<<"merge_sort"<<endl;
    mergeSort(arr1, 0, n-1);
    cout<<"sorted array is : ";
    for(auto x: arr1)cout<<x<<" ";
    cout<<endl;


    int arr2[] = {9,9,2,5,1,8,2,9,3};
    cout<<"quick_sort"<<endl;
    quickSort(arr2, 0, n-1);
    cout<<"sorted array is : ";
    for(auto x: arr2)cout<<x<<" ";
    cout<<endl;

    int arr3[] = {9,9,2,5,1,8,2,9,3};
    cout<<"bubble_sort"<<endl;
    bubble_sort(arr3, n);
    cout<<"sorted array is : ";
    for(auto x: arr3)cout<<x<<" ";
    cout<<endl;

    int arr4[] = {9,9,2,5,1,8,2,9,3};
    cout<<"selection_sort"<<endl;
    selection_sort(arr4, n);
    cout<<"sorted array is : ";
    for(auto x: arr4)cout<<x<<" ";
    cout<<endl;

    int arr5[] = {9,9,2,5,1,8,2,9,3};
    cout<<"insertion_sort"<<endl;
    insertion_sort(arr5, n);
    cout<<"sorted array is : ";
    for(auto x: arr5)cout<<x<<" ";
    cout<<endl;
}