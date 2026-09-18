#include <stdio.h>
int main()
{
    int a[50],i,j,n,temp;
    printf("Enter No of students ");
    scanf("%d",&n);
    printf("Enter the roll no of student");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                
            }
        }
    

    printf("pass %d",i+1);
    for(j=0;j<n;j++)
    
        printf("%d",a[j]);

    
    printf("\n");

    }

    printf("\nSorted Roll Numbers");
    for(i=0;i<n;i++)
        printf("%d",a[i]);
    
    return 0;
}