

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>
# include <unistd.h>

char	*get_next_line(int fd);
void	*ft_calloc(size_t n, size_t size);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int search_str);
void	*ft_memset(void *str, int c, size_t n);
char  *ft_strdup(const char *str);
#endif
