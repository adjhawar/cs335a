<<<<<<< HEAD
class $ABC{
void bubblesort(int list[])
{
=======
class $sort{
	void bubblesort(int list[])
	{
>>>>>>> e8c3ad1ac0cbf2bf75369d44ba874dbecffd405e
		int temp;
		int len= list.length;
		for(int i = 0; i < len; i++)
		{	
			for(int j = 0; j < len - i - 1; j++)
			{	
				if(list[j] > list[j+1])
				{	
					temp = list[j + 1];
					list[j + 1] = list[j];
					list[j] = temp;
				}
			}
		}
		// printing the sorted array 
		print("Sorted order of list is");
		
		for(int i= 0 ;i< len ;i++)
		{
			print(list[i] + " ");	
		}
<<<<<<< HEAD
}
}
=======
	}
}
>>>>>>> e8c3ad1ac0cbf2bf75369d44ba874dbecffd405e
