#include "infin_add.h"

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

void find_biggest(str* s1, str *s2)
{
    if (ft_strlen(s1->s) > ft_strlen(s2->s))
    {
        s1->biggest = true;
        return ;
    }
    else if (ft_strlen(s1->s) < ft_strlen(s2->s))
    {
        s2->biggest = true;
        return ;
    }
    int size = ft_strlen(s1->s);
    int i = 0;
    while (i < size)
    {
        if (s1->s[i] > s2->s[i])
        {
            s1->biggest = true;
            return ;
        }
        else if (s1->s[i] < s2->s[i])
        {
            s2->biggest = true;
            return ;
        }
        i++;
    }
}

int ctoi(char c)
{
    return (c - '0');
}

char itoc(int c)
{
    return (c + '0');
}


int main(int ac, char **av)
{
    str s1;
    str s2;

    int operator = 1;
    s1.s = av[1];
    s1.sign = 1;
    s2.s = av[2];
    s2.sign = 1;
    s1.biggest = false;
    s2.biggest = false;

    if (s1.s[0] == '-')
    {
        s1.sign = -1;
        s1.s++;
        int x = 0;
        while (s2.s[x] == '0')
        {
            x++;
            s2.s++;
        }
    }
    if (s2.s[0] == '-')
    {
        s2.sign = -1;
        s2.s++;
        int x = 0;
        while (s2.s[x] == '0')
        {
            x++;
            s2.s++;
        }
    }

    if (s1.sign == -1 && s2.sign == -1)
        write(1, "-", 1);
    else if (s1.sign != s2.sign)
    {
        operator = -1;
        find_biggest(&s1, &s2);
    }

    str biggest;
    str smallest;
    biggest = (s1.biggest == true) ? s1 : s2;
    smallest = (s1.biggest == true) ? s2 : s1;

    if (biggest.sign == -1 && smallest.sign != -1)
        write(1, "-", 1);



    int size = ft_strlen(biggest.s) + 1;

    int *arr = (int *)malloc(size * sizeof(int));

    int o = 0;
    while (o < size)
    {
        arr[o] = 0;
        o++;
    }
    int i = size - 1;
    int f = ft_strlen(biggest.s) - 1;
    int y = ft_strlen(smallest.s) - 1;

    // printf("size %d\n", size);
    while (i >= 0)
    {
        int left = (f >= 0) ? ctoi(biggest.s[f]) : 0;
        int right = (y >= 0) ? ctoi(smallest.s[y]) : 0;
        // printf("left %d right %d, ", left, right);
        arr[i] = left + operator * right;
        i--;
        f--;
        y--;
    }
    i = 0;    
    // while (i < size)
    // {
    //    printf("%d, ",arr[i]);
    //    i++;
    // }
    // printf("\n");
    int x = size;

    while (x >= 0)
    {
        if (arr[x] > 9)
        {
            arr[x - 1] += 1;
            arr[x] = arr[x] % 10;
        }
        else if (arr[x] < 0)
        {
            arr[x] += 10;
            arr[x - 1] -= 1; 
        }
        x--;
    }

    x++;
    while (x >= 0 && arr[x] == 0)
        x++;

    while (x < size)
    {
        char c = itoc(arr[x]);
        write(1, &c, 1);
        x++;
    }
    return (0);
}