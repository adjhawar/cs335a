class $PrimitiveParameters
{	
	void main(String[] args)
	{	go();
	}
	
	void go()
	{	int x = 3;
		int y = 2;
		print("In method go. x: " + x + " y: " + y);
		falseSwap(x,y);
		print("in method go. x: " + x + " y: " + y);
		moreParameters(x,y);
		print("in method go. x: " + x + " y: " + y);
	}
	
	void falseSwap(int x, int y)
	{	print("in method falseSwap. x: " + x + " y: " + y);
		int temp = x;
		x = y;
		y = temp;
		print("in method falseSwap. x: " + x + " y: " + y);
	}
	
	void moreParameters(int a, int b)
	{	print("in method moreParameters. a: " + a + " b: " + b);
		a = a * b;
		b = 12;
		print("in method moreParameters. a: " + a + " b: " + b);
		falseSwap(b,a);
		print("in method moreParameters. a: " + a + " b: " + b);	
	}
}
