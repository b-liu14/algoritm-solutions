import numpy as np 

class NumArray:

    def __init__(self, nums):
        self.n = len(nums)

        self.A = np.zeros(self.n, dtype=int)
        self.C = np.zeros(self.n, dtype=int)

        for i, a in enumerate(nums):
            self.update(i, a)

    @staticmethod
    def low_bit(n):
        return n & -n

    def update(self, i: int, val: int) -> None:
        delta = val - self.A[i]
        self.A[i] = val
        while i < len(self.C):
            self.C[i] += delta
            i += self.low_bit(i+1)

    def sumRange(self, i: int, j: int) -> int:
        return self.sum(j+1) - self.sum(i)

    def sum(self, i):
        s = 0
        while i > 0:
            s += self.C[i-1]
            i -= self.low_bit(i)
            
        return s

n = 100
nums = range(n)

obj = NumArray(nums)
assert obj.sumRange(0, n-1) == n * (n - 1) / 2 
obj.update(7, 10)
assert obj.sumRange(0, 7) == 7 * 8 / 2 + 3