application=program

build:
	mkdir -p build; cd build; cmake .../.; make; cd ../.;

run:
	cd build; ./$(application)

clean:
	rm -rf buid/;

start:
	$(MAKE) clean; $(MAKE) build; $(MAKE) run;