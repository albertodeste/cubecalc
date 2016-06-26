CC = gcc
LLIBS = -pthread -L/usr/local/Cellar/libneo4j-client/0.9.2/lib -lneo4j-client -lssl -lcrypto -lz

cubecalc:
	$(CC) $(LLIBS) src/cubecalc.c -o target/cubecalc

clean:
	\rm target/*

sample:
	$(CC) -L/usr/local/Cellar/libneo4j-client/0.9.2/lib -lneo4j-client -lssl -lcrypto -lz src/sample.c -o target/sample
