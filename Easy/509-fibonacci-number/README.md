## Fibonacci Number (#509) — Complexity Analysis

I implemented several approaches to solve this problem, ranging from naive recursion to mathematical optimization. Below is the comparison of their performance and security implications.

### Comparison Table

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Brute Force (Recursion)** | $O(2^n)$ | $O(n)$ | **Inefficient:** High CPU usage and risk of Stack Overflow. |
| **Memoization (Top-Down)** | $O(n)$ | $O(n)$ | Optimized recursion by caching results in a table. |
| **Iteration (Bottom-Up)** | $O(n)$ | $O(1)$ | **Recommended:** Most stable and memory-efficient for systems. |
| **Binet's Formula (Math)** | $O(\log n)$ | $O(1)$ | **Fastest:** Uses the Golden Ratio, but may have precision issues. |

---

### Detailed Analysis

#### 1. Brute Force (Recursive)
The simplest but most dangerous method. Due to exponential growth $O(2^n)$, it's highly susceptible to **Denial of Service (DoS)** if a large $n$ is provided, as it will exhaust CPU resources.

#### 2. Memoization
Significantly faster as it ensures each sub-problem is solved only once. However, it still relies on the **call stack**, which is a limited resource in secure environments.

#### 3. Iteration (Space Optimized)
The best solution for production. By only storing the last two values, we achieve $O(1)$ space. From a **Cybersecurity** perspective, this is the safest choice because it avoids recursion-related vulnerabilities (like Stack Overflow) and has predictable memory usage.

#### 4. Binet's Formula (Golden Ratio)
A "mathematical shortcut" that works in $O(\log n)$ time. While extremely fast, it uses floating-point arithmetic (`double`), which can lead to **rounding errors** for very large numbers. In cryptography or high-precision security systems, this inaccuracy could be a potential weakness.
