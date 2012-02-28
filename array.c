#include <stdio.h>
#define M 10
#define N 3

int main(int argc, const char *argv[])
{
        int arr[M];
        int i;
        int counter = 0;
        int out_cnt = 0;
        int step = 0;
        for (i = 0; i < M; i++) 
                arr[i] = i + 1;
        while(counter != M)
        {
               if(arr[step]) 
               {
                        out_cnt++;
                        if(out_cnt == N)
                        {
                                counter++;
                                out_cnt = 0;
                                arr[step] = 0;
                                printf("%d out!\n", step + 1);
                        }
               }
               step++;
               step = step % M;
        }
        return 0;
}
