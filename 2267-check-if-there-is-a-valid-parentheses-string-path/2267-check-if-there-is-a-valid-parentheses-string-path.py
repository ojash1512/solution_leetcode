class Solution:
    def hasValidPath(self, grid: list[list[str]]) -> bool:
        m = len(grid)
        n = len(grid[0])

        if grid[0][0] == ')' or grid[m - 1][n - 1] == '(':
            return False

        if (m + n - 1) % 2 != 0:
            return False

        memo = {}

        def dfs(r, c, balance):
            balance += 1 if grid[r][c] == '(' else -1

            if balance < 0:
                return False

            remaining = (m - 1 - r) + (n - 1 - c)

            if balance > remaining:
                return False

            if r == m - 1 and c == n - 1:
                return balance == 0

            state = (r, c, balance)

            if state in memo:
                return memo[state]

            result = False

            if r + 1 < m:
                result = dfs(r + 1, c, balance)

            if not result and c + 1 < n:
                result = dfs(r, c + 1, balance)

            memo[state] = result
            return result

        return dfs(0, 0, 0)