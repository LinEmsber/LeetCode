char ** arr;		// this will be our string pointer array
int perm;		// this will keep track of it's index

// permute to creat every probability of combination.
void permute(int *n, int start, int pos)
{
	if (pos == 0){

		// There are 10 bits we have to consider.

		// The 4 bits on the right side presents the number of hour, and it must less than 11.
		int hours = (*n >> 6) & 0x0F;
		if (hours > 11)
			return;

		// The remaining 6 bits on the left side present the number of mintue, and it must less
		// than 59.
		int minutes = *n & 0x3F;
		if (minutes > 59)
			return;

		// allocate new string
		arr[perm] = malloc(6 * sizeof(char));
		if (NULL == arr[perm])
			exit(EXIT_FAILURE);

		// make the string
		sprintf(arr[perm], "%d:%.2d", hours, minutes);
		++perm;
		return;
	}

	// permute each bits
	while (start <= 10){
		swap_bits(n, start, pos, 1);
		permute(n, start, pos - 1);
		swap_bits(n, start, pos, 1);
		++start;
	}
}

// swap bits for permutation
void swap_bits( int *x, int p1, int p2, unsigned int n)
{
	// use 1 based positions for simplicity
	*x <<= 1;

	// Move all bits of first set to rightmost side
	unsigned int set1 =  (*x >> p1) & ((1U << n) - 1);
	unsigned int set2 =  (*x >> p2) & ((1U << n) - 1);

	// XOR the two sets
	unsigned int xor = (set1 ^ set2);

	// Put the xor bits back to their original positions
	xor = (xor << p1) | (xor << p2);

	// XOR the 'xor' with the original number so that the two sets are swapped
	*x ^= (int) xor;

	// shift back for actual number
	*x >>= 1;
}

// n choose r
int combination( int n, int r )
{
	int i;
	int numerator = 1;
	int denominator = 1;

        if ( ( n - r ) < (n / 2) ){
                r = n - r;
        }

	// numerator
	for( i = n; i > (n - r); i--)
		numerator = numerator * i;

        // denominator
	for(i = 1; i <= r; i++)
		denominator = denominator * i;

	return numerator / denominator;
}

char ** readBinaryWatch(int num, int * returnSize)
{
	int i, j;
	perm = 0;

	// calculate needed number of strings and get memory
	arr = malloc( combination(10, num) * sizeof(*arr) );
	if ( arr == NULL)
		exit(EXIT_FAILURE);

	// conbination of 10 LEDs light or closed. Beacuse index starts from zero, thus it minus 1.
	// 2 ^ num - 1
	i = (1 << (num )) - 1;

	// generate all permutations
	permute(&i, num, num);

	*returnSize = perm;
	return arr;
}
