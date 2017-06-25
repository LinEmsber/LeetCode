char* convertToTitle(int n)
{
	if(n < 1)
		return "";

	int i;
	int len = 0;

	// calculate the title length
	for( i = n-1; i >= 0; i = i/26-1){
		len++;
	}

	// memroy allcate
	char *title = (char*)malloc( sizeof(char)*len );

	// num to title
	for( i = n-1; i >= 0; i = i/26-1){
		title[--len] = i%26 + 'A';
	}

	return title;
}
