all: compile

.PHONY: all compile

compile:
	$(MAKE) -C src && mv ./src/ims ./ims

clean:
	$(MAKE) clean -C src
	rm -f ims

zip:
	zip -r 06_xpetra19_xpitko00.zip src Makefile
