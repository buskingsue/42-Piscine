/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:24:34 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/03/03 12:24:38 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int	ft_display_file(char *file_name)
{
	int		file;
	int		reading;
	char	buffer[BUFFER_SIZE];

	file = open(file_name, O_RDONLY);
	if (file == -1)
		return (0);
	reading = read(file, buffer, BUFFER_SIZE);
	while (reading)
	{
		if (reading == -1)
			return (0);
		write(1, buffer, reading);
		reading = read(file, buffer, BUFFER_SIZE);
	}
	close(file);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!ft_display_file(argv[1]))
			write(2, "Cannot read file.\n", 18);
	}
	else
	{
		if (argc < 2)
			write(2, "File name missing.\n", 19);
		if (argc > 2)
			write(2, "Too many arguments.\n", 20);
	}
	return (0);
}
