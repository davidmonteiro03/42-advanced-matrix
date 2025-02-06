# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 08:08:38 by dcaetano          #+#    #+#              #
#    Updated: 2025/01/29 13:33:36 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# === COMMANDS =============================================================== #

CPP          = c++
MK           = mkdir
RM           = rm
AR_RCS       = ar rcs

# === DIRECTORIES ============================================================ #

INCS_D       = includes
SRCS_D       = srcs
OBJS_D       = objs
TMPS_D       = tmps
MAND_D       = mandatory
BNUS_D       = bonus

# === EXTENSIONS ============================================================= #

CPP_EXT      = .cpp
HPP_EXT      = .hpp
TPP_EXT      = .tpp
OBJ_EXT      = .o

# === FILES ================================================================== #

TSTS         = add subtract multiply lin_comb lin_inter dot_product \
               vector_norm cosine x_prod lin_map mat_trace mat_transpose \
               mat_row_echelon mat_determinant mat_inverse mat_rank
CLSS         = Vector Matrix
CPPS         = display
HDRS         = $(CLSS) ft_$(NAME) $(TSTS) display general
TMPL         = $(CLSS) $(TSTS) display general
TSTS_B       = $(TSTS)
HDRS_B       = $(CLSS) ft_$(NAME) $(TSTS_B) display general
TMPL_B       = $(CLSS) $(TSTS_B) display general

ifeq ($(MAKECMDGOALS),bonus)
    INCS     = $(addprefix $(BNUS_D)/$(INCS_D)/, \
                           $(addsuffix $(HPP_EXT), \
                                       $(HDRS_B)))
    SRCS     = $(addprefix $(BNUS_D)/$(SRCS_D)/, \
                           $(addsuffix $(CPP_EXT), \
                                       $(CPPS)))
    OBJS     = $(patsubst $(BNUS_D)/$(SRCS_D)/%$(CPP_EXT), \
                          $(OBJS_D)/$(BNUS_D)/$(SRCS_D)/%$(OBJ_EXT), \
                          $(SRCS))
    TMPS     = $(addprefix $(BNUS_D)/$(TMPS_D)/, \
                           $(addsuffix $(TPP_EXT), \
                                       $(TMPL_B)))
    MAIN_CPP = bonus$(CPP_EXT)
else
    INCS     = $(addprefix $(MAND_D)/$(INCS_D)/, \
                           $(addsuffix $(HPP_EXT), \
                                       $(HDRS)))
    SRCS     = $(addprefix $(MAND_D)/$(SRCS_D)/, \
                           $(addsuffix $(CPP_EXT), \
                                       $(CPPS)))
    OBJS     = $(patsubst $(MAND_D)/$(SRCS_D)/%$(CPP_EXT), \
                          $(OBJS_D)/$(MAND_D)/$(SRCS_D)/%$(OBJ_EXT), \
                          $(SRCS))
    TMPS     = $(addprefix $(MAND_D)/$(TMPS_D)/, \
                           $(addsuffix $(TPP_EXT), \
                                       $(TMPL)))
    MAIN_CPP = main$(CPP_EXT)
endif

MAIN_OBJ     = $(patsubst %$(CPP_EXT), \
                          $(OBJS_D)/%$(OBJ_EXT), \
                          $(MAIN_CPP))

# === FLAGS ================================================================== #

CPP_FLAGS    = -Wall -Wextra -Werror -std=c++2a -pedantic -g
MK_FLAGS     = -p
RM_FLAGS     = -rfv

# === PROJECT ================================================================ #

NAME         = matrix
LIB          = $(NAME).a

# === RULES ================================================================== #

all: $(NAME)

bonus: $(NAME)

$(OBJS_D)/%$(OBJ_EXT): %$(CPP_EXT) $(INCS) $(TMPS)
	@$(MK) $(MK_FLAGS) $(dir $@)
	$(CPP) $(CPP_FLAGS) -c $< -o $@

$(OBJS_D)/$(MAND_D)/$(SRCS_D)/%$(OBJ_EXT): $(MAND_D)/$(SRCS_D)/%$(CPP_EXT) $(INCS) $(TMPS)
	@$(MK) $(MK_FLAGS) $(dir $@)
	$(CPP) $(CPP_FLAGS) -c $< -o $@

$(OBJS_D)/$(BNUS_D)/$(SRCS_D)/%$(OBJ_EXT): $(BNUS_D)/$(SRCS_D)/%$(CPP_EXT) $(INCS) $(TMPS)
	@$(MK) $(MK_FLAGS) $(dir $@)
	$(CPP) $(CPP_FLAGS) -c $< -o $@

$(LIB): $(OBJS)
	@$(AR_RCS) $(LIB) $(OBJS)

$(NAME): $(LIB) $(MAIN_OBJ)
	$(CPP) $(CPP_FLAGS) $(MAIN_OBJ) $(LIB) -o $(NAME)

clean:
	@$(RM) $(RM_FLAGS) $(OBJS_D)

fclean: clean
	@$(RM) $(RM_FLAGS) $(NAME) $(LIB)

re: fclean all

.PHONY: all bonus clean fclean re
