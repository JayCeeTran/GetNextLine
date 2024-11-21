#include "get_next_line.h"

static int	findn(char *buffer, int c)
{
	while(*buffer)
	{
		if(*buffer == c)
			return(1);
		buffer++;	
	}
	return(0);
}

static char *get_line(char *buffer)
{
	int	i;
	int	len;
	char *temp;

	len = 0;
	i = 0;
	if (!buffer)
		return (NULL);
	while(buffer[len] != '\n' && buffer[len])
		len++;
	temp = ft_calloc(len + 2, sizeof(char));
	while(i < len)
	{
		temp[i] = buffer[i];
		i++;
	}
	if(buffer[len] == '\n')
		temp[i++] = '\n';
	temp[i] = '\0';
	return (temp);
}

static char	*readfile(int fd, char *buffer)
{
	size_t byteread;
	char	*temp;
	char	*nbuff;

	if (!buffer)
	{
		buffer = ft_calloc(1, sizeof(char));
		if(!buffer)
			return(NULL);
	}
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if(!temp)
		return (NULL);
	while((byteread = read(fd, temp, BUFFER_SIZE)) > 0)
	{
		temp[byteread] = '\0';
		nbuff = ft_strjoin(buffer, temp);
		free(buffer);
		buffer = nbuff;
		if (findn(buffer, '\n'))
			break;
	}	
	free(temp);
	return (buffer);
}

static char	*restoffile(char *buffer)
{
	int	i;
	char	*temp;

	i = 0;
	if (!buffer)
		return (NULL);
	while(buffer[i] != '\n' && buffer[i])
		i++;
	if(buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	temp = ft_strdup(&buffer[i + 1]);
	free(buffer);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char	*line;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = readfile(fd, buffer);
	if (!buffer || buffer[0] == '\0')
	{	
		free (buffer);
		buffer = NULL;
		return (NULL);
	}
	line = get_line(buffer);
	buffer = restoffile(buffer);
	return(line);
}

/*int	main(void)
{
	
	int	fd = open("42_with_nl", O_RDONLY);
	char *dest;
//	char *test[5];

	if (fd < 0)
	{	
		printf("failed to open");
		return (1);
	}
	while((dest = get_next_line(fd)) != NULL)
	{
		printf("%s", dest);
		free(dest);
	}
	close(fd);
	return(0);
}*/
