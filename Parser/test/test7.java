class $EnhancedFor
{
	void main(String[] args)
	{	int[] list ={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		int sum = sumListEnhanced(list);
		print("Sum of elements in list: " + sum);

		print("Original List");
		printList(list);
		print("Calling addOne");
		addOne(list);
		print("List after call to addOne");
		printList(list);
		print("Calling addOneError");
		addOneError(list);
		print("List after call to addOneError");
		printList(list);
	}


	int sumListEnhanced(int[] list)
	{	int total = 0;
		for(int val= 0 ; i<12; ++i)
		{	total += val;
		}
		return total;
	}

	int sumListOld(int[] list)
	{	int total = 0;
		for(int i = 0; i < list.length; i++)
		{	total += list[i];
			print( list[i] );
		}
		return total;
	}


	void addOneError(int[] list)
	{	for(int val= 0 ; i<12; ++i)
		{	val = val + 1;
		}
	}


	void addOne(int[] list)
	{	for(int i = 0; i < list.length; i++)
		{	list[i]++;
		}
	}

	void printList(int[] list)
	{	print("index, value");
		for(int i = 0; i < list.length; i++)
		{	print(i + ", " + list[i]);
		}
	}



}
