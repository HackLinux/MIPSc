// The declaration nodes need to have 'toOperations()' implemented
// for this to work...
// char greeting[] = "hello world";

int i;

int main()
{

    int j = 0;
    {
        int foo = 50000;
	//i = i + foo;
    }

    {
        int bar = 1;
	//bar = i + bar;
    }

    printf("%i", foo + bar );  

    lolz();

    //i = bar + 4;
}




