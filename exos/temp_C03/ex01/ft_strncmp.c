int ft_strncmp(char *s1, char *s2, unsigned int n)
{
    unsigned int i;

    i = 0;
    while (*s1 && *s2 && i < n && *s1 == *s2)
    {
        s1++;
        s2++;
        i++;
    }
    if (i == n || n == 0)
        return (0);
    return (*s1 - *s2);
}
