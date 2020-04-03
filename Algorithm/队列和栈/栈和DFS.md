# 栈

对于我们常用的 `Python` 我们使用 `stack=[]` 就可以了。

### 最小栈

```python
class MinStack:

    def __init__(self):
        self.min=sys.maxsize
        self.stack=[]

    def push(self, x: int) -> None:
        self.stack.append(x-self.min)
        if x<self.min:
            self.min=x
            
    def pop(self) -> None:
        target=self.stack.pop()
        if target<0:
            self.min=self.min-target
        
    def top(self) -> int:
        if self.stack:
            target=self.stack[-1]
            if target<0:return self.min
            return target+self.min

    def getMin(self) -> int:
        return self.min
```

### 有效的括号

注意无效情况的快速判断 - 剪枝

```python
class Solution:
    def isValid(self, s: str) -> bool:
        stack=[]
        pairs={'(':')','[':']','{':'}'}
        for char in s:
            if char in pairs:
                stack.append(char)
            else:
                if len(stack)==0:return False
                if pairs[stack[-1]]!=char:return False
                else:stack.pop()
        return len(stack)==0
```

### 每日温度

栈里面存储的是递减的元素 - 栈题型中：里面存储元素的特异性

```python
class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        if not T:return 0
        length=len(T)
        
        stack=[]
        result=[0 for _ in range(length)]
        
        for idx,temp in enumerate(T):
            if len(stack)==0:
                stack.append(idx)
                continue
            if temp<=T[stack[-1]]:
                stack.append(idx)
                continue
            while stack and temp>T[stack[-1]]:
                result[stack[-1]]=idx-stack[-1]
                stack.pop()
            stack.append(idx)
            
        return result
```

### 逆波兰表达式求值

注意 `Python除法` 的细节，`-6//12=-1`，所以最后使用了 `int(op1/op2)`

```python
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack=[]
        operations=['+','-','*','/']
        for element in tokens:
            if element in operations:
                op2=stack.pop()
                op1=stack.pop()
                if element=='+':stack.append(op1+op2)
                elif element=='-':stack.append(op1-op2)
                elif element=='*':stack.append(op1*op2)
                elif element=='/':stack.append(int(op1/op2))
            else:
                stack.append(int(element))
        
        return stack[-1]
```

# DFS

在我们到达`最深的`结点之后，我们`只`会回溯并尝试另一条路径。

### DFS模板 I

这个模板是我最开始写题目时候最顺手的一个模板：

- 代码简洁易懂，对节点的判断在进入函数之后
- 同时也可以产生出新的版本：
  - 在进入递归之前首先对于节点的有效性进行判断
  - 对于递归的出口仍然保留在进入递归之后，不僭越进行判断
  - 这样减少不必要的函数调用，同时能够使得递归形式更加简洁

```python
visited=[[False for i in range(m)] for j in range(n)]

def dfs(curr,target):
    if curr is invalid or curr is visited:return
    if curr==target:result.append(curr)
    
    visited[curr]=True
    #对当前节点其他操作
    Some_operation()
    for next in neibours:
        dfs(next,target)
    #如果回溯
    #visited[curr]=False   
```

判断版本：主要是担心判断的时候不充分，或者判断太复杂

```python
visited=[[False for i in range(m)] for j in range(n)]

def dfs(curr,target):
    if curr==target:result.append(curr)
    
    visited[curr]=True
    #对当前节点其他操作
    Some_operation()
    for next in neibours:
        if next is valid and next is not visited:
        	dfs(next,target)
    #如果回溯
    #visited[curr]=False   
```



### 岛屿数量

```python
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid or not grid[0]:return 0
        m,n=len(grid),len(grid[0])
        
        directions=[(1,0),(-1,0),(0,1),(0,-1)]
        
        def dfs(r,c):
            if r<0 or r>=m or c<0 or c>=n or grid[r][c]=='0' :return 
            grid[r][c]='0'
            for d in directions:
                dfs(r+d[0],c+d[1])
                
        count=0
        for i in range(m):
            for j in range(n):
                if grid[i][j]=='1':
                    count+=1
                    dfs(i,j)
        return count
```

### 克隆图

克隆问题都可以是类似的思路。

```python
class Solution:
    def __init__(self):
        self.visited={}
        
    def cloneGraph(self, node: 'Node') -> 'Node':
        
        if not node:return node
        if node in self.visited:return self.visited[node]
        clone_node=Node(node.val,[])
        self.visited[node]=clone_node        
        if node.neighbors:
            clone_node.neighbors=[self.cloneGraph(i) for i in node.neighbors]
        return clone_node
```

### 目标和

展示两种方法：

1. 纯正的DFS但是超时了，可能大量重复计算了

   ```python
   class Solution:
       def findTargetSumWays(self, nums: List[int], S: int) -> int:
           if not nums:return 0
           self.count,self.length=0,len(nums)
           
           def dfs(curr,bit):
               if curr==0 and bit==self.length:
                   self.count+=1
                   return
               if bit==self.length:return
               dfs(curr+nums[bit],bit+1)
               dfs(curr-nums[bit],bit+1)
           
           dfs(-S,0)
           return self.count
   ```

2. DFS要学会 `类似树状展开` 的计算方式

   ```python
   class Solution:
       def findTargetSumWays(self, nums: List[int], S: int) -> int:
           if not nums:return 0
           self.visited,self.length={},len(nums)
           def dfs(curr,i):
               if i<self.length and (curr,i) not in self.visited:
                   self.visited[(curr,i)]=dfs(curr+nums[i],i+1)+dfs(curr-nums[i],i+1)
               return self.visited.get((curr,i),int(curr==S))
           return dfs(0,0)
   ```

### DFS模板 II

避免递归深度太高，堆栈溢出 -> 使用BFS，或者显式栈实现DFS

```python
def DFS(root,target):
    visited=set()
    stack=[root]
    while stack:
        curr=stack[-1]
        if curr==target:return True
        for next in neibours:
            if next is not in visited:
                stack.append(next)
                visited.add(next)
        remove curr from stack
    return False
```

### 中序遍历

```python
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        if not root:return []
        result,stack=[],[(root,0)]
        while stack:
            node,times=stack.pop()
            if not node:continue
            if times==1:
                result.append(node.val)
                stack.append((node.right,0))
                continue
            stack.append((node,1))
            stack.append((node.left,0))
        return result
```

