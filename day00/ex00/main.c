#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUF_SIZE 1024

struct s_art {
	char	*name;
	int		price;
};

struct s_art	*split_line(struct s_art *array_art, char *line)
{
	int i;
	int j;
	char *price;

	i = 0;
	j = 0;
	printf("%s\n", line);
	while (line[i] && !strncmp(line + i, " => ", 4))
	{
		array_art->name[j] = line[i];
		i++;
		j++;
	}
	printf("I'm here\n");
	array_art->name[j] = '\0';
	printf("%s\n", &line[i]);
	i = i + 4;
	j = 0;
	price = (char *)malloc(sizeof(char) * strlen(array_art->name) + 1);
	while (line[i] && line[i] != '\n')
	{
		price[j] = line[i];
		i++;
		j++;
	}
	price[j] = '\0';
	array_art->price = atoi(price);
	return (array_art);
}

int		parse_file(char *name)
{
	FILE			*fp;
	size_t			len;
	int				ret;
	int				i;
	char			*line;
	struct s_art	**array_art;

	i = -1;
	len = 0;
	line = NULL;
	fp = fopen(name, "r");
	if (!fp)
	{
		printf("No such file or directory\n");
		exit(1);
	}
	array_art = (struct s_art **)malloc(sizeof(struct s_art *));
	while ((ret = getline(&line, &len, fp)) > 0)
	{
		i++;
		array_art[i] = split_line(array_art[i], line);
		printf("%s\n", array_art[i]->name);
		printf("%d\n", array_art[i]->price);
		exit(0);
	}
	return (0);
}

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		parse_file(argv[1]);
	}
	else
	{
		printf("usage: a.out [file_name]\n");
		return (1);
	}
	return (0);
}
