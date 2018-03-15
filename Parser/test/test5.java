class TowerHanoi
{
	 void tower(int n, char fr, char tr, char ar)
	{
	    if (n == 1)
	    {
	        print("Move disk 1 from rod" + fr + " to rod " + tr);
	        return;
	    }
	    tower(n-1, fr, ar, tr);
	    print("Move disk" + n + "from rod" + fr +" to rod " + tr);
	    tower(n-1, ar, tr, fr);
	}
	void main(String[] args)
	{
		int number_of_disks = 4;
		tower(number_of_disks, 'A' , 'C' , 'B');
	}
}
