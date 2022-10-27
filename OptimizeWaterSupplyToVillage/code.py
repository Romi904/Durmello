class disjointset:
    def __init__(self, n):
        self.parent = []
        self.rank = []
        for i in range(n+1):
            self.parent.append(i)
            self.rank.append(0)
    
    def find(self, idx):
        if self.parent[idx]==idx:
            return idx
        return self.find(self.parent[idx])
    
    def union(self, x, y, c):
        x1, y1 = self.find(x), self.find(y)
        if x1==y1: return False # already in same ntw no need to update cost
        if self.rank[x1]>self.rank[y1]:
            self.parent[y1] = x1
        elif self.rank[x1]<self.rank[y1]:
            self.parent[x1] = y1
        else:
            self.parent[y1] = x1
            self.rank[x1]+=1
        return True
        
class Solution:
    def minCostToSupplyWater(self, n: int, wells: List[int], pipes: List[List[int]]) -> int:
        cost = 0
        edges = [[0, i+1, wells[i]] for i in range(n)]
        for i in pipes:
            edges.append(i)
        edges.sort(key=lambda i: i[2]) # sort by cost
        ds = disjointset(n)
        
        # for each pipes check if connecting is min or well is min
        for (x,y,c) in edges:
            if ds.union(x,y,c):
                cost += c
            
        return cost