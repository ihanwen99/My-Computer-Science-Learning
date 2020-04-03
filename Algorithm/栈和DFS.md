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

### DFS模板

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

