4:
	rm -f A41 -f A42
	gcc Assignment_4/MorseConversion.c Assignment_4/ToMorse.c -std=c99 -Wall -o A41
	gcc Assignment_4/MorseConversion.c Assignment_4/ToLatin.c -std=c99 -Wall -o A42

5:
	rm -f A5
	gcc Assignment_5/qtest.c Assignment_5/queue.c -std=c99 -Wall -o A5

all:
	rm -f A41 -f A42 -f A5
	gcc Assignment_4/MorseConversion.c Assignment_4/ToMorse.c -std=c99 -Wall -o A41
	gcc Assignment_4/MorseConversion.c Assignment_4/ToLatin.c -std=c99 -Wall -o A42	
	gcc Assignment_5/qtest.c Assignment_5/queue.c -std=c99 -Wall -o A5


