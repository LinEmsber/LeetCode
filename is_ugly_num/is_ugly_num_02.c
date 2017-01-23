/* recursive method */

bool isUgly(int num)
{

	if(num < 1){
		return false;
	}

	// recursive loop
        if(num % 2 == 0){
            return isUgly(num / 2);
        }
        if(num % 3 == 0){
            return isUgly(num / 3);
        }
        if(num % 5 == 0){
            return isUgly(num / 5);
        }

        if(num == 1){
		return true;
	}

        return false;
}
