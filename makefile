all: derle bagla calistir
derle:
	gcc -c -I "./include" ./src/Dosya.c -o ./lib/Dosya.o
	gcc -c -I "./include" ./src/Kisi.c -o ./lib/Kisi.o
	gcc -c -I "./include" ./src/Kisiler.c -o ./lib/Kisiler.o
	gcc -c -I "./include" ./src/Sayi.c -o ./lib/Sayi.o
	gcc -c -I "./include" ./src/Sayilar.c -o ./lib/Sayilar.o
	gcc -c -I "./include" ./src/Oyun.c -o ./lib/Oyun.o
	gcc -c -I "./include" ./src/Test.c -o ./lib/Test.o
bagla:
	gcc ./lib/Dosya.o ./lib/Kisi.o ./lib/Kisiler.o ./lib/Sayi.o ./lib/Sayilar.o ./lib/Oyun.o ./lib/Test.o -o ./bin/Test
calistir:
	./bin/Test