/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:49:53 by wcorrea-          #+#    #+#             */
/*   Updated: 2025/09/30 00:00:00 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1024

static void	ft_display(int fd)
{
	char	buffer[BUF_SIZE];
	int		ret;

	ret = read(fd, buffer, BUF_SIZE);
	while (ret > 0)
	{
		write(1, buffer, ret);
		ret = read(fd, buffer, BUF_SIZE);
	}
}

static void	ft_display_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(2, "ft_cat: ", 8);
		while (*filename)
		{
			write(2, filename, 1);
			filename++;
		}
		write(2, ": No such file or directory\n", 28);
	}
	else
	{
		ft_display(fd);
		close(fd);
	}
}

void	ft_cat(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
		ft_display(0);
	else
	{
		while (i < argc)
		{
			ft_display_file(argv[i]);
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	ft_cat(argc, argv);
	return (0);
}
