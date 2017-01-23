/* hamming weight */

// Write a function that takes an unsigned integer and returns the number of ’1' bits
// it has (also known as the Hamming weight).
//
// For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011,
// so the function should return 3.


int hamming_weight(uint32_t n)
{
	int i;
	int tmp;
	int count = 0;

	for (i = 0; i<32; i++){
		tmp = n >> i;
		if ( (tmp & 0x01) == 0x01 ){
			count++;
		}
	}

	return count;
}
