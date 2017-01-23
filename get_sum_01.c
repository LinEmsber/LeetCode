
// a 		= 1
// b 		= 3
// a 		= 0001
// b 		= 0011
//
// a ^ b 		= 0010
//
// a & b 		= 0001
// (a & b ) << 1 	= 0010


int get_sum(int a, int b)
{

	if (b)
		return get_sum(a ^ b, (a & b) << 1);
	else
		return a;
}
