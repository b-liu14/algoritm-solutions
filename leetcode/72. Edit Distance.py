# -*- coding: utf-8 -*-

class Solution(object):

    # 核心代码，传入两个字符串x，y以及六种操作的cost，返回产生最小编辑距离的操作和最小cost
    def get_min_edit_diatance(self, x, y, cost_replace, cost_delete, cost_insert):
        # 一些参数的初始化
        x = list(' ' + x)
        y = list(' ' + y)
        m = len(x) - 1
        n = len(y) - 1
        cost = [[float('inf') for col in range(n+1)] for row in range(m+1)]
        for row in range(1, m+1):
            cost[row][0] = cost_delete * row
        for col in range(1, n+1):
            cost[0][col] = cost_insert * col
        cost[0][0] = 0
        # 开始动态规划
        for i in range(1, m+1):
            for j in range(1, n+1):
                cost[i][j] = cost[i][j - 1] + cost_insert
                if x[i] == y[j] and cost[i][j] > cost[i-1][j-1]:
                    cost[i][j] = cost[i-1][j-1]
                if cost[i][j] > cost[i-1][j-1] + cost_replace:
                    cost[i][j] = cost[i-1][j-1] + cost_replace
                if cost[i][j] > cost[i-1][j] + cost_delete:
                    cost[i][j] = cost[i-1][j] + cost_delete
        return cost[m][n]

    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        cost = self.get_min_edit_diatance(word1, word2, 1, 1, 1)
        return cost
