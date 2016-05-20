CC = gcc
LLIBS = -pthread

cubecalc:
	$(CC) $(LLIBS) src/cubecalc.c -o target/cubecalc

clean:
	\rm target/*
