def solution(A):
    seen_going_east = 0
    n_pairs = 0
    for car in A:
        if car == 0: # the car is going east
            seen_going_east += 1
        else: # the car is going west
            n_pairs += seen_going_east
    return n_pairs if n_pairs <= 1000000000 else -1