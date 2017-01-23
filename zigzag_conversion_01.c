char *convert(char *s, int nRows)
{
        if ( (s == NULL) || (nRows < 1) ) {
                return NULL;
        }

        int row;
        unsigned int index;
        const size_t len = strlen(s);

        // left space for '\0' in the end of a string
        char* output = (char*) malloc (sizeof(char) * ( len + 1));
        char* head = output;
        output[len] = '\0';

        // char *strcpy(char *dest, const char *src);
        // The strcpy() function copies the string pointed to by src, including the terminating null byte ('\0'),
        // to the buffer pointed to by dest.
        if ( nRows == 1 ){
                return strcpy(output, s);
        }

        for ( row = 0; row < nRows; ++row ) {

                for ( index = row; index < len; index += 2*nRows-2 ) {

                        // If it is the first row or the last row, then using (2*nRows-2) rule.
                        *output++ = s[index];

                        // Otherwise, there are middle values, using (2*nRows-2-2*row) rule
                        // notice that nRows-1 is the last row
                        if ( (row > 0) && (row < nRows-1) && ( (index + 2*nRows - 2 - 2*row) < len) ) {

                                *output++ = s[index + 2*nRows - 2 - 2*row];
                        }
                }
        }

        return head;
}
