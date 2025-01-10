hello: blah blah.o
	echo "Hello world"

blah.o: blah.c
	cc -c blah.c -o blah.o # Runs second

blah: blah.o
	cc blah.o -o blah # Runs third

# Typically blah.c would already exist, but I want to limit any additional required files
blah.c:
	echo "int main() { return 0; }" > blah.c # Runs first