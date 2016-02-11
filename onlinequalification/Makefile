NAME			:= hashcode2016

SRCS			:= $(wildcard *.cpp)
CXXFLAGS		:= -W -Wall -Wextra -std=c++11
LDFLAGS			:=

CC				:= g++
RM				:= rm -vf

OBJS_DIR		:= build
OBJS_TMP		:= $(SRCS:.cpp=.o)
OBJS			:= $(patsubst %.o, $(OBJS_DIR)/%.o, $(OBJS_TMP))
DEPS			:= $(OBJS:.o=.d)


all: $(NAME)

$(OBJS_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CXXFLAGS) -MMD -c -o $@ $<

$(NAME): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

-include $(DEPS)

clean:
	$(RM) $(OBJS) *~

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug: CXXFLAGS += -g
debug: re


.PHONY: all clean fclean re debug
