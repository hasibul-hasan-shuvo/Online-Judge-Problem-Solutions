#include<stdio.h>
int main()
{
    long long int a,b,c;

    while(scanf("%lld%lld",&a,&b)!=EOF)
    {
        if(a>b)
        {
            c=a;
            a=b;
            b=c;
        }
        c=b-a;
        printf("%lld\n",c);
    }
    return 0;
}
