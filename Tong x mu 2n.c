#include <stdio.h>
int main(){
	int x,n,s=0;
	scanf("%d%d",&x,&n);
	int t=x*x;
	for (int i=1; i<=n; i++){
		s+=t;
		t*=x*x;
	}
	printf("%d",s);
	return 0;
}
