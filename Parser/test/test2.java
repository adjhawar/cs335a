class Factorial
{
	int factorial(int n)
	{	
		int result = 1;
		for(int i = 2; i <= n; i++)
			result *= i;
		return result;
	}
	void main(String[] args)
	{	$
		int n = 100;
		for(int i = 1; i < n; i++)
		{
			int answer = factorial(i);
			print( "factorial of " + i + " is " + factorial(i));
		}
	}

}
