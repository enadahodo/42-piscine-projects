/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azhuri <azhuri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:00:00 by azhuri            #+#    #+#             */
/*   Updated: 2024/05/18 00:00:00 by azhuri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_entry
{
	char	*key;
	char	*value;
}	t_entry;

typedef struct s_dict
{
	t_entry	*entries;
	int		size;
	int		capacity;
}	t_dict;

typedef struct s_words
{
	char	**items;
	int		size;
	int		capacity;
}	t_words;

typedef struct s_state
{
	const char	*number;
	int			len;
	int			groups;
	int			first_len;
	int			pos;
	int			index;
}	t_state;

char	*load_file(const char *path);
int		parse_dict(const char *content, t_dict *dict);
int		dict_parse_line(t_dict *dict, const char *line, size_t len);
void	free_dict(t_dict *dict);
int		dict_store(t_dict *dict, char *key, char *value);

void	words_init(t_words *words);
int		words_push(t_words *words, char *value);
void	words_free(t_words *words);
int		words_add_from_dict(t_words *words, t_dict *dict, const char *key);
void	words_print(t_words *words);
int		words_finish(t_words *words, int status);

void	build_scale_key(int groups_left, char *buf);
int		append_group(int value, t_dict *dict, t_words *words);

char	*normalize_number(const char *str);
int		convert_number(const char *number, t_dict *dict);

char	*find_value(t_dict *dict, const char *key);

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		is_space(char c);

void	ft_putstr(const char *s);
void	ft_puterror(const char *s);

#endif
