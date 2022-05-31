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

void print_heap(vector<int> heap){
	for(int i=0;i<heap.size();i++){
		cout<<heap[i]<<" ";
	}
	cout<<endl;
}

int main(){
	vector<int> heap={80,45,70,40,35,50};

	insert(heap,90);

	print_heap(heap);
}