import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n, m, r = map(int, input().split())
graph = [[] for _ in range(n+1)]  
for _ in range(m):
    u, v = map(int, input().split())
    graph[u].append(v)     
    graph[v].append(u)
for i in range(n+1):   
    graph[i].sort()

cnt = [0 for _ in range(n+1)]  
visited = [False] * len(graph)   
t = 1  

def dfs(graph, r, visited):
    global t
    
    visited[r] = True
    cnt[r] = t 
    t += 1
    
    for node in graph[r]:
        if not visited[node]:
            dfs(graph, node, visited)

dfs(graph, r, visited)

for i in range(1, n+1):
    print(cnt[i])