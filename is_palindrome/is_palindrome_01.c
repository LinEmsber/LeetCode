bool isPalindrome(int x)
{
        int palindrome_x = 0;
        int input_x = x;

        while(x > 0){
                palindrome_x = palindrome_x * 10 + (x % 10);
                x = x / 10;
        }

        return palindrome_x == input_x;
}
