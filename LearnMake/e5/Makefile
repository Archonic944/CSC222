dependencies := hello.c goodbye.c
product := greetings

$(product): $(dependencies) #Compile everything
	cc -c $(dependencies)
	touch $@

$(dependencies):
	touch $@
	echo "int main(){return 0;}" > $@