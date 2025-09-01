import random
import time

def k_largest(A, k):
    B = [0] * k 

    for a in A:
        if a > B[0]:
            B[0] = a
            j = 1
            while j < k and B[j - 1] > B[j]:
                B[j - 1], B[j] = B[j], B[j - 1]
                j += 1

    return sum(B)


def test_runtime(n, k):
    A = [random.randint(1, 100000) for _ in range(n)]
    start = time.time()
    result = k_largest(A, k)
    end = time.time()
    print(f"n={n}, k={k} -> sum={result}, time={end - start:.6f} seconds")


test_runtime(1000, 10)
test_runtime(5000, 50)
test_runtime(10000, 100)
test_runtime(20000, 200)
