build: 
	cc digital_wellbeing.c -o digital_wellbeing
install: 
	cp -f digital_wellbeing /opt/bin/
clean: 
	rm digital_wellbeing

