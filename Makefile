NAME_CLIENT = client
NAME_SERVER = server

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = lib/libft
FT_PRINTF_DIR = lib/ft_printf
INC_DIR = include

SRC_CLIENT = $(SRC_DIR)/client/client.c $(SRC_DIR)/client/client_utils.c
SRC_SERVER = $(SRC_DIR)/server/server.c 
OBJ_CLIENT = $(SRC_CLIENT:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_SERVER = $(SRC_SERVER:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
LIBS = -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf

HEADERS = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR)

all: $(NAME_CLIENT) $(NAME_SERVER)
	@printf "\e[32mCLIENT OK\e[0m\n"
	@printf "\e[34mSERVER OK\e[0m\n"

$(NAME_CLIENT): $(LIBFT) $(FT_PRINTF) $(OBJ_CLIENT)
	@$(CC) $(CFLAGS) $(OBJ_CLIENT) $(HEADERS) $(LIBS) -o $(NAME_CLIENT) 1>/dev/null 

$(NAME_SERVER): $(LIBFT) $(FT_PRINTF) $(OBJ_SERVER)
	@$(CC) $(CFLAGS) $(OBJ_SERVER) $(HEADERS) $(LIBS) -o $(NAME_SERVER) 1>/dev/null 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@ 

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) 1>/dev/null

$(FT_PRINTF):
	@$(MAKE) -C $(FT_PRINTF_DIR) 1>/dev/null


clean:
	@$(MAKE) -C $(LIBFT_DIR) clean 1>/dev/null
	@$(MAKE) -C $(FT_PRINTF_DIR) clean 1>/dev/null
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean 1>/dev/null
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean 1>/dev/null
	@rm -f $(NAME_CLIENT)
	@rm -f $(NAME_SERVER)
	@echo "All executable files and object files have been removed. (fclean)"


re: fclean all

.PHONY: all clean fclean re
