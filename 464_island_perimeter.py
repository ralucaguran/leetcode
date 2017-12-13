class Solution(object):
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        rows = len(grid)
        cols = len(grid[0])
        perimeter = 0
        perimeter += sum(grid[0])
        perimeter += sum(grid[rows-1])
        for row in grid:
            perimeter += row[0] + row[cols-1]
        for row in range(rows):
            for col in range(cols):
                if grid[row][col] == 0:
                    if row-1 >= 0:
                        perimeter += grid[row-1][col]
                    if row+1 < rows:
                        perimeter += grid[row+1][col]
                    if col-1 >= 0: 
                        perimeter += grid[row][col-1]
                    if col+1 < cols:
                        perimeter += grid[row][col+1]
        return perimeter


grid = [[0,1,0,0],
        [1,1,1,0],
        [0,1,0,0],
        [1,1,0,0]]
sol = Solution()
assert sol.islandPerimeter(grid) == 16

