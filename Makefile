build: 
	cc aratime.c -o aratime
install: 
	cp -f aratime /opt/bin/
clean: 
	rm aratime

