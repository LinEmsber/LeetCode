bool repeatedSubstringPattern(char* s)
{
        int i = 1, j = 0;
        int n = strlen(s);

        int * dp = malloc( sizeof(int) * (n + 1) );
        memset(dp, 0, sizeof(int) * (n + 1));

        while( i < n ){

            if( s[i] == s[j] )
                dp[++i]=++j;

            else if( j == 0 )
                i++;

            else
                j = dp[j];

        }

        return dp[n] && ( dp[n] % (n - dp[n]) )== 0;
}
