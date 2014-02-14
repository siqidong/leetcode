class Solution:
    # @param A, a list of integer
    # @return an integer
    def singleNumber(self, A):
        res = 0
        for i in xrange(0, len(A)):
            res ^= A[i]
        return res


#test part
X = [1,2,2,3,3,1,4,5,6,4,6]
S = Solution()
print S.singleNumber(X)