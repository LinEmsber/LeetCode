/* is power of four */

// The basic idea is from power of 2, We can use "n&(n-1) == 0" to determine if n is power of 2.
//
// For power of 4, the additional restriction is that in binary form, the only "1" should always
// located at the odd position.
//
// For example:
// 4^0 = 1
// 4^1 = 100
// 4^2 = 10000
//
// Thus, we can use "num & 0x55555555==num" to check if "1" is located at the odd position.
//
// 0x55555555 = 0b01010101 01010101 01010101 01010101


bool isPowerOfFour(int num)
{
        return (num > 0) && ( ( num & (num - 1) ) == 0 ) && ( (num & 0x55555555) == num );
}
