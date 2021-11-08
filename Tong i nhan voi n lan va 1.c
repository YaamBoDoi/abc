#include <stdio.h>
int main(){
	int n,s=1,ns=0;
	scanf("%d",&n);
	for (int i=2; i<=n; ++i){
		s*=i;
		ns+=s;
	}
	printf("%d",1+ns);
	return 0;
}
