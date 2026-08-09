class Solution:
    def maxArea(self, mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])

        dp = [[0 for _ in range(n)] for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if mat[i][j] == 1:
                    if i == 0 or j == 0:
                        dp[i][j] = 1
                    else:
                        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1

        def isValid(k):
            minI, minJ = sys.maxsize, sys.maxsize
            maxI, maxJ = -1, -1
            
            for i in range(m):
                for j in range(n):
                    if dp[i][j] >= k:
                        minI, minJ, maxI, maxJ = min(minI, i), min(minJ, j), max(maxI, i), max(maxJ, j)
                        if maxI - minI >= k or maxJ - minJ >= k:
                            return True

            return False
        res = 0
        left, right = 0, min(m, n)
        while left <= right:
            k = left + ((right - left) >> 1)
            if isValid(k):
                res = k
                left = k + 1
            else:
                right = k - 1
        return res * res 