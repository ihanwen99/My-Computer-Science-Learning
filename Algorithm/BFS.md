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