# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jelvan-d <jelvan-d@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/05/25 12:35:41 by jelvan-d      #+#    #+#                  #
#    Updated: 2020/06/11 11:06:34 by jelvan-d      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	libcub3d

SRCS			=	initialize_struct\
					parser_utils\
					parser\
					error_handling\
					map_handling\
					floodfill\
					my_mlx_pixel_put

CFILES			=	$(SRCS:%=%.c)
OFILES			=	$(CFILES:.c=.o)
HFILES			=	./cub3d.h\
					./libft/libft.h\
					./get_next_line/get_next_line.h\
					./ft_printf/printf.h\
					./minilibx-master/mlx_int.h\
					./minilibx-master/mlx.h
INCLUDES		=	$(HFILES)\
					$(LIBRARIES)
FLAGS			=	-Wall -Wextra -Werror
LIBRARIES		=	libft/libft.a\
					get_next_line/gnl.a\
					ft_printf/libftprintf.a\
					minilibx-master/libmlx_x86_64.a
					
all:		$(NAME)

$(NAME):	$(OFILES)
	@ar rc $(NAME).a $(OFILES)
	@ranlib $(NAME).a
	@echo "Compiled the cub3d library"

$(LIBRARIES):
	@echo "Compiling libft..."
	@make bonus -C libft
	@echo "Compiling get_next_line..."
	@make -C get_next_line
	@echo "Compiling ft_printf..."
	@make -C ft_printf
	@echo "Compiling minilibx..."
	@make -C minilibx-master

%.o: %.c $(LIBRARIES)
	@gcc $(FLAGS) -I. -c $< -o $@
	@echo "Created $@"

clean:
	@echo "Cleaning..."
	@rm -f $(OFILES)

fclean:		clean
	@echo "Extra cleaning..."
	@rm -f $(NAME).a

re:			fclean all
