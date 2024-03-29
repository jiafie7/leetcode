// Source : https://leetcode.cn/problems/design-an-ordered-stream/
// Author : Garfield Zhang
// Date   : 2022-08-17

/************************************************************************************************************************
 *
 * There is a stream of n (idKey, value) pairs arriving in an arbitrary order, where idKey is an integer between 1 and n and value is a string. 
 * No two pairs have the same id.
 *
 * Design a stream that returns the values in increasing order of their IDs by returning a chunk (list) of values after each insertion. 
 * The concatenation of all the chunks should result in a list of the sorted values.
 *
 * Implement the OrderedStream class:
 * OrderedStream(int n) Constructs the stream to take n values.
 * String[] insert(int idKey, String value) Inserts the pair (idKey, value) into the stream, 
 * then returns the largest possible chunk of currently inserted values that appear next in the order.
 *
 ************************************************************************************************************************/

class OrderedStream:
    def __init__(self, n: int):
        self.str = [None for i in range(n)]
        self.k = 0

    def insert(self, idKey: int, value: str) -> List[str]:
        self.str[idKey - 1] = value 
        res = []
        while self.k < len(self.str) and self.str[self.k]:
            res.append(self.str[self.k])
            self.k += 1
        return res

# Your OrderedStream object will be instantiated and called as such:
# obj = OrderedStream(n)
# param_1 = obj.insert(idKey,value)


