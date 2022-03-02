char	*check_line(int fd, char *tampon, char **save)
{
	int	ret_bytes;
	char	*tmp;
	// char	*free_str;
	
	tmp = NULL;
	ret_bytes = read(fd, tampon, BUFFER_SIZE);
	tampon[ret_bytes] = '\0';
	printf("debug1:                                                           %i\n", ret_bytes);
	if (ret_bytes <= 0) // if !tampon;
	{
			// end_fd(save, tampon, tmp);
		printf("address free de tampon :%p\n", tampon);	
		free(tampon);
			//printf("%s\n", save);
		// tmp = *save;	
		if (ft_strlen(tampon) == 0)
		{
			printf("free save dans check line : %p\n", save);
			DEBUG;
			*save = ft_strjoin(*save, tampon);
			return(*save);
			//free(save);
			// return (NULL);
		}
		tmp = ft_substr(*save, line_lenght(*save, '\n'), line_lenght(*save, '\0') - line_lenght(*save, '\n'));
		printf("address free de save :%p\n", save);
		free(save);
		return (tmp);
	}
	// inserer le substr de !save de no_end_line et tester
	return(0);
}