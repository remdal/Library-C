#include <stdio.h>
#include <stdlib.h>
#include "ft_show_tab.c"
#include "ft_strs_to_tab.c"

int	main(int argc, char *argv[])
{
	t_stock_str	*strs;
//	t_stock_str	*argv_one;
	int		i;

	i = 0;
//	argv_one = ft_strs_to_tab(argc - 1, argv + 1);
//	ft_show_tab(argv_one);
	strs = ft_strs_to_tab(argc, argv); 
	//strs[i].size = 3;
	//strs[i].str = "apd";
	//strs[i].copy = NULL;
	//ft_strs_to_tab(argc, argv);
	//ft_show_tab(strs);
	//while (i <= argc)
		ft_show_tab(strs);
	//	i++;
	
//	while (argv_one[i].str)
//	{
//		free(argv_one[i].copy);
//		i++;
//	}
//	free(argv_one);
//	i = 0;
        while (strs[i].copy)
        {
                free(strs[i].copy);
                i++;
        }
        free(strs);
	return (0);
}

