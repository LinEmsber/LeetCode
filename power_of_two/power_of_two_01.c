/* power of two */

bool is_power_two(int n)
{
	if(n == 0)
		return false;

	while(n % 2 == 0)
		n = n >> 1;

	return (n == 1);
}

// ==================================================================
// Method 1: Iterative
//
// 	if(n == 0)
// 		return false;
//
// 	while(n % 2 == 0)
// 		n = n >> 1;
//
// 	return (n == 1);
//
// ==================================================================
// Method 2: Recursive
//
// 	return n > 0 && (n == 1 || (n % 2 == 0 && is_power_two(n/2) ) );
//
// ==================================================================
// Method 3: Bit operation
//
// n = 2 ^ 0 = 1 = 0b0000...00000001, and (n - 1) = 0 = 0b0000...0000.
// n = 2 ^ 1 = 2 = 0b0000...00000010, and (n - 1) = 1 = 0b0000...0001.
// n = 2 ^ 2 = 4 = 0b0000...00000100, and (n - 1) = 3 = 0b0000...0011.
// n = 2 ^ 3 = 8 = 0b0000...00001000, and (n - 1) = 7 = 0b0000...0111.
//
// If n is the power of two, we have n & (n-1) == 0b0000...0000 == 0
//
// Otherwise, n & (n-1) != 0.
//
// 	return n > 0 && ( (n & (n-1)) == 0);
//
//
// ==================================================================
// Method 4: Math derivation
//
// Because the range of an integer = -2147483648 (-2^31) ~ 2147483647 (2^31-1),
// the max possible power of two = 2^30 = 1073741824.
//
// If n is the power of two, let n = 2^k, where k is an integer.
//
// We have 2^30 = (2^k) * 2^(30-k), which means (2^30 % 2^k) == 0.
//
// 	return n > 0 && ( (1073741824 % n) == 0);
