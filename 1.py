MOD = 998244353

def solve(N, A, B):
  """
  Finds the number of non-empty subsets where max(A[i]) >= max(B[i]) modulo MOD.

  Args:
      N: Number of values.
      A: List of execution times for Java functions.
      B: List of execution times for Python functions.

  Returns:
      The number of non-empty subsets satisfying the condition, modulo MOD.
  """

  # Initialize prefix maxima for both lists
  java_maxima = [0] * (N + 1)
  for i in range(1, N + 1):
    java_maxima[i] = max(java_maxima[i - 1], A[i - 1])

  python_maxima = [0] * (N + 1)
  for i in range(1, N + 1):
    python_maxima[i] = max(python_maxima[i - 1], B[i - 1])

  # Count the number of valid subsets using dynamic programming
  dp = [[0] * (N + 1) for _ in range(N + 1)]  # dp[i][j]: number of valid subsets ending at indices i (Java) and j (Python)

  # Base case: empty subset
  dp[0][0] = 1

  for i in range(1, N + 1):
    for j in range(1, N + 1):
      # Case 1: Don't include the current element (Java)
      dp[i][j] = dp[i - 1][j]

      # Case 2: Include the current element (Java) if it satisfies the condition
      if java_maxima[i] >= python_maxima[j - 1]:
        dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD

  # Count of all non-empty subsets
  total_subsets = sum(row) % MOD

  # Remove the empty subset (which is always valid)
  return (total_subsets - 1) % MOD

# Test case
N = 2
A = [31, 12]
B = [10, 20]
result = solve(N, A, B)
print(result)  # Output: 2