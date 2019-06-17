/*
Help the TA

Ayush has recently joined InterviewBit Academy as TA (Teaching Assistant). He has been assigned a job to keep record of all the errors each student is having in his batch and report it to the Mentor.

Since, the mentor gives extra attention to weak students, he resolves the issues of student having maximum number of errors first. But, to keep equality among students, he gives one minute to each student to resolve one of his errors and then ask the TA for next student.

Also, the lecture would not last more than B minutes and whenever a student has no more errors left, he leaves the lecture immediately.

Ayush, being confused each time, needs your help to shout out the roll number of student who should be helped at any time i.
You are given an array of integers, where A[i] denotes number of errors in code of student with roll number i.
Return a list containing the roll numbers,where element at index i denotes the roll number to be helped at minute i.
Ayush should keep on shouting roll numbers unless the B minutes are over or, the class is empty(everyone has left).

HINT: The returning array size will depend on the time till which roll numbers are shouted.

NOTE

1. Roll Numbers are 0-indexed (i.e, Roll numbers start from 0)

2. In case of tie(same number of errors), the least roll number is given preference.

3. There is no restriction on spending more than one minute consecutively on one student, as far as the mentor's condtions are met

4. Your code will be run on multiple test cases(<=10), try to come up with optimised solution.

Constraints

1 <= Number of Students <= 10^6
0 <= A[i] : Errors for each student <= 10^5
0 <= Sum of All Errors <= 10^6
1 <= B <= 10^6

Sample Input

4 2 5 3 6
4

Sample Output

4 2 4 0

Explanation

At i-th minute, the roll number to be help is announced :
0th minute: Roll 4 is having 6 errors
1st minute: Roll 2 and 4 are having 5 errors
2nd minute: Roll 4 is having 5 errors
3rd minute: Roll 0, 2 and 4 are having 4 errors
4th minute: Lecture ends!
So output would be [4 2 4 0]
*/

class cmp {
    public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if(a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;    
    }
};

vector<int> Solution::solve(vector<int> &A, int B) {
    vector<int> ret;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    for(int i = 0; i < A.size(); i++) {
        pq.push({ A[i], i });
    }
    int k = 0;
    while(!pq.empty() && B--) {
        pair<int, int> p = pq.top();
        if(!p.first)
            break;
        pq.pop();
        ret.push_back(p.second);
        pq.push({ p.first - 1, p.second });
    }
    return ret;
}

