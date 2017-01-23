/* while loop */

bool isUgly(int num)
{

	if (num < 1)
		return 0;

	while (num>1){

		if (num % 2 == 0){
			num = num / 2;
			continue;
		}

		if (num % 3 == 0){
			num = num / 3;
			continue;
		}

		if (num % 5 == 0){
			num = num / 5;
			continue;
		}
		return 0;
	}
	
	return 1;
}
