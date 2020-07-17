#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/23 23:57:53 by mbiliaie          #+#    #+#              #
#    Updated: 2018/08/23 23:57:58 by mbiliaie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME       = libftprintf.a

CFLAGS     = -Wall -Wextra -Werror

LFT_FOLDER = libft
SRC_FOLDER = srcs
OUT_FOLDER = out
HDR_FOLDER = includes

C    = clang

SRC  = ft_printf.c general_parcer.c get_flags.c prepare_wstrs_handler.c \
	   prepare_ints_handler.c prepare_strs_handler.c run_chars_display.c \
	   run_ints_display.c run_strs_display.c run_wstrs_display.c \
	   upload_b_chars.c utab_atoi_extd_convert.c prepare_chars_handler.c 

SRCS = $(addprefix $(SRC_FOLDER)/,$(SRC))
OUT  = $(addprefix $(OUT_FOLDER)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OUT)
	@echo "compiling..."
	@make -C $(LFT_FOLDER)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OUT)
	@ranlib $(NAME)
	@echo "libftprintf is ready"

$(OUT_FOLDER)/%.o: $(SRC_FOLDER)/%.c
	@mkdir -p out
	@$(CC) $(CFLAGS) -I $(HDR_FOLDER) -o $@ -c $<

clean:
	@rm -f $(OUT)
	@rm -rf $(OUT_FOLDER)
	@make clean -C $(LFT_FOLDER)
	@echo "clean was done"
fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LFT_FOLDER)
	@echo "fclean was done"

re: fclean all
