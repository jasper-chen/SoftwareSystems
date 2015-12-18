#INC=-I/usr/local/Cellar/glib/2.44.1/include/glib-2.0 -I/usr/local/opt/gettext/include -L/usr/local/Cellar/glib/

helloworld: helloworld.c
	gcc helloworld.c `pkg-config --cflags --libs glib-2.0` -o helloworld