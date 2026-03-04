CC = gcc
CFLAGS = -Wall -pedantic

all: curl_downloader

curl_downloader: main.c
	$(CC) $(CFLAGS) -o curl_downloader main.c

clean:
	rm -f curl_downloader