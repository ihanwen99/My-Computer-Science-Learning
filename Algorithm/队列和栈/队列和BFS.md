# 队列

### 设计循环队列

```python
class MyCircularQueue:

    def __init__(self, k: int):
        """
        Initialize your data structure here. Set the size of the queue to be k.
        """
        self.queue = [0]*k
        self.headIndex = 0
        self.count = 0
        self.capacity = k

    def enQueue(self, value: int) -> bool:
        """
        Insert an element into the circular queue. Return true if the operation is successful.
        """
        if self.count == self.capacity:
            return False
        self.queue[(self.headIndex + self.count) % self.capacity] = value
        self.count += 1
        return True

    def deQueue(self) -> bool:
        """
        Delete an element from the circular queue. Return true if the operation is successful.
        """
        if self.count == 0:
            return False
        self.headIndex = (self.headIndex + 1) % self.capacity
        self.count -= 1
        return True

    def Front(self) -> int:
        """
        Get the front item from the queue.
        """
        if self.count == 0:
            return -1
        return self.queue[self.headIndex]

    def Rear(self) -> int:
        """
        Get the last item from the queue.
        """
        # empty queue
        if self.count == 0:
            return -1
        return self.queue[(self.headIndex + self.count - 1) % self.capacity]

    def isEmpty(self) -> bool:
        """
        Checks whether the circular queue is empty or not.
        """
        return self.count == 0

    def isFull(self) -> bool:
        """
        Checks whether the circular queue is full or not.
        """
        return self.count == self.capacity
```

### 数据流中的移动平均值

```python
class MovingAverage:

    def __init__(self, size: int):
        self.maxSize=size
        self.window=[]
        

    def next(self, val: int) -> float:
        if len(self.window)==self.maxSize:
            self.window.pop(0)
        self.window.append(val)
        return sum(self.window)/len(self.window)
```



# BFS

广度优先搜索（BFS）的一个常见应用是找出从根结点到目标结点的最短路径。

**BFS模板**：通常使用队列 + 不重复元素的`hashmap`或者`visited`

```python
def BFS(root, target):
    if not root:return xx
    queue=collections.deque()
    visited = [[False for i in range(n)] for j in range(m)]
    
    step=0
    queue.append(root)
    
    while queue:
        step+=1
        size=len(queue)
        for i in range(size):
            curr=queue.popleft()
            visited[curr]=True
            if curr==target:return step
            for next in neibours:
                if next not in visited:
                    queue.append(next)
                   	vivisted[next]=True
            
```

两种情况不需要使用`visited`：

- 树：确定没有循环
- 希望多次访问同一个节点

### 岛屿数量：基础BFS

```python
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid or not grid[0]:return 0
        m,n=len(grid),len(grid[0])
        directions=[(1,0),(-1,0),(0,1),(0,-1)]
        
        def bfs(r,c):
            queue=collections.deque()
            queue.append((r,c))
            while queue:
                size=len(queue)
                for _ in range(size):
                    currR,currC=queue.popleft()
                    if currR<0 or currR>=m or currC<0 or currC>=n:continue
                    if grid[currR][currC]=='0':continue
                    grid[currR][currC]='0'
                    for d in directions:
                        queue.append((currR+d[0],currC+d[1]))
        
        count=0
        for i in range(m):
            for j in range(n):
                if grid[i][j]=='1':
                    count+=1
                    bfs(i,j)
        return count
                
```

### 打开转盘锁：字符串处理邻居

```python
class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        def neibours_process(curr):
            result=[]
            for i in range(4):
                result.append(curr[:i]+str((int(curr[i])+1)%10)+curr[i+1:])
                result.append(curr[:i]+str((int(curr[i])-1)%10)+curr[i+1:])
            return result
        
        def bfs(root,target):
            queue=collections.deque()
            queue.append(root)
            visited=set()
            step=0
            
            while queue:
                size=len(queue)
                for _ in range(size):
                    curr=queue.popleft()
                    if curr in visited:continue
                    if curr in deadends:continue
                    if curr==target:return step
                    visited.add(curr)
                    neibours=neibours_process(curr)
                    for next in neibours:
                        queue.append(next)
                step+=1
        
        result=bfs("0000",target)
        return result if isinstance(result,int) else -1
```

### 完全平方数：简单剪枝

```python
class Solution:
    def numSquares(self, n: int) -> int:
        if n==1:return 1
        def bfs(n):
            queue=collections.deque()
            queue.append(n)
            count=0
            
            while queue:
                size=len(queue)
                for _ in range(size):
                    number=queue.popleft()
                    temp=int(sqrt(number))
                    if number==temp**2:return count+1
                    for i in range(temp,0,-1):
                        queue.append(number-i**2)
                        
                count+=1
        count=bfs(n)
        return count if isinstance(count,int) else -1
```

### 墙与门：多源点同步BFS

```python
class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        if not rooms or not rooms[0]:return rooms
        m,n=len(rooms),len(rooms[0])
        queue=collections.deque()
        visited=[[False for i in range(n)]for j in range(m)]
        directions=[(1,0),(-1,0),(0,1),(0,-1)]
        step=0
            
        for i in range(m):
            for j in range(n):
                if rooms[i][j]==0:
                    queue.append((i,j))
                    
        while queue:
            size=len(queue)
            for _ in range(size):
                currR,currC=queue.popleft()
                if currR<0 or currR>=m or currC<0 or currC>=n:continue
                if visited[currR][currC]:continue                    
                if rooms[currR][currC]==-1:continue
                if rooms[currR][currC]>step:rooms[currR][currC]=step
                visited[currR][currC]=True

                for d in directions:
                    queue.append((currR+d[0],currC+d[1]))
            step+=1  
                
        return rooms
```

---

# 总结

1. Python的队列

   ```python
   queue=collections.deque()
   
   queue.append(element)
   queue.popleft()
   
   size=len(queue)
   ```

2. 整体来看 `BFS` 算法思想就是层次遍历
3. 注意是否需要`visited` 和 如何生成 `neighbors`