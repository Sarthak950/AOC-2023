import sys
from collections import defaultdict 
file = open(sys.argv[1], 'r').read().strip()
ans = 0

for line in file.split('\n'):
    id, line = line.split(':')
    V = defaultdict(int)

    for event in line.split(';'):
        for balls in event.split(','):
            n, color = balls.split()
            n = int(n)
            V[color] = max(V[color], n)
    score = 1

    for v in V.values():
        score *= v
    ans += score 
print(ans)

