#include<queue>

//max heap
priority_queue<int> pq;
pq.push(4);
pq.push(2);
pq.push(5);
pq.push(3);

cout << "element at top" << pq.top();
pq.pop();
cout << "element at top" << pq.top();
if(pq.empty()){
	cout<<"empty"<<endl;
}
else{
	cout<<"not empty"<<endl;
}

//min heap
priority_queue<int, vector<int>, greater<int>> minHeap;
minHeap.push(4);
minHeap.push(2);
minHeap.push(5);
minHeap.push(3);

cout << "element at top" << minHeap.top();
minHeap.pop();
cout << "element at top" << minHeap.top();
if(minHeap.empty()){
	cout<<"empty"<<endl;
}
else{
	cout<<"not empty"<<endl;
}
