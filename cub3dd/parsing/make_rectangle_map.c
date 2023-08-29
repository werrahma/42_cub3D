#include "../cub.h"


char    *create_str(int len)
{
    char	*str;
    int		i;

    i = 0;
    str = malloc(len + 1);
    while (i < len)
	{
		str[i] = '1';
		i++;
	}
    str[i] = '\0';
    return (str);
}

char	**rectagle_map(char **map)
{
    int i;
    size_t width;
    int len;

    len = 0;
    width = ft_strlen(map[0]);
    while (map[len])
        len++;
    len--;
    i = 0;
    while (map[i])
    {
        if (i < len && width < ft_strlen(map[i + 1]))
            width = ft_strlen(map[i + 1]);
	// printf("width == %zu\n", width);
		i++;
    }
    i = 0;
    while (map[i])
    {
        if (ft_strlen(map[i]) < width)
        {
            //don't forget to check leaks here
			// printf("_________%s\n__________", create_str(width - ft_strlen(map[i])));
            map[i] = ft_strjoin(map[i], create_str(width - ft_strlen(map[i])));
        }
        i++;
    }
	// for(int a = 0; map[a]; a++)
	// {
	// 	printf("%s\n", map[a]);
	// }
    return (map);
}