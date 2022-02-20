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
	$(CC) example.c -L . -l$(TITLE) -o $(TITLE)

install:
	@make generate
	@echo "Installing."	
	@cp src/$(TITLE).h $(DIR)/include/
	@cp lib$(TITLE).so $(DIR)/lib/
	@echo "Done!"

uninstall:
	@echo "Removing loggr..."
	@rm -rf $(DIR)/lib/lib$(TITLE).so
	@rm -rf $(DIR)/lib/$(TITLE).h
	@echo "Done."