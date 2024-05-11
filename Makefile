build: 
	cc aratime.c -o aratime
install: 
	cp -f aratime /opt/bin/ && cp -f aratime_wrapper /opt/bin/ && cp -f aratime_wrapper_random /opt/bin/
clean: 
	rm aratime 

