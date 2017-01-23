/* Ransom Note, 6ms */

// Given  an arbitrary  ransom  note  string and another string containing letters from  all the magazines, 
// write a function that will return true if the ransom  note can be constructed from the magazines ;
// otherwise, it will return false.  
//
// canConstruct("a", "b") -> false
// canConstruct("aa", "ab") -> false
// canConstruct("aa", "aab") -> true


bool canConstruct(char* ransomNote, char* magazine)
{
	int i;
	int table[26] = {0};

	while(*magazine){
		table[*magazine++ - 'a']++;
	}

	while(*ransomNote) {

		// table[*ransomNote - 'a']--;
		// if (table[*ransomNote - 'a'] < 0)
		// 	return false;

		if (--table[*ransomNote++ - 'a'] < 0)
			return false;

		// ransomNote++;
	}

	return true;
}
