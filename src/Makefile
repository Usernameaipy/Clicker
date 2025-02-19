CC = gcc
CFLAGS_DEFOULT = -Wall -Wextra -pedantic -std=c11
CFLAGS_GTK = `pkg-config --cflags gtk+-3.0`
FLAGS_LINK_GTK = `pkg-config --libs gtk+-3.0`
FLAGS_X11 = -lX11 -lXtst
BIN_DIR = ../bin/
BUILD_DIR = ../build/
CONFIG_DIR = ../config/
NAME = app
TEST_NAME = test

all : main

main : main.o start.o gdk_application.o get_windata.o gdk_change_entry.o helper.o thread_in.o input.o save_event.o thread_cl.o click.o read_event.o
	$(CC) main.o start.o gdk_application.o get_windata.o gdk_change_entry.o helper.o thread_in.o input.o save_event.o thread_cl.o click.o read_event.o -o $(BUILD_DIR)$(NAME) $(FLAGS_LINK_GTK) $(FLAGS_X11)

main.o : main/main.c main/main.h
	$(CC) -c $(CFLAGS_GTK) main/main.c -o main.o

start.o : main/start.c main/start.h
	$(CC) -c $(CFLAGS_DEFOULT) $(CFLAGS_GTK) main/start.c -o start.o

gdk_application.o : gdk/gdk_application.c gdk/gdk_application.h
	$(CC) -c $(CFLAGS_GTK) gdk/gdk_application.c -o gdk_application.o

get_windata.o : gdk/get_windata.c gdk/get_windata.h
	$(CC) -c $(CFLAGS_DEFOULT) gdk/get_windata.c -o get_windata.o $(FLAGS_X11)

gdk_change_entry.o : gdk/gdk_change_entry.c gdk/gdk_change_entry.h
	$(CC) -c $(CFLAGS_DEFOULT) $(CFLAGS_GTK) gdk/gdk_change_entry.c -o gdk_change_entry.o

helper.o : helper/helper.c helper/helper.h
	$(CC) -c $(CFLAGS_DEFOULT) $(CFLAGS_GTK) helper/helper.c -o helper.o

thread_in.o : input/thread_in.c input/thread_in.h
	$(CC) -c $(CFLAGS_DEFOULT) $(CFLAGS_GTK) input/thread_in.c -o thread_in.o $(FLAGS_X11)

input.o : input/input.c input/input.h
	$(CC) -c $(CFLAGS_DEFOULT) $(CFLAGS_GTK) input/input.c -o input.o $(FLAGS_X11)

save_event.o : file_changer/save_event.c file_changer/save_event.h input/user_click.h
	$(CC) -c $(CFLAGS_DEFOULT) $(CFLAGS_GTK) file_changer/save_event.c -o save_event.o

thread_cl.o : clicker/thread_cl.c clicker/thread_cl.h
	$(CC) -c $(CFLAGS_DEFOULT) $(CFLAGS_GTK) clicker/thread_cl.c -o thread_cl.o $(FLAGS_X11)

click.o : clicker/click.c clicker/click.h
	$(CC) -c $(CFLAGS_DEFOULT) $(CFLAGS_GTK) clicker/click.c -o click.o $(FLAGS_X11)

read_event.o : file_changer/read_event.c file_changer/read_event.h input/user_click.h
	$(CC) -c $(CFLAGS_DEFOULT) $(CFLAGS_GTK) file_changer/read_event.c -o read_event.o

clean_o :
	rm -rf *.o

clean_conf :
	rm -rf $(CONFIG_DIR)*.conf

clean_tst :
	rm -rf $(TEST_NAME)

clean_bin :
	tm -rf $(BIN_DIR)*

clean : clean_o clean_conf clean_tst
	rm -rf $(BUILD_DIR)*
	rm -rf $(BIN_DIR)*

rebuild : clean all

go :
	$(BUILD_DIR)$(NAME)

style_check :
	find . -name "*.c" -o -name "*.h" | xargs clang-format -n --style=Google

style :
	find . -name "*.c" -o -name "*.h" | xargs clang-format -i --style=Google

valgrind : clean
	make main && CK_FORK=no valgrind --vgdb=no --leak-check=full --show-reachable=yes --show-leak-kinds=all --track-origins=yes --verbose --read-var-info=yes ./$(BUILD_DIR)$(NAME)