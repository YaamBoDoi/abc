#include <stdio.h>
int main(){
	int x,n,s,t;
	scanf("%d%d",&x,&n);
	t=x*x;
	s=t;
	for (int i=3; i<=n; ++i){
		t*=x;
		s+=t;
	}
	printf("%d",x+s);
	return 0;
}
