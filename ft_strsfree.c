#include "libft.h"

char	**ft_strsfree(char **strs, unsigned int k)
{
	while (--k >= 0)
		free(strs[k]);
	free (strs);
	return (NULL);
}
