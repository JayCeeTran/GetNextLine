#include "get_next_line.h"

char	*loop(char *buffer, char *line, int *i, int len)
{
		while (*i < len)
		{
			line[(*i)] = buffer[(*i)];
			(*i)++;
		}
		return (line);
}

char	*get_next_line(int fd)
{
	size_t byteread;
	char	buffer[999999];
	int		len;
	char	*line;
	int i;

	i = 0;
	len = 0;
	if (fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	while (((byteread = read(fd, &buffer[len], 1)) > 0) && buffer[len] != '\n')
		len++;
	if (byteread <= 0 && len == 0)
		return (NULL);
	buffer[len + 1] = '\0';
	line = malloc(len + 2);
	if (!line)
		return(NULL);
	loop(buffer, line, &i, len);
	if (byteread)
		line[i++] = '\n';
	line[i] = '\0';
	return(line);
}

/*int	main(void)
{
	
	int	fd = open("readtest", O_RDONLY);
	char *dest;
	char *test[5];

	if (fd < 0)
	{	
		printf("failed to open");
		return (1);
	}

	while ((dest = get_next_line(fd)) != NULL)
		printf("%s", dest);
	int i = 0;
	close(fd);
	return(0);

}*/
