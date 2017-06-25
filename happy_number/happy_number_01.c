// check the number n is happy number or not
// the number n would converge under 100

int trans_int(int n)
{
	int i = 0;

	// if n = 19
	// i = 0 + 9 * 9 = 81, n = 1
	// i = 81 + 1 * 1 = 82, n = 0

	while (n > 0) {
		i += (n % 10) * (n % 10);
		n /= 10;
	}

	return i;
}

bool is_happy(int n)
{
	while (n > 99) {
		n = trans_int(n);
	}

	if (n < 20)
		return (n == 1 || n == 7 || n == 10 || n == 13 || n == 19);
	else if (n < 45)
		return (n == 23 || n == 28 || n == 31 || n == 32 || n == 44);
	else if (n < 80)
		return (n == 49 || n == 68 || n == 70 || n == 79);
	else
		return (n == 82 || n == 86 || n == 91 || n == 94 || n == 97);
}
