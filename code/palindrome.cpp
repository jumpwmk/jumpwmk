#include <stdio.h>
int main()
{
	char a[10000],b[10000]={'\0'};
	int max=0,p=0,c,mi,nj;
	scanf("%s",a);
	for(int i=0;a[i]!='\0';i++)
	{									
		for(int j=i+1;a[j]!='\0';j++)
		{								
			if(a[i]==a[j])
			{							
				c=j-i+1;				
				mi=i;					
				nj=j;					
				if(c%2==0)
				{						
					p=0;
					while(mi<=i+c/2-1 && a[mi]==a[nj])
					{
						p+=2;			
						mi++;			
						nj--;			
					}
						
				}else{ 
						p=0;
						while(mi!=(j+i)/2 && a[mi]==a[nj])
						{
							p+=2;			
							mi++;			
							nj--;			
						}
						if(p==c-1)
						p+=1;
					}
					if(p==c && c>max)
					{
						max=c;					
						for(int ka=i,kb=0;ka<=j;ka++,kb++)
						b[kb]=a[ka];			
					}else if(p==c && c==max)
							{
								for(int xa=i,xb=0;xa<=j && b[xb]!='\0';xa++,xb++)
								{							
									if(a[xa]>b[xb])
									break;					
									if(a[xa]<b[xb])
										for(int ka=i,kb=0;ka<=j;ka++,kb++)
											b[kb]=a[ka];	
								}
							}		
			}
		}
	}
	if(b[0]=='\0')
	{
		b[0]=a[0];
		for(int i=0;a[i]!='\0';i++)
		{
			if(a[i]<b[0])
			b[0]=a[i];
		}	
	}
	printf("%s",b);
	return 0;
}