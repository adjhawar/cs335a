class $looping{
	void main() {
        int i;
        i=5;
		 for(i=2;i<5;i++)
		 {
		 	print(i);
		 }
		 for(i=2;i<5;)
		 {
		 	print(i);
		 	i++;
		 }
		 for(;i<5;i++)
		 {
		 	print(i);
		 }
		 for(;;)
		 {
		 	if(i==5)
		 	{
		 		break;
		 	}
		 	print(i);
		 }
		 
	}
}

