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

void adjust(vector<int> & heap,int i){
	int largest_index=i;
	int n=heap.size()-1;

	int left_child_index=2*i+1;
	int right_child_index=2*i+2;

	if(left_child_index<n && heap[left_child_index]>heap[largest_index]){
		largest_index=left_child_index;
	}
	if(right_child_index<n && heap[right_child_index]>heap[largest_index]){
		largest_index=right_child_index;
	}
	if(largest_index!=i){
		swap(heap[largest_index],heap[i]);
		adjust(heap,largest_index);
	}
}

void delete_max(vector<int> & heap){
	if(heap.size()==0){
		cout<<"Empty Heap"<<endl;
		return;
	}
	int x=heap[0];
	heap[0]=heap.back();
	heap.pop_back();
	adjust(heap,0);
}

void print_heap(vector<int> heap){
	for(int i=0;i<heap.size();i++){
		cout<<heap[i]<<" ";
	}
	cout<<endl;
}

int main(){
	vector<int> heap={80,45,70,40,35,50};

	insert(heap,90);

	delete_max(heap);

	print_heap(heap);
}