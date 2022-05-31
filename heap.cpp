#include<iostream>
#include<vector>
using namespace std;

void insert(vector<int> & heap,int item){
	heap.push_back(item);
	int i=heap.size()-1;
	while(i>1 && heap[(i-1)/2]<heap[i]){
		swap(heap[i],heap[(i-1)/2]);
		i=(i-1)/2;
	}
}

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

int* delete_max(int arr[],int size){
	int * arr_new=new int[size-1];

	if(size==0){
		cout<<"Empty Heap"<<endl;
	}
	else{
		int x=arr[0];
		arr[0]=arr[size-1];
		copy(arr,arr+size-1,arr_new);
		adjust(arr_new,size-1,0);
	}
	return arr_new;

}

void print_heap(int heap[],int size){
	for(int i=0;i<size;i++){
		cout<<heap[i]<<" ";
	}
	cout<<endl;
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

int main(){

	int arr[]={100,119,118,171,112,151,132};
	int size=sizeof arr/sizeof arr[0];

	print_heap(arr,size);

	heap_sort(arr,size);

	//heapify the array
	//swap first and last element
	//adjust heap leaving the last elements
	
	print_heap(arr,size);

}