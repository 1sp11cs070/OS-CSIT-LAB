#include<stdio.h>
int main()
{
  int page[20], i, j, k, np, nf, count[10], frame[10], min, pfcount=0;
  printf("\nEnter the available no. of frames -- ");
  scanf("%d",&nf);
    
  printf("\nEnter number of page references -- ");
  scanf("%d",&np);
  
    printf("\nEnter the reference string -- ");
  for(i=0;i<np;i++)
      scanf("%d",&page[i]);
  
    
   for(i=0;i<nf;i++)
   {
     count[i]=0;  //setting count as 0 initially
     frame[i]=-1; //setting frames empty
   }

    //scanning all pages
   for(i=0;i<np;i++)
   {
       //scanning all frames
      for(j=0;j<nf;j++)
          //checking page available in frame or not
          if(page[i]==frame[j])  //available
          {
            count[j]++;   //just increase the count
            break;
          }
           
           //logic for page replacement
           if(j==nf)  //if not available
           {
               min = 0;
               for(k=1;k<nf;k++)
                 if(count[k]<count[min])
                     min=k;
               
               frame[min]=page[i];
               count[min]=1;
               pfcount++;
           }
       
         printf("\n");
         for(j=0;j<nf;j++)
             printf("%d\t",frame[j]);
    }
    
    printf("\n\n Total number of page faults -- %d",pfcount);
    return 0;
    
}
