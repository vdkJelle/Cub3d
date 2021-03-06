# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jelvan-d <jelvan-d@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/05/25 12:35:41 by jelvan-d      #+#    #+#                  #
#    Updated: 2020/07/22 14:26:27 by jelvan-d      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3d

SRCS			=	initialize_struct\
					parser_utils\
					parser\
					error_handling\
					map_handling\
					floodfill\
					my_mlx_pixel_put\
					colours\
					main

CFILES			=	$(SRCS:%=%.c)
OFILES			=	$(CFILES:.c=.o)
HFILES			=	-I./cub3d.h\
					-I./libft/includes/libft.h\
					-I./get_next_line/get_next_line.h\
					-I./ft_printf/printf.h\
					-I./minilibx_mac/mlx.h
INCLUDES		=	$(HFILES)\
					$(LIBRARIES)
FLAGS			=	-Wall -Wextra -Werror
LIBRARIES		=	libft/libft.a\
					get_next_line/gnl.a\
					ft_printf/libftprintf.a\
					minilibx_mac/libmlx.a
					
all:		$(NAME)

$(NAME): $(OFILES) $(LIBRARIES) 
	@gcc $(FLAGS) $^ -framework OpenGL -framework AppKit -o $(NAME)

$(LIBRARIES):
	@echo "Compiling libft..."
	@make -C libft
	@echo "Compiling get_next_line..."
	@make -C get_next_line
	@echo "Compiling ft_printf..."
	@make -C ft_printf
	@echo "Compiling minilibx..."
	@make -C minilibx_mac

%.o: %.c $(HFILES)
	@gcc $(FLAGS) $(HFILES) -c $< -o $@
	@echo "Created $@"

clean:
	@echo "Cleaning..."
	@rm -f $(OFILES)

fclean:		clean
	@echo "Extra cleaning..."
	@rm -f $(NAME).a

re:			fclean all

					#minilibx-master/mlx_int.h
					#minilibx-master/mlx.h
					#minilibx_mac/mlx_int.h
					#minilibx_mac/mlx_new_window.h
					#minilibx_mac/mlx_opengl.h
					#minilibx_mac/mlx_png.h

					#minilibx-master/libmlx_x86_64.a