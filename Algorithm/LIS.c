#include <stdio.h>
int main()
{
    int arr[] = {10,22,9,33,21,50,41,60,80};
    int *res;
    int *out;
    int len = sizeof(arr)/sizeof(arr[0]);
    int max = len > 0 ? 1 : 0;
    int n = 1;
    int maxi = 0;
    int i,j;

    res = (int*)malloc(sizeof(int) * len);
    out = (int*)malloc(sizeof(int) * len);
    for (i=0; i < len; i++)
    {
        res[i] = 1;
        out[i] = -1;
    }

    for (i = 1; i < len; i++)
    {
        n = res[i];
        for (j = 0; j < i; j++)
        {
            if ((arr[i] > arr[j]) && (res[j] >= n))
            {
                n = res[j] + 1;
                out[i] = j;
            }
        }
        res[i] = n;
        if (n > max)
        {
            maxi = i;
            max = n;
        }
    }

    printf("LIS:%d\n", max);
    if (len)
        output(arr, out, maxi);
    printf("\n");
    return 0;
}

void output(int *arr, int *out, int curi)
{
    if (curi < 0)
        return;

    if (out[curi] != -1)
    {
        output(arr, out, out[curi]);
    }
    printf("%d ", arr[curi]);
}
