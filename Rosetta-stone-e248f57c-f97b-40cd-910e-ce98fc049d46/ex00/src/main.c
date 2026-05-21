/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azhuri <azhuri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:00:00 by azhuri            #+#    #+#             */
/*   Updated: 2024/05/18 00:00:00 by azhuri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static int	error_exit(char *number, char *content,
		t_dict *dict, const char *msg)
{
	if (number)
		free(number);
	if (content)
		free(content);
	if (dict)
		free_dict(dict);
	ft_puterror(msg);
	return (1);
}

static int	load_dictionary(const char *path, t_dict *dict, char **content)
{
	*content = load_file(path);
	if (*content == NULL)
		return (0);
	if (!parse_dict(*content, dict))
		return (-1);
	return (1);
}

static int	success_exit(char *number, t_dict *dict)
{
	free(number);
	free_dict(dict);
	return (0);
}

static int	fetch_dictionary(int argc, char **argv,
		t_dict *dict, char **content)
{
	if (argc == 3)
		return (load_dictionary(argv[1], dict, content));
	return (load_dictionary("numbers.dict", dict, content));
}

int	main(int argc, char **argv)
{
	char		*number;
	char		*content;
	t_dict		dict;
	int			status;

	if (argc < 2 || argc > 3)
		return (error_exit(NULL, NULL, NULL, "Error\n"));
	number = normalize_number(argv[argc - 1]);
	if (!number)
		return (error_exit(NULL, NULL, NULL, "Error\n"));
	status = fetch_dictionary(argc, argv, &dict, &content);
	if (status == 0)
		return (error_exit(number, NULL, NULL, "Dict Error\n"));
	if (status < 0)
		return (error_exit(number, content, NULL, "Dict Error\n"));
	free(content);
	if (!convert_number(number, &dict))
		return (error_exit(number, NULL, &dict, "Dict Error\n"));
	return (success_exit(number, &dict));
}
