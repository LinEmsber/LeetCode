/* for loop */

bool isUgly(int num)
{

	int i;

	if(num < 1){
		return false;
	}

        for( i = 2; i <= 5; i++){

		while(num % i == 0){
			num /= i;
		}
        }

        if(num != 1){
		return false;
	}

        return true;

}
