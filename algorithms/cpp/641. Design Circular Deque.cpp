// Source : https://leetcode.cn/problems/design-circular-deque/
// Author : Hang Zhang
// Date   : 2022-08-16

/**************************************************************************************************************************
 *
 * Design your implementation of the circular double-ended queue (deque).
 *
 * Implement the MyCircularDeque class:
 *
 * MyCircularDeque(int k) Initializes the deque with a maximum size of k.
 * boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
 * boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
 * boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
 * boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
 * int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
 * int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
 * boolean isEmpty() Returns true if the deque is empty, or false otherwise.
 * boolean isFull() Returns true if the deque is full, or false otherwise.
 *
 *************************************************************************************************************************/

class MyCircularDeque {
public:
    vector<int> q;
    int hh = 0, tt = 0;

    MyCircularDeque(int k) {
        q.resize(k + 1);
    }
    
    int get(int x) {
        return (x + q.size()) % q.size(); 
    }

    bool insertFront(int value) {
        if (isFull()) return false;
        hh = get(hh - 1);
        q[hh] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        q[tt] = value;
        tt = get(tt + 1);
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        hh = get(hh + 1);
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        tt = get(tt - 1);
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return q[hh];
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        return q[get(tt - 1)];
    }
    
    bool isEmpty() {
        return hh == tt;
    }
    
    bool isFull() {
        return tt == get(hh - 1);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
 
