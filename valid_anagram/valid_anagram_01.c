bool isAnagram(char* s, char* t)
{

	int i;
	int a[26] = {0};
	int len = strlen(s);

	// check the length
	if ( len != strlen(t) ){

		return 0;

	}else {

		// add for string s
		for(i = 0; i < len; i++){
			a[ s[i] - 'a' ]++;
		}

		// sub for string t
		for(i = 0; i < len; i++){
			a[ t[i] - 'a' ]--;
		}

		// chekc the result
		for(i = 0; i < 26; i++){
			if (a[i] != 0){
				return 0;
			}
		}
	}

	return 1;
}
