class $test {
        int x = 10;
	int a = 4;	
    	int comp() {
            int z=7;
    		switch(z){
			case 2 : z+=2 ;
				 break; 
			case 3 : z+=3;
			case 5 : z+=4;
				 break;
			case 7 : z+=7;
			default : print(z);
			 }
		return z;
    	}
        int main() {
            int i=0;
	    for( i=9;i<10;i++){
		print(a);
		if(i==8)
		continue;
		i++;
	    }
	    int j=comp();
	    return -1;
        }
}
