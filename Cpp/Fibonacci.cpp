//Recursive Approach
//Time Complexity - O(2^N)
//Space Complexity - O(N) given the function call stack size
    int fib(int N) {
        if(N == 0)  return 0;
        if(N == 1)  return 1;
        return fib(N-1) + fib(N-2);
    }

//Dynamic Programming Approach
//Time Complexity - O(N)
//Space Complexity - O(N)
int fib(int n) {
      vector<int> f(n+2,0);
        f[0]=0; f[1]=1;
        for(int i=2; i<=n; i++)
        {
            f[i]=f[i-1]+f[i-2];
        }
        return f[n];
    }

//Imperative Approach (Bottom Up DP)
//Time Complexity - O(N)
//Space Complexity - O(1)
    int fib(int N) {
        if(N < 2) 
            return N;
    	int a = 0, b = 1, c = 0;
        for(int i = 1; i < N; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
