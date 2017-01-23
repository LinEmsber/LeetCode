/* Ransom Note, 109ms */

// Given  an arbitrary  ransom  note  string and another string containing letters from  all the magazines, 
// write a function that will return true if the ransom  note can be constructed from the magazines ;
// otherwise, it will return false.  
//
// canConstruct("a", "b") -> false
// canConstruct("aa", "ab") -> false
// canConstruct("aa", "aab") -> true


int add(int a, int b)
{
	if (b){
		return add(a^b, (a&b)<<1 );
	}else{
		return a;
	}
}


int sub(int x,int y){
	return add(x, add(~y, 1));
}

bool canConstruct(char* ransomNote, char* magazine)
{
	int i;
	int table[26] = {0};

	while(*magazine){
		table[sub(*magazine, 'a')]++;
		magazine++;

	}

	while(*ransomNote) {
		table[sub(*ransomNote, 'a')]--;
		ransomNote++;
	}

	for(i = 0; i < 26; i++) {
		if(table[i] < 0)
			return false;
	}

	return true;
}
