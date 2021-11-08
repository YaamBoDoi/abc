#include <stdio.h>
int main(){
	int n,x,s=1;
	scanf("%d%d",&x,&n);
	for (int i=1; i<=n; ++i){
		s*=x;
	}
	printf("%d",s);
	return 0;
}
