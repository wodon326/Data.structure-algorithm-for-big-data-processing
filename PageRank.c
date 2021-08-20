# include <stdio.h>
#include <stdlib.h>
int main()
{
    double page_matrix[10][10] = { 0, }, page_matrix_dangling[10][10] = { 0, };
    double  page_value[10] = { 0, }, page_value_dangling[10] = { 0, };
    int num, a, b, i, j, outline[10] = { 0, };
    scanf("%d", &num);
    for (i = 0; i < 9; i++)
    {
        page_value[i] = 1.0 / num;
        page_value_dangling[i] = 1.0 / num;
        scanf("%d %d", &a, &b);
        outline[a] += 1;
        page_matrix[b][a] = 1;
    }
    for (i = 0; i < num; i++)
        for (j = 0; j < num; j++)
            page_matrix_dangling[i][j] = page_matrix[i][j];

    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num; j++)
        {
            if (abs(page_matrix[j][i] - 1.0) < 0.5)
            {
                page_matrix[j][i] = 1.0 /(float)outline[i];
            }

            if (outline[i] < 1)
            {
                for (int k = 0; k < num; k++)
                {
                    page_matrix_dangling[j][i] = 1.0 / 4.0;
                }
            }
            else if (abs(page_matrix_dangling[j][i]-1.0) < 0.5)
            {
                page_matrix_dangling[j][i] = 1.0 / (float)outline[i];
            }

            
        }
    }
    printf("page_matrix\n");
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num; j++)
        {
            printf("%.5f ", page_matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("page_matrix_dangling\n");
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num; j++)
        {
            printf("%.5f ", page_matrix_dangling[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int k = 0; k < 90; k++)
    {
        double result[10] = { 0, };
        for (i = 0; i < num; i++)
        {
            for (j = 0; j < num; j++)
            {
                result[i] += page_matrix[i][j] * page_value[j];
            }
        }
        for (i = 0; i < num; i++)
        {
            page_value[i] = result[i];
        }
    }
   
    for (int k = 0; k < 90; k++)
    {
        double result[10] = { 0, };
        for (i = 0; i < num; i++)
        {
            for (j = 0; j < num; j++)
            {
                result[i] += page_matrix_dangling[i][j] * page_value_dangling[j];
            }
        }
        for (i = 0; i < num; i++)
        {
            page_value_dangling[i] = result[i];
        }
    }

    printf("page_matrix\n");
    for (i = 0; i < num; i++)
    {
        printf("%d:   %f\n", i, page_value[i]);
    }

    printf("page_matrix_dangling\n");
    for (i = 0; i < num; i++)
    {
        printf("%d:   %f\n", i, page_value_dangling[i]);
    }
}
