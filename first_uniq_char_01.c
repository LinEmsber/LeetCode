int firstUniqChar(char * s)
{
	int total_alphabet[26] = {0};
	char * t;

	for(t = s; *t; t++){
                total_alphabet['z' - *t]++;
        }


	for(t = s; *t; t++){
                if (1 == total_alphabet['z' - *t]){
                        return t - s;
                }
        }

	return -1;
}
