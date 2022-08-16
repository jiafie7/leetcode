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
    int[] q;
    int hh = 0, tt = 0;
    public MyCircularDeque(int k) {
        q = new int[k + 1]; 
    }
    
    private int get(int x){
        return (x + q.length) % q.length;
    }

    public boolean insertFront(int value) {
        if (isFull()) return false;
        hh = get(hh - 1);
        q[hh] = value;
        return true;
    }
    
    public boolean insertLast(int value) {
        if (isFull()) return false;
        q[tt] = value;
        tt = get(tt + 1);
        return true;
    }
    
    public boolean deleteFront() {
        if (isEmpty()) return false;
        hh = get(hh + 1);
        return true;
    }
    
    public boolean deleteLast() {
        if (isEmpty()) return false;
        tt = get(tt - 1);
        return true;
    }
    
    public int getFront() {
        if (isEmpty()) return -1;
        return q[hh];
    }
    
    public int getRear() {
        if (isEmpty()) return -1;
        return q[get(tt - 1)];
    }
    
    public boolean isEmpty() {
        return hh == tt;
    }
    
    public boolean isFull() {
        return tt == get(hh - 1);
    }
}

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque obj = new MyCircularDeque(k);
 * boolean param_1 = obj.insertFront(value);
 * boolean param_2 = obj.insertLast(value);
 * boolean param_3 = obj.deleteFront();
 * boolean param_4 = obj.deleteLast();
 * int param_5 = obj.getFront();
 * int param_6 = obj.getRear();
 * boolean param_7 = obj.isEmpty();
 * boolean param_8 = obj.isFull();
 */
