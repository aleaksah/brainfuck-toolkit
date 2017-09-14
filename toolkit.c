#include "toolkit.h"


int main(int argc, char **argv)
{
	char test[] = " ++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.++++++ + ..++ + .>++. << ++++++++++++++ + .>.++ + .------.--------.>+.>.";
	setbuf(stdout, NULL);
	printf("IsEndOfProgram: %d\n", InterpIsEndOfProgram());
	printf("InterpLoad: %d\n", InterpLoad(test));
	printf("InterpSetIP: %d\n", InterpSetIP(0));
	printf("InterpRun: %d\n", InterpRun());
	printf("IsEndOfProgram: %d\n", InterpIsEndOfProgram());
}
