CXX ?= g++

CPPFLAGS := -Isrc
CXXFLAGS := -Wall -Wextra -Wswitch-enum -pedantic -O2
LDFLAGS :=

SRCDIR ?= src

all: build/html-builder.o

build:
	mkdir -p build

build/html-builder.o: $(SRCDIR)/html-builder.cpp | build
	$(CXX) -c $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

#

example: example.cpp all
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ $< build/*.o $(LDFLAGS)

.PHONY: test
test: example
	./example

.PHONY: clean
clean:
	@FILES=$$(git clean -ndX); \
	if [ -z "$$FILES" ]; then \
		echo "No deletable files, skipping"; \
	else \
		echo "These files will be deleted:"; \
		echo "$$FILES"; \
		read -p "Do you want to delete them? [N/y] " yn; \
		if [ "$$yn" = "y" ] || [ "$$yn" = "Y" ]; then \
			git clean -fdX; \
		else \
			echo "Deletion cancelled."; \
		fi \
	fi