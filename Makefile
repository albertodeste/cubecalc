CC = gcc
LLIBS = -pthread -L/usr/local/Cellar/libneo4j-client/1.1.0/lib -lneo4j-client -lssl -lcrypto -lz

cubecalc:
	$(CC) $(LLIBS) src/cubecalc.c -o target/cubecalc

clean:
	\rm target/*
