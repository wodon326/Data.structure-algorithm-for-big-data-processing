#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
#include <time.h>
struct point {
    double x;
    double y;
};
struct cluster {
    double x;
    double y;
    double newx;
    double newy;
    int size;
};
int main(void)
{
    int n, k, i,j=0,num,t=1,check=1,random[5];
    double x, y,max;
    srand((unsigned int)time(NULL));
    scanf("%d %d", &n, &k);
    struct point* p1 = (struct point*)malloc(sizeof(struct point) * n);
    struct cluster* c1 = (struct cluster*)malloc(sizeof(struct cluster) * k);
    double* distance = (double*)malloc(sizeof(double) * k);
    int* size = malloc(sizeof(int) * k);
    for (i = 0; i < n; i++) {
        scanf("%lf %lf", &x, &y);
        p1[i].x = x;
        p1[i].y = y;
    }
    for (i = 0; i < k; i++)
    {
        num = rand() % n + 1;
        for (j = 0; j <= i; j++)
        {
            if (random[j] == num)
            {
                i--;
                break;
            }
        }
        c1[i].x = p1[num].x;
        c1[i].y = p1[num].y;
        printf("%f %f\n", c1[i].x, c1[i].y);
    }
    while (check==1)
    {
        for (j = 0; j < k; j++) {
            c1[j].newx = 0;
            c1[j].newy = 0;
            size[j] = 0;
        }
        for (i = 0; i < n; i++) {
            num = 0;
            for (j = 0; j < k; j++) {
                distance[j] = 0;
            }
            for (j = 0; j < k; j++) {
                distance[j] = pow((c1[j].x - p1[i].x) * (c1[j].x - p1[i].x) + (c1[j].y - p1[i].y) * (c1[j].y - p1[i].y), 0.5);
            }
            max = distance[0];
            for (j = 0; j < k; j++) {
                if (max > distance[j])
                {
                    num = j;
                    max = distance[j];
                }
            }
            c1[num].newx += p1[i].x;
            c1[num].newy += p1[i].y;
            size[num] += 1;
        }
        check = 0;
        for (j = 0; j < k; j++) {
            if (c1[j].size != size[j])
            {
                check = 1;
                break;
            }
        }
        printf("\n%d번째 update 후 클러스터 상태\n", t++);
        printf("\n");
        for (j = 0; j < k; j++) {
            c1[j].size = size[j];
            c1[j].x = c1[j].newx / c1[j].size;
            c1[j].y = c1[j].newy / c1[j].size;
            printf("Cluster %d: [x=%f, y=%f], size = %d\n",j, c1[j].x, c1[j].y,c1[j].size);
        }
    }

    free(size);
    free(distance);
    free(p1);
    free(c1);
}
