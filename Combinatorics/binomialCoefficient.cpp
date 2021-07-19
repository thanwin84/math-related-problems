//recursive solution
class Solution {
public:
	int nCr(int n, int r) {
		// code here
		if (r == 0 or r == n) {
			return 1;
		}
		return nCr(n - 1, r - 1) + nCr(n - 1, r);

	}
};
//memoization
//time: O(n * k) and space: O(n*k)
#define mod 1000000007
using namespace std;
int dp[1002][801];
class Solution {
public:
	int solve(int  n, int r) {
		// code here
		if (dp[n][r] != -1) {
			return dp[n][r];
		}
		if (r == 0 or r == n) {
			dp[n][r] = 1;
			return 1;
		}
		return dp[n][r] = (solve(n - 1, r - 1) % mod + solve(n - 1, r) % mod) % mod;

	}
	int nCr(int n, int r) {
	    if (r > n) {
	        return 0;
	    }
		memset(dp, -1, sizeof(dp));
		return solve(n, r) % mod;
	}
};
//top down 
#define mod 1000000007
using namespace std;
int dp[1002][801];
class Solution {
public:
	int nCr(int n, int r) {
	    if (r > n) return 0;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= r; j++) {
				if (j == 0 or j == i) {
					dp[i][j] = 1;
				}
				else {
					dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
				}
			}
		}
		return dp[n][r];
	}
};
// O(k) space solution
#define mod 1000000007
using namespace std;
int dp[801];
class Solution {
public:
	int nCr(int n, int r) {
		if (r > n) return 0;
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = min(i, r); j > 0; j--) {
				dp[j] = (dp[j - 1] + dp[j]) % mod;
			}
		}
		return dp[r];
	}
};
