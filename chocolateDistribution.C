#include<stdio.h>
#include<stdbool.h>

bool isDistributable(int n1 , int n2)
{
    if((n1 + n2) % 2 == 0)
    return true;
    else
    return false;
}

int main()
{
    int coa,cob;
    printf("Enter the number of chocolates of Alice and Bob \n");
    scanf("%d %d",&coa,&cob);
    if(isDistributable(coa,cob))
    printf("\n YES");
    else
    printf("\n NO");
    return 0;
}
