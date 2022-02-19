CC = gcc
TITLE = loggr
# linux only smh
DIR ?= /usr/local

generate:
	@echo "Generating."
	@$(CC) -shared -Wl,soname,lib$(TITLE).so \
	src/$(TITLE).c -c -o lib$(TITLE).so
	@echo "Done."

test:
	$(CC) -L . -l$(TITLE) example.c -o $(TITLE)

install:
	@make generate
	@echo "Installing."	
	@sudo cp src/$(TITLE).h $(DIR)/include/
	@sudo cp lib$(TITLE).so $(DIR)/lib/
	@echo "Done."
