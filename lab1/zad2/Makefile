CC = gcc -Wall


all:
	make test clean
	
clean:
	make -C ../zad1 clean
	@rm -rf *.o  main


clean_files:
	@rm -rf *.txt main


test:
	cp -r ../files/*.txt ../zad2
	make -C ../zad1/ static
	$(CC) -c main.c
	$(CC) main.o ../zad1/lib_counting.a -o main

	@echo "SMALL TESTS\n\n\n" >> raport2.txt

	./main create: 3 count_files: small2.txt small3.txt count_files: small4.txt count_files: small1.txt small2.txt small3.txt small4.txt >> raport2.txt
	@echo "\n------------------------\n" >> raport2.txt
	./main create: 5 count_files: small2.txt small3.txt count_files: small4.txt count_files: small1.txt small2.txt small3.txt small4.txt  remove: 0 remove: 1 >> raport2.txt
	@echo "\n------------------------\n" >> raport2.txt
	./main create: 10 count_files: small.txt remove: 0 count_files: small1.txt remove: 1 >> raport2.txt

	@echo "\n\n\nMEDIUM TESTS \n\n\n" >> raport2.txt
	./main create: 4 count_files: medium1.txt medium2.txt medium3.txt count_files: medium1.txt medium2.txt medium3.txt count_files: medium1.txt medium2.txt medium3.txt >> raport2.txt
	@echo "\n------------------------\n" >> raport2.txt
	./main create: 5 count_files: medium1.txt medium2.txt medium3.txt count_files: medium1.txt medium2.txt medium3.txt remove: 0 remove: 1 >> raport2.txt
	@echo "\n------------------------\n" >> raport2.txt
	./main create: 5 count_files: medium1.txt medium2.txt medium3.txt medium1.txt medium2.txt medium3.txt remove: 0 count_files: medium1.txt medium2.txt medium3.txt medium1.txt medium2.txt medium1.txt medium3.txt remove: 1 >> raport2.txt
	@echo "\n------------------------\n" >> raport2.txt
	./main create: 10 count_files: medium1.txt medium2.txt medium3.txt count_files: medium1.txt medium2.txt medium3.txt count_files: medium1.txt medium2.txt medium3.txt >> raport2.txt

	@echo "\n\n\nLARGE TESTS \n\n\n" >> raport2.txt
	./main create: 100 count_files: large1.txt large2.txt large3.txt count_files: large1.txt large2.txt large3.txt count_files: large1.txt medium2.txt large3.txt >> raport2.txt
	@echo "\n------------------------\n" >> raport2.txt
	./main create: 5 count_files: large1.txt large2.txt large3.txt count_files: large1.txt large2.txt large3.txt large1.txt large2.txt large3.txt large1.txt large2.txt large3.txt remove: 0 remove: 1 >> raport2.txt
	@echo "\n------------------------\n" >> raport2.txt
	./main create: 10 count_files: large1.txt large2.txt large3.txt large1.txt large2.txt large3.txt remove: 0 count_files: large1.txt large2.txt large3.txt large1.txt large2.txt large3.txt large1.txt large2.txt large3.txt remove: 1 >> raport2.txt
	@echo "\n------------------------\n" >> raport2.txt
	./main create: 4 count_files: large1.txt large2.txt large3.txt count_files: large1.txt large2.txt large3.txt count_files: large1.txt large2.txt large3.txt large1.txt large2.txt large1.txt large2.txt large3.txt remove: 1 >> raport2.txt
