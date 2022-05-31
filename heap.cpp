#include<iostream>
#include<vector>
using namespace std;

void adjust(int arr[],int n,int i){
	int largest_index=i;

	int left_child_index=2*i+1;
	int right_child_index=2*i+2;

	if(left_child_index<n && arr[left_child_index]>arr[largest_index]){
		largest_index=left_child_index;
	}
	if(right_child_index<n && arr[right_child_index]>arr[largest_index]){
		largest_index=right_child_index;
	}
	if(largest_index!=i){
		swap(arr[largest_index],arr[i]);
		adjust(arr,n,largest_index);
	}
}


void heapify(int arr[],int size){
	for(int i=size/2;i>0;i--){
		adjust(arr,size,i-1);
	}
}

void heap_sort(int arr[],int size){
	heapify(arr,size);
	
	for(int i=size-1;i>0;i--){
		swap(arr[i],arr[0]);
		adjust(arr,i,0);
	}
}

void print_array(int arr[],int size){
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(){

	int arr[]={100,119,118,171,112,151,132};
	int size=sizeof arr/sizeof arr[0];

	cout<<"Before Heap Sort : ";

	print_array(arr,size);

	heap_sort(arr,size);

	//heapify the array
	//swap first and last element
	//adjust heap leaving the last elements

	cout<<"After Heap Sort : ";

	print_array(arr,size);

}