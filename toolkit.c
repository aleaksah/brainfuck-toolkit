#include "toolkit.h"


int main(int argc, char **argv)
{
	char test[] = "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.";

	printf("IsEndOfProgram: %d\n", IsEndOfProgram());
	printf("InterpLoad: %d\n", InterpLoad(test));
	printf("InterpSetIP: %d\n", InterpSetIP(0));
	printf("InterpRun: %d\n", InterpRun());
	printf("IsEndOfProgram: %d\n", IsEndOfProgram());
}
