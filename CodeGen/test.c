#include<stdio.h>
#include<string.h>

int main(){
	char str[100];
	scanf("%s",str);
	int l=strlen(str),i=0;
	while(i<l){
		if(str[i]>='0' && str[i]<='9')
			i++;
		else{
			printf("NO");
			return 0;
	}}
	printf("YES");
	return 1;
}
