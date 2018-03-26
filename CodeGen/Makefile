all: binary

binary: 
		mkdir -p bin
		gcc ./src/*.c -o codegen
		mv codegen bin/

clean: 
	rm -r bin