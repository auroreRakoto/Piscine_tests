int	ft_strlen(char *src)
{
	int	size;

	size = 0;
	while (src[size])
		size++;
	return (size);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len_dest;
	unsigned int	len_src;
	unsigned int	i;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	i = 0;
	if (size < len_dest)
		return (len_dest + size);
	while (src[i])
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	return (len_dest + len_src);
}