// Source : https://leetcode.cn/problems/design-circular-deque/
// Author : Garfield Zhang
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
 
 class MyCircularDeque:

    def __init__(self, k: int):
        self.q = [0 for i in range(k + 1)]
        self.hh = 0
        self.tt = 0

    def get(self, x):
        return (x + len(self.q)) % len(self.q)

    def insertFront(self, value: int) -> bool:
        if self.isFull():
            return False
        self.hh = self.get(self.hh - 1)
        self.q[self.hh] = value
        return True

    def insertLast(self, value: int) -> bool:
        if self.isFull():
            return False
        self.q[self.tt] = value
        self.tt = self.get(self.tt + 1)
        return True

    def deleteFront(self) -> bool:
        if self.isEmpty():
            return False
        self.hh = self.get(self.hh + 1)
        return True

    def deleteLast(self) -> bool:
        if self.isEmpty():
            return False
        self.tt = self.get(self.tt - 1)
        return True

    def getFront(self) -> int:
        if self.isEmpty():
            return -1
        return self.q[self.hh]

    def getRear(self) -> int:
        if self.isEmpty():
            return -1
        return self.q[self.tt - 1]

    def isEmpty(self) -> bool:
        return self.tt == self.hh

    def isFull(self) -> bool:
        return self.tt == self.get(self.hh - 1)


# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()
 
