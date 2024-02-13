import heapq

def max_priority(priorities, idle, len):
    pq = [-i for i in priorities]
    heapq.heapify(pq)
    q = []
    time = 1
    res = 0
    while time <= len:
        if pq:
            p = heapq.heappop(pq) 
            if p:
                q.append([p,time + idle])
                res += -p
            time += 1
        else:
            time = q[0][1]
            heapq.heappush(pq,q[0][0])
            q.pop(0)
            
    return res

_pros = [3, 1, 2]
_idle = 5
n = 1

print(max_priority(_pros, _idle, n))
            
        
        
    