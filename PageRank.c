# include <stdio.h>
#include <stdlib.h>
int main()
{
    double m[10][10] = { 0, }, arr[10] = { 0, }, arr2[10] = { 0, };
    int num, a, b, i, j;
    scanf("%d", &num);
    for (i = 0; i < 9; i++)
    {
        arr2[i] = 1.0 / num;
        scanf("%d %d", &a, &b);
        arr[a] += 1;
        m[b][a] = 1;
    }
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num; j++)
        {
            if (arr[i] < 0.5)
            {
                for (int k = 0; k < num; k++)
                {
                    m[j][i] = 1.0 / 4.0;
                }
            }
            else if (abs(m[j][i]-1.0) < 0.5)
            {
                m[j][i] = 1.0 / arr[i];
            }
        }
    }
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num; j++)
        {
            printf("%.5f ", m[i][j]);
        }
        printf("\n");
    }
    for (int k = 0; k < 90; k++)
    {
        double result[10] = { 0, };
        for (i = 0; i < num; i++)
        {
            for (j = 0; j < num; j++)
            {
                result[i] += m[i][j] * arr2[j];
            }
        }
        for (i = 0; i < num; i++)
        {
            arr2[i] = result[i];
        }
    }
    for (i = 0; i < num; i++)
    {
        printf("%d:   %f\n", i, arr2[i]);
    }
}
