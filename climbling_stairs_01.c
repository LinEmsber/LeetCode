/*
 * You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 */


int climbStairs(int n)
{
	int i;

	int n_1 = 1;
	int n_2 = 0;
	int ways;

	for( i = 1; i <= n; i++){
		ways = n_1 + n_2;
		n_2 = n_1;
		n_1 = ways;
	}

	return ways;
}
