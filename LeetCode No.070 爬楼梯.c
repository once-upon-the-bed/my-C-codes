//递归
int climbStairs(int n) {
    if(n==1) return 1;
    if(n==2) return 2;
    return climbStairs(n-1)+climbStairs(n-2);
}

//动态规划
int climbStairs(int n) {
    if(n==1) return 1;
    if(n==2) return 2;
    int dp[n+1];
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

//优化空间
int climbStairs(int n) {
    if(n==1) return 1;
    if(n==2) return 2;
    int first = 1;
    int second = 2;
    int result;
    for (int i = 3; i <= n; i++) {
        result = first + second;
        first = second;
        second = result;
    }
    return result;
}
