def isValidPair(left, right):
    if left == '(' and right == ')':
        return True
    if left == '[' and right == ']':
        return True
    if left == '{' and right == '}':
        return True
    return False

def solution(S):
    stack = []

    if len(S)%2 != 0:
        return 0

    for symbol in S:
        if symbol == '[' or symbol == '{' or symbol == '(':
            stack.append(symbol)
        else:
            if len(stack) == 0:
                return 0
            last = stack.pop()
            if not isValidPair(last, symbol):
                return 0

    if len(stack) != 0:
        return 0

    return 1