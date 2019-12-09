#include <stdio.h>

int main ()
{
    int n;
	int v[8] = {3, 5, 7, 9, 1, 6, 4, 2};
	n =8;
	mostravetor (n, v);
	mergesort (n, v); 
	mostravetor (n, v);
	return 0;
}

void mostravetor(int n, int *v)
{
    int i;
    printf("\n Vetor: \n");
    for (i=0; i<n; i++)
    {
        printf("- %d ",v[i]);
    }
            printf("-");
}



void combina (int n1, int *v1, int n2, int *v2) 
{
    int i, j, k, n;
    
	n = n1 + n2;
    int vt[n];

	i=0; 
	j = 0;
	
   for (k=0; k<n; k++)
   	{
		 if((i<n1 ) && (j<n2))
   	     {
   		    if(v1[i] < v2[j])
   		    {
  		        vt[k] = v1[i];
  		        i++;
    		 }
             else
             { 
                vt[k] = v2[j];
                j++;
 	          }
   	     }
 	      else
			 if (i <n1)
 	      	  {
 	      	  	vt[k] = v1[i];
 	      	  	i++;
 	      	  }
 	      	  else
 	      	  {
 	      	  	 vt[k] = v2[j];
 	      	  	 j++;
		 	  }
	   
    }
 		
 		
 	for (k=0; k<n; k++)
 			v1[k] = vt[k];
}

void mergesort (int n, int *v)
{
    int m;

	if (n>1)
	{
		m = n/2;
		mergesort (m, v); 

		mergesort (n-m, &v[m]); 
		
		combina (m, v, n-m, &v[m]);   
	}
}