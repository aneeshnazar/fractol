# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anazar <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/02 16:09:29 by anazar            #+#    #+#              #
#    Updated: 2018/01/05 14:43:31 by anazar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRCDIR = srcs/
LIBDIR = libft/
INCDIR = includes/
MLXDIR = minilibx_ec/
FILES = main fractol init_img init_coord init_fractol draw_fractol place_at julia mandelbrot burningship events
SRCS = $(addprefix $(SRCDIR), $(patsubst %, %.c, $(FILES)))
OBJS = $(patsubst %, %.o, $(FILES))
FLAGS = -Wall -Werror -Wextra -I$(INCDIR) -I$(LIBDIR)$(INCDIR) -I$(MLXDIR)
LFLAG = -framework OpenGL -framework Appkit -L $(LIBDIR) -lft -L $(MLXDIR) -lmlx

all:	$(NAME)

lib:
	@make -C libft/ re

$(NAME):	$(OBJS)
	@$(MAKE) lib
	@make -C $(MLXDIR) re
	@gcc $(OBJS) $(LFLAG) -o $(NAME)

$(OBJS):	$(SRCS)
	@gcc $(FLAGS) -c $(SRCS)

clean:
	@make -C $(LIBDIR) clean
	@make -C $(MLXDIR) clean
	@rm -rf *.o

fclean:
	@make -C $(LIBDIR) fclean
	@$(MAKE) clean
	@rm -rf $(NAME)

re:	fclean all
