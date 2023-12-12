def num_arrangements(record, pattern):
    table = {}
    def num_arr(i, j):
        if (i, j) in table:
            return table[(i, j)]
        if i == 0 and j == 0:
            return 1
        elif i == 0:
            return 0
        elif j == 0:
            return int(all(char != '#' for char in record[:i]))
        elif record[i-1] == '.':
            result = num_arr(i-1, j)
        else:
            num = pattern[j-1]
            if num > i or any(char == '.' for char in record[i-num:i]):
                result = 0
            elif i > num and record[i-num-1] == '#':
                result = 0
            else:
                result = num_arr(max(i-num-1, 0), j-1)
            if record[i-1] == '?':
                result += num_arr(i-1, j)
        table[(i, j)] = result
        return result
    return num_arr(len(record), len(pattern))

total1, total2 = 0, 0
with open('./test.txt', 'r') as f:
    for line in f.readlines():
        l, r = line.strip().split()
        l1 = l
        r1 = tuple(int(x) for x in r.split(','))
        l2 = '?'.join([l]*5)
        r2 = r1*5
        total1 += num_arrangements(l1, r1)
        total2 += num_arrangements(l2, r2)
print(total1)
print(total2)
