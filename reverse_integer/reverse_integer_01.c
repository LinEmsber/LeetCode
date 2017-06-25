// Remainder calculation for the modulo operation
//
// 103 % 10 = 3
// -103 % 10 = -3
// 103 % -10 = 3
// -103 % -10 = -3
//
// 103 / 10 = 10
// -103 / 10 = -10
// 103 / -10 = -10
// -103 / -10 = 10
//
// https://en.wikipedia.org/wiki/Modulo_operation


// Location: /usr/include/limits.h
//
// /* Minimum and maximum values a signed int can hold.  */
// #  define INT_MIN       (-INT_MAX - 1)
// #  define INT_MAX       2147483647
//
// If r > INT_MAX or r < -(INT_MAX), the overflow weill happen.
// Furthermore, r will be multiplied 10, so, we have descrese the overflow threshold to INT_MAX / 10.
int overflow_check = INT_MAX / 10;

int reverse(int integer)
{
        // check the sign of integer
        const char sign = integer < 0 ? -10 : 10;
        int r = 0;

        while (integer) {

                if (r > overflow_check || r < -overflow_check)
                        return 0;

                r = (integer % sign) + (r * 10);
                integer /= 10;
        }

        return r;
}
