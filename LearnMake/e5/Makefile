dependencies := hello.c goodbye.c
output := $(dependencies:%.c=%.o)
product := greetings

$(product): $(output) #Compile everything
	cc $(output) -o $@

$(dependencies):
	touch $@
	echo "int main(){return 0;}" > $@