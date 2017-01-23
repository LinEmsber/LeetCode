/* Romain to Integer, 28ms */

int get_value(char c)
{
	switch(c){
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
	}
	return NULL;
}

int roman_to_int(char* s)
{
	int i;
	int len = strlen(s);
        int sum = 0;

        for(i=0; i < len; i++){
		if(i+1<len && get_value(s[i]) < get_value(s[i+1])){
			sum += get_value(s[i+1]) - get_value(s[i]);
			i++;
		}else
			sum += get_value(s[i]);
        }
        return sum;
}
