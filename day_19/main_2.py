import copy

def process_input(filename):
    """Acquire input data"""
    with open(filename) as file:
        input = file.read().splitlines()

    workflows = {}

    for line in input:
        if len(line) == 0: break

        line = line.replace('}','')
        token = line.split('{')
        workflow_name = token[0]
        workflow_rules = []
        rules = token[1].split(',')
        for rule in rules[:-1]:
            token = rule.split(':')
            next_workflow = token[1]
            attrib = token[0][0]
            op = token[0][1]
            rating = int(token[0][2:])
            workflow_rules.append((attrib,op,rating,next_workflow))
        workflow_rules.append(('L','=',-1,rules[-1]))
        workflows[workflow_name] = workflow_rules

    return workflows


def check_all_parts():
    accepted = []
    while len(queue) > 0:
        part = queue.pop()
        result = run_workflow(part)
        if result == 'A':
            accepted.append(part)
    return accepted

def run_workflow(part):
    workflow = 'in'
    while True:
        rules = workflows[workflow]
        for rule in rules:
            workflow = test_rule(part, rule)
            if workflow == '':
                continue
            if workflow in ('A','R'):
                return workflow
            break
    return workflow

def test_rule(part, rule):
    attrib, op, rating, next = rule
    if op == '=':
        return next
    elif op == '<':
        if split_part_less(part, attrib, rating):
            return next
    elif op == '>':
        if split_part_greater(part, attrib, rating):
            return next
    return ''

def split_part_less(part, attrib, rating):
    if part[attrib][1] < rating:
        return True # entire range meets condition
    if part[attrib][0] >= rating:
        return False # entire range fails condition
    false_part = copy.deepcopy(part)
    false_part[attrib][0] = rating
    part[attrib][1] = rating - 1
    queue.append(false_part)
    return True  # Part range now meets condition

def split_part_greater(part, attrib, rating):
    if part[attrib][0] > rating:
        return True # entire range meets condition
    if part[attrib][1] <= rating:
        return False # entire range fails condition
    false_part = copy.deepcopy(part)
    false_part[attrib][1] = rating
    part[attrib][0] = rating + 1
    queue.append(false_part)
    return True  # Part range now meets condition


def sum_ratings():
    total = 0
    for part in accepted:
        part_total = 1
        for rating in part.values():
            rating_total = rating[1] - rating[0] + 1
            part_total *= rating_total
        total += part_total
    return total


#-----------------------------------------------------------------------------------------

filename = './test.txt'
#filename = 'sample.txt'

workflows = process_input(filename)

max_part = {'x':[1,4000],'m':[1,4000],'a':[1,4000],'s':[1,4000]}
queue = [max_part]

accepted = check_all_parts()

total = sum_ratings()

print('Ratings', total)
