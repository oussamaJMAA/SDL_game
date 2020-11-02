programme:main.o input.o draw.o init.o menu.o jonathan.o jonathan_vh.o animation.o map.o collision.o ennemis.o col_mvt.o etoile.o text.o gestion.o herbe.o arduino.o sauvegarde.o herbes2.o statues.o
	gcc main.o input.o draw.o init.o menu.o jonathan.o jonathan_vh.o animation.o map.o collision.o ennemis.o col_mvt.o etoile.o text.o gestion.o herbe.o arduino.o sauvegarde.o herbes2.o statues.o -o programme -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -g
main.o:main.c
	gcc -c main.c -g
input.o:input.c
	gcc -c input.c -g
draw.o:draw.c
	gcc -c draw.c -g
init.o:init.c
	gcc -c init.c -g
menu.o:menu.c
	gcc -c menu.c -g
jonathan.o:jonathan.c
	gcc -c jonathan.c -g
jonathan_vh.o:jonathan_vh.c
	gcc -c jonathan_vh.c -g 
animation.o:animation.c
	gcc -c animation.c -g
map.o:map.c
	gcc -c map.c -g 
collision.o:collision.c 
	gcc -c collision.c -g 
ennemis.o:ennemis.c 
	gcc -c ennemis.c -g
col_mvt.o:col_mvt.c
	gcc -c col_mvt.c -g 		 
etoile.o:etoile.c
	gcc -c etoile.c -g 
text.o:text.c
	gcc -c text.c -g 
gestion.o:gestion.c
	gcc -c gestion.c -g
herbe.o:herbe.c
	gcc -c herbe.c -g 
arduino.o:arduino.c
	gcc -c arduino.c -g
sauvegarde.o:sauvegarde.c
	gcc -c sauvegarde.c -g
herbes2.o:herbes2.c
	gcc -c herbes2.c -g
statues.o:statues.c
	gcc -c statues.c -g
clean:
	rm -fr *.o
mrproper:clean
	rm -f programme
