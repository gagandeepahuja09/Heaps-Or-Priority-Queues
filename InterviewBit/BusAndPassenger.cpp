/*
Bus and Passenger

There is bus having N rows, each row consist of two seats of equal size. Given an array A where A[i] determines the width of seats in the ith row.

There are 2*N passengers of type 0 and type 1 (exactly N passengers of type 0 and exactly N passengers of type 1).

Type 0 : Type 0 passenger always chooses a row where both seats are empty. Among these rows, he chooses the one with the smallest seat width and takes one of the seats in it.

Type 1 : Type 1 always chooses a row where exactly one seat is occupied (by a type 0 passenger). Among these rows, he chooses the one with the largest seat width and takes the vacant place in it.

You are given a string B determining the order the passenger entering the bus where B[i] is either '0' (type 0 passenger) or '1' (type 1 passenger).

Return an array of intergers C, where C[i] determines row taken by ith passenger*/
/*
Input 1:
    A = [3, 1]
    B = "0011"
Output 1:
    C= [2, 1, 1, 2]

Input 2:
    A = [10, 8, 9, 11, 13, 5]
    B = "010010011101"
Output 2:
    C= [6, 6, 2, 3, 3, 1, 4, 4, 1, 2, 5, 5]*/


#define pi pair<int, int>

vector<int> Solution::solve(vector<int> &A, string B) {
    priority_queue<pi> maxHeap;
    priority_queue<pi, vector<pi>, greater<pi>> minHeap;
    for(int i = 0; i < A.size(); i++) {
        minHeap.push({ A[i], i + 1 });
    }
    vector<int> C;
    for(int i = 0; i < B.size(); i++) {
        if(B[i] == '0') {
            if(!minHeap.empty()) {
                pi p = minHeap.top();
                C.push_back(p.second);
                minHeap.pop();
                maxHeap.push(p);
            }
        }
        else {
            if(!maxHeap.empty()) {
                pi p = maxHeap.top();
                C.push_back(p.second);
                maxHeap.pop();
            }
        }
    }
    return C;
}

