#include <stdio.h>
#include <stdlib.h>


typedef struct {
	int x;
}point;
 static int compare(void *menor, void *maior)
    {
       int *pMenor = (int *)menor;
       int *pMaior = (int *)maior;

       return ( *pMenor > *pMaior );
    }
     static int compareDouble(void *menor, void *maior)
    {
       double *pMenor = (double *)menor;
       double *pMaior = (double*)maior;

       return ( *pMenor > *pMaior );
    }
  int compareStruct(void *arg1, void *arg2)
{
	int x = (*((point *)arg1)).x;
	int y = (*((point *)arg2 )).x;

	return x>y;
}

    void bubleSort(void *base, int bWidth, int len, int (*func)(void *key, void *data))
    {
       int i, j;
       char *k=0;
       char *bPtr = (char *)base;         //Points to the beginning of the array
       char *pi, *pj;

       k = (char *)malloc(bWidth);        //Creates a new var with the size of the data type

       if(!k)
          return;

       for(i = 0; i < len; i++)
       {
          pi = (bPtr + (i*bWidth));

          for(j=i+1; j < len; j++)
          {
             pj = (bPtr+(j*bWidth));

             if( func((void *)pi, (void *)pj) )
             {
                memcpy(k, pi, bWidth);
                memcpy(pi,pj, bWidth);
                memcpy(pj, k, bWidth);
             }
          }
       }

       free(k);
    }
int main()
{
    printf("//////////");
    printf("\n");
    int vet[5] = {4, 1, 3, 5, 2},i;
   bubleSort((void *)vet, sizeof(int), 5, compare);
   for(i=0;i<sizeof(vet)/sizeof(int);i++){
    printf("%d\n",vet[i]);

   }
      printf("end\n");
   double ket[5]={4.0,1.0,3.0,5.0,2.0};
    bubleSort((void *)ket, sizeof(double), 5, compareDouble);
    for(i=0;i<sizeof(ket)/sizeof(double);i++){
    printf("%1f\n",ket[i]);

   }


   printf("end\n");

   point coords[5]; coords[0].x = 9; coords[1].x = 12; coords[2].x = 122; coords[3].x = 10;
   coords[4].x=33;
	bubleSort((void*)coords, sizeof(point),5, compareStruct);
	for (i = 0; i < sizeof(coords) / sizeof(point); i++){
        printf("%d\n",coords[i]);
	}
		printf("end\n");
}
