import math
def nonSpecialCount(l: int, r: int) -> int:
        '''
        # Count the divisors 
        def countDiv(n: int) -> int:
            c = 0
            
            for i in range(1, (int)(n ** 0.5) + 1): 
                if c > 3:
                    return c
                if (n % i == 0): 
                    if (n / i == i): 
                        c += 1
                    else: 
                        c += 2
                        
            return c

        ans = r-l+1
        for i in range(l, r+1):
            if i % 2 == 0 and i > 4:
                continue
            if i % 3 == 0 and i != 9:
                continue
            if i % 5 == 0 and i != 25:
                continue

            div = countDiv(i) - 1
            if div == 2:
                ans -= 1
        
        return ans
        '''
        # seive of eratosthenes
        def sieve(n: int) -> list:
            # List of prime numbers upto n 
            is_prime = [True] * (n + 1)
            is_prime[0] = is_prime[1] = False
            
            for i in range(2, int(n**0.5) + 1):
                if is_prime[i]:
                    for j in range(i*i, n + 1, i):
                        is_prime[j] = False
            return [i for i in range(2, n + 1) if is_prime[i]]
        
        # All primes up to sqrt(r)
        primes = sieve(int(math.sqrt(r)))
        
        # Count the special numbers 
        special = 0
        for prime in primes:
            square = prime ** 2
            if l <= square <= r:
                special += 1

        total = r - l + 1
        return total - special
    
print("Answer: ", nonSpecialCount(5, 7))