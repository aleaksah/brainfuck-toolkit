/**
\mainpage My Personal Index Page
\tableofcontents
\brief brief?
\section Introduction Introduction
Here will be introduction
\section test Test section
\subsection subsection
bla-bla-bla
- first
- second
- third
\attention alarm!
\todo everything
\details some details
\author aleaksah
\version 0.1 dev pre-alpha
\date 1944
\pre pre?
\bug bug description
\warning half-alarm
\copyright MIT
\note half-important text
\remark some remark text
\return return from this page equals true (or not)
\remark latex test \f$\pi = 3, \sum_{x=3}^{1}=\frac{\pi ^{21}}{3}\f$
*/

/**
\page brainfuck Brainfuck description
\tableofcontents
Leading text.
\section sec An example section
This page contains the subsections \ref subsection1 and \ref subsection2.
For more info see page \ref page2.
\subsection subsection1 The first subsection
Text.
\subsection subsection2 The second subsection
More text.
*/

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
