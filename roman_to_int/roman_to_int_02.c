/* Romain to Integer, 20ms */
int roman_to_int(char* s)
{
	int NUM[128] = { 0 };
	NUM['I'] = 1;
	NUM['V'] = 5;
	NUM['X'] = 10;
	NUM['L'] = 50;
	NUM['C'] = 100;
	NUM['D'] = 500;
	NUM['M'] = 1000;
	int val = 0;
	int prev = 0;
	int buf = 0;

	while(*s != '\0')  {

		// read the char from left to right
		buf = NUM[*s];

		// e.g. IV, it means 5 - 1 = 4.
		if (prev && prev<buf){
			val += buf - prev;
			prev = 0;

		// e.g. VII, it means 5 + 2 = 7.
		}else if (prev && prev>=buf){
			val += prev;
			prev = buf;

		// get the first char
		}else{
			prev = buf;
		}

		// move to the next char
		s++;
	}

	return val + prev;
}
