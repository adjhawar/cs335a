class $StringExample
{	
	void main(String[] args)
	{	
		String s1 = "Compiler Design";
		int x = 307;					// checking for the literals
		String s2 = s1 + " " + x;
		String s3 = s2.substring(10,17);
		String s4 = "is fun";
		String s5 = s2 + s4;

		print("s1: " + s1);
		print("s2: " + s2);
		print("s3: " + s3);
		print("s4: " + s4);
		print("s5: " + s5);

		x = 3;
		int y = 5;
		String s6 = x + y + "total";
		String s7 = "total " + x + y;
		String s8 = " " + x + y + "total";
		print("s6: " + s6);
		print("s7: " + s7);
		print("s8: " + s8);
	}
}