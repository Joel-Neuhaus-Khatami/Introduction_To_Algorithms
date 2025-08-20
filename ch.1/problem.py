import math

##Introduction to algorithms chapter 1 problem

def logn(c):
    ##Cannot return integer due to value error (4300 limit)
    return f"10^{c}"

def sqrtn(c):
    return c**2

def nlogn(c, tol=1e-6, max_iter=100):
    n = c / 2  # initial guess
    for _ in range(max_iter):
        f = n * math.log2(n) - c
        df = math.log2(n) + 1 / math.log(2)
        n_next = n - f / df
        if abs(n_next - n) < tol:
            return n_next
        n = n_next
    return n

def n_squared(c):
    return c**0.5

def n_cubed(c):
    return c**(1/3)

def two_pwr_n(c):
    return math.log2(c)

def n_factorial(c):
    x = 1
    while c > math.factorial(x):
        x+=1
    return x -1
def main():
    units = [1_000_000, 1_000_000*60, 1_000_000*60*60, 1_000_000*60*60*24,
             1_000_000*60*60*24*30, 1_000_000*60*60*24*365, 1_000_000*60*60*24*365*100]
    
    functions = [
        ("logn", logn),
        ("sqrtn", sqrtn),
        ("identity", lambda x: x),
        ("nlogn_newton", nlogn),
        ("n_squared", n_squared),
        ("n_cubed", n_cubed),
        ("two_pwr_n", two_pwr_n),
        ("n_factorial", n_factorial)
    ]

    for name, func in functions:
        print(f"--- {name} ---")
        for unit in units:
            print(func(unit))
        print()

main()
