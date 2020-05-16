def is_matched(expression):
    split = list(expression)
    stack = []
    for entry in split:
        if entry == '{' or entry == '[' or entry == '(':
            stack.append(entry)
        elif len(stack) > 0:
            lastEntry = stack[-1]
            if entry == '}' and lastEntry == '{':
                stack.pop()
            elif entry == ']' and lastEntry == '[':
                stack.pop()
            elif entry == ')' and lastEntry == '(':
                stack.pop()
            else:
                return False
        else:
            return False
    return len(stack) == 0

a = int(input().strip())
for a0 in range(a):
    expression = input().strip()
    if is_matched(expression) == True:
        print("YES")
    else:
        print("NO")
