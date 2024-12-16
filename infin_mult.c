#include "infin_mult.h"

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
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
    str *s1 = (str *)malloc(sizeof(str));
    str *s2 = (str *)malloc(sizeof(str));

    s1->s = av[1];
    s2->s = av[2];
    s1->sign = true;
    s2->sign = true;

    if (s1->s[0] == '-')
    {
        s1->sign = false;
        s1->s++;
        int x = 0;
        while (s2->s[x] == '0')
        {
            x++;
            s2->s++;
        }
    }
    if (s2->s[0] == '-')
    {
        s2->sign = false;
        s2->s++;
        int x = 0;
        while (s2->s[x] == '0')
        {
            x++;
            s2->s++;
        }
    }

    if (s1->sign == false && s2->sign == true)
        write(1, "-", 1);
    else if (s1->sign == true && s2->sign == false)
        write(1, "-", 1);

    int len = ft_strlen(s1->s) + ft_strlen(s2->s);
    int* array = (int *)malloc(len * sizeof(int));
    
    for (int i = 0; i < len; i++)
        array[i] = 0;

    int i = ft_strlen(s2->s) - 1;
    int loops = 0;;
    while (i >= 0)
    {
        int idxarr = len - loops;
        int x = ft_strlen(s1->s) - 1;
        while (x >= 0)
        {
            printf("%d, %d\n", ctoi(s2->s[i]), ctoi(s1->s[x]));
            array[idxarr] += ctoi(s2->s[i]) * ctoi(s1->s[x]);
            printf("%d\n", array[idxarr]);
            idxarr--;
            x--;
        }
        printf("\n");
        loops++;
        i--;
    }

    // Print the array
    for (int i = 0; i <= len; i++)
    {
       printf("%d, ", array[i]);
    }
    printf("\n");
    int duplen = len;

    while (len > 0)
    {
        
        if (len > 0)
            array[len - 1] += array[len] / 10;
        array[len] = array[len] % 10;
        len--;
    }
    len++;

    while (len <= duplen)
    {
        char c = itoc(array[len]);
        write(1, &c, 1);
        // write(1, (char[2]) {itoc(array[len]), '\0'}, 1);
        len++;
    }

    free(array);
    free(s1);
    free(s2);
    return 0;

}
