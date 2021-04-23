#include "libft.h"

static int	ft_get_rank(unsigned int un)
{
	int	i;

	if (un < 10)
		return (1);
	i = 1000000000;
	while (un / i == 0)
		i /= 10;
	return (i);
}

static size_t	ft_get_length(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	un;
	int			i;
	int			j;

	j = 0;
	un = (long int)n;
	if (un < 0)
		un = -un;
	i = ft_get_rank(un);
	str = malloc((ft_get_length(i) + 1) * sizeof(*str));
	if (0 == str)
		return (0);
	while (i)
	{
		str[j++] = (char)(un / i + '0');
		un %= i;
		i /= 10;
	}
	str[j] = 0;
	if (n < 0)
		str = ft_strjoin("-", str);
	return (str);
}
