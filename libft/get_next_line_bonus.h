/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidzhang <lidzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:41:34 by lidzhang          #+#    #+#             */
/*   Updated: 2022/12/07 10:37:45 by lidzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 2048

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *rest_str, char *buff);
char	*extract_line(char *rest_str);
char	*extract_rest(char *rest_str);
char	*ft_read_to_rest_str(int fd, char *rest_str);
size_t	ft_strlen(const char *s);

#endif